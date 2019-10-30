

            pragma solidity >= 0.4.24 <= 0.6.0;


            contract sample1
            {
                    int a  = 1;

                    function assign(int b) external {
                        a = b;
                    }
            }

            contract sample2 {

                constructor() public {
                    sample1 s = new sample1();
                    s.assign(12);
                }
            }
