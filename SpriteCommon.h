#pragma once
#include <DirectXMath.h>
#include <d3d12.h>
#include <wrl.h>
#include <array>

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

	/// <summary>
	///�e�N�X�`���̓ǂݍ���
	/// </summary>
	/// <param name = "index">�e�N�X�`���ԍ�</param>
	void LoadTexture(uint32_t index);

	/// <summary>
	///�`��p�e�N�X�`���R�}���h���s
	/// </summary>
	/// <param name = "index">�e�N�X�`���ԍ�</param>
	void SetTextureCommands(uint32_t index);

	//Getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }
private://�����o�ϐ�
	DirectXCommon* dxCommon;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;

	//Microsoft::WRL::ComPtr<ID3D12Resource> texBuff;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap;
	//SRV�̍ő��
	static const size_t kMaxSRVCount = 2056;
	//�e�N�X�`���o�b�t�@
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, kMaxSRVCount> texBuffs_;
};

