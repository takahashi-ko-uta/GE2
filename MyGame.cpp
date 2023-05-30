#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region 基盤システムの初期化
    Framework::Initialize();

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンを初期化

    //サウンド初期化
    Audio* audio = new Audio();
    audio->Initialize();
    //サウンド読み込み
    audio->LoadWave("Alarm01.wav");
    //サウンド再生
    audio->PlayWave("Alarm01.wav");

    //imGuiManager初期化
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");
    //スプライト初期化
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

    //モデル読み込み
    model_1 = Model::LoadFromOBJ("ground");
    model_2 = Model::LoadFromOBJ("triangle_mat");

    //オブジェクト生成
    object3d_1 = Object3d::Create();
    object3d_2 = Object3d::Create();
    object3d_3 = Object3d::Create();

    //3Dオブジェクトと3Dモデルをひも付け
    object3d_1->SetModel(model_1);
    object3d_2->SetModel(model_2);
    object3d_3->SetModel(model_2);
    //3Dオブジェクトの位置を指定
    object3d_2->SetPosition({ -5,0,-5 });
    object3d_3->SetPosition({ +5,0,+5 });
    //3Dオブジェクトのスケールを指定
    object3d_1->SetPosition({ 0,-50,0 });
    object3d_1->SetScale({ 10.0f,10.0f,10.0f });
    object3d_2->SetScale({ 10.0f,10.0f,10.0f });
    object3d_3->SetScale({ 10.0f,10.0f,10.0f });
#pragma endregion 最初のシーンを初期化
}

void MyGame::Finalize()
{
#pragma region 最初のシーンの終了
    delete sprite;
    imGuiManager->Finalize();
    delete imGuiManager;

#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    ////スプライト共通部解放
    //delete spriteCommon;
    ////入力解放
    //delete input;
    ////DirectX解放
    //delete dxCommon;

    delete object3d_1;
    delete object3d_2;
    delete object3d_3;

    delete model_1;
    delete model_2;


    Framework::Finalize();
    delete audio;
    audio->Finalize();
    ////WindowsAPI解放
    //delete winApp;
#pragma endregion 基盤システムの終了
}

void MyGame::Update()
{
#pragma region 基盤システムの更新
    Framework::Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新


    sprite->Update();

    object3d_1->Update();
    object3d_2->Update();
    object3d_3->Update();

    imGuiManager->Begin();

    ImGui::ShowDemoWindow();

    imGuiManager->End();


#pragma endregion 最初のシーンの更新
}

void MyGame::Draw()
{
    //描画前処理
    dxCommon->PreDraw();

#pragma region 最初のシーンの描画
    spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();
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