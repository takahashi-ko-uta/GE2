#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include <vector>

#include "WinApp.h"

// DirectX基盤
class DirectXCommon
{
public:// メンバ関数
	//初期化
	void Initialize(WinApp* winApp);
	void InitializeDevice();
	void InitializeCommand();
	void InitializeSwapchain();
	void InitializeRenderTargetView();
	void InitializeDepthBuffer();
	void InitializeFence();

private:
	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DirectX12デバイスファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	//スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//コマンドアロケータ
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	//コマンドリスト
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	//コマンドキュー
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	//ヒープ
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	//Backバッファ
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//WindowsAPI
	WinApp* winApp_ = nullptr;

	Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain1;
};

