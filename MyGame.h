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

// �Q�[���S��
class MyGame
{

public:// �����o�֐�
	// ������
	void Initialize();

	// �I��
	void Finalize();

	// ���t���[���X�V
	void Update();

	// �`��
	void Draw();

	// �I���t���O���`�F�b�N
	bool IsEndRequst() { return endRequst_; }

private:// �����o�ϐ�
	//�|�C���^�u����
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Audio* audio = nullptr;
	ImGuiManager* imGuiManager = nullptr;
	Sprite* sprite = nullptr;

	// �Q�[���I���t���O
	bool endRequst_ = false;

	//.obj���烂�f���f�[�^��ǂݍ���
	Model* model_ground = nullptr;
	Model* model_triangle = nullptr;
	Model* model_cube = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_1 = nullptr;
	Object3d* object3d_2 = nullptr;
	Object3d* object3d_3 = nullptr;

};

