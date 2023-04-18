#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システム初期化
    HRESULT result;

    //WindowsAPIの初期化
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();

    MSG msg{};  // メッセージ

    //DirectX初期化
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //inputの初期化
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    //スプライト共通部の初期化
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon;
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

    //object3dの初期化
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
    
    //ImGuiManagerの初期化
    ImGuiManager* imGuiManager = nullptr;
    imGuiManager = new ImGuiManager;
    imGuiManager->Initialize(winApp, dxCommon);
#pragma endregion 基盤システム初期化
      
#pragma region 最初のシーンの初期化

    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon,0);
  
    //.objからモデルデータを読み込む
    Model* model_ground = Model::LoadFromOBJ("ground");
    Model* model_triangle = Model::LoadFromOBJ("triangle_mat");
    Model* model_cube = Model::LoadFromOBJ("cube");
    //3Dオブジェクト生成
    Object3d* object3d_1 = Object3d::Create();
    Object3d* object3d_2 = Object3d::Create();
    Object3d* object3d_3 = Object3d::Create();
    //3Dオブジェクトと3Dモデルを紐づける
    object3d_1->SetModel(model_ground);
    object3d_2->SetModel(model_triangle);
    object3d_3->SetModel(model_cube);
    //各3Dオブジェクトの位置指定
    object3d_1->SetPosition({ 0,-5, 0 });
    object3d_2->SetPosition({ -5,0,-5 });
    object3d_3->SetPosition({ +5,0,+5 });
#pragma endregion 最初のシーンの初期化
    
#pragma region ゲームループ
    while (true) {

#pragma region 基盤システムの更新
        //Windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            //ゲームループを抜ける
            break;
        }

      
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新
        //ImGuiの受付開始
        imGuiManager->Begin();
        //入力の更新
        input->Update();

        sprite->Update();
        object3d_1->Update();
        object3d_2->Update();
        object3d_3->Update();

        //ImGuiの受付終了
        imGuiManager->End();
#pragma endregion 最初のシーンの更新
        
        //描画前処理
        dxCommon->PreDraw();
#pragma region 最初のシーンの描画

        //スプライト描画
        spriteCommon->PreDraw();
        sprite->Draw();
        spriteCommon->PostDraw();

        //オブジェクト描画
        Object3d::PreDraw(dxCommon->GetCommandList());
        object3d_1->Draw();
        object3d_2->Draw();
        object3d_3->Draw();
        Object3d::PostDraw();

        imGuiManager->Draw();
#pragma endregion 最初のシーンの描画
        //描画後処理
        dxCommon->PostDraw();
        
    }
#pragma endregion ゲームループ

#pragma region 最初のシーンの終了
    delete sprite;
#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
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
    //3Dモデルの解放
    delete model_ground;
    delete model_triangle;
    delete model_cube;
    //3Dオブジェクト解放
    delete object3d_1;
    delete object3d_2;
    delete object3d_3;

#pragma endregion 基盤システムの終了

    return 0;
}
