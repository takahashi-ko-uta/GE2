#pragma once
#include "Model.h"
#include "Object3d.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"
#include "Input.h"

class GamePlayScene
{
public://メンバ関数
	//初期化
	void Initialize(DirectXCommon* dxCommon, Input* input);
	//終了
	void Finalize();
	//毎フレーム処理
	void Update();
	//描画
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	//スプライト共通部の生成
	SpriteCommon* spriteCommon_ = nullptr;
	//スプライト生成
	Sprite* sprite_ = nullptr;
	//モデル生成
	Model* model_ = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_ = nullptr;
	//audio生成
	Audio* audio_ = nullptr;
};

