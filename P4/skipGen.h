// AUTHOR: Irwan Winarto
// FILENAME: skipGen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef skipGen_h
#define skipGen_h

#include <stdio.h>
#include "gen.h"

/*
 * skipGen() initializes variables.
 * GimmeSequence(): returns successive values in the arithmetic sequence, and takes into account the position that was specified to be skipped. Depends on skipPosition(int) to know which position to be skipped. Otherwise, it uses the default position.
 * skipPosition(int): intializes a variable that lets GimmeSequence() know which position to be skipped in the sequence.
 */

class skipGen : public gen
{
protected:
    const std::string returnSkipped = "Skipped. ";
private:
    int skipThis = 0;
    int stateCount = 0;
    int threshold = 0;
    
public:
    // pre: object declared
    // post: none
    skipGen();
    
    // pre: ensure position to be skipped is bigger or equal to current position
    // post: position number will change?
    virtual float GimmeSequence();
    
    // pre: position to be skipped must be bigger or equal to current position
    // post: none? or variable changed?
    virtual void skipPosition(int k);
    
    // Should ChangeState be virtual? Or do we just use the Base class ChangeState?
};

#endif /* skipGen_h */