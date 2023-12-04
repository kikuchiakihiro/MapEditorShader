#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/sprite.h"
#include "Ball.h"
#include "Arrow.h"
#include "Floor.h"

TestScene::TestScene(GameObject* parent):GameObject(parent,"TestScene")
{

}

void TestScene::Initialize()
{
	Instantiate<Ball>(this);
	Instantiate<Arrow>(this);
	Instantiate<Floor>(this);
	
}

void TestScene::Update()
{
	
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
