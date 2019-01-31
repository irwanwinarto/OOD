// AUTHOR: Irwan Winarto
// FILENAME: cohortReps.cs
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;
using System;

namespace Assignment2_Winartoi
{
    /* -------------------------------------------------------------------------------------------------
     * The CohortReps class is a cohort of blurtReps objects. It is responsible of adding and removing
     * blurtReps objects into an array, essentially keeping track of them. 
     * The constructor simply initializes the repNum variable that keeps track on the number of active blurtReps objects.
     * The HowMany() method writes the number of active objects to the console.
     * The Adder method initializes an element in the cohorts array to the passed blurtReps object and pings the object.
     * Upon doing this, the number of active blurtReps is increased.
     * The Remover method searches for the blurtReps object to be removed in the array and sets it to null. It then
     * decrements the number of active blurtReps and swaps the null element with the element in the next address if 
     * not also null.
     * The Concatenator method accesses the blurtReps objects in the array and gets the string they are holding and 
     * displays their concatenation to the console.
      -------------------------------------------------------------------------------------------------*/

    /* -------------------------------------------------------------------------------------------------
     * The CohortReps class assumes that blurtReps objects will be passed into it. It will not create objects inside the class.
     * Constructor precondition: none. Postcondition: repNum variable will be inialized to 0;
     * HowMany()-    Precondition: Requires blurtReps objects to be added to have a number greater than 0.
     *                 Postcondition: Number of active blurtReps objects will vary.
     * Adder method- Precondition: A blurtReps object has been created and passed into the method along with a string.
     *              Postcondition: Object will no longer be in the array and the cohorts' size will shrink.
     * Remover method- Precondition: There must be at least one existing blurtReps object in the array.
     *              Postcondition: There will be one less blurtReps objects in the array or cohort. Cohort size will shrink.
     * Concatenator method- Precondition: The objects in the array must already be 'ping-ed' to carry a string.
     *                      Postcondition: Output string will become longer.
      -------------------------------------------------------------------------------------------------*/
    public class CohortReps
    {
        private blurtReps[] cohorts = new blurtReps[5];
        int repNum = new int();
        public CohortReps()
        {
            repNum = 0;
        }

        //-----------------------------------------------------------
        public void HowMany()
        {
            Console.WriteLine("Number of active blurtReps objects: " + this.repNum);
        }

        //-----------------------------------------------------------
        public void Adder(ref blurtReps obj, string passedString)
        {
            cohorts[repNum] = obj;
            obj.Ping(passedString);
            repNum++;
        }

        //-----------------------------------------------------------
        public void Remover(ref blurtReps obj)
        {
            int length = cohorts.Length;
            for (int i = 0; i < length; i++)
            {
                if (cohorts[i] == obj)
                {
                    cohorts[i] = null;
                    Console.WriteLine("An object has been removed.");
                    length--;

                    if (cohorts[i+1] == null) 
                    {
                        for (int j = i; j < length; j++)
                        {
                            cohorts[i] = cohorts[i + 1];
                        }
                    }
                }
            }
            repNum--;
        }

        //-----------------------------------------------------------
        public void Concatenator()
        {
            string concatenation = null;
            for (int i = 0; i < cohorts.Length; i++)
            {
                if (cohorts[i] != null)
                {
                    //Console.WriteLine(cohorts[i].concatenateThis);
                    string word = cohorts[i].concatenateThis;
                    concatenation += word;
                }
            }
            Console.WriteLine(concatenation);
        }
    }
}
