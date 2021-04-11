

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract sample1 {
            function a() public returns (int b);
        }

        contract sample2 {
            function myFunc()
            {
                sample1 s = sample1(0xd5f9d8d94886e70b06e474c3fb14fd43e2f23970);

                // without abstract contract this wouldn't have compiled;
                s.a();
            }
        }
