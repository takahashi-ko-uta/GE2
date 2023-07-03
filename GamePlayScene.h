#pragma once
#include "Model.h"
#include "Object3d.h"
#include "Audio.h"
#include "DirectXCommon.h"

class GamePlayScene
{
public://メンバ関数
	//初期化
	void Initialize(DirectXCommon* dxCommon);
	//終了
	void Finalize();
	//毎フレーム処理
	void Update();
	//描画
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;

	//モデル生成
	Model* model_ = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_ = nullptr;
	//audio生成
	Audio* audio = nullptr;
};

