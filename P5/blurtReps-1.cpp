// Author: Irwan Winarto
// FILENAME: blurtReps.cpp
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

#include "blurtReps.h"

int blurtReps:: active_member = 0;

blurtReps:: blurtReps()
{
    prvt_string = DEAFULT_STRING;
    edited = prvt_string;
    output_controller = PLAIN;
    obj_state = true;
    ping_count = 0;
    
    active_member++;
}
blurtReps:: blurtReps(string passed_string)
{
    prvt_string = passed_string;
    edited = prvt_string;
    output_controller = PLAIN;
    obj_state = true;
    ping_count = 0;
    
    active_member++;
}


void blurtReps:: edit_string()
{
    if(output_controller == PLAIN)
    {
        edited = prvt_string;
    }
    else if(output_controller == REPEAT)
    {
        edited = prvt_string;
        for(int i = 0; i< REP_COUNT; i++)
            edited = edited + prvt_string;
    }
    else if(output_controller == TERSE)
    {
        edited = prvt_string.substr(0, prvt_string.length() - 1);
    }
}


string blurtReps:: Ping()
{
    if(obj_state)
    {
        ping_count++;
        if(ping_count <= PING_THRESHOLD)
        {
            edit_string();
            return edited;
        }
        else
        {
            // exceeded allowable pings
            obj_state = !obj_state;
            return REP_INACTIVE;
        }
    }
    else
        return REP_INACTIVE;
}

void blurtReps:: set_string(string passed_string)
{
	int l = MAX_STRING_LENGTH;
	l++;
    if(passed_string.length() < l)
    {
        reset();
        prvt_string = passed_string;
    }
	l--;
}

void blurtReps:: change_state(int state)
{
    if(state == 1 || state == 2 || state == 3)
        output_controller = state;
}


int blurtReps:: query_ping()
{
    return ping_count;
}

void blurtReps:: reset()
{
    prvt_string = DEAFULT_STRING;
    edited = prvt_string;
    output_controller = PLAIN;
    obj_state = true;
    ping_count = 0;
}

blurtReps:: ~blurtReps()
{
    // WHAT TO DO
    active_member--;
}

// COPY CONSTRUCTOR
blurtReps:: blurtReps(const blurtReps& copy)
{
    prvt_string = copy.prvt_string;
    edited = copy.edited;
    output_controller = copy.output_controller;
    obj_state = copy.obj_state;
    ping_count = copy.ping_count;
    
    active_member++;
}

//copy
void blurtReps:: copier (const blurtReps& copy)
{
    prvt_string = copy.prvt_string;
    edited = copy.edited;
    output_controller = copy.output_controller;
    obj_state = copy.obj_state;
    ping_count = copy.ping_count;
}

//OVERLOAD OPERATORS

// assignment operator =
blurtReps& blurtReps:: operator=(const blurtReps& rhs)
{
    if(this != &rhs)
    {
        copier(rhs);
    }
    return *this;
}

// addition operator +
blurtReps& blurtReps:: operator+(const blurtReps& rhs)
{
    if(this != &rhs)
    {
        int length = (int)rhs.prvt_string.length();
        if(prvt_string.length() + length <= MAX_STRING_LENGTH)
            prvt_string += rhs.prvt_string;
    }
    return *this;
}

// ==
bool blurtReps:: operator==(const blurtReps& rhs)
{
    if(this != &rhs)
    {
        if(prvt_string.length() == rhs.prvt_string.length())
        {
            //compare name
            for(int i = 0; i < prvt_string.length(); i++)
            {
                if(prvt_string[i] != rhs.prvt_string[i])
                {
                    return false;
                }
            }
            // no need to check ping count
            return true;
        }
    }
    // else it's the same one..return true..
    return true;
}

// !=
bool blurtReps:: operator!=(const blurtReps& rhs)
{
    if(this != &rhs)
    {
        //compare name
        for(int i = 0; i < MAX_STRING_LENGTH; i++)
        {
            if(prvt_string[i] != rhs.prvt_string[i])
            {
                return true;
            }
        }
        return false;
    }
    return false;
}