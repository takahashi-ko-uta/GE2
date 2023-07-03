#include "GamePlayScene.h"
#include "DirectXCommon.h"
#include "WinApp.h"
#include "ImGuiManager.h"
#include "imgui/imgui.h"

void GamePlayScene::Initialize(DirectXCommon* dxCommon, Input* input)
{
    this->dxCommon_ = dxCommon;
    this->input_ = input;
    
    //カメラ初期化
    camera_ = new Camera();
    camera_->Initialize();

    //オブジェクト全体の初期化
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height, camera_);

    //スプライト共通部の初期化
    spriteCommon_ = new SpriteCommon();
    spriteCommon_->Initialize(dxCommon);
    //テクスチャのセット
    spriteCommon_->LoadTexture(0, "texture.png");
    spriteCommon_->LoadTexture(1, "reimu.png");
    //スプライト初期化
    sprite_ = new Sprite();
    sprite_->SetTextureIndex(0);
    sprite_->Initialize(spriteCommon_, 0);

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

    //サウンド初期化
    Audio* audio = new Audio();
    audio->Initialize();
    //サウンド読み込み
    audio->LoadWave("Alarm01.wav");
    //サウンド再生
    audio->PlayWave("Alarm01.wav");
}

void GamePlayScene::Finalize()
{
    //カメラ解放
    delete camera_;
    //入力解放
    delete input_;
    //スプライト共通部解放
    delete spriteCommon_;

    //スプライト解放
    delete sprite_;
    //オブジェクト解放
    delete object3d_;
    //モデル解放
    delete model_;
    //オーディオ解放
    delete audio_;
    audio_->Finalize();
}

void GamePlayScene::Update()
{
    camera_->SetEye({ 0,0,-100 });
    
    if(input_->PushKey(DIK_P))
    {
        object3d_->SetPosition({ +5,0,-5 });
    }
    else
    {
        object3d_->SetPosition({ -5,0,-5 });
    }

    ImGui::Text("cameraEye:%f,%f,%f", camera_->GetEye().x, camera_->GetEye().y, camera_->GetEye().z);
    ImGui::Text("cameraTarget:%f,%f,%f", camera_->GetTarget().x, camera_->GetTarget().y, camera_->GetTarget().z);
    ImGui::Text("cameraUp:%f,%f,%f", camera_->GetUp().x, camera_->GetUp().y, camera_->GetUp().z);

    camera_->Update();
    input_->Update();
    sprite_->Update();
    object3d_->Update();
}

void GamePlayScene::Draw()
{
    //スプライトの描画
    spriteCommon_->PreDraw();
    sprite_->Draw();
    spriteCommon_->PostDraw();

    //オブジェクトの描画
    Object3d::PreDraw(dxCommon_->GetCommandList());
    object3d_->Draw();
    Object3d::PostDraw();
}
