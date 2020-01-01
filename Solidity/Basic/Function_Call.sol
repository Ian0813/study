

            pragma solidity >= 0.4.24 < 0.6.0;


            contract sample1 {
                int a;

                // "payble" is a bulit-in modifier
                // This modifier is required if another contract is sending Ether while
                // calling the method.
                constructor(int b) payable public {
                    a = b;
                }

                function assign(int c) public {
                    a = c;
                }

                function makePayment(int d) payable public {
                    a = d;
                }
            }

            contract sample2 {
                function hello() public {

                }

                constructor(address addressOfContract) public {
                    // send 12 wei while creating contract instance
                    sample1 s = (new sample1).value(12)(23);

                    s.makePayment(22);

                    // sending Ether also
                    s.makePayment.value(45)(12);

                    // specifying the amount of gas to use
                    s.makePayment.gas(895)(12);

                    // sending Ether and also specifying gas
                    s.makePayment.value(4).gas(900)(12);

                    // hello() is internal call whereas this.hello() is external call
                    this.hello();

                    // pointing a contract that's already deployed
                    sample1 s2 = sample1(addressOfContract);

                    s2.makePayment(112);
                }

            }
