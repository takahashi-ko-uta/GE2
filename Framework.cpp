#include "Framework.h"

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

void Framework::Initialize()
{
	//WindowsAPI�̏�����
	winApp = new WinApp();
	winApp->Initialize();

	//DirectX�̏�����
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);

	//�X�v���C�g���ʕ��̏�����
	spriteCommon = SpriteCommon::GetInstance();
	spriteCommon = new SpriteCommon();
	spriteCommon->Initialize(dxCommon);

	//�e�N�X�`���̃Z�b�g
	spriteCommon->LoadTexture(0, "texture.png");
	spriteCommon->LoadTexture(1, "reimu.png");

	//�X�v���C�g������
	sprite = new Sprite();
	sprite->SetTextureIndex(0);
	sprite->Initialize(spriteCommon, 0);

	//���͂̏�����
	input = new Input();
	input->Initialize(winApp);
}

void Framework::Update()
{
	sprite->Update();
	//input�̍X�V����
	input->Update();
}

void Framework::Finalize()
{
	//�X�v���C�g���ʕ����
	delete spriteCommon;
	//���͉��
	delete input;
	//DirectX���
	delete dxCommon;
	//WindowsAPI���
	delete winApp;
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

