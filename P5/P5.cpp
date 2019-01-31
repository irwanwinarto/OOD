// Author: Irwan Winarto
// FILENAME: p5.cpp
// DATE: 3/6/2018
// REVISION HISTORY: ver1
// PLATFORM (compiler, version): Xcode
// REFERENCES: 

#include <iostream>
#include "blurtReps.h"
#include "mixReps.h"
#include "cohortReps.h"

using namespace std;

void test_blurtReps();
void test_mixReps();
void test_cohortReps();

int main(int argc, const char * argv[]) {

    test_blurtReps();
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    test_mixReps();
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    test_cohortReps();
    
    return 0;
}


void test_blurtReps()
{
    const int PLAIN = 1;
    const int REPEAT = 2;
    const int TERSE = 3;
    
    string word_1 = "Hello";
    string word_2 = "World";
    string word_3 = "a";
    string word_4 = "b";
    string word_5 = "c";
    
    // testing normal blurtReps
    blurtReps obj1;
    obj1.set_string(word_2);
    cout << "Ping 1: " << obj1.Ping() << endl;
    cout << "Changing to REPEAT state..\n";
    obj1.change_state(REPEAT);
    cout << "Ping 2: " << obj1.Ping() << endl;
    cout << "Changing to TERSE state..\n";
    obj1.change_state(TERSE);
    cout << "Ping 3: " << obj1.Ping() << endl;
    cout << "Changing to PLAIN state..\n";
    obj1.change_state(PLAIN);
    cout << "Ping 4: " << obj1.Ping() << endl;
    cout << "Ping 5: " << obj1.Ping() << endl;
    cout << "Ping 6: " << obj1.Ping() << endl;
    
    cout << "=====================\n\n";
    
    
    // testing copy constructor
    obj1.reset();
    obj1.set_string(word_2);
    
    cout << "Assigning obj1 to obj2..\n";
    blurtReps obj2(obj1);
    cout << "obj2 Ping 1: " << obj2.Ping() << endl;
    
    obj1.set_string(word_1);
    cout << "obj1 Ping 1: " << obj1.Ping() << endl;
    
    obj1 = obj1 + obj2;
    cout << "obj1 Ping 2: obj1 + obj2 (Hello+World): " << obj1.Ping() << endl;
    cout << "It is not HelloWorld because it is more than 5 characters.\n";
    
    cout << "=====================\n\n";
    
    // testing + and = operator
    obj1.reset();
    obj2.reset();
    
    obj1.set_string(word_3);
    obj2.set_string(word_4);
    
    blurtReps obj3(word_5);
    obj1 = obj1 + obj2 + obj3;
    cout << "obj1 Ping 1: obj1 + obj2 + obj3 (a+b+c): " << obj1.Ping() << endl;
    
    // testing == operator
    obj2 = obj3;
    cout << "obj1: " << obj1.Ping() << endl;
    cout << "obj2: " << obj2.Ping() << endl;
    cout << "obj3: " << obj3.Ping() << endl;
    if(obj2 == obj3)
        cout << "Verdict: obj2 == obj3\n";
    else
        cout << "Verdict: obj2 != obj3\n";
    
    cout << "=====================\n\n";
}

void test_mixReps()
{
    int num_preference = 10;
    string word_1 = "Aa";
    string word_2 = "Bb";
    string word_3 = "Cc";
    string word_4 = "Dd";
    
    mixReps obj1(word_1, word_2);
    mixReps obj2(word_3, word_4);
    
    // testing normal mixReps
    cout << "mixCount = 1 and preference = even number\n";
    obj1.set_preference(num_preference);
    cout << "1: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = even number\n";
    obj1.toggle_mix_count();
    cout << "2: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = odd number\n";
    obj1.set_preference(num_preference--);
    cout << "3: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 1 and preference = odd number\n";
    obj1.toggle_mix_count();
    cout << "4: " << obj1.mix_the_reps() << endl;
    
    cout << "=====================\n\n";
    num_preference++;
    obj1.reset();
    
    // test = operator
    mixReps obj3 = obj1;
    cout << "obj3 = obj1: \n";
    
    cout << "mixCount = 1 and preference = even number\n";
    obj3.set_preference(num_preference);
    cout << "1: " << obj3.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = even number\n";
    obj3.toggle_mix_count();
    cout << "2: " << obj3.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = odd number\n";
    obj3.set_preference(num_preference--);
    cout << "3: " << obj3.mix_the_reps() << endl;
    cout << "mixCount = 1 and preference = odd number\n";
    obj3.toggle_mix_count();
    cout << "4: " << obj3.mix_the_reps() << endl;
    
    cout << "=====================\n\n";
    num_preference++;
    obj3.reset();
    
    // test + and = operator
    cout << "obj1 = obj1 + obj2: \n";
    obj1 = obj1 + obj2;
    
    cout << "mixCount = 1 and preference = even number\n";
    obj1.set_preference(num_preference);
    cout << "1: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = even number\n";
    obj1.toggle_mix_count();
    cout << "2: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 2 and preference = odd number\n";
    obj1.set_preference(num_preference--);
    cout << "3: " << obj1.mix_the_reps() << endl;
    cout << "mixCount = 1 and preference = odd number\n";
    obj1.toggle_mix_count();
    cout << "4: " << obj1.mix_the_reps() << endl;
    
    cout << "=====================\n\n";
    obj1.reset();
    
}

void test_cohortReps()
{
    string word_1 = "Nat";
    string word_2 = "Gab";
    string word_3 = "Roc";
    string word_4 = "Wan";
    string word_5 = "Vin";
    string word_6 = "Tim";
    
    blurtReps obj1(word_1);
    blurtReps obj2(word_2);
    blurtReps obj3(word_3);
    blurtReps obj4(word_4);
    blurtReps obj5(word_5);
    blurtReps obj6(word_6);
    
    cohortReps list_1;
    
    cohortReps list_0;
    list_0.adder(obj1);
    list_0.adder(obj2);
    list_0.adder(obj3);
    list_0.adder(obj4);
    list_0.adder(obj5);
    list_0.adder(obj6);
    
    // testing normal cohortReps and = operator
    list_1 = list_0;
    cout << "Concatenation of active blurtReps: " << list_1.concatenated_string() << endl;
    cout << "Number of objects in the cohort: " << list_1.num_in_cohort() << endl << endl;
    cout << "Let us remove Gab, Roc, and Vin from the cohort list..\n";
    
    list_1.remover(obj2);
    list_1.remover(obj3);
    list_1.remover(obj5);
    cout << "Concatenation of active blurtReps: " << list_1.concatenated_string() << endl;
    cout << "Number of objects in the cohort: " << list_1.num_in_cohort() << endl << endl;
    
    cout << "=====================\n\n";
    
    // testing = operator
    cohortReps list_2 = list_1;
    cout << "Concatenation of active blurtReps in list_2: " << list_2.concatenated_string() << endl;
    cout << "Number of objects in the cohort in list_2: " << list_2.num_in_cohort() << endl << endl;
    
    cout << "Some objects have gone inactive. Let us reset them\n";
    list_1 = list_0;
    list_2 = list_1;
    list_2.remover(obj2);
    list_2.remover(obj5);
    
    cout << "=====================\n\n";
    
    // testing + and = operator
    cout << "Adding Roc back to list_2..\n";
    list_2.adder(obj2);
    cout << "Concatenation of active blurtReps in list_2: " << list_2.concatenated_string() << endl;
    cout << "Number of objects in the cohort in list_2: " << list_2.num_in_cohort() << endl << endl;
    
    cout << "list_1 + list_2:\n";
    list_1 = list_1 + list_2;
    cout << "Concatenation of active blurtReps in list_1: " << list_1.concatenated_string() << endl;
    cout << "Number of objects in the cohort in list_1: " << list_1.num_in_cohort() << endl << endl;
    
    cout << "=====================\n\n";
    
    cout << "list_1 + obj6\n";
    
    list_1 = list_1 + obj3;
    cout << "Concatenation of active blurtReps in list_1: " << list_1.concatenated_string() << endl;
    cout << "Number of objects in the cohort in list_1: " << list_1.num_in_cohort() << endl << endl;
    
    cout << "=====================\n\n";
    
    // testing == operator
    if(list_1 == list_2)
        cout << "Verdict: list_1 == list_2\n";
    else
        cout << "Verdict: list_1 != list_2\n";
    
    cout << "=====================\n\n";
    

}

