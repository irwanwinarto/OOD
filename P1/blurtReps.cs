// AUTHOR: Irwan Winarto
// FILENAME: blurtReps.cs
// DATE: 1/16/2018
// REVISION HISTORY: last revised Jan 16 2017, 22:30
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

/* DESCRIPTION--------------------------------------------------------------------------------------
 * blurtReps class
 * The blurtReps class contains 7 private variables and 4 functions excluding the constructor.
 * The constructor requires three parameters and initializes four of the private variables.
 * The Ping function takes in a string which it will assign the privately stored prvtString's value as.
It checks for the object's state (active/inactive), number of times 'pinged', and length of the string 
being passed before calling the concatenation function.
 * The Concatenation function checks for the output controls (outputController) and outputs the original
string when in plain mode, concatenates according to the number of repetitions (repCount) when in  
repeat mode, and truncates the last character of the string when in terse mode. Otherwise, it displays 
error messages.
 * The ChangeState function allows the user to change the output mode (1=plain, 2=repeat, 3=terse). It 
directly accessed the private variable outputController.
 * The QueryPing function reports the number of pings to the Ping function.
 -------------------------------------------------------------------------------------------------- */

using System;

namespace Assignment1_Winartoi
{
 /* blurtReps Class Assumption-----------------------------------------------------------------------
 * It is assumed that the number of repetitions is kept hidden from the user and the user would only 
 * need to specify the threshold, length of string, and output type they want.
 * It is also assumed that the class does not need to filter out non-alphabet strings.
 * Querying the ping is assumed to not be a ping to the object.
 * Upon being called or 'ping-ed', this function will generate output according to the output's mode.
 * The first mode is 'plain' and it does nothing to the string passed to the object. The second is 'repeat'
 * and it concatenates the string by an amount set by repCount to the end of the passed string. The third
 * is 'terse' and it truncates the last character of the passed string.
 * The object will give out error messages if the passed string is more than 5 characters in length, exceeds
 * the maximum allowable number of pings, and is inactive. It is initially active, but turns inactive once
 * the maximum allowable number of pings is reached.
 * We can query the object for the number of times it was 'ping-ed'.
 -------------------------------------------------------------------------------------------------- */
    class blurtReps
    {
        private string prvtString;
        private int repCount = 3;
        private int outputController; // 1=plain, 2=repeat, 3=terse

        private int pingCount;
        private int threshold;
        private bool objState;
        private int strLength;

        public blurtReps(int threshold, int strLength, int outputController)
        {
            this.outputController = outputController;
            this.threshold = threshold;
            this.strLength = strLength;
            this.objState = true;
        }

        public void Ping(string passedString)
        {
            // Check objState
            if(objState)
            {
                // Increase pingCount with each ping
                this.pingCount++;

                // Check pingCount
                if (pingCount < threshold + 1)
                {
                    // Check string length
                    if(passedString.Length < strLength + 1)
                    {
                        this.prvtString = passedString;
                        EditString();
                    }
                    else
                    {
                        Console.WriteLine("Only a maximum of " + strLength + " characters allowed!");
                    }
                }
                else
                {
                    // If you're here, it means you have exceeded the allowable number of pings.
                    // Update objState.
                    this.objState = false;
                    Console.WriteLine("You have exceeded the allowable number of pings.");
                    Console.WriteLine("Allowable number of pings: " + threshold);
                }
            }
            else
            {
                Console.WriteLine("Object is inactive. Allowable number of pings exceeded.");
            }

        }

        private void EditString()
        {
            if(outputController == 1)           // Plain
            {
                Console.WriteLine("Output1 (plain) : " + prvtString);
            }
            else if(outputController == 2)      // Repeat
            {
                string mask = prvtString;
                for (int i = 0; i < repCount - 1; i++)
                {
                    mask = mask + prvtString;
                }
                Console.WriteLine("Output2 (repeat): " + mask);
            }
            else if(outputController == 3)      // Terse
            {
                int stringLength = prvtString.Length;
                string terse = prvtString.Substring(0, stringLength -1);
                Console.WriteLine("Output3 (terse) : " + terse);
            }
            else
            {
                Console.WriteLine("No such state. 1=plain, 2=repeat, 3=terse");
            }
        }

        public void ChangeState(int state)
        {
            this.outputController = state;
        }

        public void QueryPing()
        {
            Console.WriteLine("Current number of pings: " + pingCount);
        }
    }
}
