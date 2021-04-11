

            pragma solidity >= 0.4.24 < 0.6.0;

            contract sample1
            {}

            contract sample2
            {}

            contract sample3 is sample2
            {}

            contract sample4 is sample2
            {}

            contract sample5 is sample4
            {
                function myFunc() public
                {}
            }

            contract sample6 is sample1, sample2, sample3, sample5
            {
                function myFunc() public
                {
                    // sample5.myFunc()
                    super.myFunc();
                }
            }
