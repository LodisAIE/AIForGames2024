#pragma once
#include "BooleanDecision.h"

class CanIdleDecision :
    public BooleanDecision
{
public:
    CanIdleDecision(Decision* leftChild, Decision* rightChild) : BooleanDecision(leftChild, rightChild) {}

    bool checkCondition(Agent* owner, float deltaTime) override;

private:
    float m_wanderTime = 3;
    float m_currentTime;
};

