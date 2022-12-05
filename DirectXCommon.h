#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include <vector>

#include "WinApp.h"

// DirectX���
class DirectXCommon
{
public:// �����o�֐�
	//������
	void Initialize(WinApp* winApp);
	

	//�`�揈��
	void PreDraw();
	//�`�揈����
	void PostDraw();

	//�f�o�C�X�擾
	ID3D12Device* GetDevice() const { return device.Get(); }
	//�R�}���h���X�g�擾
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }
private:

	void InitializeDevice();
	void InitializeCommand();
	void InitializeSwapchain();
	void InitializeRenderTargetView();
	void InitializeDepthBuffer();
	void InitializeFence();

private:
	//DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DirectX12�f�o�C�X�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	//�X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//�R�}���h�A���P�[�^
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	//�R�}���h���X�g
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	//�R�}���h�L���[
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	//�q�[�v
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	//Back�o�b�t�@
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//�t�F���X
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	//WindowsAPI
	WinApp* winApp_ = nullptr;

	Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain1;
};

