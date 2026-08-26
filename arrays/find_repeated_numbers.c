/*
The repeated numbers are stored in heap in "repeated_numbers_array"
return the count of numbers repeated
*/
int repeated_number_finder(int size, int *input_array){
    int *repeated_numbers_array = (int *)malloc((size/2) * sizeof(int));
    int repeated_numbers = 0;

    // if the array size is only 1, no repeition possible
    if(size == 1)
        return 0;

    for(int i=0; i<size; i++){
        // Check if the current number is already present in the "repeated_numbers_array".
        // If yes, we can directly skip this iteration as it is already known to be repeating.
        bool already_checked = false;
        for(int k=0; k<repeated_numbers; k++){
            if (input_array[i] == repeated_numbers_array[k]){
                already_checked = true;
                break;
            }
        }

        if (already_checked)
            continue;
    
        for(int j=i+1; j<size; j++){
            if(input_array[i] == input_array[j]){
                repeated_numbers_array[repeated_numbers] = input_array[i];
                repeated_numbers ++;
                break;
            }
        }
    }

    return repeated_numbers;
    
}