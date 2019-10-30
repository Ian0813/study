

            pragma solidity >= 0.4.24 <= 0.6.0;

            contract Mappings {
                // mapping variable location must be Storage, not be memory.
                mapping (int => string) myMap;

                constructor(int key, string memory value) public {
                    myMap[key] = value;

                    // myMap2 is a reference to myMap
                    mapping (int => string) storage myMap2 = myMap;
                }
            }
