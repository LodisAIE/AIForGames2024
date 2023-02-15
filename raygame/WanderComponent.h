#pragma once
#include "SteeringComponent.h"

class WanderComponent :
    public SteeringComponent
{
public:
    WanderComponent(float circleDistance, float circleRadius, float steeringForce, Actor* owner);
    MathLibrary::Vector2 calculateForce() override;

private:
    float m_circleRadius;
    float m_circleDistance;
    float m_wanderAngle;

    MathLibrary::Vector2 m_circlePosition;
};

