#include "FleeComponent.h"
#include "Agent.h"
#include "Transform2D.h"
#include "MoveComponent.h"

FleeComponent::FleeComponent(Actor* target, float steeringForce, Actor* owner) : SteeringComponent(target, steeringForce, owner, "FleeComponent")
{
}

MathLibrary::Vector2 FleeComponent::calculateForce()
{
	//If there isn't a valid target...
    if (!getTarget())
        //...don't apply a force.
        return { 0,0 };

    //Cache agent and target positions for calculations.
    MathLibrary::Vector2 agentPosition = getOwner()->getTransform()->getWorldPosition();
    MathLibrary::Vector2 targetPosition = getTarget()->getTransform()->getWorldPosition();

    //Find the desired direction to move in.
    MathLibrary::Vector2 directionToTarget = (agentPosition - targetPosition).getNormalized();

    //Scale the direction by the force magnitude.
    MathLibrary::Vector2 fleeForce = directionToTarget * getSteeringForce();

    MathLibrary::Vector2 forceToApply = fleeForce - getAgent()->getMoveComponent()->getVelocity();

    return forceToApply;
}
