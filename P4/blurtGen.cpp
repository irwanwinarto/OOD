// AUTHOR: Irwan Winarto
// FILENAME: blurtGen.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "blurtGen.h"

// pre:
// post:
blurtGen:: blurtGen()
{
    
}

// pre: parent class must work..
// post: none.
string blurtGen:: Ping()
{
    string word="";
    float num=0;
    
    word = blurtReps::Ping();
    num = gen::GimmeSequence();
    if(word != repInactive && num != inactive)
        return word + " " + to_string(num);
    else if (num == inactive)
        return inactiveThis;
    else
        return word;
}

// pre: gen must be active
// post: gen state may turn inactive due to exceeding maximum allowable ping
float blurtGen:: GimmeSequence()
{
    return gen:: GimmeSequence();
}

// pre:
// post:
blurtGen:: ~blurtGen()
{
    
}