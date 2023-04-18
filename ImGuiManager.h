#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"

//ImGuiの管理
class ImGuiManager
{
private:
	//SRV用デスクリプタヒープ
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap_;
public://メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(WinApp* winApp,DirectXCommon* dxCommon);
};

