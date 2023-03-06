#pragma once
#include "Decision.h"

class IdleDecision :
    public Decision
{
public:
    void makeDecision(Agent* owner, float deltaTime);
};

