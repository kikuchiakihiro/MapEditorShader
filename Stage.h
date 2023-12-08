#pragma once
#include "Engine/GameObject.h"


struct CBUFF_STAGESCENE
{
    XMFLOAT4 lightDirection;
    XMFLOAT4 eyePos;
};

//◆◆◆を管理するクラス
class Stage : public GameObject
{
    int hModel_;    //モデル番号
    XMFLOAT4 lightPos_;
    Transform LightTrans;
    int ModelLight;
    ID3D11Buffer* pCBStageScene_;
    void IntConstantBuffer();
    XMFLOAT4 lightSourcePosition_;
   
public:

    

    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};