#pragma once
#include <DirectXMath.h>
#include <d3d12.h>
#include <wrl.h>
#include <array>

#include "DirectXCommon.h"

//定数バッファ用データ構造体
struct ConstBufferDataMaterial{
	
};

//スプライト共通部
class SpriteCommon
{
public: //メンバ関数
	//初期化
	void Initialize(DirectXCommon* _dxCommon);

	//描画
	void PreDraw();

	/// <summary>
	///テクスチャの読み込み
	/// </summary>
	/// <param name = "index">テクスチャ番号</param>
	void LoadTexture(uint32_t index);

	/// <summary>
	///描画用テクスチャコマンド発行
	/// </summary>
	/// <param name = "index">テクスチャ番号</param>
	void SetTextureCommands(uint32_t index);

	//Getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }
private://メンバ変数
	DirectXCommon* dxCommon;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;

	//Microsoft::WRL::ComPtr<ID3D12Resource> texBuff;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap;
	//SRVの最大個数
	static const size_t kMaxSRVCount = 2056;
	//テクスチャバッファ
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, kMaxSRVCount> texBuffs_;
};

