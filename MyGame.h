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

// ゲーム全体
class MyGame
{

public:// メンバ関数
	// 初期化
	void Initialize();

	// 終了
	void Finalize();

	// 毎フレーム更新
	void Update();

	// 描画
	void Draw();

	// 終了フラグをチェック
	bool IsEndRequst() { return endRequst_; }

private:// メンバ変数
	//ポインタ置き場
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Audio* audio = nullptr;
	ImGuiManager* imGuiManager = nullptr;
	Sprite* sprite = nullptr;

	// ゲーム終了フラグ
	bool endRequst_ = false;

	//.objからモデルデータを読み込む
	Model* model_ground = nullptr;
	Model* model_triangle = nullptr;
	Model* model_cube = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_1 = nullptr;
	Object3d* object3d_2 = nullptr;
	Object3d* object3d_3 = nullptr;

};

