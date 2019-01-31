// AUTHOR: Irwan Winarto
// FILENAME: gen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "gen.h"
#include <string>

/*
 * 
 */

// pre: none
// post: none
gen:: gen()
{
    default_value = 0;
    a1 = 0;
    constant = 1;
    n = 0;
    m = 0;
    state = true;
    position = 0;
    ChgCount = 0;
    ChgThreshold = 3;
    originalState = state;
}

// pre: gen should be in valid state
// post: none
float gen:: doMath()
{
    if (state)
    {
        float an = 0;
        an = a1 + (n - m) * constant;
        return an;
    }
    else
        return inactive;
}

// pre: gen should be in valid state
// post: value of starting position (n) may change
float gen:: doMath(int pos)
{
    if(state)
    {
        float an = 0;
        n = pos;        // we don't even need to do this. Just use pos directly. think about it.
        an = a1 + (n - m) * constant;
        return an;
    }
    else
        return inactive;
}

// pre: gen should be in valid state
// post: postion value increases by 1
float gen:: GimmeSequence()
{
    if(state)
    {
        float an = 0;
        an = a1 + position * constant;
        position++;
        return an;
    }
    else
        return inactive;
}

// pre: none
// post: state variable will change.
void gen:: ToggleState()
{
    ChgCount++;
    if (ChgCount <= ChgThreshold)
    {
        state = !state;
    }
}

// pre: none
// post: none
void gen:: Reset()
{
    position = default_value;
    state = originalState;
    ChgCount = default_value;
}

// empty function (nop)
// pre: none
// post: none
void gen:: skipPosition(int k)
{
    int x;
}

// empty function (nop)
// pre: none
// post: none
float gen:: DoubleThis(int pos)
{
    int x;
    return 0;
}

gen:: ~gen()
{
    
}