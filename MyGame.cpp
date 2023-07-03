#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region ��ՃV�X�e���̏�����
    Framework::Initialize();

#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[����������

    //imGuiManager������
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    //�J����������
    camera = new Camera();
    camera->Initialize();

    //�I�u�W�F�N�g�S�̂̏�����
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height, camera);

    ////�X�v���C�g���ʕ��̏�����
    //spriteCommon = new SpriteCommon();
    //spriteCommon->Initialize(dxCommon);
    ////�e�N�X�`���̃Z�b�g
    //spriteCommon->LoadTexture(0, "texture.png");
    //spriteCommon->LoadTexture(1, "reimu.png");
    ////�X�v���C�g������
    //sprite = new Sprite();
    //sprite->SetTextureIndex(0);
    //sprite->Initialize(spriteCommon, 0);

    //�V�[���̏�������
    scene = new GamePlayScene();
    scene->Initialize(dxCommon,input);

    ////���f���ǂݍ���
    //model_ = Model::LoadFromOBJ("triangle_mat");

    ////�I�u�W�F�N�g����
    //object3d_ = Object3d::Create();
    ////3D�I�u�W�F�N�g��3D���f�����Ђ��t��
    //object3d_->SetModel(model_);
    ////3D�I�u�W�F�N�g�̈ʒu���w��
    //object3d_->SetPosition({ -5,0,-5 });
    ////3D�I�u�W�F�N�g�̃X�P�[�����w��
    //object3d_->SetScale({ 10.0f,10.0f,10.0f });

    ////�T�E���h������
    //Audio* audio = new Audio();
    //audio->Initialize();
    ////�T�E���h�ǂݍ���
    //audio->LoadWave("Alarm01.wav");
    ////�T�E���h�Đ�
    //audio->PlayWave("Alarm01.wav");

#pragma endregion �ŏ��̃V�[����������
}

void MyGame::Finalize()
{
#pragma region �ŏ��̃V�[���̏I��
    imGuiManager->Finalize();
    delete imGuiManager;

    ////�X�v���C�g���ʕ����
    //delete spriteCommon;
    ////�X�v���C�g���
    //delete sprite;

    //�V�[���̏I������
    scene->Finalize();

    /*delete object3d_;
    delete model_;
    delete audio;
    audio->Finalize();*/

#pragma endregion �ŏ��̃V�[���̏I��

#pragma region ��ՃV�X�e���̏I��
    Framework::Finalize();
#pragma endregion ��ՃV�X�e���̏I��
}

void MyGame::Update()
{
#pragma region ��ՃV�X�e���̍X�V
    Framework::Update();
#pragma endregion ��ՃV�X�e���̍X�V

#pragma region �ŏ��̃V�[���̍X�V
    camera->SetEye({ 0,0,-100 });
    camera->Update();

    /*sprite->Update();*/

    //�V�[���̖��t���[������
    scene->Update();

    //object3d_->Update();


    imGuiManager->Begin();
    ////ImGui�̃f���E�B���h�E�\��
    //ImGui::ShowDemoWindow();
#pragma region ImGui::Text

    ImGui::Text("cameraEye:%f,%f,%f", camera->GetEye().x, camera->GetEye().y, camera->GetEye().z);
    ImGui::Text("cameraTarget:%f,%f,%f", camera->GetTarget().x, camera->GetTarget().y, camera->GetTarget().z);
    ImGui::Text("cameraUp:%f,%f,%f", camera->GetUp().x, camera->GetUp().y, camera->GetUp().z);
#pragma endregion ImGui::Text

    imGuiManager->End();



#pragma endregion �ŏ��̃V�[���̍X�V
}

void MyGame::Draw()
{
    //�`��O����
    dxCommon->PreDraw();

#pragma region �ŏ��̃V�[���̕`��
    /*spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();*/

    //�V�[���̕`��
    scene->Draw();

    /*Object3d::PreDraw(dxCommon->GetCommandList());  
    object3d_->Draw();
    Object3d::PostDraw();*/

    imGuiManager->Draw();
#pragma endregion �ŏ��̃V�[���̕`��

    //�`��㏈��
    dxCommon->PostDraw();
}