// Program copies all of the values in source1 
// which are also found in source2 into destination
// return the number of elements copied into destination

// by Len Au 29/06/20 (z5308653)

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.

int common_elements(int length, int source1[length], int source2[length], 
    int destination[length]) {

    //Loop through the elements for common elements
    int i = 0;
    int j = 0;
    //counts how many integers in destination array
    int destination_count = 0;
    int found = 0;
    while (i < length) {
        j = 0;
        found = 0;
        while (j < length && found == 0) {
            if (source1[i] == source2[j] && destination_count < length) {
                destination[destination_count] = source1[i];
                //stops looping through array once there is a common value
                found = 1;
                //stops loop from going outside the array
                destination_count++;

            }
            //counts across source2 array
            j++; 
        }
        //count across source1 array
        i++;
        
    }
    //returns destination array values
    return destination_count;
}
