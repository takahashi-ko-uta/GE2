#pragma once
#include "Audio.h"
#include "SpriteCommon.h"
#include "Model.h"
#include "Object3d.h"
#include "Sprite.h"

class GamePlayScene
{
public://�����o�֐�
	//������
	void Initialize();
	//�I��
	void Finalize();
	//���t���[������
	void Update();
	//�`��
	void Draw();

private://�����o�ϐ�
	Audio* audio = Audio::GetInstance();
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();
	Sprite* sprite = nullptr;
	//model����
	Model* model_1 = nullptr;
	Model* model_2 = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_1 = nullptr;
	Object3d* object3d_2 = nullptr;
	Object3d* object3d_3 = nullptr;
};

