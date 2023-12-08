#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"
#include "Engine/Transform.h"
#include "Engine/Input.h"
#include "LightPosController.h"
#include "Engine/Camera.h"
void Stage::IntConstantBuffer()
{
}
//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}


//������
void Stage::Initialize()
{
   
   //transform_.rotate_.x = -120;
    
    
   /* hModel2_ = Model::Load("Assets/arrow.fbx");
    assert(hModel2_ >= 0);*/
   /* hModel3_ = Model::Load("Assets/floor.fbx");
    assert(hModel3_ >= 0);*/
    
    
    ModelLight = Model::Load("Assets/Ballkyu.fbx");
    assert(ModelLight >= 0);
}

//�X�V
void Stage::Update()
{
   
    //�����̈ʒu��WASD�Ƃ��Ŏw��
    lightPos_ = LightPosController::GetLightPosition();
    //Model����LightPos�����Ă���
    if (Input::IsKey(DIK_W))
        lightPos_.z += 0.5;

    if (Input::IsKey(DIK_A))
        lightPos_.x += 0.5;

    if (Input::IsKey(DIK_S))
        lightPos_.z -= 0.5;

    if (Input::IsKey(DIK_D))
        lightPos_.x -= 0.5;

    LightPosController::SetLightPosition(lightPos_);
    LightTrans.position_ = XMFLOAT3{1,1,1};

    CBUFF_STAGESCENE cb;
    cb.lightDirection = lightSourcePosition_;
    XMStoreFloat4(&cb.eyePos, Camera::GetEyePosition());

    Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);


}

//�`��
void Stage::Draw()
{
     Model::SetTransform(ModelLight, transform_);
    Model::Draw(ModelLight);
   /* Model::SetTransform(hModel2_, transform_);
    Model::Draw(hModel2_);*/
   /* Model::SetTransform(hModel3_, transform_);
    Model::Draw(hModel3_);*/
    
}

//�J��
void Stage::Release()
{
}