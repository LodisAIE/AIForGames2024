#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent :
    public Component
{
public:
    MoveComponent() : Component::Component() {}

    /// <summary>
    /// Gets the current speed and direction of this actor.
    /// </summary>
    MathLibrary::Vector2 getVelocity() { return m_velocity; }

    /// <summary>
    /// Sets the current speed and direction of this actor.
    /// </summary>
    void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

    /// <summary>
    /// Gets the maximimum magnitude of this actors velocity.
    /// </summary>
    float getMaxSpeed() { return m_maxSpeed; }
    /// <summary>
    /// Sets the maximimum magnitude of this actors velocity.
    /// Actors cannot move faster than the given value.
    /// </summary>
    void setMaxSpeed(float speed) { m_maxSpeed = speed; }

    /// <summary>
    /// Gets whether or not this actor will rotate towards the direction its heading.
    /// </summary>
    bool getUpdateFacing() { return m_updateFacing; }
    /// <summary>
    /// Sets whether or not this actor will rotate towards the direction its heading.
    /// </summary>
    void setUpdateFacing(bool updateFacing) { m_updateFacing = updateFacing; }

    void update(float deltaTime) override;

private:
    MathLibrary::Vector2 m_velocity;
    float m_maxSpeed;
    bool m_updateFacing;
};

