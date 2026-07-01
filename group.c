/*
name: Natalie Bittar
Date: 30/4/2023
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE_ENLARGE 10 /*Define the constant value to add when resizing the group array*/
#define ENLARGE_SIZE(x) ((x+1) * sizeof(int))
int get_set(int *size_ptr);
int print_set(int *group, int size);
int main() 
{
    int size;
    int *group;
    *group = get_set(size);
    print_set(group, size);
    free(group); /* Free the memory allocated for the group array*/
    return 0;
}

/*This function take Set as input and remove duplicates*/
int get_set(int  *size_ptr) 
{
    int value, i;
    int *group ;
    int found = 0;
    *group = NULL; /* Initialize the group */
    *size_ptr = 0; /*Initialize the size to zero*/
    printf("please enter an integer numbers");
    while (scanf("%d", &value) != EOF) /* while loop read input integers until EOF*/ 
    {
        printf("%d\n");
        for (i = 0; i < *size_ptr; i++)  /*Check if the value is group*/
        {
         /*Loop over array */
          if (group[i] == value)
          {
               found = 1;
               break;
          }
        }
        if (!found)/*If the value is not in the group, add it */
        {
            (*size_ptr)++;
            if (*size_ptr == 1) 
            {
				/*If array is empty then malloc for first element */
              group =malloc((*size_ptr) * sizeof(int));
            } 
       else 
            {
                if ((*size_ptr - 1) % SIZE_ENLARGE == 0) /*If array has elements already then use realloc to dynamically change the size*/
                {
                    group = realloc(group, (*size_ptr) * sizeof(int) + SIZE_ENLARGE * sizeof(int));
                }
            }		
            group[(*size_ptr)-1] = value; /*Add element to the back of the array*/
        }
    }

    return group;
}

/*Print the Set without duplicates*/
int print_set(int *group, int size) 
{
    int i;
    printf("Group members:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", group[i]);
    }
    return 0;
}

