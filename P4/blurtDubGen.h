// AUTHOR: Irwan Winarto
// FILENAME: blurtDubGen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef blurtDubGen_h
#define blurtDubGen_h

#include <stdio.h>
#include <string>
#include "blurtReps.h"
#include "dubGen.h"

/*
 * blurtDubGen(): constructor.
 * Ping(): calls blurtRep's Ping() function and dubGen's GimmeSequence() function and concatenates the return values into a string type. Checks to see if any states are inactive and returns the appropriate string to the driver. High dependency on blurtReps and dubGen class.
 * GimmeSequence(): echoes blurtReps' GimmeSequence() function. High dependency on blurtReps.
 * doubleThis(int): echoes dubGen's doubleThis(int) functin. High dependency on dubGen.
 * ~blurtDubGen(): destrutor.
 */

class blurtDubGen : public blurtReps, public dubGen
{
protected:
private:
public:
    
    blurtDubGen();
    
    // pre: gens and blurtReps must be in active state
    // post: may change gens or blurtReps to inactive
    virtual string Ping();
    
    // pre: gen(s) must be active
    virtual float GimmeSequence();
    
    // pre: gen must be active
    virtual float DoubleThis(int pos);
    
    ~blurtDubGen();
};

#endif /* blurtDubGen_h
*/
