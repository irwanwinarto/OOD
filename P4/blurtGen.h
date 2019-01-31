// AUTHOR: Irwan Winarto
// FILENAME: blurtGen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef blurtGen_h
#define blurtGen_h

#include <stdio.h>
#include "blurtReps.h"
#include "gen.h"

/*
 blurtGen will generate a sequence of numbers and string...
 * blurtGen(): constructor
 * Ping(): calls blurtRep's Ping() function and gen's GimmeSequence() function and concatenates the return values into a string type. Checks to see if any states are inactive and returns the appropriate string to the driver. High dependency on blurtReps and gen class.
 * GimmeSequence(): echoes blurtReps' GimmeSequence() function. High dependency on blurtReps.
 * ~blurtGen(): destructor
 */
class blurtGen : public blurtReps, public gen
{
private:
public:
    
    // pre:
    // post:
    blurtGen();
    
    // pre: all objects must be active
    // post: none.
    virtual string Ping();
    
    // pre: gen must be active
    // post: gen state may turn inactive due to exceeding maximum allowable ping
    virtual float GimmeSequence();
    
    // pre:
    // post:
    ~blurtGen();
};

#endif /* blurtGen_h */
