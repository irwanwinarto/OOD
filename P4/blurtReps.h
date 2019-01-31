// AUTHOR: Irwan Winarto
// FILENAME: blurtReps.h
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#ifndef blurtReps_h
#define blurtReps_h

#include <stdio.h>
#include <iomanip>

using namespace std;

// Invariants: no maximum number of state changes.
/*
 * blurtReps(): initializes variables
 * setString(string): specify a specified string to use. Saved into prvtString if conditions met.
 * EditString(): Depending on outputController, changes 'edited' variable according to the following states: Plain, Repeat, or Terse. Repeat depends on repCount variable to determine the number of times to repeat the string and Terse truncates the last character of the string.
 * Ping(): calls EditString() when conditions are met and returns the edited string to the driver.
 * ChangeState(int): changes the type of output (outputContoller) to 1=Plain, 2=Repeat, and 3=Terse.
 * QueryPing(): returns to the driver the number of times the object's Ping() function has been called.
 * ~blurtReps(): destructor.
 */

class blurtReps
{
protected:
    const string repInactive = "Inactive";
    
private:
    int repCount = 3;
    int strLength = 0;
    string defaultString;
    
    string prvtString = "";
    int outputController;
    bool objState;
    int pingThreshold = 0;
    int pingCount = 0;
    string edited = "";
    
public:
    // pre: none
    // post: none.
    blurtReps();
    
    // pre: string length must not exceed limit (5)
    // post: string may be set to null/..........
    void setString(string passedString);
    
    // pre: prvtString must not be null or empty
    // post: none
    void EditString();
    
    // pre: object must be in active state, ping count must not exceed threshold.
    // post: objState may turn inactive.
    virtual string Ping();
    
    // pre: none
    // post: outputController will change. This will change the type of output.
    virtual void ChangeState(int state);
    
    // pre: none. pingCount doesn't have to be bigger than 0, righttt???
    // post: none.
    const int QueryPing();
    
    virtual ~blurtReps();
};


#endif /* blurtReps_h
*/
