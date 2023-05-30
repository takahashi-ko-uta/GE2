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
#include "Framework.h"

class Framework
{
public:// メンバ関数
	//実行
	void Run();

	virtual ~Framework() = default;

	//初期化
	virtual void Initialize();

	//終了
	virtual void Finalize();

	//毎フレーム処理
	virtual void Update();

	//描画
	virtual void Draw() = 0;

	//終了チェック
	virtual bool IsEndRequst() { return endRequst_; }

protected:// メンバ変数
	//ポインタ置き場
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	ImGuiManager* imGuiManager = nullptr;
	
	// ゲーム終了フラグ
	bool endRequst_ = false;
};

