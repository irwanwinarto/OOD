// AUTHOR: Irwan Winarto
// FILENAME: dubGen.cs
// DATE: 3/15/2018
// REVISION HISTORY: Version 1 
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

using System;
namespace p6
{
    public class dubGen : gen
    {
        /*
         * position of which the value is to be doubled
         * 
         * Invariants: compiler automatically sets this to 0. Will be changed in constructor
         */
        private int pos_2b_dub;

        /*
         * multiplier
         * 
         * Invariants: multiplier is always 2 because this function doubles and not triples numbers.
         */
        private const int MULTIPLIER = 2;

        /* SUPPRESSED *
         * copy(dubGen) - for deep-copying
         * 
         * Preconditions: argument must be of type dubGen
         * 
         */
        private dubGen copy(dubGen rhs)
        {
            if(rhs != this)
            {
                pos_2b_dub = rhs.pos_2b_dub;
            }
            return this;
        }

        /*
         * constructor - initializes variables
         * 
         * Preconditions:
         * Postconditions:
         * Invariants:
         */
        public dubGen()
        {
            pos_2b_dub = 4;
        }

        /*
         * copy constructor
         * 
         * Preconditions: passed object (to be copied) must be of type dubGen
         * Postconditions: variable values may change
         * Invariants: 
         */
        public dubGen(dubGen rhs)
        {
            this.copy(rhs);
        }

        /*
         * double_this(int) - doubles the arithmetic value in the position number specified by argument
         * 
         * Preconditions: position to be doubled must be 0 or greater. There are no sequences for negative positions.
         * Postconditions:
         * Invariants: Value is always doubled.
         */
        public override float double_this(int pos)
        {
            pos_2b_dub = pos;
            return do_math(pos_2b_dub) * MULTIPLIER;
        }

        /*
         * gimme_sequence() - returns successive numbers in the internal arithmetic sequence, taking into account the doubled position
         * 
         * Preconditions: gen object must be in active state
         * Postconditions: position increments by 1
         * Invariants: 
         */
        public override float gimme_sequence()
        {
            float ans;
            if(position == pos_2b_dub)
            {
                ans = double_this(position);
                position++;
                return ans;
            }
            else
            {
                ans = do_math(position);
                position++;
                return ans;
            }
        }

        /*
         * reset() - sets variables to original values
         * 
         * Preconditions: none
         * Postconditions: variable may change values. Object state may change.
         * Invariants: always sets back to original states/values
         */
        public override void gen_reset()
        {
            pos_2b_dub = 0;
            base.gen_reset();
        }
    }
}
