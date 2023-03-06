#include "BooleanDecision.h"

BooleanDecision::BooleanDecision(Decision* leftChild, Decision* rightChild)
{
	m_no = leftChild;
	m_yes = rightChild;
}

void BooleanDecision::makeDecision(Agent* owner, float deltaTime)
{
	bool result = checkCondition(owner, deltaTime);

	if (result && m_yes)
		m_yes->makeDecision(owner, deltaTime);
	else if (!result && m_no)
		m_no->makeDecision(owner, deltaTime);
}
