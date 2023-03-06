#pragma once
#include "Decision.h"

class SeekComponent;

class ChaseDecision :
    public Decision
{
public:
    ChaseDecision(SeekComponent* ownerSeekComponent) { m_ownerSeekComponent = ownerSeekComponent; }
    void makeDecision(Agent* owner, float deltaTime);

private: 
    SeekComponent* m_ownerSeekComponent;
};

