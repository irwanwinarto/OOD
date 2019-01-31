// AUTHOR: Irwan Winarto
// FILENAME: dubGen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef dubGen_h
#define dubGen_h

#include <stdio.h>
#include "gen.h"

/*
 * dubGen(): initializes variables
 * DoubleThis(int): doubles the value in the position specified of the sequence.
 * GimmeSequence(): returns successive values in the arithmetic sequence, taking into consideration the position which was doubled in value.
 ~dubGen(): destructor.
 */

class dubGen : public gen
{
    
private:
    int p; // Position to be doubled
    float multiplier;
    
public:
    dubGen();
    
    // pre: position must be valid (positive integer)
    // post: none
    virtual float DoubleThis(int pos);
    
    // pre: position to be doubled must be greater or equal to current position.
    // post: none
    virtual float GimmeSequence();

    ~dubGen();
};

#endif /* dubGen_h */