#include "Ball.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"
#include "Engine/Transform.h"
//コンストラクタ
Ball::Ball(GameObject* parent)
    :GameObject(parent, "Ball"),hModel_(-1)
{
}

//デストラクタ
Ball::~Ball()
{
}
Sprite* pSprite = nullptr;
//初期化
void Ball::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Assets/Ballkyu.fbx");
    assert(hModel_ >= 0);

}

//更新
void Ball::Update()
{
    transform_.rotate_.y += 0.5;
}

//描画
void Ball::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Ball::Release()
{
}