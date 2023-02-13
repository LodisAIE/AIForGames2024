#include "Agent.h"
#include "MoveComponent.h"

void Agent::start()
{
	Actor::start();

	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(500);
	m_moveComponent->setUpdateFacing(true);
}
