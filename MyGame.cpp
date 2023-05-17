#include "MyGame.h"



void MyGame::Initialize()
{
#pragma region ��ՃV�X�e��������

    //WindowsAPI�̏�����
    winApp = new WinApp();
    winApp->Initialize();
    
    MSG msg{};  // ���b�Z�[�W

    //DirectX������
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //input�̏�����
    input = new Input();
    input->Initialize(winApp);

    //�X�v���C�g���ʕ��̏�����
    spriteCommon = new SpriteCommon;
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    //object3d�̏�����
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);

    //�T�E���h�̏�����
    audio = new Audio();
    audio->Initialize();

    //ImGuiManager�̏�����
    imGuiManager = new ImGuiManager;
    imGuiManager->Initialize(winApp, dxCommon);

    //�X�v���C�g�̏�����
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

#pragma endregion ��ՃV�X�e��������

#pragma region �ŏ��̃V�[���̏�����

    model_ground = Model::LoadFromOBJ("ground");
    model_triangle = Model::LoadFromOBJ("triangle_mat");
    model_cube = Model::LoadFromOBJ("cube");

    object3d_1 = Object3d::Create();
    object3d_2 = Object3d::Create();
    object3d_3 = Object3d::Create();

    //3D�I�u�W�F�N�g��3D���f����R�Â���
    object3d_1->SetModel(model_ground);
    object3d_2->SetModel(model_triangle);
    object3d_3->SetModel(model_cube);
    //�e3D�I�u�W�F�N�g�̈ʒu�w��
    object3d_1->SetPosition({ 0,-5, 0 });
    object3d_2->SetPosition({ -5,0,-5 });
    object3d_3->SetPosition({ +5,0,+5 });

    //�T�E���h�̓ǂݍ���
    audio->LoadWave("Alarm01.wav");
    //�T�E���h�Đ�
    audio->PlayWave("Alarm01.wav");

#pragma endregion �ŏ��̃V�[���̏�����
}

void MyGame::Finalize()
{
    //�X�v���C�g���
    delete sprite;
    //���͉��
    delete input;
    //DirectX���
    delete dxCommon;
    //WindowsAPI�̏I������
    winApp->Finalize();
    //WindowsAPI���
    delete winApp;
    //�X�v���C�g���ʕ����
    delete spriteCommon;
    //ImGui�̏I������
    imGuiManager->Finalize();
    //ImGuiManager�̉��
    delete imGuiManager;
    //3D���f���̉��
    delete model_ground;
    delete model_triangle;
    delete model_cube;
    //3D�I�u�W�F�N�g���
    delete object3d_1;
    delete object3d_2;
    delete object3d_3;
    //Audio���
    audio->Finalize();
    delete audio;
}

void MyGame::Update()
{
#pragma region �ŏ��̃V�[���̍X�V
    //ImGui�̎�t�J�n
    imGuiManager->Begin();
    //���͂̍X�V
    input->Update();

    sprite->Update();
    object3d_1->Update();
    object3d_2->Update();
    object3d_3->Update();

    //�f���E�B���h�E�̕\���I��
    //ImGui::ShowDemoWindow();
    //ImGui�̎�t�I��
    imGuiManager->End();
#pragma endregion �ŏ��̃V�[���̍X�V
}

void MyGame::Draw()
{
    //�`��O����
    dxCommon->PreDraw();
#pragma region �ŏ��̃V�[���̕`��

    //�X�v���C�g�`��
    spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();

    //�I�u�W�F�N�g�`��
    Object3d::PreDraw(dxCommon->GetCommandList());
    object3d_1->Draw();
    object3d_2->Draw();
    object3d_3->Draw();
    Object3d::PostDraw();
    imGuiManager->Draw();
#pragma endregion �ŏ��̃V�[���̕`��
    //�`��㏈��
    dxCommon->PostDraw();
}