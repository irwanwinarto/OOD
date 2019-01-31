// Author: Irwan Winarto
// FILENAME: cohortReps.cpp
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

#include <stdio.h>
#include <iostream>
#include "cohortReps.h"

cohortReps:: cohortReps()
{
    size = 0;
    num_of_dummies = 1;
    
    // initialize array with "dummy"
    dummy.set_string("");
    for(int i = 0; i < REPS_TO_TRACK; i++)
        cohorts[i] = dummy;
    
    // don't count dummies as active
    blurtReps::active_member -= REPS_TO_TRACK;
    blurtReps::active_member -= num_of_dummies;
}

int cohortReps:: num_active()
{
    return blurtReps::active_member;
}

int cohortReps:: num_in_cohort()
{
    return size;
}

void cohortReps:: adder(const blurtReps& obj)
{
    if(size < REPS_TO_TRACK)
    {
        cohorts[size] = obj;
        size++;
    }
}

void cohortReps:: remover(blurtReps obj)
{
    for(int i = 0; i < size; i++)
    {
        // overloaded ==. Find the object
        if(cohorts[i] == obj)
        {
            // "zero" out current element
            cohorts[i] = dummy;
            
            // check if next iteration exists by comparing to dummy. Then replace
            for(int j = i; j < size; j++)
            {
                if(cohorts[j+1] == dummy)
                {
                    cohorts[j] = cohorts[j+1];
                    cohorts[j+1] = dummy;
                }
            }
            // decrement size
            size--;
        }
    }
}

string cohortReps:: concatenated_string()
{
    string concatenation = "";
    for(int i = 0; i < REPS_TO_TRACK; i++)
    {
        if(cohorts[i] != dummy)
        {
            string word = cohorts[i].Ping();
            if(word != REP_INACTIVE)
                concatenation += word;
        }
    }
    return concatenation;
}

void cohortReps:: cohort_copier(const cohortReps& copy)
{
    if(this != &copy)
    {
        size = copy.size;
        for(int i = 0; i < REPS_TO_TRACK; i++)
        {
            cohorts[i] = copy.cohorts[i];
        }
    }
}

// destructor
cohortReps:: ~cohortReps()
{
    //eottoke
}

// COPY CONSTRUCTOR
cohortReps:: cohortReps(const cohortReps& copy)
{
    if(this != &copy)
    {
        size = copy.size;
        for(int i = 0; i < REPS_TO_TRACK; i++)
        {
            cohorts[i] = copy.cohorts[i];
        }
    }
}


// OVERLOADED OPERATORS===================================

// ==
bool cohortReps:: operator==(const cohortReps& rhs)
{
    if(this != &rhs)
    {
        for(int i = 0; i < size; i++)
        {
            if(cohorts[i] != rhs.cohorts[i])
                return false;
        }
        return true;
    }
    return true;
}

// =
cohortReps& cohortReps:: operator=(const cohortReps& rhs)
{
    if(this != &rhs)
    {
        cohort_copier(rhs);
    }
    return *this;
}

// +
cohortReps& cohortReps:: operator+(const cohortReps& rhs)
{
    if(this != &rhs)
    {
        int mask = size;
        mask += rhs.size;
        
        if(mask > REPS_TO_TRACK)
        {
            // do nothing
            return *this;
        }
        else
        {
            int ori_size=size;
            for(int i = ori_size; i < REPS_TO_TRACK; i++)
            {
                cohorts[i] = rhs.cohorts[i-ori_size];
                if(dummy != rhs.cohorts[i-ori_size])
                    size++;
            }
        }
    }
    return *this;
}

// cohort + blurt
cohortReps& cohortReps:: operator+(const blurtReps& rhs)
{
    int mask = size++;
    if(mask > REPS_TO_TRACK)
    {
        // do nothing
		size--;
        return *this;
    }
    else
    {
        cohorts[mask] = rhs;
    }
    return *this;
}