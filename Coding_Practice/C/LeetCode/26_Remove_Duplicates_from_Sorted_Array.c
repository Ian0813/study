/*
 * =====================================================================================
 *
 *       Filename:  26_Remove_Duplicates_from_Sorted_Array.c
 *
 *    Description:  Remove duplicates from Sorted Array 
 *
 *        Version:  1.0
 *        Created:  2020年12月13日 16時01分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */


int removeDuplicates(int* nums, int numsSize){
    
        
    if(numsSize == 0)
        return 0;
    
    int index = 1, count = 1, loc = 1;
        
    for(index; index < numsSize; index++){
        if(nums[index -1] == nums[index]){            
            continue;
        }                
        nums[loc] = nums[index];   
        count++;
        loc++;    
    }
                    
    return count;
}
