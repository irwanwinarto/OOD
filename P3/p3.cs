// AUTHOR: Irwan Winarto
// FILENAME: p3.cs
// DATE: 2/4/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;

/* -------------------------------------------------------------------------------------------------
 * P3 seeks to demonstrate the functionalities of the gen base class, dubGen child class, and the 
 * skipGen child class. This will we done with heterogeneous arrays. 3 objects are called - each of 
 * the three different class types. For loops are used to set the element type and store values of the
 * types.
  -------------------------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------------------------------
 * p3 uses a heterogeneous array to demonstrate the functionalities of each class. The array is of the base
 * class type, gen. The array has 3 elements of the gen, dubGen, and skipGen type. Each element are used 
 * to demonstrate the class' functionalities.
 * Parameter inputs are not used as the classes are able to internally randomize their own parameters for
 * the arithmetic sequence.
 * Outputs are of the float type, and are written to the console.
 * All sequences start from position 0.
  -------------------------------------------------------------------------------------------------*/
using System;
namespace Assignment3_Winartoi
{
    public class p3
    {
        static void Main()
        {
            //float ans;
            Random rnd = new Random();
            int pos = rnd.Next(10);
            int testNum = 10;
            int randomPos = rnd.Next(2, 10);

            gen sample = new gen();
            dubGen dubSample = new dubGen();
            skipGen skipSample = new skipGen();

            gen[] array = new gen[3];
            array[0] = sample;
            array[1] = dubSample;
            array[2] = skipSample;

            Console.WriteLine("Testing gen's random position in the sequence generator: ");
            Console.WriteLine(array[0].doMath());

            Console.WriteLine();
            Console.WriteLine("Testing gen's SPECIFIC position in the sequence generator: ");
            Console.WriteLine("Position: " + pos);
            Console.WriteLine(array[0].doMath(pos));

            Console.WriteLine();
            Console.WriteLine("Testing gen's sequence generator: ");
            for (int i = 0; i < testNum; i++)
            {
                Console.WriteLine(array[0].GimmeSequence());
            }

            Console.WriteLine();
            Console.WriteLine("Testing dubGen's sequence generator. ");
            for (int i = 0; i < testNum; i++)
            {
                Console.WriteLine(array[1].GimmeSequence());
            }
            Console.WriteLine("We will now double the value of position " + randomPos);
            dubSample.Reset();
            dubSample.DoubleThis(randomPos);
            for (int j = 0; j < testNum; j++)
            {
                Console.WriteLine(array[1].GimmeSequence());
            }

            Console.WriteLine();
            Console.WriteLine("Testing skipGen's sequence generator. Let's skip position 2. Outputs -1 if blank. ");
            Console.WriteLine("So we are skipping positions 0,1, and 2.");
            Console.WriteLine("Maximum number of state changes allowed: " + skipSample.GetThreshold());
            skipSample.SkipPosition(2);
            for (int i = 0; i < testNum; i++)
            {
                Console.WriteLine(array[2].GimmeSequence());
                array[2].ChangeState();
            }
        }
    }
}
