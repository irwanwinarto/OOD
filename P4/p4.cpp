// AUTHOR: Irwan Winarto
// FILENAME: main.cpp
// DATE: 2/22/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, cplusplus,

#include <iostream>
#include <iomanip>
#include "gen.h"
#include "dubGen.h"
#include "skipGen.h"
#include "blurtReps.h"
#include "blurtGen.h"
#include "blurtSkipGen.h"
#include "blurtDubGen.h"

using namespace std;
/*
 * p4 uses global variables, each to help determine which type of object to be placed in each heterogeneous collection space. They are of int types and should use numbers that do not have 2 or 3 as common multiples because 6%2 = 6%3 = 0. "Pickers" are incremented by 1 each time a new object is returned to the main.
 * Different types of heterogeneous collections with different base classes are explained below
 */

/* blurtReps base
 * Each object's outputController will be changed after each Ping(). outputController will start from Plain then to Repeat then to Terse. Any changes after this will not change anything. We will only see the different types of outputs in the first 3 values of the sequence.
 * Each object will be Ping()-ed as many times as the value specified by testNum.
 * Object will return "Inactive," when the number of Pings is at maximum (default of 5).
 * blurtReps object will not have concatenated values.
 order:
 blurtGen
 blurtDubGen
 blurtSkipGen
 blurtDubGen
 blurtReps
 */

/* gen base
 * Every object in the collection will skip the position specified by skipThisSum and double the value of the position specified by doubleThisNum.
 * The for loop gets the next value in the internalized arithmetic sequence of each object by the number specified by testNum and the output is checked if they are inactive or skipped. They will be assigned respective outputs to the controller.
 * Each object's state will be toggled after every call to the arithmetic sequence generator and is expected to return an "Inactive," indicator the state of the object is off.
 order:
 blurtGen
 blurtDubGen
 blurtSkipGen
 blurtDubGen
 gen
 */

blurtReps* blurtBaseObjAddr();
gen* genBaseObjAddr();

int picker_1 = 1;
int picker_2 = 1;

int main(int argc, const char * argv[])
{
    const int isInactive = -1;
    const int isSkipped = -2;
    const int coll_size = 5;
    string inactive = "Inactive, ";
    string skipped = "Skipped, ";
    float temp = 0;
    int testNum = 8;
    int skipThisNum = 5;
    int doubleThisNum = 4;
    int outputControl = 0;
    

    blurtReps* collection_1[coll_size];
    gen* collection_2[coll_size];
    
    // Fill in Heterogeneous Collections
    for(int i = 0; i < coll_size; i++)
    {
        collection_1[i] = blurtBaseObjAddr();
        collection_2[i] = genBaseObjAddr();
    }
    
    // blurtReps base
    for(int j = 0; j < coll_size; j++)
    {
        outputControl++;
        collection_1[j]->ChangeState(outputControl);
        for(int i = 0; i < testNum; i++)
            cout << collection_1[j]->Ping() << ", ";
        cout << endl << endl;
    }
    cout << endl;
    
    // gen base
    for(int j = 0; j < coll_size; j++)
    {
        collection_2[j]->skipPosition(skipThisNum);
        collection_2[j]->DoubleThis(doubleThisNum);
        for(int i = 0; i < testNum; i++)
        {
            temp = collection_2[j]->GimmeSequence();
            if((int)temp == isInactive)
                cout << inactive;
            else if((int)temp == isSkipped)
                cout << skipped;
            else
                cout << temp << ", ";
            collection_2[j]->ToggleState();
        }
        cout << endl << endl;
    }
    cout << endl;
    
    
    
    // Memory Management
    for(int i = 0; i< coll_size; i++)
    {
        delete collection_1[i];
        delete collection_2[i];
    }
    return 0;
}

// pre: picker_1 should use numbers that do not have 2 or 3 as common multiples
// post: none
blurtReps* blurtBaseObjAddr()
{
    if(picker_1%2 == 0){
        picker_1++;
        return new blurtDubGen;
    }
    else if(picker_1%3 == 0){
        picker_1++;
        return new blurtSkipGen;
    }
    else if(picker_1%5 == 0){
        picker_1++;
        return new blurtReps;
    }
    else{
        picker_1++;
        return new blurtGen;
    }
    
}

// pre: picker_2 should use numbers that do not have 2 or 3 as common multiples
// post: none
gen* genBaseObjAddr()
{
    if(picker_2%2 == 0){
        picker_2++;
        return new blurtDubGen;
    }
    else if(picker_2%3 == 0){
        picker_2++;
        return new blurtSkipGen;
    }
    else if(picker_2%5 == 0){
        picker_2++;
        return new gen;
    }
    else{
        picker_2++;
        return new blurtGen;
    }
}