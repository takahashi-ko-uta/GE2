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
	//初期化
	void Initialize() override;
	//終了
	void Finalize() override;
	//毎フレーム処理
	void Update() override;
	//描画
	void Draw() override;

private:

	ImGuiManager* imGuiManager = nullptr;
	Sprite* sprite = nullptr;

	////モデル生成
	//Model* model_ = nullptr;
	////3Dオブジェクト生成
	//Object3d* object3d_ = nullptr;
	////audio生成
	//Audio* audio = nullptr;

	Camera* camera = nullptr;

	GamePlayScene* scene = nullptr;
};