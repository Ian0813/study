

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract Strings_sample {
            /* wherever a string literal is seen a new string is created.
               If the string literal is in state than it's stored in storage
               and if it's sound inside function than its stored in memory */

            // Here myString stores "" string.
            string myString = "";  // string literal.
            bytes myRawString;

            constructor(string memory initString, bytes memory rawStringInit) public {
                myString = initString;

                // myString2 holds a pointer to myString
                string storage myString2 = myString;

                // myString3 is a string in memory
                string memory myString3 = "ABCDE";

                //here the length and content changes
                myString3 = "XYZ";

                myRawString = rawStringInit;

                // incrementing the length of myRawString
                myRawString.length++;

                //throws exception while compiling
                string memory myString4 = "Example";

                //throws exception while compiling
                string memory myString5 = initString;
            }
        }
