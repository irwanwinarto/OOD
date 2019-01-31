// Author: Irwan Winarto
// FILENAME: blurtReps.h
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

/*
Description: 
Generates an edited string based on the chosen output controller. Returns a plain string (not edited) if in state PLAIN.
Returns a repeated string by a set number of times if in state REPEAT. Returns a truncated string if in state TERSE. There is
a set maximum allowable number of PINGs (or calls to the class method Ping) in the private section. Object will turn inactive
if the maximum number of pings is reached and it will no longer return the edited string.
*/


#ifndef blurtReps_h
#define blurtReps_h

#include <stdio.h>
#include <iomanip>
//#include "blurtReps.cpp"

using namespace std;

class blurtReps
{
protected:

    
private:
    const string REP_INACTIVE = "Inactive";
    const string DEAFULT_STRING = "Default";
    const int REP_COUNT = 3;
    const int MAX_STRING_LENGTH = 5;
    const int PING_THRESHOLD = 5;
    
    // states
    const int PLAIN = 1;
    const int REPEAT = 2;
    const int TERSE = 3;
    
    string prvt_string;
    string edited;
    int output_controller;
    bool obj_state;
    int ping_count;
    
    void edit_string();
    
public:
	/*
	static member that serves for bookkeeping purposes, keeping track of active blurtReps objects.
	
	Invariant: active_member will always be bigger or equal to 0.
	*/
    static int active_member;
    
	/*
	no argument Constructor
	Initializes variables to default values.
	
	Postcondition: The number of active blurtRep objects increments by 1.
	Invariants: Object state will always start out as active. Output controller will always start out as PLAIN mode.
	*/
    blurtReps();
    
	/*
	Constructor
	
	Precondition: Passed string must be less than or equal to the maximum allowable length (5).
	Invariantss: Object state will always start out as active. Output controller will always start out as PLAIN mode.
	*/
    blurtReps(string passed_string);
	
    /*
	Returns to the driver the string edited by different outpur controllers.
	
	Precondition: Object must be in active state.
	Postcondition: Object may turn inactive.
	*/
    string Ping();
    
	/*
	writes the passed string into the private string variable.
	
	Precondition: Passed string must be less than or equal to the maximum allowable length (5). Otherwise,
	nothing happens.
	*/
    void set_string(string passed_string);
    
	/*
	Changes the state between 3 different output controllers: PLAIN = 1, REPEAT = 2, and TERSE = 3.
	
	Precondition: Passed integer must be integers 1, 2 or 3. Otherwise, nothing changes.
	Postcondition: The output_controller may change, and the edited string may change.
	*/
    void change_state(int state);
    
	/*
	Returns to the driver the number of times the object's Ping function has been called.
	
	Invariant: The number of pings will never be less than 0.
	*/
    int query_ping();
    
	/*
	Resets variables to default values. The private string will be assigned DEFAULT_STRING.
	
	Postcondition: Inactive objects will become active. The output_controller will turn to PLAIN mode.
	Invariants: Inactive objects will become active. The output_controller will turn to PLAIN mode. PingCount will be
	reset to 0. The private string will always be set to DEFAULT_STRING.
	*/
    void reset();
    
	/*
	Destructor
	*/
    ~blurtReps();
    
    /*
	Copy Constructor
	
	Precondition: Passed object must be of type blurtReps.
	Postcondition: Object state and output_controller may change.
	*/
    blurtReps(const blurtReps& copy);
    
    /*
	method that supports deep copying between blurtReps objects.
	
	Precondition: Passed object must be of type blurtReps.
	Postcondition: Object state and output_controller may change.
	*/
    void copier (const blurtReps& copy);
    
    //OVERLOAD OPERATORS
    
    /*
	Overloaded = operator
	Assigns the left hand side blurtRep object the contents of the right hand side blurtRep object.
	
	Precondition: Passed object must be of type blurtReps. Must not pass itself.
	Postcondition: Object state and output_controller may change.
	*/
    blurtReps& operator=(const blurtReps& rhs);
    
    /*
	Overloaded + operator
	Performs addition between two blurtRep objects.
	
	Precondition: Passed object must be of type blurtReps. Must not pass itself. Total length of string
	must not exceed the maximum allowable length.
	*/
    blurtReps& operator+(const blurtReps& rhs);
    
    /*
	Overloaded == operator
	Checks if the right hand side blurtRep object has the same contents as the left hand side blurtRep object.
	
	Precondition: Passed object must be of type blurtReps. Must not pass itself.
	*/
    bool operator==(const blurtReps& rhs);
    
    /*
	Overloaded != operator
	Checks if the right hand side blurtRep object does not have the same contents as the left hand side blurtRep object.
	
	Precondition: Passed object must be of type blurtReps. Must not pass itself.
	*/
    bool operator!=(const blurtReps& rhs);
    
};



#endif /* blurtReps_h */
