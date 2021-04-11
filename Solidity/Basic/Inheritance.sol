

            pragma solidity >= 0.4.24 < 0.6.0;

            contract sample1 {

                function a() public {}

                function b() public {}
            }

            // sample2 inherits sample1
            contract sample2 is sample1 {
                function b() public {}
            }

            contract sample3 {
                constructor(int b) public {}
            }

            // sample4 inherits from sample1 and samole2
            // Note that sample1 is also parent of sample2, yet there is only a single instance of smaple1
            contract sample4 is sample1, sample2 {
                function a() public {}

                function c() public {

                    // this executes the "a" method of sample4 Contract
                    a();

                    // this executes the "a" method of sample1 contract
                    sample1.a();

                    /* calls sample2.b() because it's in last in the parent contracts
                       list and therefore it overrides sample1.b() */
                    b();
                }
            }

            /* If a constructor take an argument, it needs to be provided at the constructor of the child contract */
            /* In Solidity child doesn't call parent constructor instead parent is initialized and copied to child. */
            contract sample5 is sample3(122) {}
