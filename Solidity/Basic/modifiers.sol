

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract sample {

            int a = 90;

            modifier myModifier1(int b) {
                int c = b;
                _;
                c = a;
                a = 8;
            }

            modifier myModifier2 {
                int c = a;
                _;
            }

            modifier myModifier3 {
                a = 96;
                return;
                _;
                a = 99;
            }

            function myFunction() public myModifier1(a) myModifier2() myModifier3() returns(int d){
                a = 1;
                return a;
            }
            /* myFunction executed steps :
                {
                    int c = b;
                        a = 96;
                        return;
                            int c = a;
                            a = 1;
                            return a;
                        a = 99;
                    c = a;
                    a = 8;
                }
            */
        }
