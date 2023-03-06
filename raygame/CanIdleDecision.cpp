#include "CanIdleDecision.h"

bool CanIdleDecision::checkCondition(Agent* owner, float deltaTime)
{
    if (m_currentTime >= m_wanderTime)
    {
        m_currentTime = 0;
        return true;
    }

    m_currentTime += deltaTime;
    return false;
}
