// AUTHOR: Irwan Winarto
// FILENAME: blurtReps.cs
// DATE: 1/16/2018
// REVISION HISTORY: last revised Jan 16 2017, 22:30
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com, csharp.net-turorials.com

/* DESCRIPTION--------------------------------------------------------------------------------------
 * This p1 driver uses a random string and number generator class to create random words.
 * p1 creates 2 words, one having a length between 1 and 5, and the second having a length 
of 6 and 8. Each word will be be passed to the blurtReps object's Ping function in all three states:
plain, repeat, and terse. It will lastly query the object for the number of times it was 'ping-ed'.
 * The first 3 pings demonstrates the basic functionality of the blurtReps class.
 * The fourth ping demonstrates the character limit of the string.
 * The fifth ping shows that non-alphabet strings are allowed.
 * The sixth ping demonstrates a wrong input of mode of output.
 * The seventh ping exceeds the threshold and demonstrates the object becoming 'inactive'.
 * The eight and ninth confirms the seventh ping's demonstration.
 -------------------------------------------------------------------------------------------------- */
using System;
using System.Text;  // Needed for StringBuilder

namespace Assignment1_Winartoi
{
    class p1
    {
        static void Main()
        {
            int maxChar = 5;
            int maxPing = 6;
            int outputState = 1; // 1=plain, 2=repeat, 3=terse
            int minLength, maxLength;
            string word;
            string nonWord = "1@#r";
            blurtReps obj = new blurtReps(maxPing, maxChar, outputState);

            minLength = 1;
            maxLength = 5;
            word = RndGenerators.RandomString(RndGenerators.RandomNum(minLength, maxLength));
            Console.WriteLine("Input: " + word);
            obj.Ping(word);
            obj.ChangeState(2);
            obj.Ping(word);
            obj.ChangeState(3);
            obj.Ping(word);
            obj.ChangeState(1);
            Console.WriteLine("---------------------------------");

            minLength = 6;
            maxLength = 8;
            word = RndGenerators.RandomString(RndGenerators.RandomNum(minLength, maxLength));
            Console.WriteLine("Input: " + word);
            obj.Ping(word);
            Console.WriteLine("---------------------------------");

            Console.WriteLine("Input: " + nonWord);
            obj.Ping(nonWord);

            Console.WriteLine("Changing to state 4...");
            obj.ChangeState(4);
            obj.Ping(nonWord);
            obj.ChangeState(1);
            Console.WriteLine("---------------------------------");

            obj.Ping(word);
            obj.Ping(word);
            obj.Ping(nonWord);
            Console.WriteLine("---------------------------------");



            obj.QueryPing();
        }
    }
 /* RndGenerators Class Assumption------------------------------------------------------------------
 * It is assumed that the user only uses the alphabet as inputs and not symbols or numbers.
 * This RndGenerators class will create random strings and random numbers between a specified boundary 
 * (minNum and maxNum).
 * The random string generator uses a pool of characters and uses the Random function to build a 
 * random string using a loop.
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
            return word.ToString();     // ToString() converts it to string
        }

        public static int RandomNum(int minNum, int maxNum)
        {
            return rndNum.Next(minNum, maxNum); // Creates a number between minNum and maxNum
        }
    }

}
