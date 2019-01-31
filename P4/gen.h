// AUTHOR: Irwan Winarto
// FILENAME: gen.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef gen_h
#define gen_h

#include <stdio.h>
#include <iomanip>

/*
 * gen(): initializes variables.
 * doMath(): gets a value from a position in the sequence.
 * doMath(pos) gets the value from the specified position in the sequence.
 * GimmeSequence(): successively returns a value from the sequence beginning from 0.
 * ToggleState(): changes current state from Active to Inactive and vice versa.
 * Reset(): Reinitializes changeable variables to default values.
 * skipPosition(): empty function (nop).
 * doubleThis(): empty function (nop).
 */

class gen
{
protected:
    float a1 = 0;
    float constant = 0;
    unsigned int position = 0;
    bool state = true;
    unsigned int ChgCount = 0;
    unsigned int ChgThreshold;
    const int inactive = -1;
    const int skipped = -2;
    const std::string inactiveThis = "genInactive.";

private:
    int n;
    int m;
    int default_value;
    bool originalState;
    
public:
    // pre: none
    // post: object initialization.
    gen();
    
    // pre: none
    // post: none
    float doMath();
    
    // pre: position must be a positive number
    // post: value of starting position (n) may change
    float doMath(int pos);
    
    // pre: variables initialized? or none?
    // post: position number may be incremented by 1.
    virtual float GimmeSequence();
    
    // pre: none
    // post: state variable will change.
    virtual void ToggleState();
    
    // pre: position not 0. It's fine if it is, though.
    // post: position will become 0.
    virtual void Reset();
    
    //empty functions
    
    // pre: none
    // post: none
    virtual void skipPosition(int k);
    
    // pre: position must be valid (positive integer)
    // post: none
    virtual float DoubleThis(int pos);
    
    virtual ~gen();
    
    
};

#endif /* gen_h */