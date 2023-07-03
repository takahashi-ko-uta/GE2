#include "GamePlayScene.h"
#include "DirectXCommon.h"

void GamePlayScene::Initialize(DirectXCommon* dxCommon)
{
    this->dxCommon_ = dxCommon;

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
    delete object3d_;

    delete model_;

    delete audio;
    audio->Finalize();
}

void GamePlayScene::Update()
{
    object3d_->Update();
}

void GamePlayScene::Draw()
{
    Object3d::PreDraw(dxCommon_->GetCommandList());
    object3d_->Draw();
    Object3d::PostDraw();
}
