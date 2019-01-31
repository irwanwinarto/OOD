//
//  mixReps.cpp
//  3200_p5
//
//  Created by Irwan Winarto on 3/5/18.
//  Copyright © 2018 Irwan Winarto. All rights reserved.
//

#include <stdio.h>
#include "mixReps.h"

bool mixReps:: is_odd(int num)
{
    if(num%2 == 0)
        return false;
    else
        return true;
}

mixReps:: mixReps()
{
    name_1 = DEAFULT_STRING;
    name_2 = DEAFULT_STRING;
    mix_count = MIX_COUNT_ONE;
    preference = 0;
}

mixReps:: mixReps(string name1, string name2)
{
    name_1 = name1;
    name_2 = name2;
    x.set_string(name_1);
    z.set_string(name_2);
    
    mix_count = MIX_COUNT_ONE;
    preference = 0;
}

string mixReps:: mix_the_reps()
{
    if(mix_count == MIX_COUNT_ONE && !is_odd(preference))
    {
        // output as only 'x'
        return x.Ping();
    }
    else if(mix_count == MIX_COUNT_ONE && is_odd(preference))
    {
        // output as only 'z'
        return z.Ping();
    }
    else if(mix_count == MIX_COUNT_TWO && is_odd(preference))
    {
        // output as 'x' followed by 'z'
        return x.Ping()+z.Ping();
    }
    else //if(mix_count == MIX_COUNT_TWO && !is_odd(preference))
    {
        // output as 'z', then 'x'
        return z.Ping()+x.Ping();
    }
}

void mixReps:: toggle_mix_count()
{
    if(mix_count == MIX_COUNT_ONE)
        mix_count = MIX_COUNT_TWO;
    else
        mix_count = MIX_COUNT_ONE;
}

void mixReps:: set_preference(int num)
{
    preference = num;
}
void mixReps:: reset()
{
    x.reset();
    z.reset();
    x.set_string(name_1);
    z.set_string(name_2);
}

mixReps:: ~mixReps()
{
}

// COPY CONSTRUCTOR
mixReps:: mixReps(const mixReps& copy)
{
    x = copy.x;
    z = copy.z;
    
    mix_count = copy.mix_count;
    preference = copy.preference;
}

// OVERLOADED OPERATORS

// assignment =
mixReps& mixReps:: operator=(const mixReps &rhs)
{
    if(this != &rhs)
    {
        mixReps(rhs);
    }
    return *this;
}

// addition +
mixReps& mixReps:: operator+(const mixReps &rhs)
{
    if(this != &rhs)
    {
        x = x + rhs.x;
        z = z + rhs.z;
        preference += rhs.preference;
    }
    return *this;
}
