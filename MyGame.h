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
	//初期化
	void Initialize() override;
	//終了
	void Finalize() override;
	//毎フレーム処理
	void Update() override;
	//描画
	void Draw() override;

private:
	GamePlayScene* gamePlayScene = nullptr;
	ImGuiManager* imGuiManager = nullptr;
	Audio* audio = nullptr;
	Sprite* sprite = nullptr;

	Model* model_ = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_ = nullptr;
};