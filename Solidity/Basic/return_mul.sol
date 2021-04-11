

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract sample
        {
                function aa() public returns(int a, string memory c)
                {
                    return (1, "ss");
                }

                function b() public
                {
                    int A;
                    string memory B;

                    // A is 1 and B is "ss"
                    (A, B) = aa();

                    // A is 1
                    (A,) = aa();

                    // B is "ss"
                    (,B) = aa();
                }
        }
