// Author: Irwan Winarto
// FILENAME: cohortReps.h
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

/*
The cohortReps class is a cohort of blurtRep objects. It is responsible for adding and removing blurtRep objects
into an array, essentially keeping track of them.
It keeps track of ALL blurtRep objects, even those called inside other classes. It also keeps track of blurtReps objects
that are inside the cohorts array. It can only admit a maximum number of blurtRep objects.
*/

#ifndef cohortReps_h
#define cohortReps_h

#include <stdio.h>
#include <iomanip>
#include "blurtReps.h"

using namespace std;

class cohortReps
{
private:
    const int REPS_TO_TRACK = 5;
    const string REP_INACTIVE = "Inactive";
    const string DEFAULT_STRING = "default";
    int size;
    int num_of_dummies;
    blurtReps cohorts[5];   // wouldn't allow me to initialize using REPS_TO_TRACK
    blurtReps dummy;
    
public:
	/*
	no argument Constructor
	
	Postcondition: If PINGed beyond maximum, object(s) may turn inactive.
	Invariants: There are always the maximum number of blurtRep objects allowed inside the array. Each object is assigned
	an empty string. If no changes are made to their private strings, they remain as "". And they are all initially active.
	*/
    cohortReps();
    
	/*
	Returns to the driver the number of active blurtRep objects in the driver.
	Dependent on the active_count static int variable inside the blurtReps class.
	*/
    int num_active();
    
	/*
	Returns to the driver the number of blurtRep objects inside the cohort array.
	*/
    int num_in_cohort();
    
	/*
	Adds blurtRep objects into the cohorts array.
	
	Precondition: Passed parameter must be of type blurtReps.
	Postcondition: If the cohorts array is full, the passed object will not be added.
	
	Invariants: The size of the cohorts array is fixed.
	*/
    void adder(const blurtReps& obj);
    
	/*
	Removes blurtRep objects from the cohorts array.
	
	Precondition: Array must not be empty. Passsed parameter must be of blurtReps type.
	Postcondition: The array may become empty.
	
	Invariants: the size of the array is fixed.
	*/
    void remover(blurtReps obj);
    
	/*
	Returns to the driver the concatenated string of all the active blurtReps objects that are inside the cohorts array.
	
	Precondition: Objects must not be inactive. 
	Postcondition: Inactive objects may not be concatenated.
	*/
    string concatenated_string();
    
    /*
	Method to support deep copying between cohortReps types
	
	Precondition: Passed parameter must be of type cohortReps. Do not pass in itself.
	Postcondition: Private string may change. Inactive objects may become active.
	*/
    void cohort_copier(const cohortReps& copy);
    
    /*
	Destructor
	*/
    ~cohortReps();
    
    /*
	Copy Constructor.
	Method to support deep copying between cohortReps types
	
	Precondition: Passed parameter must be of type cohortReps. Do not pass in itself.
	*/
    cohortReps(const cohortReps& copy);
    
    
     // OVERLOADED OPERATORS===================================
    
    /*
	Overloaded == operator
	Determines whether two cohortReps objects are equal. This method is dependent on deep copying methods of blurtReps class.
	
	Precondition: Passed parameter must be of type cohortReps. Do not pass in itself.
	*/
    bool operator==(const cohortReps& rhs);
    
    /*
	Overloaded = operator
	Assigns the left hand side cohortReps object the contents of the right hand side cohortReps content. 
	This method is dependent on deep copying methods of blurtReps class.
	
	Precondition: Passed parameter must be of type cohortReps. Do not pass in itself.
	*/
    cohortReps& operator=(const cohortReps& rhs);
    
    /*
	Overloaded + operator
	Addition of contens of two blurtReps objects. 
	This method is dependent on deep copying methods of blurtReps class.
	
	Precondition: Passed parameter must be of type cohortReps. Do not pass in itself. Do not pass in cohortRep objects 
	whose size when added with the left hand side's size exceeds the maximum number of objects allowed in the cohorts array.
	Otherwise, nothing will happen.
	*/
    cohortReps& operator+(const cohortReps& rhs);
    
    /*
	Overloaded + operator
	Addition of cohortRep object and blurtRep object. 
	This method is dependent on the overloaded = operator of the blurtReps class.
	
	Precondition: Passed parameter must be of type blurtreps class.
	*/
    cohortReps& operator+(const blurtReps& rhs);
    
    
    
    
    
};

#endif /* cohortReps_h */
