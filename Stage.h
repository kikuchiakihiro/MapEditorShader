#pragma once
#include "Engine/GameObject.h"


struct CBUFF_STAGESCENE
{
    XMFLOAT4 lightDirection;
    XMFLOAT4 eyePos;
};

//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hModel_;    //���f���ԍ�
    XMFLOAT4 lightPos_;
    Transform LightTrans;
    int ModelLight;
    ID3D11Buffer* pCBStageScene_;
    void IntConstantBuffer();
    XMFLOAT4 lightSourcePosition_;
   
public:

    

    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};