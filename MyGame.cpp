#include "MyGame.h"
#include "Framework.h"


void MyGame::Initialize()
{
#pragma region 基盤システム初期化

    //基底クラスの初期化処理
    Framework::Initialize();
    
    MSG msg{};  // メッセージ
 
#pragma endregion 基盤システム初期化

#pragma region 最初のシーンの初期化
    //サウンドの初期化
    audio = new Audio();
    audio->Initialize();

    //サウンドの読み込み
    audio->LoadWave("Alarm01.wav");
    //サウンド再生
    audio->PlayWave("Alarm01.wav");

    //スプライト読み込み
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");
    //スプライトの初期化
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon, 0);

    //モデル読み込み
    model_ground = Model::LoadFromOBJ("ground");
    model_triangle = Model::LoadFromOBJ("triangle_mat");
    model_cube = Model::LoadFromOBJ("cube");

    //オブジェクト生成
    object3d_1 = Object3d::Create();
    object3d_2 = Object3d::Create();
    object3d_3 = Object3d::Create();

    //3Dオブジェクトと3Dモデルを紐づける
    object3d_1->SetModel(model_ground);
    object3d_2->SetModel(model_triangle);
    object3d_3->SetModel(model_cube);
    //各3Dオブジェクトの位置指定
    object3d_1->SetPosition({ 0,-5, 0 });
    object3d_2->SetPosition({ -5,0,-5 });
    object3d_3->SetPosition({ +5,0,+5 });
#pragma endregion 最初のシーンの初期化
}

void MyGame::Finalize()
{
    //スプライト解放
    delete sprite;
    //3Dモデルの解放
    delete model_ground;
    delete model_triangle;
    delete model_cube;
    //3Dオブジェクト解放
    delete object3d_1;
    delete object3d_2;
    delete object3d_3;
    //Audio解放
    audio->Finalize();
    delete audio;

    //基底クラスの終了処理
    Framework::Finalize();
}

void MyGame::Update()
{
#pragma region 最初のシーンの更新
    //ImGuiの受付開始
    imGuiManager->Begin();
  
    //基底クラスの更新処理
    Framework::Update();

    sprite->Update();
    object3d_1->Update();
    object3d_2->Update();
    object3d_3->Update();

    //デモウィンドウの表示オン
    //ImGui::ShowDemoWindow();
    //ImGuiの受付終了
    imGuiManager->End();
#pragma endregion 最初のシーンの更新
}

void MyGame::Draw()
{
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