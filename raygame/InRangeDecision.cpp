#include "InRangeDecision.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Agent.h"

InRangeDecision::InRangeDecision(float chaseRange, Actor* target, Decision* leftChild, Decision* rightChild)
    : BooleanDecision(leftChild, rightChild)
{
    m_chaseRange = chaseRange;
    m_target = target;
}

bool InRangeDecision::checkCondition(Agent* owner, float deltaTime)
{
    MathLibrary::Vector2 targetPosition = m_target->getTransform()->getWorldPosition();
    MathLibrary::Vector2 ownerPosition = owner->getTransform()->getWorldPosition();

    float distanceFromTarget = (targetPosition - ownerPosition).getMagnitude();

    return distanceFromTarget <= m_chaseRange;
}
