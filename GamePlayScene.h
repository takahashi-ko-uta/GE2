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
	Audio* audio = nullptr;

	//model1����
	Model* model_ = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_ = nullptr;
};

