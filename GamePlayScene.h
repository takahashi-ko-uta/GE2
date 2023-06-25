#pragma once
#include "Audio.h"
#include "SpriteCommon.h"
#include "Model.h"
#include "Object3d.h"
#include "Sprite.h"

class GamePlayScene
{
public://メンバ関数
	//初期化
	void Initialize();
	//終了
	void Finalize();
	//毎フレーム処理
	void Update();
	//描画
	void Draw();

private://メンバ変数
	Audio* audio = nullptr;

	//model1生成
	Model* model_ = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_ = nullptr;
};

