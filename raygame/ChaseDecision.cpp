#include "ChaseDecision.h"
#include "SeekComponent.h"
#include "Agent.h"

void ChaseDecision::makeDecision(Agent* owner, float deltaTime)
{
	owner->enableMovement();
	m_ownerSeekComponent->setSteeringForce(50);
}
