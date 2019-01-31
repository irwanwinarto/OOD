// AUTHOR: Irwan Winarto
// FILENAME: blurtSkipGen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef blurtSkipGen_h
#define blurtSkipGen_h

#include <stdio.h>
#include <string>
#include "blurtReps.h"
#include "skipGen.h"

/*
 * blurtSkipGen(): constructor.
 * Ping(): calls blurtRep's Ping() function and skipGen's GimmeSequence() function and concatenates the return values into a string type. Checks to see if any states are inactive and returns the appropriate string to the driver. High dependency on blurtReps and skipGen class.
 * GimmeSequence(): echoes blurtReps' GimmeSequence() function. High dependency on blurtReps.
 * skipPosition(int): echoes skipGen's skipPosition(int) function. High dependency on skipGen.
 * ~blurtSkipGen(): destructor.
 */

class blurtSkipGen : public blurtReps, public skipGen
{
protected:
private:
public:
    
    blurtSkipGen();
    
    // pre: blurtReps and skipGen should be Active
    // post: may change the states of the blurtReps' and skipGen's states
    virtual string Ping();
    
    // pre: skipGen must be active
    virtual float GimmeSequence();
    
    // pre: position must be valid (positive number)
    virtual void skipPosition(int k);

    ~blurtSkipGen();
};

#endif /* blurtSkipGen_h */
