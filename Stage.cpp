#include "Stage.h"
#include "Engine/sprite.h"
#include "Engine/Model.h"
#include "Engine/Transform.h"
//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), hModel2_(-1)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

Sprite* pSprite = nullptr;
//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Assets/BoxDefault.fbx");
    assert(hModel_ >= 0);
    pSprite = new Sprite;
    pSprite->Initialize();
    
}

//�X�V
void Stage::Update()
{
    //transform_.rotate_.y += 5;
}

//�`��
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    pSprite->Draw(transform_);
}

//�J��
void Stage::Release()
{
}