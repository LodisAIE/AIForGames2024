#include "IdleDecision.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* owner, float deltaTime)
{
	owner->disableMovement();
}
