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
	GamePlayScene* gamePlayScene = nullptr;
	ImGuiManager* imGuiManager = nullptr;

	//Audio* audio = nullptr;
	Sprite* sprite = nullptr;
};