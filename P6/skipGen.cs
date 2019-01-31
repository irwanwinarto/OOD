using System;
namespace p6
{
    public class skipGen : gen
    {
        protected const string RETURN_SKIPPED = "Skipped.";
        private const int CHANGE_THRESHOLD = 5;

        /*
         * position to be skipped
         */
        private int skip_this;

        /*
         * number of times the object changes states
         */
        private int state_change_count;

        /*
         * constructor - initializes variables
         * 
         * Preconditions: 
         * Postconditions:
         * Invariants:
         */
        public skipGen()
        {
            skip_this = 2;
            state_change_count = DEFAULT_VALUE;
        }

        /*
         * gimme_sequence() - returns successive numbers in the internal arithmetic sequence, taking into account the skipped position
         * 
         * Preconditions: object state must be active.
         * Postconditions: position increments by 1.
         * Invariants: 
         */
		public override float gimme_sequence()
		{
            float ans = 0;

            if (gen_state)
            {
                if (position == 0 || position == 1 || position == skip_this)
                {
                    position++;
                    return SKIPPED_INT;
                }
                else
                {
                    ans = do_math(position);
                    position++;
                    return ans;
                }
            }
            else
            {
                position++;
                return INACTIVE_INT;
            }
		}

        /*
         * skip_position(int) - skips the arithmetic value in the position number specified by argument
         * 
         * Preconditions: position to be skipped must be 0 or greater. There are no sequences for negative positions.
         * Postconditions:
         * Invariants: specified value is always skipped
         */
        public override void skip_position(int pos)
        {
            skip_this = pos;
        }

        /*
         * toggle_state() - changes object state
         * 
         * Preconditions: must be within the maximum allowable toggle times
         * Postconditions: object state may change
         * Invariants:
         */
		public override void toggle_state()
		{
            if (state_change_count <= CHANGE_THRESHOLD)
            {
                base.toggle_state();
                state_change_count++;
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
            state_change_count = DEFAULT_VALUE;
            base.gen_reset();
		}
	}
}
