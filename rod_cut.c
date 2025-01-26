#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_max(int a, int b) { return (a > b) ? a : b; }
int cut_rod(int values[], int supplied_rod_length, int *remainder){
    if (supplied_rod_length <= 0)
        return 0;
    int last_val = 0; //keeps track of what the previous value of max_val was, for the purpose of getting the remainder at the end
    int max_val = 0;
 
    //Recursively find and compare every way the rods can be cut to find the highest value
    for (int i = 0; i < supplied_rod_length; i++){
        max_val = find_max(max_val, values[i] + cut_rod(values, supplied_rod_length - i - 1, remainder));
        printf("%d @ %d = %d \n", supplied_rod_length, i, values[i]);
        if (max_val > last_val){
            *remainder = supplied_rod_length - 1;
            last_val = max_val;
        }
    }

    return max_val;
}

int main(){
    int supplied_rod_length;
    int *values; //The list of values of possible cut lengths
    int output_value;
    int remainder; //the amount of length we will have remaining after the cutting is finished
    int rod_list_length; //Inputted length of a rod
    int rod_list_value; //Inputted value of the same rod

    printf("***Rod Cutting Problem***\n");
    printf("Enter rod length:\n");

    scanf("%d", &supplied_rod_length);

    printf("supplied length: %d\n", supplied_rod_length);
    printf("enter your list of rods (ctrl-z to end the list):\n <Length> <Value>\n ");


    values = (int*)malloc(supplied_rod_length * sizeof(int)); //Allocating new memory for the values array, of the same length as our supplied rod length

    for(int i = 0; i < supplied_rod_length; i++){
        values[i] = 0;
    }

    while(scanf("%d %d", &rod_list_length, &rod_list_value) != EOF){ //IF the user types a 'ctrl-z' the output fo scanf will be EOF
        if(rod_list_length <= supplied_rod_length){ //If the user gives us a rod BIGGER than the supplied rod, we can never use this value and throw it out
            values[rod_list_length - 1] = rod_list_value;
        }
    }

    output_value = cut_rod(values, supplied_rod_length, &remainder);

    printf("Remainder: %d\n", remainder);
    printf("Value = %d \n", output_value);
    
    return 0;
}