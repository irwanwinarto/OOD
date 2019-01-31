// AUTHOR: Irwan Winarto
// FILENAME: skipGen.cs
// DATE: 2/4/2018
// REVISION HISTORY: Version 1
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.comusing System;
using System;
namespace Assignment3_Winartoi
{
    /* -------------------------------------------------------------------------------------------------
     * The skipGen class is similar to the gen class. However, it skips the 0th, 1st, and pth position in
     * the arithmetic sequence. It will output a -1 when this happens.
     * -------------------------------------------------------------------------------------------------*/

    /* -------------------------------------------------------------------------------------------------
     * Constructor
     * Pre: none
     * Post: initializes all the variables.
     * skipPosition(int p)
     * Pre: Must specify the position to be skipped.
     * Post: Specified position will output -1.
     * GimmeSequence()
     * Pre: none
     * Post: returns the value in the arithmetic sequence according to the counter. Skips positions 0, 1 and p.
     * ChangeState()
     * Pre: Number of times called should not exceed a threshold. Otherwise, method does nothing.   
     * Post: The state of the object is changed to "off". It will always return -1 when "off".
     * -------------------------------------------------------------------------------------------------*/
    public class skipGen : gen
    {
        public skipGen()
        {
            this.position = 0;
            this.skipThis = 2;
            this.state = true;
            this.threshold = RandomNum(2,10);
            this.stateCount = 0;
        }

        private int position;
        private int skipThis;
        private bool state;
        private int threshold;
        private int stateCount;

        public int GetThreshold()
        {
            return threshold;
        }

        public override float GimmeSequence()
        {
            float ans;
            if (state)
            {
                if (position == 0 || position == 1 || position == skipThis)
                {
                    this.position++;
                    return -1;
                }
                else
                {
                    ans = doMath(position);
                    this.position++;
                    return ans;
                }
            }
            else
            {
                this.position++;
                return -1;
            }
        }

        public void SkipPosition(int k)
        {
            this.skipThis = k;
        }

        public override void ChangeState()
        {
            if (stateCount < threshold)
            {
                if (this.state)
                {
                    this.state = false;
                    stateCount++;
                }
                else if (!this.state)
                {
                    this.state = true;
                    stateCount++;
                }
            }
        }
    }
}
