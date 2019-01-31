// AUTHOR: Irwan Winarto
// FILENAME: blurtReps.cpp
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

#include "blurtReps.h"

// pre: must be called
// post: none.
blurtReps:: blurtReps()
{
    outputController = 1;
    objState = true;
    
    pingThreshold = 5;
    pingCount = 0;
    repCount = 3;
    strLength = 5;
    
    defaultString = "Default";
    prvtString = defaultString;
    edited = defaultString;
    
}

// pre: prvtString must not be null or empty
// post: none

// MAKE PRIVATE
void blurtReps:: EditString()
{
    if(outputController ==1)        // Plain
    {
        edited = prvtString;
    }
    else if(outputController == 2)  // Repeat
    {
        string mask = prvtString;
        for (int i = 0; i < repCount - 1; i++)
            mask = mask + prvtString;
        
        edited = mask;
    }
    else if(outputController == 3)  // Terse
    {
        int stringLength = (int) prvtString.length();
        string terse = prvtString.substr(0, stringLength-1);
        
        edited = terse;
    }
}

// pre: string must be less than maximum length
// post: none
void blurtReps:: setString(string passedString)
{
    if(passedString.length() < strLength+1)
    {
        prvtString = passedString;
    }
    else
        prvtString = "";
}

// pre: must pass in a valid string that meets conditions
// post: objState may turn inactive.
string blurtReps:: Ping()
{
    if(objState)
    {
        pingCount++;
        
        if(pingCount < pingThreshold+1)
        {
            EditString();
            return edited;
        }
        else
        {
            // Exceeded the allowable number of pings.
            objState = false;
            return repInactive;
        }
    }
    else
    {
        // Object is inactive.
        return repInactive;
    }
}

// pre: none
// post: outputController will change. This will change the type of output.
void blurtReps:: ChangeState(int state)
{
    outputController = state;
}

// pre: none. pingCount doesn't have to be bigger than 0, righttt???
// post: none.
const int blurtReps:: QueryPing()
{
    return pingCount;
}

// pre: none
// post: no more class
blurtReps:: ~blurtReps()
{
    
}