#include "SteeringComponent.h"

SteeringComponent::SteeringComponent()
{
	m_steeringForce = 0;
	m_target = nullptr;
}

SteeringComponent::SteeringComponent(Actor* target, float steeringForce, Actor* owner, const char* name) :
	Component(owner, name)
{
	m_target = target;
	m_steeringForce = steeringForce;
}
