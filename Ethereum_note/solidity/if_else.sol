

            pragma solidity >= 0.4.24 <= 0.6.0;


            contract structures {
                // Using var
                int256 x = 12;

                // y type is int 256
                var y = x;

                uint256 z = 9;
                // exception because implicit conversion not possible
                y = z;
                // Remeber that var cannot be used when defining arrays and maps.
                // And it cannot used to define function paramaters and state variables.

                /////////////////////////////////////////////////////////////////////////
                /*  Control structures  */
                int a = 12;
                int[] b;
                constructor() public {
                    // "==" throw exception for complex types
                    if(a == 12)
                    {
                    }
                    else if(a == 34)
                    {
                    }
                    else
                    {
                    }

                    var temp = 10;

                    while(temp < 20)
                    {
                        if (temp == 17)
                        {
                            break;
                        }
                        else
                        {
                            continue;   // back to most near loop
                        }

                        temp++;
                    }

                    for (var iii = 0; iii < b.length; iii++)
                    {

                    }
                }
            }
