#include "Framework.h"

void Framework::Initialize()
{
	//WindowsAPI�̏�����
	winApp = new WinApp();
	winApp->Initialize();

	//DirectX�̏�����
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);

	//�X�v���C�g���ʕ��̏�����
	spriteCommon = new SpriteCommon();
	spriteCommon->Initialize(dxCommon);

	//���͂̏�����
	input = new Input();
	input->Initialize(winApp);

	audio = new Audio();
	audio->Initialize();
}

void Framework::Update()
{
	input->Update();
}

void Framework::Finalize()
{
	audio->Finalize();
	winApp->Finalize();

}

bool Framework::IsEndRequest()
{
	//Windows�̃��b�Z�[�W����
	if (winApp->ProcessMessage()) {
		return true;
	}
	if (input->TriggerKey(DIK_ESCAPE)) {
		return true;
	}

	return false;
}

void Framework::Run()
{
	//�Q�[���̏�����
	Initialize();

	while (true)//�Q�[�����[�v
	{
		//���t���[���X�V
		Update();
		//�I�����N�G�X�g�������甲����
		if (IsEndRequest())
		{
			break;
		}
		//�`��
		Draw();
	}
	//�Q�[���̏I��
	Finalize();
}