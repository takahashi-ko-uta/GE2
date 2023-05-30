#include "MyGame.h"
#include "Framework.h"


void MyGame::Initialize()
{
#pragma region ��ՃV�X�e��������

    //���N���X�̏���������
    Framework::Initialize();
    
    MSG msg{};  // ���b�Z�[�W
 
#pragma endregion ��ՃV�X�e��������

#pragma region �ŏ��̃V�[���̏�����
    //�T�E���h�̏�����
    audio = new Audio();
    audio->Initialize();

    //�T�E���h�̓ǂݍ���
    audio->LoadWave("Alarm01.wav");
    //�T�E���h�Đ�
    audio->PlayWave("Alarm01.wav");

    //�X�v���C�g�ǂݍ���
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");
    //�X�v���C�g�̏�����
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

    //���f���ǂݍ���
    model_ground = Model::LoadFromOBJ("ground");
    model_triangle = Model::LoadFromOBJ("triangle_mat");
    model_cube = Model::LoadFromOBJ("cube");

    //�I�u�W�F�N�g����
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
#pragma endregion �ŏ��̃V�[���̏�����
}

void MyGame::Finalize()
{
    //�X�v���C�g���
    delete sprite;
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

    //���N���X�̏I������
    Framework::Finalize();
}

void MyGame::Update()
{
#pragma region �ŏ��̃V�[���̍X�V
    //ImGui�̎�t�J�n
    imGuiManager->Begin();
  
    //���N���X�̍X�V����
    Framework::Update();

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