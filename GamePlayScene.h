#pragma once
#include "Model.h"
#include "Object3d.h"
#include "Audio.h"
#include "DirectXCommon.h"

class GamePlayScene
{
public://�����o�֐�
	//������
	void Initialize(DirectXCommon* dxCommon);
	//�I��
	void Finalize();
	//���t���[������
	void Update();
	//�`��
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;

	//���f������
	Model* model_ = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_ = nullptr;
	//audio����
	Audio* audio = nullptr;
};

