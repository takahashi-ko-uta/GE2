#pragma once
#include "Model.h"
#include "Object3d.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"
#include "Input.h"

class GamePlayScene
{
public://�����o�֐�
	//������
	void Initialize(DirectXCommon* dxCommon, Input* input);
	//�I��
	void Finalize();
	//���t���[������
	void Update();
	//�`��
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	//�X�v���C�g���ʕ��̐���
	SpriteCommon* spriteCommon_ = nullptr;
	//�X�v���C�g����
	Sprite* sprite_ = nullptr;
	//���f������
	Model* model_ = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_ = nullptr;
	//audio����
	Audio* audio_ = nullptr;
};

