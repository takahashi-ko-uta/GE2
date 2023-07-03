#include "MyGame.h"


void MyGame::Initialize()
{
#pragma region 基盤システムの初期化
    Framework::Initialize();

#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンを初期化

    //imGuiManager初期化
    imGuiManager = new ImGuiManager();
    imGuiManager->Initialize(winApp, dxCommon);

    //カメラ初期化
    camera = new Camera();
    camera->Initialize();

    //オブジェクト全体の初期化
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height, camera);

    ////スプライト共通部の初期化
    //spriteCommon = new SpriteCommon();
    //spriteCommon->Initialize(dxCommon);
    ////テクスチャのセット
    //spriteCommon->LoadTexture(0, "texture.png");
    //spriteCommon->LoadTexture(1, "reimu.png");
    ////スプライト初期化
    //sprite = new Sprite();
    //sprite->SetTextureIndex(0);
    //sprite->Initialize(spriteCommon, 0);

    //シーンの初期か化
    scene = new GamePlayScene();
    scene->Initialize(dxCommon,input);

    ////モデル読み込み
    //model_ = Model::LoadFromOBJ("triangle_mat");

    ////オブジェクト生成
    //object3d_ = Object3d::Create();
    ////3Dオブジェクトと3Dモデルをひも付け
    //object3d_->SetModel(model_);
    ////3Dオブジェクトの位置を指定
    //object3d_->SetPosition({ -5,0,-5 });
    ////3Dオブジェクトのスケールを指定
    //object3d_->SetScale({ 10.0f,10.0f,10.0f });

    ////サウンド初期化
    //Audio* audio = new Audio();
    //audio->Initialize();
    ////サウンド読み込み
    //audio->LoadWave("Alarm01.wav");
    ////サウンド再生
    //audio->PlayWave("Alarm01.wav");

#pragma endregion 最初のシーンを初期化
}

void MyGame::Finalize()
{
#pragma region 最初のシーンの終了
    imGuiManager->Finalize();
    delete imGuiManager;

    ////スプライト共通部解放
    //delete spriteCommon;
    ////スプライト解放
    //delete sprite;

    //シーンの終了処理
    scene->Finalize();

    /*delete object3d_;
    delete model_;
    delete audio;
    audio->Finalize();*/

#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    Framework::Finalize();
#pragma endregion 基盤システムの終了
}

void MyGame::Update()
{
#pragma region 基盤システムの更新
    Framework::Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新
    camera->SetEye({ 0,0,-100 });
    camera->Update();

    /*sprite->Update();*/

    //シーンの毎フレーム処理
    scene->Update();

    //object3d_->Update();


    imGuiManager->Begin();
    ////ImGuiのデモウィンドウ表示
    //ImGui::ShowDemoWindow();
#pragma region ImGui::Text

    ImGui::Text("cameraEye:%f,%f,%f", camera->GetEye().x, camera->GetEye().y, camera->GetEye().z);
    ImGui::Text("cameraTarget:%f,%f,%f", camera->GetTarget().x, camera->GetTarget().y, camera->GetTarget().z);
    ImGui::Text("cameraUp:%f,%f,%f", camera->GetUp().x, camera->GetUp().y, camera->GetUp().z);
#pragma endregion ImGui::Text

    imGuiManager->End();



#pragma endregion 最初のシーンの更新
}

void MyGame::Draw()
{
    //描画前処理
    dxCommon->PreDraw();

#pragma region 最初のシーンの描画
    /*spriteCommon->PreDraw();
    sprite->Draw();
    spriteCommon->PostDraw();*/

    //シーンの描画
    scene->Draw();

    /*Object3d::PreDraw(dxCommon->GetCommandList());  
    object3d_->Draw();
    Object3d::PostDraw();*/

    imGuiManager->Draw();
#pragma endregion 最初のシーンの描画

    //描画後処理
    dxCommon->PostDraw();
}