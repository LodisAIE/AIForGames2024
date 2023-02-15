#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include <stdlib.h>

void SampleScene::start()
{
	Scene::start();

	//This is a better comment
	Agent* test = new Agent(50, 50, "Test");
	Agent* target = new Agent(300, 300, "Target");
	float positiveRandVal = (float)(rand()) / RAND_MAX;
	float negativeRandVal = -((float)(rand()) / RAND_MAX);
	float randVal = positiveRandVal + negativeRandVal;
	test->setMaxForce(100);
	target->setMaxForce(75);

	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	target->addComponent(new SpriteComponent(target, "Images/enemy.png"));

	test->getTransform()->setScale({ 50, 50 });
	target->getTransform()->setScale({ 50, 50 });

	test->addComponent(new SeekComponent(target, 50, test));
	target->addComponent(new FleeComponent(test, 50, target));

	addActor(test);
	addActor(target);
}
