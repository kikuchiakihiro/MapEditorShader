#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Transform.h"
//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), hModel2_(-1), hModel3_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

Sprite* pSprite = nullptr;
//初期化
void Stage::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Assets/Ball.fbx");
    assert(hModel_ >= 0);
    hModel2_ = Model::Load("Assets/arrow.fbx");
    assert(hModel2_ >= 0);
    hModel3_ = Model::Load("Assets/floor.fbx");
    assert(hModel3_ >= 0);
    
   /* pSprite = new Sprite;
    pSprite->Initialize();*/
    
}

//更新
void Stage::Update()
{
    transform_.rotate_.y += 5;
}

//描画
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    Model::SetTransform(hModel2_, transform_);
    Model::Draw(hModel2_);
    Model::SetTransform(hModel3_, transform_);
    Model::Draw(hModel3_);
    //pSprite->Draw(transform_);
}

//開放
void Stage::Release()
{
}