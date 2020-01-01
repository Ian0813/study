

            pragma solidity >= 0.4.24 < 0.6.0;

            contract Delete_sample {

                struct Struct {
                    mapping (int => int) myMap;
                    int myNumber;
                }

                int [] myArray;
                Struct myStruct;

                constructor(int key, int value, int number, int[] memory array) public {

                    // maps cannot assigned so while constructing struct we ignore the maps
                    myStruct = Struct(number);

                    // here set the map key/value
                    myStruct.myMap[key] = value;

                    myArray = array;
                }

                function reset() public {
                    // myArray length is now 0
                    delete myArray;
                    // myNumber is now 0 and myMap remains as it is
                    delete myStruct;
                }

                function deleteKey(int key) public {
                    // here we are deleting the deleteKey
                    delete myStruct.myMap[key];
                }
            }

