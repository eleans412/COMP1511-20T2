#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_last(head);
    print_list(new_head);

    return 0;
}


//
// Delete the last node in list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_last(struct node *head) {
    struct node *current = head;
    struct node *previous = NULL;
    
    //If there is no elements in the list
    if (current == NULL) {
        
        return head;
    }
    
    
    //If there is only one element in the list
    if (current->next == NULL) {
        free(current);
        head = NULL;
        return head;
    }
    
    
    // Loop to the second last element of the list
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    //Set previous to the second last element
    //Move current to the last element
    previous = current;
    current = current->next;
    
    // Set previous next to be the last element in the list
    
    previous->next = current->next;
    
    // Free the last element
    free(current);
    
   return head;
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

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

