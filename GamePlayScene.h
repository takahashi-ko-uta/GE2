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
	Audio* audio = Audio::GetInstance();
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();
	Sprite* sprite = nullptr;
	//model生成
	Model* model_1 = nullptr;
	Model* model_2 = nullptr;
	//3Dオブジェクト生成
	Object3d* object3d_1 = nullptr;
	Object3d* object3d_2 = nullptr;
	Object3d* object3d_3 = nullptr;
};

