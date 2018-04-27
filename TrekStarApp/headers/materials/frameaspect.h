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

    bool operator ==(const FrameAspect& frameAspect){
        if(
                this->horizontalRatio==frameAspect.horizontalRatio &&
                this->verticalRatio==frameAspect.verticalRatio&&
                this->ratioDescription==frameAspect.ratioDescription)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator !=(const FrameAspect& frameAspect){
        if(
                this->horizontalRatio!=frameAspect.horizontalRatio||
                this->verticalRatio!=frameAspect.verticalRatio||
                this->ratioDescription!=frameAspect.ratioDescription)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // FRAMEASPECT_H
