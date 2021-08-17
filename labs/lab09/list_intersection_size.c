//Function returns the number of values that occur in 2 linked lists

//by Len Au (z5308653) 27/07/20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int intersection_size(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = intersection_size(head1, head2);
    printf("%d\n", result);

    return 0;
}

// return the number of values which occur in both linked lists
// no value is repeated in either list
int intersection_size(struct node *head1, struct node *head2) {

    // PUT YOUR CODE HERE (change the next line!)
    int values = 0;
    struct node *current1 = head1;
    struct node *current2 = head2;
    
    //Loop through lists to find matching values
    //Outer loop == list 1
    //Innter loop == list 2
    //Loop to look at each element
    while (current1 != NULL) {
        current2 = head2;
        while (current2 != NULL) {
            //if data is equal, add to value
            if (current1->data == current2->data) {
                values++;
            }
            //Loop through the inner second list
            current2 = current2->next;
        }
        //Loop throguh the outer first list
        current1 = current1->next;
    }
    //Return total value
    return values;
}
    

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
