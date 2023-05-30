#include "Framework.h"
void Framework::Run()
{
	//ゲームの初期化
	Initialize();

	while (true)//ゲームループ
	{
		//毎フレーム処理
		Update();
		//終了リクエストが来たら抜ける
		if (IsEndRequst()) {
			break;
		}
		//描画
		Draw();
	}

	//ゲームの終了
	Finalize();
}

void Framework::Initialize()
{
	//WindowsAPIの初期化
	winApp = new WinApp();
	winApp->Initialize();
	
	//DirectX初期化
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);

	//inputの初期化
	input = new Input();
	input->Initialize(winApp);

	//スプライト共通部の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);

	//object3dの初期化
	Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);

	//ImGuiManagerの初期化
	imGuiManager = new ImGuiManager;
	imGuiManager->Initialize(winApp, dxCommon);
}

void Framework::Finalize()
{
	//入力解放
	delete input;
	//DirectX解放
	delete dxCommon;
	//WindowsAPIの終了処理
	winApp->Finalize();
	//WindowsAPI解放
	delete winApp;
	//スプライト共通部解放
	delete spriteCommon;
	//ImGuiの終了処理
	imGuiManager->Finalize();
	//ImGuiManagerの解放
	delete imGuiManager;
}

void Framework::Update()
{
	//入力の更新
	input->Update();
}
