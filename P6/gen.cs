// AUTHOR: Irwan Winarto
// FILENAME: gen.cs
// DATE: 3/15/2018
// REVISION HISTORY: Version 1 
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

using System;
namespace p6
{
    /*
     * When in Inactive state, calls to the gimme_sequence() method does not increment the position.
     */
    public class gen
    {
        protected const int INACTIVE_INT = -1;
        protected const int SKIPPED_INT = -2;
        protected const int DEFAULT_VALUE = 0;

        protected bool gen_state;
        protected float constant;
        protected float a1;
        protected int position;

        private int n, m;
        private bool original_state;

        /*
         * constructor - initializes variables
         * 
         * Preconditions:
         * Postconditions:
         * Invariants:
         */
        public gen()
        {
            a1 = 0;
            constant = 1;
            n = 0;
            m = 0;
            gen_state = true;
            position = 0;
            original_state = gen_state;
        }

        /*
         * copy constructor - copies passed gen object's data
         * 
         * Preconditions: argument must be of gen type
         * Postconditions: 
         * Invariants:
         */
        public gen(gen rhs)
        {
            this.copy(rhs);
        }

        /*
         * copy(gen) - for deep copying
         * 
         * Preconditions: argument must of gen type
         * Postconditions: states and variables may change
         * Invariants: 
         */
        private gen copy(gen rhs)
        {
            if(rhs != this)
            {
                gen_state = rhs.gen_state;
                constant = rhs.constant;
                a1 = rhs.a1;
                position = rhs.position;
                n = rhs.n;
                m = rhs.m;
                original_state = rhs.original_state;
            }
            return this;
        }

        /*
         * do_math() - returns the value of a number in the arithmetic sequence
         * 
         * Preconditions: gen object must be in active state
         * Postconditions: 
         * Invariants:
         */
        public float do_math()
        {
            if (gen_state)
            {
                float an;
                an = a1 + (n - m) * constant;
                return an;
            }
            else
                return INACTIVE_INT;
        }

        /*
         * do_math(int) - returns the value of a number in a specifid position in the arithmetic sequence
         * 
         * Preconditions: gen object must be in active state
         * Postconditions: 
         * Invariants:
         */
        public float do_math(int pos)
        {
            if (gen_state)
            {
                float an;
                n = pos;
                an = a1 + (n - m) * constant;
                return an;
            }
            else
                return INACTIVE_INT;
        }

        /*
         * gimme_sequence() - returns successive numbers in the internal arithmetic sequence
         * 
         * Preconditions: gen object must be in active state
         * Postconditions: position increments by 1 if active.
         * Invariants:
         */
        public virtual float gimme_sequence()
        {
            float an;
            an = do_math(position);
            if((int)an != INACTIVE_INT)
                position++;
            return an;
        }

        /*
         * toggle_state() - toggles between object state
         * 
         * Preconditions: must be within the maximum allowable toggle times
         * Postconditions: state of the object will change
         * Invariants:
         */
        public virtual void toggle_state()
        {
            gen_state = !gen_state;
        }

        /*
         * reset() - sets changeable values to original
         * 
         * Preconditions: none
         * Postconditions: state of the object will change
         * Invariants: always sets back to original states/values
         */
        public virtual void gen_reset()
        {
            position = DEFAULT_VALUE;
            gen_state = original_state;
        }

        /*
         * EMPTY FUNCTIONS
         * Used for proper function of heterogeneous collections
         */
        public virtual void skip_position(int pos)
        {
            
        }
        public virtual float double_this(int pos)
        {
            float x = 0;
            return x;
        }

    }
}
