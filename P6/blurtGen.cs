// AUTHOR: Irwan Winarto
// FILENAME: blurtGen.cs
// DATE: 3/15/2018
// REVISION HISTORY: Version 1 
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

using System;
namespace p6
{
    public class blurtGen : gen, i_blurtReps
    {
        protected const string REP_INACTIVE = "INACTIVE";

        blurtReps blurtReps_part = new blurtReps();

        /*
         * constructor
         * 
         * Preconditions:
         * Postconditions:
         * Invariants:
         */
        public blurtGen()
        {
        }

        /*
         * gimme_sequence() - callse the gen base and returns successive numbers in the internal arithmetic sequence
         * Reliant on base (gen) gimme_sequence() method.
         * 
         * Preconditions: gen object must be in active state
         * Postconditions: position increments by 1 if active.
         * Invariants: none
         */
        public override float gimme_sequence()
        {
            return base.gimme_sequence();
        }

        // i_blurtReps methods
        /*
         * set_string(string) - calls the blurtReps object and sets the string
         * Reliant on blurtReps set_string(string) method.
         * 
         * Precondition: must pass in a string of valid length as determined by MAX_STRING_LENGTH from blurtReps class.
         * Postcondition:
         * Invariants: If string is not valid, string will not change.
         */
        void i_blurtReps.set_string(string passed_string)
        {
            blurtReps_part.set_string(passed_string);
        }

        /*
         * Ping() - returns the edited string if object is ACTIVE and has not exceeded ping threshold
         * 
         * Precondition: object must be active
         * Postcondition: object may turn inactive
         * Invariants: none
         */
        public string Ping()
        {
            string word = blurtReps_part.Ping();
            float num = base.gimme_sequence();
            if (word != REP_INACTIVE && (int)num != INACTIVE_INT)
                return word + " " + num;
            else if ((int)num == INACTIVE_INT)
                return REP_INACTIVE;
            else
                return word;
        }

        /*
         * change_state(int) - calls the blurtReps object and changes the output_controller to a valid state
         * Reliant on blurtReps change_state() method.
         * 
         * Precondition: state must be integers 1, 2 or 3
         * Postcondition: output controller state may change
         * Invariants: none
         */
        void i_blurtReps.change_state(int state)
        {
            blurtReps_part.change_state(state);
        }

        /*
         * query_ping() - calls the blurtReps object and queries the ping_count
         * Reliant on blurtReps query_ping() method.
         * 
         * Precondition: none
         * Postcondition: none
         * Invariants: none
         */
        uint i_blurtReps.query_ping()
        {
            return blurtReps_part.query_ping();
        }

        /*
         * reset() - calls the blurtReps object and resets variables and states to user chosen default value
         * Reliant on blurtReps blurt_reset() method.
         * 
         * Preconditions: none
         * Postconditions: none
         * Invariants: String set to default string. Output controller set to plain.
         *      ping_count set to 0.
         */
        void i_blurtReps.blurt_reset()
        {
            blurtReps_part.blurt_reset();
        }

        /*
         * reset() - sets variables to original values
         * Reliant on base gen_reset() method.
         * 
         * Preconditions: none
         * Postconditions: variable may change values. Object state may change.
         * Invariants: always sets back to original states/values
         */
        public override void gen_reset()
        {
            base.gen_reset();
        }
	}
}
