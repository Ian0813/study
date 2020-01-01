

            pragma solidity >= 0.4.24 < 0.6.0;

            contract Exception {
                function myFunction() public {
                    revert();   // Also have require() and assert()
                }
            }
