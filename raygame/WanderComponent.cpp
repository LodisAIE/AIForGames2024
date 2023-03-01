#include "WanderComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "MoveComponent.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

WanderComponent::WanderComponent(float circleDistance, float circleRadius, float steeringForce, Actor* owner) 
	: SteeringComponent(nullptr, steeringForce, owner, "WanderComponent")
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	srand(time(NULL));
}

MathLibrary::Vector2 WanderComponent::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0,0 };

	//Find the agents position and the direction it's moving in.
	MathLibrary::Vector2 position = getAgent()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 facing = getAgent()->getTransform()->getForward();

	//Find the circle's position in front of the agent.
	m_circlePosition = position + (facing * m_circleDistance);

	//Find a random direction in a unit circle.
	int randomInt = (rand() % 7);
	float randomFloat = (float)(rand()) / (float)(RAND_MAX);
	m_wanderAngle = randomInt + randomFloat;
	
	//Scale the random direction by the size of the circle.
	MathLibrary::Vector2 direction = { (float)cos(m_wanderAngle), (float)sin(m_wanderAngle) };
	direction = direction * m_circleRadius;

	/// <summary>
	/// Add the random vector to the circle
	/// position to get a new random point on the edge of the circle.
	/// </summary>

	MathLibrary::Vector2 seekTarget = direction + m_circlePosition;

	//Seek to the random point.

	MathLibrary::Vector2 directionToTarget = (seekTarget - position).getNormalized();

	MathLibrary::Vector2 wanderForce = directionToTarget * getSteeringForce();

	MathLibrary::Vector2 forceToApply = wanderForce - getAgent()->getMoveComponent()->getVelocity();

	return forceToApply;
}
