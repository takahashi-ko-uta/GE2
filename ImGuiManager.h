#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"

//ImGui�̊Ǘ�
class ImGuiManager
{
private:
	//SRV�p�f�X�N���v�^�q�[�v
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap_;
public://�����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(WinApp* winApp,DirectXCommon* dxCommon);
};

