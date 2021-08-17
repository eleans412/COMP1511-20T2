// COMP1511 Array Sum Product
// Calculate the sum and the product of the elements in an array
// and write the results into variables passed into the function
// by reference.

// This program was written by Len Au (z5308653)
// on 29/06/20

#include <stdio.h>

void array_sum_prod(int length, int nums[length], int *sum, int *product);

// This is a simple main function that you can use to test your array_sum_prod
// function.
// It will not be marked - only your array_sum_prod function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your array_sum_prod function directly.
// Any changes that you make to this main function will not affect the autotests.

int main(void) {
    int nums[] = {3, 4, 1, 5, 6, 1};
    int prod;
    int sum;

    //Pass in the address of the sum and product variables
    array_sum_prod(6, nums, &sum, &prod);

    printf("Sum: %d, Product: %d\n", sum, prod);
   
    int nums2[] = {1, 2, 3, 4};

    //Pass in the address of the sum and product variables
    array_sum_prod(4, nums2, &sum, &prod);

    printf("Sum: %d, Product: %d\n", sum, prod);
   
    return 0;
}


// Calculates the sum and product of the array nums.
// Actually modifies the  variables that *sum and *product are pointing to
void array_sum_prod(int length, int nums[length], int *sum, int *product) {
    //this function's output is not returned by this function
    //its returning is by changing the value of 
    //the thing the pointer is pointing at
 
    
    *sum = 0;
    int i = 0;
    while (i < length) {
        //this formula captures 'the sum so far'
        //gives the value of sum to int sum
        *sum = *sum + nums[i];
        i++;
    }
    
    *product = 1;
    int j = 0;
    while (j < length) { 
        //gives the value of product to int product
        *product = *product * nums[j];
        j++;
    }
    
}
