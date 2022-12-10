#pragma once
#include "SpriteCommon.h"

//�X�v���C�g
class Sprite
{
public: //�����o�֐�
	//������
	void Initialize(SpriteCommon* _spriteCommon);

	//�`��
	void Draw();

private:
	//�X�v���C�g���ʕ���
	SpriteCommon* spriteCommon = nullptr;

	//���_�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;
	//���_�o�b�t�@�r���[
	D3D12_VERTEX_BUFFER_VIEW vbView{};
};

