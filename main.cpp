#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "ImGuiManager.h"
#include <imgui.h>
#include <fstream>
#include "Audio.h"
#include "MyGame.h"





// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    
    MyGame game;// = nullptr;

    //ゲームの初期化
    //game = new MyGame();
    game.Initialize();

    while (true) {
        // 毎フレームの更新
        game.Update();
        // 終了リクエストがきたらループを抜ける
        if (game.IsEndRequst() == true) {
            break;
        }

        // 描画
        game.Draw();
    }


    // ゲームの終了
    game.Finalize();
    return 0;
}
