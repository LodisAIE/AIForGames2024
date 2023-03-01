#include "StateMachineComponent.h"


StateMachineComponent::StateMachineComponent(Actor* owner) : Component(owner, "StateMachine")
{

}

void StateMachineComponent::start()
{
	Component::start();
	m_currentState = IDLE;
}
