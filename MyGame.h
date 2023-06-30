#pragma once

#include "Sprite.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"
#include "imgui/imgui.h"
#include <fstream>
#include <wrl.h>
#include "Framework.h"
//#include "Camera.h"

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
	Audio* audio = nullptr;
	Sprite* sprite = nullptr;

	Model* model_ = nullptr;
	//3D�I�u�W�F�N�g����
	Object3d* object3d_ = nullptr;
	Camera* camera = nullptr;
};