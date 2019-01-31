// AUTHOR: Irwan Winarto
// FILENAME: dubGen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "dubGen.h"
#include "gen.h"

// pre: none
// post: none
dubGen:: dubGen()
{
    p = 1;
    multiplier = 2;
}

// pre: position to be doubled must be bigger or equal to current position.
// post: none
float dubGen:: DoubleThis(int pos)
{
    float doubledValue;
    p = pos;
    doubledValue = doMath(p) * multiplier;
    return doubledValue;
}

// pre: ensure position to be doubled be greater or equal to current position.
// post: none.
float dubGen:: GimmeSequence()
{
    float ans = 0;
    if (position == p)
    {
        ans = DoubleThis(position);
        position++;
        return ans;
    }
    else
    {
        ans = doMath(position);
        position++;
        return ans;
    }
}


dubGen:: ~dubGen()
{
    
}