//Program reads integers from standard input until EOF
//Program prints the missing integers that aren't input from the lowest to 
//highest

//by Len Au (z5308653)

#include <stdio.h>

#define MAX_INTEGERS 1000

int main (void) {
    int user_input[MAX_INTEGERS];
    int i = 0;

    //reads in integers from standard input until EOF
    while (scanf("%d", &user_input[i]) != EOF) {
        i++;
    }
    
    int j = 0;
    int lowest_num = 0;
    int highest_num = 0;
    //loops through user_input to determine largest and lowest number
    lowest_num = user_input[j];
    highest_num = user_input[j];
    
    j = 0;
    while (j <= i) {
        //lowest_num = user_input[j];
        //highest_num = user_input[j];
        if (user_input[j] < lowest_num) {
            lowest_num = user_input[j];
            //user_input[j] = lowest_num;
            j++;
        }
        if (user_input[j] > highest_num) {
            highest_num = user_input[j];
            //user_input[j] = highest_num;
            j++;
        }
        j++;
        
    }
    printf("Lowest = %d\n", lowest_num);
    printf("Highest = %d\n", highest_num);
    //loops through array to find missing numbers
    int missing_num_count = 0;
    int missing_num_check[MAX_INTEGERS] = {0};
    int missing_num[MAX_INTEGERS] = {0};
    int x = 0;
    int y = 0;
    //Takes away in an incremental manner to find missing numbers
    int g = 1;
    while (x < i) {
        missing_num_check[x] = highest_num - g;
        y = 0;
        while (y < i && missing_num_count < i) {
            if (missing_num_check[x] == user_input[y]) {
                y++;
            }
            else {
                missing_num[missing_num_count] = missing_num_check[x];
                missing_num_count++;
                y = i;
            }
            y++;
        }
        
        x++;
        g++;
        
    }
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("missing_num_count = %d\n", missing_num_count);
    //prints missing numbers
    int num_print_count = 0;
    
    while (num_print_count != missing_num_count) {
        printf("%d ", missing_num[num_print_count]);
        num_print_count++;
    }
    printf("\n");
    
    return 0;
}
