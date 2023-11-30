//
//Texture2D	g_texture : register(t0);	//�e�N�X�`���[
//SamplerState	g_sampler : register(s0);	//�T���v���[
//
////������������������������������������������������������������������������������
// // �R���X�^���g�o�b�t�@
//// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
////������������������������������������������������������������������������������
//cbuffer global
//{
//	float4x4	matWVP;			// ���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
//	float4x4	matW;	//���[���h�s��
//	float4		diffuseColor;		// �f�B�t���[�Y�J���[�i�}�e���A���̐F�j
//	bool		isTextured;		// �e�N�X�`���\���Ă��邩�ǂ���
//};
//
////������������������������������������������������������������������������������
//// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
////������������������������������������������������������������������������������
//struct VS_OUT
//{
//	
//	float4 pos    : SV_POSITION;	//�ʒu
//	float2 uv	: TEXCOORD;	//UV���W
//	float4 color	: COLOR;	//�F�i���邳�j
//};
//
////������������������������������������������������������������������������������
//// ���_�V�F�[�_
////������������������������������������������������������������������������������
//VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
//{
//	//�s�N�Z���V�F�[�_�[�֓n�����
//	VS_OUT outData;
//
//
//	//���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
//	//�X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
//	outData.pos = mul(pos, matWVP);
//	outData.uv = uv;
//
//
//	//�@������]
//	normal = mul(normal,matW);
//	float4 light = float4(-1, 0.6, -0.3, 0);
//	light = normalize(light);
//	outData.color = clamp(dot(normal, light), 0, 1);
//
//	//�܂Ƃ߂ďo��
//	return outData;
//}
//
////������������������������������������������������������������������������������
//// �s�N�Z���V�F�[�_
////������������������������������������������������������������������������������
//float4 PS(VS_OUT inData) : SV_Target
//{
//	
//	float4 lightSource = float4 (1.0,1.0,1.0,1.0);
//	float4 ambientSource = float4 (0.2, 0.2, 0.2, 1.0);
//	float4 diffuse;
//	float4 ambient;
//
//	if (isTextured == false) {
//		diffuse = lightSource * diffuseColor * inData.color;
//		ambient = lightSource * diffuseColor * ambientSource;
//	}
//	else {
//		 diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
//		 ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambientSource;
//	}
//	return (diffuse + ambient);
//}
//	

//������������������������������������������������������������������������������
//  �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D       g_texture : register(t0);   //�e�N�X�`���[
SamplerState    g_sampler : register(s0);   //�T���v���[

//������������������������������������������������������������������������������
// �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer global
{
    float4x4    matW;
    float4x4    matWVP;         // ���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
    float4x4    matNormal;           // �@��
    float4      diffuseColor;       //�}�e���A���̐F���g�U���ˌW��
    bool        isTextured;         //�e�N�X�`���[���\���Ă��邩�ǂ���

    float4      vecLight;
    float4      CameraPosition;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
    float4 pos  : SV_POSITION;  //�ʒu
    float2 uv   : TEXCOORD;     //UV���W
    float4 color    : COLOR;    //�F�i���邳�j
    float4 viewDir  :TEXCOORD1; //�����x�N�g��
    float4 reflection   :TexCOORD2;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
    //�s�N�Z���V�F�[�_�[�֓n�����
    VS_OUT outData;

    //���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
    //�X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
    outData.pos = mul(pos, matWVP);
    outData.uv = uv;


    /* l */float4 light = normalize(vecLight);
    /* n */normal = mul(normal, matNormal);
    /* r */outData.reflection = 2.0f * normal * dot(normal, light) - light;
    /* v */outData.viewDir = normalize(mul(CameraPosition, matW) - mul(pos, matW));


    float4 l = vecLight;
    light = normalize(light);
    outData.color = clamp(dot(normal, light), 0, 1);

    //�܂Ƃ߂ďo��
    return outData;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
    float4 lightSource = float4(1.0, 1.0, 1.0, 1.0);
    float4 ambientSource = float4(0.2, 0.2, 0.2, 1.0);

    float4 diffuse;
    float4 ambient;
    float glossiness = 5.0f;
    float4 specular;

    if (isTextured == false)
    {
        diffuse = lightSource * diffuseColor * inData.color;
        ambient = lightSource * diffuseColor * ambientSource;
        specular = (pow(dot(inData.reflection, inData.viewDir), glossiness)) * diffuseColor * lightSource;

    }
    else
    {
        diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
        ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambientSource;
        specular = (pow(dot(inData.reflection, inData.viewDir), glossiness)) * g_texture.Sample(g_sampler, inData.uv) * lightSource;
    }

    //return ambient + diffuse + specular;
    
    return diffuse;
}