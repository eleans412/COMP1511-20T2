// Function returns middle element of a linked list

// by Len Au (z5308653)
// 07-08-2020
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_middle(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = get_middle(head);
    printf("%d\n", result);

    return 0;
}


// Return middle element of a linked list
// if list contains [6,7,8,9,10]  8 is returned
// if a list has even number of elements, first of middle two elements returned
// if list contains [1,2,3,4] 2 is returned
// list can not be empty
int get_middle(struct node *head) {
    // Logic guided by: https://www.mycplus.com/tutorials/data-structures/find-the-middle-element-of-linked-list-in-c/#:~:text=In%20order%20to%20find%20middle,See%20the%20following%20C%20program.
    
    struct node *slow_ptr = head;
    struct node *previous = NULL;
    struct node *fast_ptr = head;
    int middle = 0;
 
     if (previous == NULL && slow_ptr->next == NULL) {
        middle = slow_ptr->data;
        return middle;
     }
     
    // Loop will only run if there is data input
    if (head != NULL) {
        // Fast pointer moves along the list, moving 2 nodes forward
        // Slow pointer moves along 1 node at a time
        // When Fast pointer stops, slow pointer will have reached 
        // the middle of the list 
        // (as it is following fast pointer at 0.5x speed)
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            // Previous holds slow_ptr as slow pointer moves 
            // one node ahead of the middle
            previous = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
       middle = previous->data;
    }
    
    

    //struct node *current = head;
    //struct node *previous = NULL;
    //struct node *fast_pointer = head;
    //int middle = 0;
    
    // If there is only one number input
    /*if (previous == NULL) {
        return head->data;
    }*/
    
   
   /* int count = 0;
    int total = 0;
    int num_nodes = 0;
    int middle = 0;
    
    
    // If there is only one number input
    if (previous == NULL) {
        return head->data;
    }
    
    // Count how many nodes are in the list
    while (current != NULL) { 
        count++;
        previous = current;
        current = current->next;
    }
    total = count;
    
    // Set pointers back to the start of the linked list
    previous = NULL;
    current = head;
    
    // If there are an odd number of nodes in the list
    if (total % 2 == 1) {
        while (current != NULL) {
            if (num_nodes == total/2) {
                middle = current->data;
                current = NULL;
            }
            num_nodes++;
            previous = current;
            current = current->next;
        
        }
    }
    
    // If there are an even number of nodes in the list
    else if (total % 2 == 0) {
        while (current != NULL) {
            if (num_nodes == total/2) {
                middle = previous->data;
                current = NULL;
            }
            num_nodes++;
            
            previous = current;
            current = current->next;
        }
    }
        printf("total = %d\n", total);*/
    return middle;

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
