// Program adds two numbers together, but in an array.

//by Len Au 29/06/20 9(z5308653)

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 101

int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE] = {0};

    // Get the array size.
    int num_digits, num_rows;
    printf("Enter the number of rows (excluding the last): ");
    scanf("%d", &num_rows);
    assert(num_rows > 0 && num_rows < 100);

    printf("Enter the number of digits on each row: ");
    scanf("%d", &num_digits);
    assert(num_digits > 0 && num_digits < MAX_SIZE);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < num_rows) {
        int j = 0;
        while (j < num_digits) {
            assert(scanf("%d", &array[i][j]) == 1);
            if (array[i][j] < 0 || array[i][j] > 9) {
                printf("You entered a value not between 0 and 9.\n");
                return 1;
            }
            j++;
        }
        i++;
    }

    int carry = sum(num_rows, num_digits, array);

    int j = 0;
    while (j < num_digits) {
        printf("%d ", array[num_rows][j]);
        j++;
    }
    printf("\n");
    i++;

    if (carry > 0) {
        printf("Carried over: %d\n", carry);
    }

    return 0;
}

// Put the sum of the lines in the array into the last line
// accounting for carrying. Return anything you did not carry.
//
// NOTE: num_lines is the number of lines you are adding together. The
// array has an extra line for you to put the result.
int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]) {
    int j = num_digits - 1;
    int i = 0;
    int sum_value = 0;
    int carry = 0;
    while (j >= 0) {
        i = 0;
        sum_value = 0;
        while (i <= num_lines) {
            //sum everything in the column
            sum_value = sum_value + array[i][j];
            i++;
        }
        //sum = sum + carry 
        //this adds the carry to the next column
        sum_value = sum_value + carry;
        //carry = sum/10
        //finds the carry value
        carry = sum_value / 10;
        //sum = sum % 10
        //finds the single unit total for the column
        sum_value = sum_value % 10;
        //set array position to equal sum
        array[num_lines][j] = sum_value;
        //if there is no column to carry over (in last column)
        if (j - 1 < 0) {
            return carry;
        }
    
        //increment counter
        //moves to the next column
        j--;
    }
    //return carry
    return carry; 
}
    


