#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region ��ՃV�X�e���̏�����
    Framework::Initialize();

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[����������
    //imGuiManager������
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    //�V�[���̏�����
    gamePlayScene = new GamePlayScene();
    gamePlayScene->Initialize();
#pragma endregion �ŏ��̃V�[����������
}

void MyGame::Finalize()
{
#pragma region �ŏ��̃V�[���̏I��
    /*delete sprite;*/
    imGuiManager->Finalize();
    delete imGuiManager;

#pragma endregion �ŏ��̃V�[���̏I��

#pragma region ��ՃV�X�e���̏I��
    //�V�[���I������
    gamePlayScene->Finalize();
    //�V�[���̉��
    delete gamePlayScene;
    //���N���X�̏I������
    Framework::Finalize();
#pragma endregion ��ՃV�X�e���̏I��
}

void MyGame::Update()
{
#pragma region ��ՃV�X�e���̍X�V
    Framework::Update();
#pragma endregion ��ՃV�X�e���̍X�V

#pragma region �ŏ��̃V�[���̍X�V

    
    //�V�[���̍X�V
    gamePlayScene->Update();

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
    gamePlayScene->Draw();
    Object3d::PostDraw();

    imGuiManager->Draw();
#pragma endregion �ŏ��̃V�[���̕`��

    //�`��㏈��
    dxCommon->PostDraw();
}