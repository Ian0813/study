

            pragma solidity >= 0.4.24 <= 0.6.0;


            contract Enums {

                // The integer type which can hold all enum values and is the smallest is chosen to hold enum values.
                enum OS {Windows, Linux, OSX, UNIX}

                OS choice;

                constructor(OS chosen) public {
                    choice = chosen;
                }

                function setLinuxOS() {
                    choice = OS.Linux;
                }

                function getChoic() public returns(OS chosenOS) {
                    return choice;
                }
            }
