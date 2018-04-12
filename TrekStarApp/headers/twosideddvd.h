#ifndef TWOSIDEDDVD_H
#define TWOSIDEDDVD_H

#include <string>
#include "dvd.h"

using namespace std;

class TwoSidedDVD : public DVD
{
private:
    string secondSideContent = "";

public:
    TwoSidedDVD();
    string getSecondSideContent() const;
    void setSecondSideContent(const string &value);
};

#endif // TWOSIDEDDVD_H
