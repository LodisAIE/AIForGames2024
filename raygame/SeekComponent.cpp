#include "SeekComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "MoveComponent.h"

SeekComponent::SeekComponent(Actor* target, float steeringForce, Actor* owner) :
    SteeringComponent(target, steeringForce, owner, "SeekComponent")
{
    
}

MathLibrary::Vector2 SeekComponent::calculateForce()
{
    //If there isn't a valid target...
    if (!getTarget())
        //...don't apply a force.
        return { 0,0 };

    //Cache agent and target positions for calculations.
    MathLibrary::Vector2 agentPosition = getOwner()->getTransform()->getWorldPosition();
    MathLibrary::Vector2 targetPosition = getTarget()->getTransform()->getWorldPosition();

    //Find the desired direction to move in.
    MathLibrary::Vector2 directionToTarget = (targetPosition - agentPosition).getNormalized();
    //Scale the direction by the force magnitude.
    MathLibrary::Vector2 seekForce = directionToTarget * getSteeringForce();

    MathLibrary::Vector2 forceToApply = seekForce - getAgent()->getMoveComponent()->getVelocity();

    return forceToApply;
}
