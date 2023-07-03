#include "GamePlayScene.h"
#include "DirectXCommon.h"
#include "WinApp.h"
#include "ImGuiManager.h"
#include "imgui/imgui.h"

void GamePlayScene::Initialize(DirectXCommon* dxCommon, Input* input)
{
    this->dxCommon_ = dxCommon;
    this->input_ = input;
    
    //�J����������
    camera_ = new Camera();
    camera_->Initialize();

    //�I�u�W�F�N�g�S�̂̏�����
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height, camera_);

    //�X�v���C�g���ʕ��̏�����
    spriteCommon_ = new SpriteCommon();
    spriteCommon_->Initialize(dxCommon);
    //�e�N�X�`���̃Z�b�g
    spriteCommon_->LoadTexture(0, "texture.png");
    spriteCommon_->LoadTexture(1, "reimu.png");
    //�X�v���C�g������
    sprite_ = new Sprite();
    sprite_->SetTextureIndex(0);
    sprite_->Initialize(spriteCommon_, 0);

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
    //�J�������
    delete camera_;
    //���͉��
    delete input_;
    //�X�v���C�g���ʕ����
    delete spriteCommon_;

    //�X�v���C�g���
    delete sprite_;
    //�I�u�W�F�N�g���
    delete object3d_;
    //���f�����
    delete model_;
    //�I�[�f�B�I���
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
    //�X�v���C�g�̕`��
    spriteCommon_->PreDraw();
    sprite_->Draw();
    spriteCommon_->PostDraw();

    //�I�u�W�F�N�g�̕`��
    Object3d::PreDraw(dxCommon_->GetCommandList());
    object3d_->Draw();
    Object3d::PostDraw();
}
