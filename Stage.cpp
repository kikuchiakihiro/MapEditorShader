#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"
#include "Engine/Transform.h"
#include "Engine/Input.h"
#include "LightPosController.h"
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
    //�����̈ʒu��WASD�Ƃ��Ŏw��
    lightPos = LightPosController::GetLightPosition();
    //Model����LightPos�����Ă���
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