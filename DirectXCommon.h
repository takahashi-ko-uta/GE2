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
	

	//描画処理
	void PreDraw();
	//描画処理後
	void PostDraw();

	//デバイス取得
	ID3D12Device* GetDevice() const { return device.Get(); }
	//コマンドリスト取得
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }
private:

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
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	//Backバッファ
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//フェンス
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	//WindowsAPI
	WinApp* winApp_ = nullptr;

	Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain1;
};

