#pragma once
#include "Component.h"
#include <Vector2.h>

class Agent;

class SteeringComponent :
    public Component
{
public:
    SteeringComponent();
    SteeringComponent(Actor* target, float steeringForce, Actor* owner, const char* name);

    virtual MathLibrary::Vector2 calculateForce() = 0;

    /// <summary>
    /// Gets the magnitude of the force that will be applied by the component.
    /// </summary>
    float getSteeringForce() { return m_steeringForce; }
    /// <summary>
    /// Sets the magnitude of the force that will be applied by the component.
    /// </summary>
    /// <param name="steeringForce">The new magnitude of the steering force.</param>
    void setSteeringForce(float steeringForce) { m_steeringForce = steeringForce; }

    /// <summary>
    /// Returns the target that will be used to calculate the steering force.
    /// </summary>
    Actor* getTarget() { return m_target; }
    /// <summary>
    /// Sets the target that will be used to calculate the steering force.
    /// </summary>
    void setTarget(Actor* target) { m_target = target; }

    /// <summary>
    /// Gets the owner of this component and attempts to cast it as an agent.
    /// </summary>
    Agent* getAgent() { return (Agent*)getOwner(); }
private:
    float m_steeringForce = 0;
    Actor* m_target = nullptr;
};

