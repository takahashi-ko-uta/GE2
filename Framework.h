#pragma once
#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"
#include <imgui.h>
#include <fstream>
#include "Audio.h"
#include "Framework.h"

class Framework
{
public:// �����o�֐�
	//���s
	void Run();

	virtual ~Framework() = default;

	//������
	virtual void Initialize();

	//�I��
	virtual void Finalize();

	//���t���[������
	virtual void Update();

	//�`��
	virtual void Draw() = 0;

	//�I���`�F�b�N
	virtual bool IsEndRequst() { return endRequst_; }

protected:// �����o�ϐ�
	//�|�C���^�u����
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	ImGuiManager* imGuiManager = nullptr;
	
	// �Q�[���I���t���O
	bool endRequst_ = false;
};

