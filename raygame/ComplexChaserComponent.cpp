#include "ComplexChaserComponent.h"
#include "Actor.h"
#include "Agent.h"
#include "WanderComponent.h"
#include "SeekComponent.h"
#include "InRangeDecision.h"
#include "IdleDecision.h"
#include "ChaseDecision.h"
#include "CanIdleDecision.h"
#include "WanderDecision.h"

ComplexChaserComponent::ComplexChaserComponent(float chaseRange, Actor* target, Actor* owner) : Component(owner, "ComplexChaserComponent")
{
	m_owner = (Agent*)owner;

	m_wanderComponent = (WanderComponent*)getOwner()->addComponent(new WanderComponent(100, 100, 100, getOwner()));
	m_seekComponent = (SeekComponent*)getOwner()->addComponent(new SeekComponent(target, 50, getOwner()));

	//Create decision tree.

	//Initialize leaves.
	ChaseDecision* chase = new ChaseDecision(m_seekComponent);
	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision(m_wanderComponent);
	CanIdleDecision* canIdle = new CanIdleDecision(wander, idle);

	//Initialize root.
	m_root = new InRangeDecision(chaseRange, target, canIdle, chase);
}

void ComplexChaserComponent::update(float deltaTime)
{
	m_root->makeDecision(m_owner, deltaTime);
}
