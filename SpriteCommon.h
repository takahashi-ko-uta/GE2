#pragma once
#include <DirectXMath.h>
#include <d3d12.h>
#include <wrl.h>

#include "DirectXCommon.h"

//�萔�o�b�t�@�p�f�[�^�\����
struct ConstBufferDataMaterial{
	
};

//�X�v���C�g���ʕ�
class SpriteCommon
{
public: //�����o�֐�
	//������
	void Initialize(DirectXCommon* _dxCommon);

	//�`��
	void PreDraw();

	//Getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }
private://�����o�ϐ�
	DirectXCommon* dxCommon;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;

	Microsoft::WRL::ComPtr<ID3D12Resource> texBuff;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap;
};

