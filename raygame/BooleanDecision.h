#pragma once
#include "Decision.h"

/// <summary>
/// A decision that can have up to two children.
/// </summary>
class BooleanDecision :
    public Decision
{
public:
    /// <param name="leftChild">The decision that will happen when this condition is false.</param>
    /// <param name="rightChild">The decision that will happen when this condition is true.</param>
    BooleanDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

    /// <summary>
    /// Checks the condition and transitions to a different decision based on the value of the condition.
    /// </summary>
    /// <param name="owner">The agent that this tree is making decisions for.</param>
    /// <param name="deltaTime">The time that has passed between this frame and the last.</param>
    virtual void makeDecision(Agent* owner, float deltaTime) override;

    /// <summary>
    /// Checks if a certain condition has been met and returns the result.
    /// </summary>
    /// <param name="owner">The agent that this tree is making decisions for.</param>
    /// <param name="deltaTime">The time that has passed between this frame and the last.</param>
    virtual bool checkCondition(Agent* owner, float deltaTime) = 0;

private:
    Decision* m_no;
    Decision* m_yes;
};

