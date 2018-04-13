#ifndef FRAMEASPECT_H
#define FRAMEASPECT_H

#include "main.h"

using namespace std;

class FrameAspect
{

private:
    unsigned int horizontalRatio = 0;
    unsigned int verticalRatio = 0;
    string ratioDescription = "";


public:
    FrameAspect();
    unsigned int getHorizontalRatio() const;
    void setHorizontalRatio(unsigned int value);
    unsigned int getVerticalRatio() const;
    void setVerticalRatio(unsigned int value);
    string getRatioDescription() const;
    void setRatioDescription(const string &value);
};

#endif // FRAMEASPECT_H
