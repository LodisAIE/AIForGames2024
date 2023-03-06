#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "WanderComponent.h"
#include "MoveComponent.h"
#include <stdlib.h>
#include "ChaserComponent.h"
#include "ComplexChaserComponent.h"

void SampleScene::start()
{
	Scene::start();

	//This is a better comment
	Agent* chaser = new Agent(50, 50, "Test");
	Agent* target = new Agent(60, 60, "Target");

	chaser->setMaxForce(100);
	target->setMaxForce(75);

	chaser->addComponent(new SpriteComponent(chaser, "Images/player.png"));
	target->addComponent(new SpriteComponent(target, "Images/enemy.png"));

	chaser->getTransform()->setScale({ 50, 50 });
	target->getTransform()->setScale({ 50, 50 });

	chaser->addComponent(new ComplexChaserComponent(50, target, chaser));
	target->addComponent(new WanderComponent(100, 100, 100, target));

	addActor(chaser);
	addActor(target);
}
