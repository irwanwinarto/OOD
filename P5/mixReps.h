// Author: Irwan Winarto
// FILENAME: mixReps.h
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

/*
Description:
The mixReps class contains two blurtRep objects x and z. Two variables, mixCount and preference will determine the class' 
return string to the driver by using either or both blurtRep objects. W
It's return values is also dependent on the state of the blurtRep objects. Inactive objects will return an inactive signal.

*/
#ifndef mixReps_h
#define mixReps_h
#include "blurtReps.h"

class mixReps
{
private:
    const int MAX_PING = 6;
    const int MIX_COUNT_ONE = 1;
    const int MIX_COUNT_TWO = 2;
    const string DEAFULT_STRING = "Default";
    
    int mix_count;
    int preference;
    string name_1;
    string name_2;
    
    blurtReps x;
    blurtReps z;
    /*
	Determines if the number passed is odd or not. Accepts positive and negative values.
	Precondition: Pass in an integer
	*/
    bool is_odd(int num);
    
public:
	/*
	no argument Constructor
	
	Postcondition: DEFAULT_STRING will be used as the encapsulated string.
	Invariants: The state of the objects will always start as true or active. The mixCount always starts at MIX_COUNT_ONE, 
	and the preference always starts at an even number. This results in outputting as only 'z' when neither mixCount or 
	preference is changed before calling mix_the_reps().
	*/
    mixReps();
    
	/*
	constructor
	
	Precondition: name must be 5 characters or less. Otherwise, default strings are used.
	Invariants: The state of the objects will always start as true or active. The mixCount always starts at MIX_COUNT_ONE, 
	and the preference always starts at an even number. This results in outputting as only 'z' when neither mixCount or 
	preference is changed before calling mix_the_reps().
	*/
    mixReps(string name1, string name2);
    
	/*
	Uses conditional statements to determine which blurtRep object(s) to PING.
	
	Precondition: both x and z must be in active state. If any object is inactive, reset this object.
	Postcondition: If PINGed beyond maximum, object(s) may turn inactive.
	*/
    string mix_the_reps();
    
	/*
	toggles between mixCount = 1 and mixCount = 2
	
	Postcondition: mixCount will change to either MIX_COUNT_ONE or MIX_COUNT_TWO 
	*/
    void toggle_mix_count();
    
	/*
	Sets the preferred number
	
	Precondition: Must pass in integer value.
	*/
    void set_preference(int num);
    
	/*
	Calls reset on both objects x and z
	 
	Postcondition: Any inactive object will become active. PrvtString of each remains the same.
	*/
    void reset();
    
	/*
	Destructor
	*/
    ~mixReps();
    
	/*
	Copy Constructor
	
	Precondition: Object to be copied must be of type mixReps.
	Postcondition: State of object may not change.
	*/
    mixReps(const mixReps& copy);
    
    // OVERLOADED OPERATORS
    
	/*
	Overloaded = operator
	
	Precondition: Object to be copied must be of type mixReps.
	Postcondition: State of object may not change.
	*/
    mixReps& operator=(const mixReps &rhs);
    
    // addition +
    mixReps& operator+(const mixReps &rhs);
};

#endif /* mixReps_h */
