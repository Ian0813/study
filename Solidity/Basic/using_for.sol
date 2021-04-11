

        pragma solidity >= 0.4.24 <= 0.6.0;

        library math
        {
            struct myStruct1 {
                int a;
            }
            struct myStruct2 {
                int a;
            }

            function addInt(myStruct1 storage s, int b) public returns(int c) {
                return s.a + b;
            }

            function subInt(myStruct2 storage s, int b) public returns(int c) {
                return s.a + b;
            }
        }

        contract sample {

            // " * " attaches the function to all the structs

            using math for *;
            math.myStruct1 s1;
            math.myStruct2 s2;

            function sample1() public {
                s1 = math.myStruct1(9);
                s2 = math.myStruct2(9);

                s1.addInt(2);

                /* compiler error as the first parameter of addInt is of type myStruct1 so addInt
                    is not attached to myStruct2 */
                s1.addInt(1);
            }
        }
