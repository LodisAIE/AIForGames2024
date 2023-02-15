#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"

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
	MathLibrary::Vector2 newPostion = currentPosition + getVelocity() * deltaTime;

	//If the actor should look where it's heading and is moving...
	if (getUpdateFacing() && getVelocity().getMagnitude() > 0)
		transform->setForward(getVelocity());

	transform->setLocalPosition(newPostion);
}
