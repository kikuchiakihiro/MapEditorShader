#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"
#include "Engine/Transform.h"
//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//Sprite* pSprite = nullptr;
//������
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

//�X�V
void Stage::Update()
{
    //transform_.rotate_.y += 0.5;
    //transform_.rotate_.y = 45;
   

}

//�`��
void Stage::Draw()
{
   
   /* Model::SetTransform(hModel2_, transform_);
    Model::Draw(hModel2_);*/
   /* Model::SetTransform(hModel3_, transform_);
    Model::Draw(hModel3_);*/
    //pSprite->Draw(transform_);
}

//�J��
void Stage::Release()
{
}