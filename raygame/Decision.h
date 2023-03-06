#pragma once

class Agent;

/// <summary>
/// An abstract class for all decisions.
/// </summary>
class Decision
{
public:
	virtual void makeDecision(Agent* owner, float deltaTime) = 0;
};

