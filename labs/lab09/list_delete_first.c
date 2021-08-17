//Program deletes the head of the list and returns new head

// by Len Au (z5308653) 27/07/20

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_first(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_first(head);
    print_list(new_head);

    return 0;
}


//
// Delete the first node in list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_first(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *current = head;
    struct node *previous = NULL;
    struct node *new_head = NULL;
    
    while (current != NULL) {
        //For the first element of the list
        if (previous == NULL) {
            //Make the second element the new head
            new_head = head->next;
            previous = new_head;
            free(head);
            //Return the new_head after freeing the head of the list
            return new_head;
        }
        //Proceed through the rest of the list
        previous = current;
        current = current->next;
    }
    
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

