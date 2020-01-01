/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */


var arr = new Array(3, 2, 4);


var twoSum = function(nums, target) {
    var i, j;
	for(i = 0; i<nums.length; i++)
    {
		for(j = i+1; j<nums.length; j++)
        {
			if(nums[i]+nums[j] == target)	
				return [i, j];
		}
	}
};

var num = new Array();

num = twoSum(arr, 6);

console.log(num);
