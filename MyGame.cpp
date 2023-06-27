#include "MyGame.h"

void MyGame::Initialize()
{
#pragma region ��ՃV�X�e���̏�����
    Framework::Initialize();


    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[����������
    //�X�v���C�g���ʕ��̏�����
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon);

    //�e�N�X�`���̃Z�b�g
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);

    //�����ǂݍ���
    //audio->SoundLoadWave("Resources/fanfare.wav");
    //�����Đ�
    //audio->SoundPlayWave("Resources/fanfare.wav");

#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[����������

    //camera_ = new Camera();

    imGui = new ImGuiManager();
    imGui->Initialize(winApp, dxCommon);


    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

    model_ = Model::LoadFromOBJ("triangle_mat");

    object3d_ = Object3d::Create();
  
    //3D�I�u�W�F�N�g��3D���f�����Ђ��t��
    object3d_->SetModel(model_);
  
    //3D�I�u�W�F�N�g�̃X�P�[�����w��
    object3d_->SetPosition({ 0,-50,0 });
    object3d_->SetScale({ 10.0f,10.0f,10.0f });

    //object3d_->SetCamera(camera_);

#pragma endregion �ŏ��̃V�[����������
}

void MyGame::Finalize()
{
#pragma region �ŏ��̃V�[���̏I��
    delete sprite;
    imGui->Finalize();
    delete imGui;

#pragma endregion �ŏ��̃V�[���̏I��

#pragma region ��ՃV�X�e���̏I��
    //�X�v���C�g���ʕ����
    delete spriteCommon;
    //���͉��
    delete input;
    //DirectX���
    delete dxCommon;

    delete object3d_;

    delete model_;

    Framework::Finalize();
    //delete audio;
    //WindowsAPI���
    delete winApp;
#pragma endregion ��ՃV�X�e���̏I��
}

void MyGame::Update()
{
#pragma region ��ՃV�X�e���̍X�V
    Framework::Update();
#pragma endregion ��ՃV�X�e���̍X�V

#pragma region �ŏ��̃V�[���̍X�V
    sprite->Update();
    //camera_->Update();
    object3d_->Update();

    imGui->Begin();

    //ImGui::ShowDemoWindow();
    ImGui::Text("%f,%f,%f", object3d_->GetPosition().x, object3d_->GetPosition().y, object3d_->GetPosition().z);
    //ImGui::Text("%f,%f,%f", camera_->GetEye().x, camera_->GetEye().y, camera_->GetEye().z);
    imGui->End();


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

    imGui->Draw();
#pragma endregion �ŏ��̃V�[���̕`��

    //�`��㏈��
    dxCommon->PostDraw();
}
