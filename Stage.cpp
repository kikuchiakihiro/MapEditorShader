#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"
#include "Engine/Transform.h"
#include "Engine/Input.h"
#include "LightPosController.h"
//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//デストラクタ
Stage::~Stage()
{
}

//Sprite* pSprite = nullptr;
//初期化
void Stage::Initialize()
{
   
   //transform_.rotate_.x = -120;
    
    
   /* hModel2_ = Model::Load("Assets/arrow.fbx");
    assert(hModel2_ >= 0);*/
   /* hModel3_ = Model::Load("Assets/floor.fbx");
    assert(hModel3_ >= 0);*/
    
   /* pSprite = new Sprite;
    pSprite->Initialize();*/
    
}

//更新
void Stage::Update()
{
    //transform_.rotate_.y += 0.5;
    //transform_.rotate_.y = 45;
    //光源の位置をWASDとかで指定
    lightPos = LightPosController::GetLightPosition();
    //ModelからLightPosもってくる
    if (Input::IsKey(DIK_W))
        lightPos.z += 0.5;

    if (Input::IsKey(DIK_A))
        lightPos.x += 0.5;

    if (Input::IsKey(DIK_S))
        lightPos.z -= 0.5;

    if (Input::IsKey(DIK_D))
        lightPos.x -= 0.5;

    LightPosController::SetLightPosition(lightPos);

    //ballTrans.rotate_.y += 0.8;

}

//描画
void Stage::Draw()
{
   
   /* Model::SetTransform(hModel2_, transform_);
    Model::Draw(hModel2_);*/
   /* Model::SetTransform(hModel3_, transform_);
    Model::Draw(hModel3_);*/
    //pSprite->Draw(transform_);
}

//開放
void Stage::Release()
{
}