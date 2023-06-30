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

	void UpdeteViewMatrix();
	
	void UpdeteProjectionMatrix();
public://アクセッサ
	//getter
	const XMMATRIX& GetMatView() { return matView; }
	const XMMATRIX& GetMatProjection() { return matProjection; }
	const XMFLOAT3& GetEye() { return eye; }
	const XMFLOAT3& GetTarget() { return target; }
	const XMFLOAT3& GetUp() { return up; }
	//setter
	void SetMatView(const XMMATRIX& matView) { this->matView = matView; }
	void SetMatProjection(const XMMATRIX& matProjection) { this->matProjection = matProjection; }
	void SetEye(const XMFLOAT3& eye) { this->eye = eye; }
	void SetTarget(const XMFLOAT3& target) { this->target = target; }
	void SetUp(const XMFLOAT3& up) { this->up = up; }

protected:
	// ビュー行列
	XMMATRIX matView = {};
	// 射影行列
	XMMATRIX matProjection = {};

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