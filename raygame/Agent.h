#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>

class SteeringComponent;
class MoveComponent;

/// <summary>
/// An actor that can be controlled using behaviour components.
/// </summary>
class Agent :
    public Actor
{
public:
    void start() override;
    void update(float deltaTime) override;

    float getMaxForce() { return m_maxForce; }
    void setMaxForce(float maxForce) { m_maxForce = maxForce; }

    MoveComponent* getMoveComponent() { return m_moveComponent; }

private:
    DynamicArray<SteeringComponent*> m_steeringComponents;
    MoveComponent* m_moveComponent;

    float m_maxForce;
    MathLibrary::Vector2 m_force;
};

