

            pragma solidity >= 0.4.24 <= 0.6.0;

            library math
            {
                function addInt(int a, int b) public returns (int c){
                    return a * b;
                }
            }

            contract sample {
                function data() public returns (int d) {
                    return math.addInt(1, 2);
                }
            }
