#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region 基盤システムの初期化
    Framework::Initialize();

    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンを初期化
    //imGuiManager初期化
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    //シーンの初期化
    gamePlayScene = new GamePlayScene();
    gamePlayScene->Initialize();

    //テクスチャのセット
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    //スプライト初期化
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);
#pragma endregion 最初のシーンを初期化
}

void MyGame::Finalize()
{
#pragma region 最初のシーンの終了
    /*delete sprite;*/
    imGuiManager->Finalize();
    delete imGuiManager;

#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    gamePlayScene->Finalize();
    //シーンの解放
    delete gamePlayScene;
    //基底クラスの終了処理
    Framework::Finalize();
#pragma endregion 基盤システムの終了
}

void MyGame::Update()
{
#pragma region 基盤システムの更新
    Framework::Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新

    sprite->Update();
    //シーンの更新
    gamePlayScene->Update();

    imGuiManager->Begin();

    ImGui::ShowDemoWindow();

    imGuiManager->End();


#pragma endregion 最初のシーンの更新
}

void MyGame::Draw()
{
    //描画前処理
    dxCommon->PreDraw();

#pragma region 最初のシーンの描画
    spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();

    Object3d::PreDraw(dxCommon->GetCommandList());
    gamePlayScene->Draw();
    Object3d::PostDraw();

    imGuiManager->Draw();
#pragma endregion 最初のシーンの描画

    //描画後処理
    dxCommon->PostDraw();
}