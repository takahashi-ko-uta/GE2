#include "Framework.h"
void Framework::Run()
{
	//�Q�[���̏�����
	Initialize();

	while (true)//�Q�[�����[�v
	{
		//���t���[������
		Update();
		//�I�����N�G�X�g�������甲����
		if (IsEndRequst()) {
			break;
		}
		//�`��
		Draw();
	}

	//�Q�[���̏I��
	Finalize();
}

void Framework::Initialize()
{
	//WindowsAPI�̏�����
	winApp = new WinApp();
	winApp->Initialize();
	
	//DirectX������
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);

	//input�̏�����
	input = new Input();
	input->Initialize(winApp);

	//�X�v���C�g���ʕ��̏�����
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);

	//object3d�̏�����
	Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);

	//ImGuiManager�̏�����
	imGuiManager = new ImGuiManager;
	imGuiManager->Initialize(winApp, dxCommon);
}

void Framework::Finalize()
{
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
}

void Framework::Update()
{
	//���͂̍X�V
	input->Update();
}
