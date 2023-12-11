//#include "Stage.h"
//#include "Engine/sprite.h"
//#include "Engine/Model.h"
//#include "Engine/Fbx.h"
//#include "Engine/Transform.h"
//#include "Engine/Input.h"
//#include "LightPosController.h"
//#include "Engine/Camera.h"
//
//namespace {
//    const XMFLOAT4 DEF_LIGHT_POSITION{ 1, 2, 1, 0 };
//}
//
//void Stage::InitConstantBuffer()
//{
//
//
//}
////�R���X�g���N�^
//Stage::Stage(GameObject* parent)
//    :GameObject(parent, "Stage")
//{
//}
//
////�f�X�g���N�^
//Stage::~Stage()
//{
//}
//
//
////������
//void Stage::Initialize()
//{
//   
//   //transform_.rotate_.x = -120;
//    
//    
//   /* hModel2_ = Model::Load("Assets/arrow.fbx");
//    assert(hModel2_ >= 0);*/
//   /* hModel3_ = Model::Load("Assets/floor.fbx");
//    assert(hModel3_ >= 0);*/
//    
//    
//    ModelLight = Model::Load("Assets/Ballkyu.fbx");
//    assert(ModelLight >= 0);
//}
//
////�X�V
//void Stage::Update()
//{
//   
//    //�����̈ʒu��WASD�Ƃ��Ŏw��
//    lightPos_ = LightPosController::GetLightPosition();
//    //Model����LightPos�����Ă���
//    if (Input::IsKey(DIK_W))
//        lightPos_.z += 0.5;
//
//    if (Input::IsKey(DIK_A))
//        lightPos_.x += 0.5;
//
//    if (Input::IsKey(DIK_S))
//        lightPos_.z -= 0.5;
//
//    if (Input::IsKey(DIK_D))
//        lightPos_.x -= 0.5;
//
//    LightPosController::SetLightPosition(lightPos_);
//    LightTrans.position_ = XMFLOAT3{1,1,1};
//
//    CBUFF_STAGESCENE cb;
//    cb.lightDirection = lightSourcePosition_;
//    XMStoreFloat4(&cb.eyePos, Camera::GetEyePosition());
//
//    Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);
//
//
//}
//
////�`��
//void Stage::Draw()
//{
//     Model::SetTransform(ModelLight, transform_);
//    Model::Draw(ModelLight);
//   /* Model::SetTransform(hModel2_, transform_);
//    Model::Draw(hModel2_);*/
//   /* Model::SetTransform(hModel3_, transform_);
//    Model::Draw(hModel3_);*/
//    
//}
//
////�J��
//void Stage::Release()
//{
//}

#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "axisClass.h"


namespace {
    const XMFLOAT4 DEF_LIGHT_POSITION{ 1, 2, 1, 0 };
}

void Stage::InitConstantBuffer()
{
    D3D11_BUFFER_DESC cb;
    cb.ByteWidth = sizeof(CBUFF_STAGESCENE);
    cb.Usage = D3D11_USAGE_DEFAULT;
    cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cb.CPUAccessFlags = 0;
    cb.MiscFlags = 0;
    cb.StructureByteStride = 0;

    // �R���X�^���g�o�b�t�@�̍쐬
    HRESULT hr;
    hr = Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pCBStageScene_);
    if (FAILED(hr))
    {
        MessageBox(NULL, "�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
    }

}

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), hGround_(-1), lightSourcePosition_(DEF_LIGHT_POSITION)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    ////���f���f�[�^�̃��[�h
    //hModel_ = Model::Load("assets/Torus.fbx");
    //hGround_ = Model::Load("assets/Ground.fbx");
    //hLightBall_ = Model::Load("assets/RedBall.fbx");

  /*  assert(hModel_ >= 0);
    assert(hGround_ >= 0);
    assert(hLightBall_ >= 0);*/
    Camera::SetPosition(XMVECTOR{ 0, 10, -20, 0 });
    Camera::SetTarget(XMVECTOR{ 0, 2, 0, 0 });
   /* trDonuts.position_ = { 0, 2, 0 };
    trDonuts.rotate_ = { 0, 0, 0 };
    trDonuts.scale_ = { 1,1,1 };

    trGround.position_ = { 0, 0, 0 };
    trGround.rotate_ = { 0, 0, 0 };
    trGround.scale_ = { 10, 10, 10 };

    trLightBall.position_ = { 0, 0, 0 };
    trLightBall.rotate_ = { 0, 0, 0 };
    trLightBall.scale_ = { 0.4, 0.4, 0.4 };*/
    Instantiate<axisClass>(this);
    InitConstantBuffer();
}

//�X�V
void Stage::Update()
{

   
    //transform_.rotate_.y += 0.5f;
    //trDonuts.rotate_.y += 0.5f;
    if (Input::IsKey(DIK_RIGHT))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x + 0.1f, p.y + 0.0f, p.z + 0.0f, p.w + 0.0f };

        //Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    if (Input::IsKey(DIK_LEFT))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x - 0.1f, p.y - 0.0f, p.z - 0.0f, p.w - 0.0f };

        /// Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    if (Input::IsKey(DIK_UP))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x - 0.0f, p.y + 0.1f, p.z - 0.0f, p.w - 0.0f };

        //Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    if (Input::IsKey(DIK_DOWN))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.1f, p.z - 0.0f, p.w - 0.0f };

        //Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    if (Input::IsKey(DIK_W))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.0f, p.z + 0.1f, p.w + 0.0f };

        //Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    if (Input::IsKey(DIK_S))
    {
        XMFLOAT4 p = GetLightPos();
        XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.0f, p.z - 0.1f, p.w - 0.0f };

        //Model::GetModel(hModel_)->SetLightPos(margin);
        SetLightPos(margin);
    }
    XMFLOAT4 tmp{ GetLightPos() };
    //trLightBall.position_ = { tmp.x, tmp.y,tmp.z };

    CBUFF_STAGESCENE cb;
    cb.lightPosition = lightSourcePosition_;
    XMStoreFloat4(&cb.eyePos, Camera::GetEyePosition());

    Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);

    Direct3D::pContext_->VSSetConstantBuffers(1, 1, &pCBStageScene_);	//���_�V�F�[�_�[�p	
    Direct3D::pContext_->PSSetConstantBuffers(1, 1, &pCBStageScene_);	//�s�N�Z���V�F�[�_�[�p
}

//�`��
void Stage::Draw()
{
    //q->Draw(transform_);
    //Model::SetTransform(hModel_, trDonuts);
    //Model::Draw(hModel_);
    ////Model::SetTransform(hGround_, trGround);
    ////Model::Draw(hGround_);
    //Model::SetTransform(hLightBall_, trLightBall);
    //Model::Draw(hLightBall_);
}

//�J��
void Stage::Release()
{
}