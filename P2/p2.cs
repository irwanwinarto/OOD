// AUTHOR: Irwan Winarto
// FILENAME: p2.cs
// DATE: 1/25/2018
// REVISION HISTORY: Version 1 (last revised Jan 25 2017, 23:30)
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

/* -------------------------------------------------------------------------------------------------
 * The P2 driver seeks to test out the mixReps and cohortReps class' functionalities.
 * It creates a mixReps object named mixRObj and accesses the 4 expected outputs.
 * Three blurtReps objects are then created to be added into cohortReps. The second one (blurtIt2) will be removed
 * and the console will display all the object's words (including the removed one) and the concatenation 
 * of the remaining words (blurtIt1 and blurtIt3 in this driver).
  -------------------------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------------------------------
 * The Systems.Text library was added in order to use StringBuilder, which is part of the random string 
 * generator.
 * Sources of input were determined through the default constraints by the prompt. The string to be passed
 * into the objects were randomized using a random string generator. This is also true with the length 
 * of the string. 
 * The variables mixCount1,2 and preference were picked in order to demonstrate the functionality of 
 * the mixReps class
 * The different strings: nonWord and weirdWord were put in to allow clear distinction between strings.
 * This was done for demonstration purposes only. They can both be randomized with the string generator.
  -------------------------------------------------------------------------------------------------*/
using System;
using System.Text;

namespace Assignment2_Winartoi
{
    public class p2
    {
        static void Main()
        {
            int maxChar = 5;
            int maxPing = 6;
            int outputState = 1; // 1=plain, 2=repeat, 3=terse
            int minLength, maxLength;
            string word;
            string nonWord = "1@#r";
            string weirdWord = "asdfg";

            minLength = 1;
            maxLength = 5;

            int mixCount1 = 1;
            int mixCount2 = 2;
            bool preference = false;

            // Let's test mixReps
            word = RndGenerators.RandomString(RndGenerators.RandomNum(minLength, maxLength));
            mixReps mixRObj = new mixReps();
            mixRObj.MixTheReps(word, mixCount1, preference);
            Console.WriteLine("-------------------");
            mixRObj.MixTheReps(word, mixCount2, preference);
            Console.WriteLine("-------------------");

            preference = true;

            mixRObj.MixTheReps(word, mixCount1, preference);
            Console.WriteLine("-------------------");
            mixRObj.MixTheReps(word, mixCount2, preference);
            Console.WriteLine("-------------------");

            blurtReps blurtIt = new blurtReps(maxChar, maxPing, outputState);
            blurtReps blurtIt2 = new blurtReps(maxChar, maxPing, outputState);
            blurtReps blurtIt3 = new blurtReps(maxChar, maxPing, outputState);

            // Let's test cohortReps
            CohortReps aCohort = new CohortReps();
            aCohort.Adder(ref blurtIt, word);
            aCohort.Adder(ref blurtIt2, nonWord);
            aCohort.Adder(ref blurtIt3, weirdWord);
            aCohort.Remover(ref blurtIt2);
            aCohort.HowMany();
            Console.WriteLine("-------------------");
            aCohort.Concatenator();

        }
    }


/* RndGenerators Class Assumption------------------------------------------------------------------
* It is assumed that the user only uses the alphabet as inputs and not symbols or numbers.
* This RndGenerators class will create random strings and random numbers between a specified boundary 
* (minNum and maxNum).
* The random string generator uses a pool of characters and uses the Random function to build a 
* random string using a loop.
* 
-------------------------------------------------------------------------------------------------- */
    class RndGenerators 
    {
     public RndGenerators()
     {
    
     }
        private static Random rndString = new Random();

        private static Random rndNum = new Random();

        public static string RandomString(int maxlength)
        {
         StringBuilder word = new StringBuilder();

         const string pool = "abcdefghijklmnopqrstuvwxyz";
         char chrtr;
         for (int i = 0; i < maxlength; i++)
            {
             chrtr = pool[rndString.Next(0, pool.Length)];
             word.Append(chrtr);
            }  
         return word.ToString();
        }

        public static int RandomNum(int minNum, int maxNum)
        {
         return rndNum.Next(minNum, maxNum);
        }

        public static int RandomMixCount()
        {
            int minNum = 1;
            int maxNum = 2;
            return rndNum.Next(minNum, maxNum);
        }
    }
}
