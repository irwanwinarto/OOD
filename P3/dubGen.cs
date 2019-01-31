// AUTHOR: Irwan Winarto
// FILENAME: dubGen.cs
// DATE: 2/4/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;
using System;
namespace Assignment3_Winartoi
{
    /* -------------------------------------------------------------------------------------------------
     * The dubGen class is similar to the gen class, except that it doubles the value at a desired position.
     * If no position is specfied by the user, the default is position -1.
     * -------------------------------------------------------------------------------------------------*/

    /* -------------------------------------------------------------------------------------------------
     * Constructor
     * Pre: none
     * Post: Starting position is initialized to position 0 and the position to be doubled, 'p', is set to -1
     * DoubleThis(int p)
     * Pre: user specifies position to be doubled
     * Post: That value will be doubled.
     * GimmeSequence()
     * Pre: none
     * Post: returns the number in the arithmetic sequence. It doubles the value in the position 'p'.
     * -------------------------------------------------------------------------------------------------*/
    public class dubGen : gen
    {
        private int p;
        private int position;
        private float multiplier;

        public dubGen()
        {
            this.p = -1;
            this.position = 0;
            this.multiplier = 2;
        }

        public float DoubleThis(int p)
        {
            float doubledValue;
            this.p = p;
            doubledValue = doMath(p) * multiplier;
            return doubledValue;
        }

        public override float GimmeSequence()
        {
            float ans;
            if (this.position == this.p)
            {
                ans = DoubleThis(this.position);
                this.position++;
                return ans;
            }
            else
            {
                ans = doMath(position);
                this.position++;
                return ans;
            }
        }

        public override void Reset()
        {       
            this.position = 0;
        }
    }
}
