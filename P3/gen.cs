// AUTHOR: Irwan Winarto
// FILENAME: gen.cs
// DATE: 2/4/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;
using System;

namespace Assignment3_Winartoi
{
    /* -------------------------------------------------------------------------------------------------
     * The gen class is a random arithmetic sequence generator. It uses randomized values to determine the starting number and constant.
     * Overriding was done for the GimmeSequence() method to satisfy requirements for the driver's side.
     * The doMath and GimmeSequence methods implement arithmetic equations.
     * The difference is that one utilizes a counter to generate the next value in the sequence. It also utilizes doMath(position).
     * The constructor initializes all the variables of the arithmetic equation: a1, n, m, constant (d) to default values.
     * The user can pass in their own values into an overloaded constructor, which will be used instead of the defaults.
     * -------------------------------------------------------------------------------------------------*/

    /* -------------------------------------------------------------------------------------------------
     * doMath()
     * Pre: none
     * Post: Returns value of random position in sequence.
     * doMath(position)
     * Pre: User must specify which position of the value in the sequence they want.
     * Post: Class method will return that value in the specified position.
     * GimmeSequence()
     * Pre: Counter starts from 0.
     * Post: Returns the value at position 'counter' and increments 'counter' value by 1 each time method is called.
     * ChangeState(bool state)
     * Pre: Must input desired state. Active = true. Inactive = false.
     * Post: state will change from true to false or vice versa.
     * RandomNum()
     * Pre: Must specify range of numbers to randomize from.
     * Post: generates random number.
     * -------------------------------------------------------------------------------------------------*/
    public class gen
    {
        bool state;
        float a1;
        float constant;
        int n;
        int m;
        private int counter;

        gen(float a1, float constant, int n)
        {
            this.a1 = a1;
            this.constant = constant;
            this.n = n;
            state = true;
            this.m = 1; // Let this be a default value if user doesn't care.
        }

        gen(float a1, float constant, int n, int m)
        {
            this.a1 = a1;
            this.constant = constant;
            this.n = n;
            this.m = m;
            this.state = true;
        }

        public gen()    // Using this one in driver
        {
            this.a1 = rndNum.Next(99);
            this.constant = rndNum.Next(99);
            this.n = rndNum.Next(99);
            this.m = 1;
            this.state = true;
            this.counter = 0;
        }

        public float doMath()
        {
            if (state)
            {
                float an = 0;
                an = this.a1 + (this.n - this.m) * this.constant;
                return an;
            }
            else
            {
                return 0;   
            }
        }

        public float doMath(int pos)    // This one used in dubGen
        {
            if(state)
            {
                float an = 0;
                this.n = pos;
                an = this.a1 + (this.n - this.m) * this.constant;
                return an;
            }
            else
            {
                return 0;
            }
        }

        public virtual float GimmeSequence()
        {
            if (state)
            {
                float an = 0;
                an = this.a1 + counter * this.constant;
                this.counter++;
                return an;
            }
            else
            {
                return 0;
            }
        }

        public virtual void ChangeState()
        {
            if (this.state)
            {
                this.state = false;
                }
            else if (!this.state)
            {
                this.state = true;
            }
        }

        public virtual void Reset()
        {
            this.counter = 0;
        }

        private static Random rndNum = new Random();

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
