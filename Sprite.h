#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"

//�X�v���C�g
class Sprite
{
public:
	//�萔�o�b�t�@�f�[�^�\����(�}�e���A��)
	struct ConstBufferDataMaterial {
		DirectX::XMFLOAT4 color;
	};

	//�萔�o�b�t�@�f�[�^�\����(3D�ϊ��s��)
	struct ConstBufferDataTransform {
		DirectX::XMMATRIX mat;//3D�ϊ��s��
	};

	//���_�f�[�^
	struct Vertex {
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT2 uv;
	};


public: //�����o�֐�
	//������
	void Initialize(SpriteCommon* _spriteCommon);

	//�`��
	void Draw();

	//�X�V
	void Update();
private:
	//�X�v���C�g���
	DirectX::XMFLOAT4 color = { 1,0,0,0.5f };

	float rotationZ;
	DirectX::XMFLOAT3 position;
	//DirectX::XMFLOAT position;

	SpriteCommon* spriteCommon;

	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;

	D3D12_VERTEX_BUFFER_VIEW vbView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffMaterial;
	ConstBufferDataMaterial* constMapMaterial = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffTransform;
	ConstBufferDataTransform* constMapTransform = nullptr;
};

