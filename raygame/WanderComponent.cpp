#include "WanderComponent.h"
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

	//Find the circle's position in front of the agent.

	//Find a random direction in a unit circle.
	int randomInt = (rand() % 6);
	float randomFloat = (float)(rand()) / (float)(RAND_MAX);
	float randomAngle = randomInt + randomFloat;
	
	//Scale the random direction by the size of the circle.

	/// <summary>
	/// Add the random vector to the circle
	/// position to get a new random point on the edge of the circle.
	/// </summary>


	//Seek to the random point.


	return MathLibrary::Vector2();
}
