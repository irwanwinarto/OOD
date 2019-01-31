// AUTHOR: Irwan Winarto
// FILENAME: blurtSkipGen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "blurtSkipGen.h"

// pre:
// post:
blurtSkipGen:: blurtSkipGen()
{
    
}

// pre: blurtReps and skipGen should be Active
// post: may change the states of the blurtReps' and skipGen's states
string blurtSkipGen:: Ping()
{
    string word="";
    float num=0;
    
    word = blurtReps::Ping();
    num = skipGen::GimmeSequence();
    if(word != repInactive && num != inactive && num != skipped)
        return word + " " + to_string(num);
    else if(num == skipped)
        return returnSkipped;
    else if(num == inactive)
        return inactiveThis;
    else
        return word;
}

// pre: skipGen must be active
// post:
float blurtSkipGen:: GimmeSequence()
{
    return skipGen:: GimmeSequence();
}

// pre: position must be valid (positive number)
// post: none
void blurtSkipGen:: skipPosition(int k)
{
    skipGen:: skipPosition(k);
}

// pre:
// post:
blurtSkipGen:: ~blurtSkipGen()
{
    
}
