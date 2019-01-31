// AUTHOR: Irwan Winarto
// FILENAME: blurtDubGen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "blurtDubGen.h"
#include <string>

// pre: none
// post: none
blurtDubGen:: blurtDubGen()
{
    
}

// pre: gens and blurtReps must be in active state
// post: may change gens or blurtReps to inactive
string blurtDubGen:: Ping()
{
    string word="";
    float num=0;
    
    word = blurtReps::Ping();
    num = dubGen::GimmeSequence();
    if(word != repInactive)
        return word + " " + to_string(num);
    else
        return word;
}

// pre: gen(s) must be active
// post: none
float blurtDubGen:: GimmeSequence()
{
    return dubGen:: GimmeSequence();
}

// pre: gen must be active
float blurtDubGen:: DoubleThis(int pos)
{
    return dubGen:: DoubleThis(pos);
}

// pre: none
// post: none
blurtDubGen:: ~blurtDubGen()
{
    
}