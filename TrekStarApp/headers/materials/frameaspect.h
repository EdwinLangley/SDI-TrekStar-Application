#ifndef FRAMEASPECT_H
#define FRAMEASPECT_H

#include "main.h"

using namespace std;

class FrameAspect
{

private:
    int horizontalRatio = 0;
    int verticalRatio = 0;
    string ratioDescription = "";


public:
    FrameAspect();
    FrameAspect(int horizontalRatio, int verticalRatio, string ratioDescription);
    unsigned int getHorizontalRatio() const;
    void setHorizontalRatio(unsigned int value);
    unsigned int getVerticalRatio() const;
    void setVerticalRatio(unsigned int value);
    string getRatioDescription() const;
    void setRatioDescription(const string &value);
    string getFrameAspect();
};

#endif // FRAMEASPECT_H
