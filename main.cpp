#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"
#include <imgui.h>
#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")

#include <fstream>



//チャンクヘッダ
struct ChunkHeader
{
    char id[4];     //チャンク毎のID
    int32_t size;   //チャンクサイズ
};
//RIFFヘッダチャンク
struct RiffHeader
{
    ChunkHeader chunk;  //"RIFF"
    char type[4];       //"WAVE"
};
//FMTチャンク
struct FormatChunk
{
    ChunkHeader chunk;  //"fmt"
    WAVEFORMATEX fmt;   //波形フォーマット
};
//音声データ
struct SoundData
{
    //波形フォーマット
    WAVEFORMATEX wfex;
    //バッファの先頭アドレス
    BYTE* pBuffer;
    //バッファのサイズ
    unsigned int bufferSize;
};

SoundData SoundLoadWave(const char* filename)
{
    //ファイル入力ストリームのインスタンス
    std::ifstream file;
    //.wavファイルをバイナリモードで開く
    file.open(filename, std::ios_base::binary);
    //ファイルオープン失敗を検出する
    assert(file.is_open());

    //RIFFヘッダの読み込み
    RiffHeader riff;
    file.read((char*)&riff, sizeof(riff));
    //ファイルがRIFFかチェック
    if (strncmp(riff.chunk.id, "RIFF", 4) != 0) {
        assert(0);
    }
    //タイプがWAVEかチェック
    if(strncmp(riff.type,"WAVE",4)!= 0){
        assert(0);
    }

    //Formatチャンクの読み込み
    FormatChunk format = {};
    //チャンクヘッダーの確認
    file.read((char*)&format, sizeof(ChunkHeader));
    if (strncmp(format.chunk.id, "fmt ", 4) != 0) {//3だと動く
        assert(0);
    }
    //チャンク本体の読み込み
    assert(format.chunk.size <= sizeof(format.fmt));
    file.read((char*)&format.fmt, format.chunk.size);

    //Dataチャンクの読み込み
    ChunkHeader data;
    file.read((char*)&data, sizeof(data));
    //JUNKチャンクを検出した場合
    if(strncmp(data.id,"JUNK",4)== 0){
        //読み取り位置をJUNKチャンクの終わりまで進める
        file.seekg(data.size, std::ios_base::cur);
        //再読み込み
        file.read((char*)&data, sizeof(data));
    }

    if (strncmp(data.id, "data", 4) != 0) {
        assert(0);
    }

    //Dataチャンクのデータ部（波形データ）の読み込み
    char* pBuffer = new char[data.size];
    file.read(pBuffer, data.size);

    //Waveファイルを閉じる
    file.close();

    //returnする為の音声データ
    SoundData soundData = {};

    soundData.wfex = format.fmt;
    soundData.pBuffer = reinterpret_cast<BYTE*>(pBuffer);
    soundData.bufferSize = data.size;

    return soundData;
}

void SoundUnload(SoundData* soundData)
{
    //バッファのメモリ
    delete[] soundData->pBuffer;

    soundData->pBuffer = 0;
    soundData->bufferSize = 0;
    soundData->wfex = {};
}

//音声再生
void SoundPlayWave(IXAudio2* xAudio2, const SoundData& soundData) {
    HRESULT result;

    //波形フォーマットを元にSourceVoiceの生成
    IXAudio2SourceVoice* pSourceVoice = nullptr;
    result = xAudio2->CreateSourceVoice(&pSourceVoice, &soundData.wfex);
    assert(SUCCEEDED(result));

    //再生する波形データの設定
    XAUDIO2_BUFFER buf{};
    buf.pAudioData = soundData.pBuffer;
    buf.AudioBytes = soundData.bufferSize;
    buf.Flags = XAUDIO2_END_OF_STREAM;

    //波形データの再生
    result = pSourceVoice->SubmitSourceBuffer(&buf);
    result = pSourceVoice->Start();
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システム初期化
    HRESULT result;

    //WindowsAPIの初期化
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();

    MSG msg{};  // メッセージ

    //DirectX初期化
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //inputの初期化
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    //スプライト共通部の初期化
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon;
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    //object3dの初期化
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
    
    //ImGuiManagerの初期化
    ImGuiManager* imGuiManager = nullptr;
    imGuiManager = new ImGuiManager;
    imGuiManager->Initialize(winApp, dxCommon);

    //サウンドの変数宣言
    Microsoft::WRL::ComPtr<IXAudio2> xAudio2;
    IXAudio2MasteringVoice* masterVoice;
    //xAudioエンジンのインスタンスを生成
    result = XAudio2Create(&xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
    //マスターボイスを生成
    result = xAudio2->CreateMasteringVoice(&masterVoice);
    
#pragma endregion 基盤システム初期化
      
#pragma region 最初のシーンの初期化

    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon,0);
  
    //.objからモデルデータを読み込む
    Model* model_ground = Model::LoadFromOBJ("ground");
    Model* model_triangle = Model::LoadFromOBJ("triangle_mat");
    Model* model_cube = Model::LoadFromOBJ("cube");
    //3Dオブジェクト生成
    Object3d* object3d_1 = Object3d::Create();
    Object3d* object3d_2 = Object3d::Create();
    Object3d* object3d_3 = Object3d::Create();
    //3Dオブジェクトと3Dモデルを紐づける
    object3d_1->SetModel(model_ground);
    object3d_2->SetModel(model_triangle);
    object3d_3->SetModel(model_cube);
    //各3Dオブジェクトの位置指定
    object3d_1->SetPosition({ 0,-5, 0 });
    object3d_2->SetPosition({ -5,0,-5 });
    object3d_3->SetPosition({ +5,0,+5 });
    //サウンドの読み込み
    SoundData soundData1 = SoundLoadWave("Resources/Alarm01.wav");
    //サウンド再生
    SoundPlayWave(xAudio2.Get(), soundData1);
#pragma endregion 最初のシーンの初期化
    
#pragma region ゲームループ
    while (true) {

#pragma region 基盤システムの更新
        //Windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            //ゲームループを抜ける
            break;
        }

      
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新
        //ImGuiの受付開始
        imGuiManager->Begin();
        //入力の更新
        input->Update();

        sprite->Update();
        object3d_1->Update();
        object3d_2->Update();
        object3d_3->Update();

        //デモウィンドウの表示オン
        //ImGui::ShowDemoWindow();
        //ImGuiの受付終了
        imGuiManager->End();
#pragma endregion 最初のシーンの更新
        
        //描画前処理
        dxCommon->PreDraw();
#pragma region 最初のシーンの描画

        //スプライト描画
        spriteCommon->PreDraw();
        sprite->Draw();
        spriteCommon->PostDraw();

        //オブジェクト描画
        Object3d::PreDraw(dxCommon->GetCommandList());
        object3d_1->Draw();
        object3d_2->Draw();
        object3d_3->Draw();
        Object3d::PostDraw();
        imGuiManager->Draw();
#pragma endregion 最初のシーンの描画
        //描画後処理
        dxCommon->PostDraw();
        
    }
#pragma endregion ゲームループ

#pragma region 最初のシーンの終了
    delete sprite;
#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    //入力解放
    delete input;
    //DirectX解放
    delete dxCommon;
    //WindowsAPIの終了処理
    winApp->Finalize();
    //WindowsAPI解放
    delete winApp;
    //スプライト共通部解放
    delete spriteCommon;
    //ImGuiの終了処理
    imGuiManager->Finalize();
    //ImGuiManagerの解放
    delete imGuiManager;
    //3Dモデルの解放
    delete model_ground;
    delete model_triangle;
    delete model_cube;
    //3Dオブジェクト解放
    delete object3d_1;
    delete object3d_2;
    delete object3d_3;
    //XAudioの解放
    xAudio2.Reset();
    //音声データの解放
    SoundUnload(&soundData1);
#pragma endregion 基盤システムの終了

    return 0;
}
