

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract Struct_sample {

            struct myStruct {
                bool myBool;
                string myString;
            }

            myStruct s1;

            /* wherver a struct method is seen a new struct is created. If the
               struct method is in state than it's stored in storage and if it's
               found inside function than its stored in memory */
            myStruct s2 = myStruct(true, ""); // struct method syntax


            constructor(bool initBool, string memory initString) public {

                // create a instance of struct
                s1 = myStruct(initBool, initString);

                //myStruct(initBool, initString) creates a instance in memory
                myStruct memory s3 = myStruct(initBool, initString);
            }
        }
