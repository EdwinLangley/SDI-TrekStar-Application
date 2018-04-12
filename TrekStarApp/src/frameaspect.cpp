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
