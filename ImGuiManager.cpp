#include "ImGuiManager.h"
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx12.h>

void ImGuiManager::Initialize(WinApp* winApp, DirectXCommon* dxCommon)
{
	HRESULT result;
	//ImGui�̃R���e�L�X�g
	ImGui::CreateContext();
	//ImGui�̃X�^�C����ݒ�
	ImGui::StyleColorsDark();

	//win32�p������
	ImGui_ImplWin32_Init(winApp->GetHwnd());

	//�f�X�N���v�^�q�[�v�ݒ�
	D3D12_DESCRIPTOR_HEAP_DESC desc = {};
	desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	desc.NumDescriptors = 1;
	desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	//�f�X�N���v�^�q�[�v����
	result = dxCommon->GetDevice()->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&srvHeap_));
	ImGui_ImplDX12_Init(
		dxCommon->GetDevice(),
		static_cast<int>(dxCommon->GetBackBufferCount()),
		DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, srvHeap_.Get(),
		srvHeap_->GetCPUDescriptorHandleForHeapStart(),
		srvHeap_->GetGPUDescriptorHandleForHeapStart()
		);

	//�t�H���g�ǉ�
	ImGuiIO& io = ImGui::GetIO();
	//�W���t�H���g��ǉ�����
	io.Fonts->AddFontDefault();
}