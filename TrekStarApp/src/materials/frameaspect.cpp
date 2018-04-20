#include "frameaspect.h"

unsigned int FrameAspect::getHorizontalRatio() const
{
    return horizontalRatio;
}

void FrameAspect::setHorizontalRatio(unsigned int value)
{
    horizontalRatio = value;
}

unsigned int FrameAspect::getVerticalRatio() const
{
    return verticalRatio;
}

void FrameAspect::setVerticalRatio(unsigned int value)
{
    verticalRatio = value;
}

string FrameAspect::getRatioDescription() const
{
    return ratioDescription;
}

void FrameAspect::setRatioDescription(const string &value)
{
    ratioDescription = value;
}

FrameAspect::FrameAspect()
{

}

FrameAspect::FrameAspect(int horizontalRatio, int verticalRatio, string ratioDescription)
{

}

string FrameAspect::getFrameAspect()
{
    string frameAspect;
    frameAspect.append(to_string(this->horizontalRatio));
    frameAspect.append(",");
    frameAspect.append(to_string(this->verticalRatio));
    frameAspect.append(",");
    frameAspect.append(this->ratioDescription);
    return frameAspect;
}
