#pragma once
#include "BooleanDecision.h"

class Actor;

class InRangeDecision :
    public BooleanDecision
{
public:
    InRangeDecision(float chaseRange, Actor* target, Decision* leftChild = nullptr, Decision* rightChild = nullptr);

    bool checkCondition(Agent* owner, float deltaTime) override;

private:
    float m_chaseRange;
    Actor* m_target;
};

