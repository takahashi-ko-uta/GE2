#include <cassert>
#include <string>
#include <DirectXMath.h>
#include <DirectXTex.h>
#include <d3dcompiler.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"

using namespace DirectX;
using namespace Microsoft::WRL;

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
#pragma endregion 基盤システム初期化
      
#pragma region 最初のシーンの初期化

#pragma endregion 最初のシーンの初期化
    
#pragma region ゲームループ
    while (true) {

#pragma region 基盤システムの更新
        //Windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            //ゲームループを抜ける
            break;
        }

        //入力の更新
        input->Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新

#pragma endregion 最初のシーンの更新
        
       

        //描画前処理
        dxCommon->PreDraw();
  
#pragma region 最初のシーンの描画

#pragma endregion 最初のシーンの描画

        //描画後処理
        dxCommon->PostDraw();
    }
#pragma endregion ゲームループ

  
#pragma region 基盤システムの終了
    //入力開放
    delete input;
    //DirectX解放
    delete dxCommon;
    //WindowsAPIの終了処理
    winApp->Finalize();
    //WindowsAPI解放
    delete winApp;
#pragma endregion 基盤システムの終了

    return 0;
}
