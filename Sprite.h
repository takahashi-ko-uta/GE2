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

	//���_�ԍ�
	enum VertexNumber {
		LB,//����
		LT,//����
		RB,//�E��
		RT,//�E��
	};

public: //�����o�֐�
	//������
	void Initialize(SpriteCommon* _spriteCommon);

	//�`��
	void Draw();

	//�X�V
	void Update();

	void SetPosition(const DirectX::XMFLOAT2& position) { position_ = position; }
	const DirectX::XMFLOAT2& GetPosition() const { return position_; }
	void SetRotation(float rotation) { rotationZ = rotation; }
	float GetRotation() const { return rotationZ; }
	void SetColor(DirectX::XMFLOAT4 color) { color_ = color; }
	const DirectX::XMFLOAT4 GetColor()const { return color_; }
	void SetSize(const DirectX::XMFLOAT2& size) { size_ = size; }
	const DirectX::XMFLOAT2& GetSize() const { return size_; }
	void SetAnchorPoint(const DirectX::XMFLOAT2& anchorPoint) { anchorPoint_ = anchorPoint; }
	const DirectX::XMFLOAT2& GetAnchorPoint()const { return anchorPoint_; }
	void SetIsFlipX(const bool& isFlipX) { isFlipX_ = isFlipX; }
	const bool GetIsFlipX()const { return isFlipX_; }
	void SetIsFlipY(const bool& isFlipY) { isFlipY_ = isFlipY; }
	const bool GetIsFlipY()const { return isFlipY_; }
	void SetIsInvisible(const bool& isInvisible) { isInvisible_ = isInvisible; }
	const bool GetIsInvisible()const { return isInvisible_; }

private:
	//�X�v���C�g���
	DirectX::XMFLOAT4 color_ = { 1.0f,1.0f,1.0f,1.0f };

	float rotationZ = 0.0f;
	DirectX::XMFLOAT2 position_ = { 0.0f,0.0f };

	DirectX::XMFLOAT2 size_ = { 100.0f,100.0f };

	//�A���J�[�|�C���g
	DirectX::XMFLOAT2 anchorPoint_ = { 0.0f,0.0f };

	//���E�t���b�v
	bool isFlipX_ = false;
	//�㉺�t���b�v
	bool isFlipY_ = false;
	//��\���t���O
	bool isInvisible_ = false;

	SpriteCommon* spriteCommon_;

	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;

	D3D12_VERTEX_BUFFER_VIEW vbView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffMaterial;
	ConstBufferDataMaterial* constMapMaterial = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffTransform;
	ConstBufferDataTransform* constMapTransform = nullptr;

	Vertex vertices[4];
};

