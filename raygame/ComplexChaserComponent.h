#pragma once
#include "Component.h"

class SeekComponent;
class WanderComponent;
class Agent;
class Decision;

class ComplexChaserComponent :
    public Component
{
public:
    ComplexChaserComponent(float chaseRange, Actor* target, Actor* owner);

    SeekComponent* getSeekComponent() { return m_seekComponent; }
    WanderComponent* getWanderComponent() { return m_wanderComponent; }

    void update(float deltaTime) override;

private:
    SeekComponent* m_seekComponent;
    WanderComponent* m_wanderComponent;

    Decision* m_root;

    Agent* m_owner;
};

