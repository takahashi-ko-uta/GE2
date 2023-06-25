#include "GamePlayScene.h"

void GamePlayScene::Initialize()
{
    //���f���ǂݍ���
    model_ = Model::LoadFromOBJ("triangle_mat");

    //�I�u�W�F�N�g����
    object3d_ = Object3d::Create();
    //3D�I�u�W�F�N�g��3D���f�����Ђ��t��
    object3d_->SetModel(model_);
    //3D�I�u�W�F�N�g�̃X�P�[�����w��
    object3d_->SetScale({ 10.0f,10.0f,10.0f });
}

void GamePlayScene::Finalize()
{
    delete object3d_;
    delete model_;
}

void GamePlayScene::Update()
{
    object3d_->Update();
}

void GamePlayScene::Draw()
{
    object3d_->Draw();
}





