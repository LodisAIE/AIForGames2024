#pragma once
#include "Component.h"

class StateMachineComponent;
class WanderComponent;
class SeekComponent;
class MoveComponent;
class Agent;

class ChaserComponent :
    public Component
{
public: 
    ChaserComponent(float chaseRange, Actor* target, Actor* owner);

    SeekComponent* getSeekComponent() { return m_seekComponent; }
    Actor* getTarget();

    WanderComponent* getWanderComponent() { return m_wanderComponent; }

    float getChaseRange() { return m_chaseRange; }
    void setChaseRange(float range) { m_chaseRange = range; }

    float getSeekForce() { return m_seekForce; }
    void setSeekForce(float seekForce) { m_seekForce = seekForce; }

    float getWanderForce() { return m_wanderForce; }
    void setWanderForce(float wanderForce) { m_wanderForce = wanderForce; }

    void update(float deltaTime) override;

private:
    StateMachineComponent* m_stateMachine;

    Agent* m_agent;

    SeekComponent* m_seekComponent;
    WanderComponent* m_wanderComponent;
    MoveComponent* m_moveComponent;

    float m_wanderTime = 3;
    float m_currentTime;

    float m_seekForce = 50;

    float m_wanderForce = 100;
    float m_wanderCircleRadius = 100;
    float m_wanderCircleDistance = 100;

    float m_chaseRange;
};

