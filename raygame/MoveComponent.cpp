#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Engine.h"

MoveComponent::MoveComponent(Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = 0;
	m_updateFacing = false;
	m_velocity = { 0,0 };
}

void MoveComponent::update(float deltaTime)
{
	//Add the current velocity to the current postion to get the new position.
	Transform2D* transform = getOwner()->getTransform();
	MathLibrary::Vector2 currentPosition = transform->getLocalPosition();
	MathLibrary::Vector2 newPosition = currentPosition + getVelocity() * deltaTime;

	//If the actor should look where it's heading and is moving...
	if (getUpdateFacing() && getVelocity().getMagnitude() > 0)
		transform->setForward(getVelocity());

	if (!getWrapPosition())
	{
		transform->setLocalPosition(newPosition);
		return;
	}
	
	//Wrap position on x.
	if (newPosition.x > Engine::getScreenWidth())
		newPosition.x = 0;
	else if (newPosition.x < 0)
		newPosition.x = Engine::getScreenWidth();

	//Wrap position on y.
	if (newPosition.y > Engine::getScreenHeight())
		newPosition.y = 0;
	else if (newPosition.y < 0)
		newPosition.y = Engine::getScreenHeight();

	transform->setLocalPosition(newPosition);
}
