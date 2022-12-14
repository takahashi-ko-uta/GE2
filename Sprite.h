#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"

//スプライト
class Sprite
{
public:
	//定数バッファデータ構造体(マテリアル)
	struct ConstBufferDataMaterial {
		DirectX::XMFLOAT4 color;
	};

	//定数バッファデータ構造体(3D変換行列)
	struct ConstBufferDataTransform {
		DirectX::XMMATRIX mat;//3D変換行列
	};

	//頂点データ
	struct Vertex {
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT2 uv;
	};

	//頂点番号
	enum VertexNumber {
		LB,//左下
		LT,//左上
		RB,//右下
		RT,//右上
	};

public: //メンバ関数
	//初期化
	void Initialize(SpriteCommon* _spriteCommon);

	//描画
	void Draw();

	//更新
	void Update();

	void SetPosition(const DirectX::XMFLOAT2& position) { position_ = position; }
	const DirectX::XMFLOAT2& GetPosition() const { return position_; }
	void SetRotation(float rotation) { rotationZ = rotation; }
	float GetRotation() const { return rotationZ; }
	void SetColor(DirectX::XMFLOAT4 color) { color_ = color; }
	const DirectX::XMFLOAT4 GetColor()const { return color_; }
	void SetSize(const DirectX::XMFLOAT2& size) { size_ = size; }
	const DirectX::XMFLOAT2& GetSize() const { return size_; }
	void SetAnchorPoint(const DirectX::XMFLOAT2& anchorPoint) { anchorPoint_ = anchorPoint; }
	const DirectX::XMFLOAT2& GetAnchorPoint()const { return anchorPoint_; }
	void SetIsFlipX(const bool& isFlipX) { isFlipX_ = isFlipX; }
	const bool GetIsFlipX()const { return isFlipX_; }
	void SetIsFlipY(const bool& isFlipY) { isFlipY_ = isFlipY; }
	const bool GetIsFlipY()const { return isFlipY_; }
	void SetIsInvisible(const bool& isInvisible) { isInvisible_ = isInvisible; }
	const bool GetIsInvisible()const { return isInvisible_; }

private:
	//スプライト情報
	DirectX::XMFLOAT4 color_ = { 1.0f,1.0f,1.0f,1.0f };

	float rotationZ = 0.0f;
	DirectX::XMFLOAT2 position_ = { 0.0f,0.0f };

	DirectX::XMFLOAT2 size_ = { 100.0f,100.0f };

	//アンカーポイント
	DirectX::XMFLOAT2 anchorPoint_ = { 0.0f,0.0f };

	//左右フリップ
	bool isFlipX_ = false;
	//上下フリップ
	bool isFlipY_ = false;
	//非表示フラグ
	bool isInvisible_ = false;

	SpriteCommon* spriteCommon_;

	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;

	D3D12_VERTEX_BUFFER_VIEW vbView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffMaterial;
	ConstBufferDataMaterial* constMapMaterial = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffTransform;
	ConstBufferDataTransform* constMapTransform = nullptr;

	Vertex vertices[4];
};

