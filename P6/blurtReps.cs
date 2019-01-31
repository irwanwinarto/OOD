// AUTHOR: Irwan Winarto
// FILENAME: blurtReps.cs
// DATE: 3/15/2018
// REVISION HISTORY: Version 1 
// PLATFORM (compiler, version): Visual Studio Community 2017 for Mac, Ver 7.3.3 (build 5)
// REFERENCES: stackoverflow, msdn.microsoft.com, docs.microsoft.com

using System;
namespace p6
{
    /*
     * i_blurtReps interface
     * This interface helps simulate multiple inheritance. It will serve as the base for our heterogeneous collection.
     * The methods declared inside the interface will be defined in each class that inherits from it.
     * Therefore, these methods don't have definitions yet.
     */
    public interface i_blurtReps
    {
        void set_string(string passed_string);
        string Ping();
        void change_state(int state);
        uint query_ping();
        void blurt_reset();
    }

    public class blurtReps : i_blurtReps
    {
        protected const string REP_INACTIVE = "INACTIVE";
        protected const int PING_THRESHOLD = 5;
        protected const int MAX_STRING_LENGTH = 5;
        protected const int PLAIN = 1;
        protected const int REPEAT = 2;
        protected const int TERSE = 3;
        protected const bool ACTIVE = true;
        protected const bool INACTIVE = false;

        private const string DEFAULT_STRING = "DEFAULT";
        private const int DEFAULT_REP_COUNT = 3;

        private string prvt_string;
        private int output_controller;
        private uint rep_count;
        private uint ping_count;

        private string edited;
        private bool obj_state;

        /*
         * constructor - initializes variables
         * 
         * Precondition:
         * Postcondition:
         * Invariants: Initial private string is "default". Object state will always start out as 
         *  active state. Output controller will always start out in PLAIN state.
         */
        public blurtReps()
        {
            prvt_string = DEFAULT_STRING;
            edited = prvt_string;

            output_controller = PLAIN;
            obj_state = ACTIVE;

            rep_count = DEFAULT_REP_COUNT;
            ping_count = 0;
        }

        /*
         * set_string(string)
         * sets the private string to a desired and valid string
         * 
         * Precondition: must pass in a string of valid length as determined by MAX_STRING_LENGTH
         * Postcondition:
         * Invariants: If string is not valid, string will not change.
         */
        public void set_string(string passed_string)
        {
            if (passed_string.Length <= MAX_STRING_LENGTH)
            {
                prvt_string = passed_string;    // IS THIS BY REFERENCE OR BY VALUEEE???????
            }
        }

        /*
         * edit_string() - takes the prvt_string and applies the effects of the chosen output_controller
         * 
         * Precondition: prvt_string must not be null. Heck, it shouldn't even be null.
         * Postcondition:
         * Invariants:
         */
        private void edit_string()
        {
            if (output_controller == PLAIN)
            {
                edited = prvt_string;
            }
            else if (output_controller == REPEAT)
            {
                string mask = prvt_string;
                for (int i = 0; i < rep_count; i++)
                    mask += prvt_string;
                edited = mask;
            }
            else if (output_controller == TERSE)
            {
                int string_len = prvt_string.Length;
                string terse = prvt_string.Substring(0, string_len - 1);
                edited = terse;
            }
        }

        /*
         * Ping() - returns the edited string if object is ACTIVE and has not exceeded ping threshold
         * 
         * Precondition: object must be active
         * Postcondition: object may turn inactive
         * Invariants:
         */
        public virtual string Ping()
        {
        if (obj_state)
        {
            ping_count++;

            if (ping_count <= PING_THRESHOLD)
            {
                edit_string();
                return edited;
            }
            else
            {
                // exceeded allowable pings
                obj_state = INACTIVE;
                return REP_INACTIVE;
            }
        }
        else
            return REP_INACTIVE;
        }

        /*
         * change_state(int) - changes the output_controller to a valid state
         * 
         * Precondition: state must be integers 1, 2 or 3
         * Postcondition: output controller state may change
         * Invariants: none
         */
        public virtual void change_state(int state)
        {
            if (state == PLAIN || state == REPEAT || state == TERSE)
                output_controller = state;
        }

        /*
         * query_ping() - queries the ping_count
         * 
         * Precondition: none
         * Postcondition: none
         * Invariants: none
         */
        public uint query_ping()
        {
            return ping_count;
        }

        /*
         * reset() - resets variables and states to user chosen default value
         * 
         * Preconditions: none
         * Postconditions: none
         * Invariants: Values set to same values in constructor. String set to default string. Output controller set to plain.
         *      ping_count set to 0.
         */
        public virtual void blurt_reset()
        {
            prvt_string = DEFAULT_STRING;
            edited = prvt_string;

            output_controller = PLAIN;
            obj_state = ACTIVE;

            rep_count = DEFAULT_REP_COUNT;
            ping_count = 0;
        }
    }
}

