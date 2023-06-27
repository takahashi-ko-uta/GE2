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
    model_ = Model::LoadFromOBJ("triangle_mat");

    //オブジェクト生成
    object3d_ = Object3d::Create();

    //3Dオブジェクトと3Dモデルをひも付け
    object3d_->SetModel(model_);
    //3Dオブジェクトの位置を指定
    object3d_->SetPosition({ -5,0,-5 });
    //3Dオブジェクトのスケールを指定
    object3d_->SetScale({ 10.0f,10.0f,10.0f });
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
    delete object3d_;

    delete model_;

    delete audio;
    audio->Finalize();
    Framework::Finalize();
#pragma endregion 基盤システムの終了
}

void MyGame::Update()
{
#pragma region 基盤システムの更新
    Framework::Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新
    sprite->Update();
    object3d_->Update();


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
    object3d_->Draw();
    Object3d::PostDraw();

    imGuiManager->Draw();
#pragma endregion 最初のシーンの描画

    //描画後処理
    dxCommon->PostDraw();
}