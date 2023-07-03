#pragma once

#include "Sprite.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"
#include "imgui/imgui.h"
#include <fstream>
#include <wrl.h>
#include "Framework.h"
#include "GamePlayScene.h"
#include "Camera.h"

class MyGame : public Framework
{
public:
	//������
	void Initialize() override;
	//�I��
	void Finalize() override;
	//���t���[������
	void Update() override;
	//�`��
	void Draw() override;

private:

	ImGuiManager* imGuiManager = nullptr;
	Sprite* sprite = nullptr;

	////���f������
	//Model* model_ = nullptr;
	////3D�I�u�W�F�N�g����
	//Object3d* object3d_ = nullptr;
	////audio����
	//Audio* audio = nullptr;

	Camera* camera = nullptr;

	GamePlayScene* scene = nullptr;
};