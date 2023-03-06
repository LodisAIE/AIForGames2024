#include "WanderDecision.h"
#include "WanderComponent.h"
#include "Agent.h"

void WanderDecision::makeDecision(Agent* owner, float deltaTime)
{
	m_ownerWanderComponent->getAgent()->enableMovement();
	m_ownerWanderComponent->setSteeringForce(100);
}
