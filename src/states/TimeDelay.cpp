#include "TimeDelay.h"

void TimeDelay::Update(int deltaMS)
{
    mElapsedMS += deltaMS;
}

bool TimeDelay::IsFinished()
{
    return mElapsedMS >= mDelayMS;
}
