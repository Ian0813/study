

		pragma solidity >= 0.4.24 <= 0.6.0;

		contract Array_sample{
		/* dynamic size array
		// wherever an array literal is seen a new array is created.
		 If the array literal is in state than it's stored in storage and if it's
		 found inside function than its stored in memory	*/

		/* Here myArray stores [0, 0] array. The type of [0, 0] is decided based on its values.
		 Therefore you cannot assign an empty arrat literal. */
		 int[] myArray = [0, 0];

		 constructor(uint index, int value) public {

					// index of an array should be uint256 type
					myArray[index] = value;

					//myArray2 holds pointer to myArray2
					int[] storage myArray2 = myArray;

					// a fixed size array in memory
					/* here we are forced to use uint24 because 99999 is the max value and
					/* This restriction is applied to literals in memory  because memory is expensive.
					Twenty-Four bits is the max size required to hold it	*/
					/* As [1, 2, 99999] is of type uint24 therefore myArray3 also has to be the same
						 type to store pointer to it */
					 uint24[3] memory myArray3 = [1, 2, 99999]; //array literal

					 // throws exception while compiling as myArray4 cannot be assigned to complex type stored in memory.
					 uint8[2] memory myArray4 = [1, 2];
		 }
		}
