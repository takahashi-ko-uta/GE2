#include "GamePlayScene.h"
#include "DirectXCommon.h"

void GamePlayScene::Initialize(DirectXCommon* dxCommon)
{
    this->dxCommon_ = dxCommon;

    //���f���ǂݍ���
    model_ = Model::LoadFromOBJ("triangle_mat");

    //�I�u�W�F�N�g����
    object3d_ = Object3d::Create();
    //3D�I�u�W�F�N�g��3D���f�����Ђ��t��
    object3d_->SetModel(model_);
    //3D�I�u�W�F�N�g�̈ʒu���w��
    object3d_->SetPosition({ -5,0,-5 });
    //3D�I�u�W�F�N�g�̃X�P�[�����w��
    object3d_->SetScale({ 10.0f,10.0f,10.0f });

    //�T�E���h������
    Audio* audio = new Audio();
    audio->Initialize();
    //�T�E���h�ǂݍ���
    audio->LoadWave("Alarm01.wav");
    //�T�E���h�Đ�
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
