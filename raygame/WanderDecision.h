#pragma once
#include "Decision.h"

class WanderComponent;

class WanderDecision :
    public Decision
{
public:
    WanderDecision(WanderComponent* ownerSeekComponent) { m_ownerWanderComponent = ownerSeekComponent; }
    void makeDecision(Agent* owner, float deltaTime);

private:
    WanderComponent* m_ownerWanderComponent;
};

