// AUTHOR: Irwan Winarto
// FILENAME: p6.cs
// DATE: 3/15/2018
// REVISION HISTORY: Version 1 
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

using System;

namespace p6
{
    class MainClass
    {
        /* p6 driver
         * p6 uses global variables. Each help to determine which types of objects to be placed in each heterogeneous collection.
         * The p6 driver calls 2 functions that demonstrates multiple inheritance simulated using the interface class. Both functions make use of heterogeneous collections
         *      of base i_blurtReps and gen respectively.
         * Each function is described more in detail below.
         */
        public static void Main(string[] args)
        {
            MainClass test_obj = new MainClass();
            test_obj.i_blurtReps_hetero_test();
            Console.WriteLine("===============================");
            test_obj.gen_hetero_test();
        }

        // Global variables to help pick which object references to return to the caller code.
        int picker_1 = 1;
        int picker_2 = 1;

        /* gen base
         * Returns a new object reference from from the gen hierarchy
         * 
         * Preconditions: picker_1 should use numbers that do not have 2 or 3 as common multiples
         *      Choosing such a number fulfills the conditions for a blurtDubGen() and a blurtSkipGen. The compiler will pick the first one. 
         *      Avoid this to avoid confusion.
         * Postconditions: none
         * Invariants: unless the initial value of picker_1 is chosen by the user programmer, the first five objects will be of the order:
         *      blurtGen
         *      blurtDubGen
         *      blurtSkipGen
         *      blurtDubGen
         *      blurtReps
         */
        i_blurtReps blurtReps_base_obj()
        {
            if(picker_1%2 == 0)
            {
                picker_1++;
                return new blurtDubGen();
            }
            else if (picker_1%3 == 0)
            {
                picker_1++;
                return new blurtSkipGen();
            }
            else if(picker_1%5 == 0)
            {
                picker_1++;
                return new blurtReps();
            }
            else
            {
                picker_1++;
                return new blurtGen();
            }
        }

        /* i_blurtReps base
         * Returns a new object from the i_blurtReps hierarchy
         * 
         * Preconditions: picker_2 should use numbers that do not have 2 or 3 as common multiples
         *      Choosing such a number fulfills the conditions for a blurtDubGen() and a blurtSkipGen. The compiler will pick the first one. 
         *      Avoid this to avoid confusion.
         * Postconditions: none
         * Invariants: unless the initial value of picker_2 is chosen by the user programmer, the first five objects will be of the order:
         *      blurtGen
         *      blurtDubGen
         *      blurtSkipGen
         *      blurtDubGen
         *      gen
         */
        gen gen_base_obj()
        {
            if (picker_2 % 2 == 0)
            {
                picker_2++;
                return new blurtDubGen();
            }
            else if (picker_2 % 3 == 0)
            {
                picker_2++;
                return new blurtSkipGen();
            }
            else if (picker_2 % 5 == 0)
            {
                picker_2++;
                return new gen();
            }
            else
            {
                picker_2++;
                return new blurtGen();
            }
        }

        /*
         * Testing for heterogeneous collection with i_blurtReps interface as base
         * Each object's output_controller will be changed after each object is Ping()-ed. The sequence goes from 
         *      Plain->Repeat->Terse->Plain and so on.
         * Each object will be Ping()-ed as many times as the value specified by test_num.
         * Object will return "Inactive" when the number of Pings reaches a maximum threshold. The default set maximum is 5. 
         *      This is changeable in the blurtReps class.
         * 
         * Invariants: This test uses 5 objects. If the initial value of picker_1 isn't changed, the objects are in the order:
         *      blurtGen
         *      blurtDubGen
         *      blurtSkipGen
         *      blurtDubGen
         *      blurtReps
         */
        void i_blurtReps_hetero_test()
        {
            const int COLL_SIZE = 5;
            const int PLAIN = 1;
            const int REPEAT = 2;
            const int TERSE = 3;
            int output_control = 0;
            int test_num = 8;

            i_blurtReps[] i_blurtReps_array = new i_blurtReps[COLL_SIZE];

            // fill in heterogeneous array
            for (int i = 0; i < COLL_SIZE; i++)
                i_blurtReps_array[i] = blurtReps_base_obj();
            Console.WriteLine("Current Order: blurtGen, blurtDubGen, blurtSkipGen, blurtDubGen, blurtReps");
            Console.WriteLine();
            // general PING test
            for (int i = 0; i < COLL_SIZE; i++)
            {
                if (output_control == TERSE)
                    output_control = PLAIN;
                output_control++;
                i_blurtReps_array[i].change_state(output_control);
                for (int j = 0; j < test_num; j++)
                    Console.Write(i_blurtReps_array[i].Ping() + ", ");
                Console.WriteLine();
                Console.WriteLine();
            }
            Console.WriteLine();


        }

        /*
         * Testing of heterogeneous collection with gen interface as base
         * Every object in the collection will skip the position specified by "skip_this_num" and double the value of the position 
         *      specified by "double_this_num". This will only affect dubGen, skipGen, blurtDubGen, and blurtSkipGen.
         * The for loop gets the next value from the internalized arithmetic sequence of each object by the number specified by 
         *      test_num and the output is checked if they are skipped or if the object is inactive.
         * Each object's states will be toggled after every call to the arithmetic sequence and is expected to return an "Inactive" 
         *      string when the state of the object is off.
         * Compared to p4, explicit tests using blurtDubGen and blurtSkipGen objects were done. They print out to the console the original 
         *      arithmetic sequences, then resetting them and doubling or skipping every position in the sequence.
         * 
         * Invariants: This test uses 5 objects. If the initia value of picker_2 isn't changed, the objects are in the order:
         *      blurtGen
         *      blurtDubGen
         *      blurtSkipGen
         *      blurtDubGen
         *      gen
         */
        void gen_hetero_test()
        {
            const int COLL_SIZE = 5;
            const int IS_INACTIVE = -1;
            const int IS_SKIPPED = -2;
            const string STR_INACTIVE = "Inactive";
            const string STR_SKIPPED = "Skipped";
            int output_control = 0;
            int test_num = 8;
            int skip_this_num = 2;
            int double_this_num = 4;
            int current_array_element = 0;

            gen[] gen_array = new gen[COLL_SIZE];

            // fill in heterogeneous array
            for (int i = 0; i < COLL_SIZE; i++)
                gen_array[i] = gen_base_obj();
            Console.WriteLine("Current Order: blurtGen, blurtDubGen, blurtSkipGen, blurtDubGen, gen");
            Console.WriteLine();
            // general getting sequence test
            for (int i = 0; i < COLL_SIZE; i++)
            {
                output_control++;
                gen_array[i].skip_position(skip_this_num);
                gen_array[i].double_this(double_this_num);
                for (int j = 0; j < test_num; j++)
                {
                    float temp = gen_array[i].gimme_sequence();
                    if ((int)temp == IS_INACTIVE)
                        Console.Write(STR_INACTIVE);
                    else if ((int)temp == IS_SKIPPED)
                        Console.Write(STR_SKIPPED);
                    else
                        Console.Write(temp);
                    if (j != test_num-1)
                        Console.Write(", ");
                    gen_array[i].toggle_state();
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            // Explicitly testing blurtDubGen
            current_array_element++;
            Console.WriteLine("Explicitly testing out blurtDubGen. It is the 3rd object in the array.");
            gen_array[current_array_element].gen_reset();
            for (int i = 0; i < test_num; i++)
                Console.Write(gen_array[current_array_element].gimme_sequence() + ", ");
            Console.WriteLine();
            Console.WriteLine("Resetting and doubling every position in blurtDubGen obj:");
            gen_array[current_array_element].gen_reset();
            for (int i = 0; i < test_num; i++)
            {
                gen_array[1].double_this(i);
                Console.Write(gen_array[1].gimme_sequence() + ", ");
            }
            Console.WriteLine();
            Console.WriteLine();

            // Explicitly testing blurtSkipGen
            current_array_element++;
            Console.WriteLine("Explicitly testing out blurtSkipGen. It is the 2nd and 4th object in the array. Let us use the 2nd.");
            gen_array[current_array_element].gen_reset();
            for (int i = 0; i < test_num; i++)
            {
                float temp = gen_array[current_array_element].gimme_sequence();
                if ((int)temp == IS_INACTIVE)
                    Console.Write(STR_INACTIVE);
                else if ((int)temp == IS_SKIPPED)
                    Console.Write(STR_SKIPPED);
                else
                    Console.Write(temp);
                if (i != test_num - 1)
                    Console.Write(", ");
            }
            Console.WriteLine();
            Console.WriteLine("Resetting and skipping every position in blurtSkipGen obj:");
            gen_array[current_array_element].gen_reset();
            for (int i = 0; i < test_num; i++)
            {
                gen_array[current_array_element].skip_position(i);

                float temp = gen_array[current_array_element].gimme_sequence();
                if ((int)temp == IS_INACTIVE)
                    Console.Write(STR_INACTIVE);
                else if ((int)temp == IS_SKIPPED)
                    Console.Write(STR_SKIPPED);
                else
                    Console.Write(temp);
                if (i != test_num - 1)
                    Console.Write(", ");
            }
            Console.WriteLine();
        }

    } // END OF MainClass
} // END OF p6
