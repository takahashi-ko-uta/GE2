#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region ��ՃV�X�e���̏�����
    Framework::Initialize();

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[����������

    //�T�E���h������
    Audio* audio = new Audio();
    audio->Initialize();
    //�T�E���h�ǂݍ���
    audio->LoadWave("Alarm01.wav");
    //�T�E���h�Đ�
    audio->PlayWave("Alarm01.wav");

    //imGuiManager������
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");
    //�X�v���C�g������
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

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
#pragma endregion �ŏ��̃V�[����������
}

void MyGame::Finalize()
{
#pragma region �ŏ��̃V�[���̏I��
    delete sprite;
    imGuiManager->Finalize();
    delete imGuiManager;

#pragma endregion �ŏ��̃V�[���̏I��

#pragma region ��ՃV�X�e���̏I��
    delete object3d_;

    delete model_;

    delete audio;
    audio->Finalize();
    Framework::Finalize();
#pragma endregion ��ՃV�X�e���̏I��
}

void MyGame::Update()
{
#pragma region ��ՃV�X�e���̍X�V
    Framework::Update();
#pragma endregion ��ՃV�X�e���̍X�V

#pragma region �ŏ��̃V�[���̍X�V
    sprite->Update();
    object3d_->Update();


    imGuiManager->Begin();

    ImGui::ShowDemoWindow();

    imGuiManager->End();


#pragma endregion �ŏ��̃V�[���̍X�V
}

void MyGame::Draw()
{
    //�`��O����
    dxCommon->PreDraw();

#pragma region �ŏ��̃V�[���̕`��
    spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();
    Object3d::PreDraw(dxCommon->GetCommandList());  
    object3d_->Draw();
    Object3d::PostDraw();

    imGuiManager->Draw();
#pragma endregion �ŏ��̃V�[���̕`��

    //�`��㏈��
    dxCommon->PostDraw();
}