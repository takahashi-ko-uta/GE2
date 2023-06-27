#pragma once
#include <DirectXMath.h>
#include <wrl.h>

class Camera
{
private:
	// DirectX::を省略
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMMATRIX = DirectX::XMMATRIX;
public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();
public://アクセッサ
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
	// ビュー行列
	XMMATRIX matView_ = {};
	// 射影行列
	XMMATRIX matProjection_ = {};

	//XMMATRIX matViewProjection_ = {};
	//// ビルボード行列
	//XMMATRIX matBillboard_ = {};
	//// Y軸回りビルボード行列
	//XMMATRIX matBillboardY_ = {};
	// 視点座標
	XMFLOAT3 eye;
	// 注視点座標
	XMFLOAT3 target;
	// 上方向ベクトル
	XMFLOAT3 up;


};