#pragma once
#include <DirectXMath.h>
#include <wrl.h>

class Camera
{
private:
	// DirectX::���ȗ�
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMMATRIX = DirectX::XMMATRIX;
public:
	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();
public://�A�N�Z�b�T
	//getter
	const XMMATRIX& GetMatView() { return matView_; }
	const XMMATRIX& GetMatProjection() { return matProjection_; }
	//const XMMATRIX& GetMatViewProjection() { return matViewProjection_; }
	//const XMMATRIX& GetMatBillboard() { return matBillboard_; }
	//const XMMATRIX& GetMatBillboardY() { return matBillboardY_; }
	//const XMFLOAT3& GetEye() { return eye_; }
	//const XMFLOAT3& GetTarget() { return target_; }
	//const XMFLOAT3& GetUp() { return up_; }
	////setter
	//void SetEye(const XMFLOAT3& eye);
	//void SetTarget(const XMFLOAT3& target);
	//void SetUp(const XMFLOAT3& up);

protected:
	// �r���[�s��
	XMMATRIX matView_ = {};
	// �ˉe�s��
	XMMATRIX matProjection_ = {};

	//XMMATRIX matViewProjection_ = {};
	//// �r���{�[�h�s��
	//XMMATRIX matBillboard_ = {};
	//// Y�����r���{�[�h�s��
	//XMMATRIX matBillboardY_ = {};
	// ���_���W
	XMFLOAT3 eye;
	// �����_���W
	XMFLOAT3 target;
	// ������x�N�g��
	XMFLOAT3 up;


};