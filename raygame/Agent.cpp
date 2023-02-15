#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

Agent::Agent(float x, float y, const char* name) : Actor(x, y, name)
{
	m_moveComponent = nullptr;
	m_steeringComponents = DynamicArray<SteeringComponent*>();
	m_maxForce = 0.0f;
	m_force = { 0,0 };
}

void Agent::start()
{
	Actor::start();

	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent(this));
	m_moveComponent->setMaxSpeed(500);
	m_moveComponent->setUpdateFacing(true);
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Collect all the force being applied from the steering behaviours.
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//If the magnitude of the force exceeds the limit...
	if (m_force.getMagnitude() > getMaxForce())
		//...normalize and scale by the force limit.
		m_force = m_force.getNormalized() * getMaxForce();

	//Apply new force to velocity.
	MathLibrary::Vector2 currentVelocity = getMoveComponent()->getVelocity();
	getMoveComponent()->setVelocity(currentVelocity + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* newComponent = dynamic_cast<SteeringComponent*>(component);

	if (newComponent)
		m_steeringComponents.add(newComponent);
}
