#include "ChaserComponent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Actor.h"
#include "Agent.h"
#include "MoveComponent.h"
#include "StateMachineComponent.h"
#include <Vector2.h>
#include "Transform2D.h"

ChaserComponent::ChaserComponent(float chaseRange, Actor* target, Actor* owner) : Component(owner, "ChaserComponent")
{
	m_chaseRange = chaseRange;

	m_stateMachine = (StateMachineComponent*)getOwner()->addComponent(new StateMachineComponent(getOwner()));
	m_seekComponent = (SeekComponent*)getOwner()->addComponent(new SeekComponent(target, m_seekForce, getOwner()));
	m_wanderComponent = (WanderComponent*)getOwner()->addComponent(new WanderComponent(m_wanderCircleDistance, m_wanderCircleRadius, m_wanderForce, getOwner()));

	m_agent = m_seekComponent->getAgent();
}

Actor* ChaserComponent::getTarget()
{
	return getSeekComponent()->getTarget();
}

void ChaserComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPosition = getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPosition - ownerPosition).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_chaseRange;

	switch (m_stateMachine->getCurrentState())
	{
	case IDLE:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(0);

		m_agent->disableMovement();

		if (targetInRange)
			m_stateMachine->setCurrentState(CHASE);

		break;
	case CHASE:
		m_wanderComponent->setSteeringForce(0);
		m_seekComponent->setSteeringForce(m_seekForce);

		m_agent->enableMovement();
		if (!targetInRange)
			m_stateMachine->setCurrentState(WANDER);

		break;
	case WANDER:
		m_wanderComponent->setSteeringForce(m_wanderForce);
		m_seekComponent->setSteeringForce(0);

		m_agent->enableMovement();
		m_currentTime += deltaTime;

		if (targetInRange)
		{
			m_stateMachine->setCurrentState(CHASE);
			m_currentTime = 0;
		}
		else if (m_currentTime >= m_wanderTime)
		{
			m_stateMachine->setCurrentState(IDLE);
			m_currentTime = 0;
		}

		break;
	}
}
