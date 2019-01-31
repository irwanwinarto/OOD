// AUTHOR: Irwan Winarto
// FILENAME: mixReps.cs
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;
using System;

namespace Assignment2_Winartoi
{
    /* -------------------------------------------------------------------------------------------------
     * The mixReps class contains two blurtReps objects: x and z. Two variables: mixCount and preference
     * will determine the class's output to the console by using either or both blurtReps objects.
     * The constructor will initialize the blurtReps objects, mixCount and prefernce variables.
     * The DOSOMETHING method checks the user inputs: the word, mixCount, and preference. It then displays
     * the corresponding output to the console.
      -------------------------------------------------------------------------------------------------*/

    /* -------------------------------------------------------------------------------------------------
     * The mixReps class assumes that the blurtReps class is accessible
     * Constructor  Precondition: none
     *              PostCondition: variables and objects will be initialized.
     * DoSomething  Precondition: The blurtReps objects 'x' and 'z' are already created and user has picked 
     *                            a mixCount value and a preference of 'even' or 'odd'.
     *              Postcondition: Outputs a combination of the words the objects hold.
     * The class does not allow preference state changes during run time.
      -------------------------------------------------------------------------------------------------*/
    class mixReps
    {
        private static int maxChar = 5;
        private static int maxPing = 6;
        private static int outputState = 1; // 1=plain, 2=repeat, 3=terse
        private blurtReps x;
        private blurtReps z;

        private int mixCount;
        private bool preference; // true = EVEN, false = ODD

        //-----------------------------------------------------------
        public mixReps()
        {
            // Initialize blurtRep objects
            x = new blurtReps(maxChar, maxPing, outputState);
            z = new blurtReps(maxChar, maxPing, outputState);

            // Initialize mixCount and preference
            mixCount = 1;
            preference = true;
        }

        ~mixReps()
        {
        }

        //-----------------------------------------------------------
        public void MixTheReps(string word, int mixCount, bool preference)
        {
            this.mixCount = mixCount;
            this.preference = preference;
            z.ChangeState(2);

            if (mixCount == 1 && !preference)
            {
                //outputs as only 'x'
                Console.WriteLine("X: ");
                x.Ping(word);
            }
            else if (mixCount == 1 && preference)
            {
                // outputs as only 'z'
                Console.WriteLine("Z: ");
                z.Ping(word);
            }
            else if (mixCount == 2 && !preference)
            {
                // outputs as 'x'. then outputs as 'z'
                Console.WriteLine("X then Z: ");
                x.Ping(word);
                z.Ping(word);
            }
            else if (mixCount == 2 && preference)
            {
                // outptus as 'z'. then outputs as 'x'
                Console.WriteLine("Z then X: ");
                z.Ping(word);
                x.Ping(word);
            }
        }
    }
}