#include "MyGame.h"

void MyGame::Initialize()
{
#pragma region 基盤システムの初期化
    Framework::Initialize();


    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンを初期化
    //スプライト共通部の初期化
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon);

    //テクスチャのセット
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);

    //音声読み込み
    //audio->SoundLoadWave("Resources/fanfare.wav");
    //音声再生
    //audio->SoundPlayWave("Resources/fanfare.wav");

#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンを初期化

    //camera_ = new Camera();

    imGui = new ImGuiManager();
    imGui->Initialize(winApp, dxCommon);


    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

    model_ = Model::LoadFromOBJ("triangle_mat");

    object3d_ = Object3d::Create();
  
    //3Dオブジェクトと3Dモデルをひも付け
    object3d_->SetModel(model_);
  
    //3Dオブジェクトのスケールを指定
    object3d_->SetPosition({ 0,-50,0 });
    object3d_->SetScale({ 10.0f,10.0f,10.0f });

    //object3d_->SetCamera(camera_);

#pragma endregion 最初のシーンを初期化
}

void MyGame::Finalize()
{
#pragma region 最初のシーンの終了
    delete sprite;
    imGui->Finalize();
    delete imGui;

#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    //スプライト共通部解放
    delete spriteCommon;
    //入力解放
    delete input;
    //DirectX解放
    delete dxCommon;

    delete object3d_;

    delete model_;

    Framework::Finalize();
    //delete audio;
    //WindowsAPI解放
    delete winApp;
#pragma endregion 基盤システムの終了
}

void MyGame::Update()
{
#pragma region 基盤システムの更新
    Framework::Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新
    sprite->Update();
    //camera_->Update();
    object3d_->Update();

    imGui->Begin();

    //ImGui::ShowDemoWindow();
    ImGui::Text("%f,%f,%f", object3d_->GetPosition().x, object3d_->GetPosition().y, object3d_->GetPosition().z);
    //ImGui::Text("%f,%f,%f", camera_->GetEye().x, camera_->GetEye().y, camera_->GetEye().z);
    imGui->End();


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

    imGui->Draw();
#pragma endregion 最初のシーンの描画

    //描画後処理
    dxCommon->PostDraw();
}
