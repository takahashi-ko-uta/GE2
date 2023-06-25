#include "GamePlayScene.h"

void GamePlayScene::Initialize()
{
    //モデル読み込み
    model_ = Model::LoadFromOBJ("triangle_mat");

    //オブジェクト生成
    object3d_ = Object3d::Create();
    //3Dオブジェクトと3Dモデルをひも付け
    object3d_->SetModel(model_);
    //3Dオブジェクトのスケールを指定
    object3d_->SetScale({ 10.0f,10.0f,10.0f });

    //サウンド初期化
    audio = Audio::GetInstance();
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
    
    //オーディオ終了処理
    delete audio;
    audio->Finalize();
}

void GamePlayScene::Update()
{
    object3d_->Update();
}

void GamePlayScene::Draw()
{
    object3d_->Draw();
}





