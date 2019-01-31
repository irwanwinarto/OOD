// AUTHOR: Irwan Winarto
// FILENAME: skipGen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "skipGen.h"

// pre: object declared
// post: none
skipGen:: skipGen()
{
    skipThis = 2;
    ChgThreshold= 1;  //CHANGE THIS or just change in gen.hpp
    stateCount = 0;
}

// pre: ensure position to be skipped is bigger or equal to current position
// post: position number will change?
float skipGen:: GimmeSequence()
{
    float ans = 0;
    if(state)
    {
        if(position == 0 || position == 1 || position == skipThis)
        {
            position++;
            return skipped;
        }
        else
        {
            ans = doMath(position);
            position++;
            return ans;
        }
    }
    else
    {
        position++;
        return inactive;
    }
}

// pre: position to be skipped must be bigger or equal to current position
// post: none? or variable changed?
void skipGen:: skipPosition(int k)
{
    skipThis = k;
}

// Should ChangeState be virtual? Or do we just use the Base class ChangeState?