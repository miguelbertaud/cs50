/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int end = n-1;
    int start = 0;
    
    
    if (n < 0)
    {
         return false;
    }
    
    while (end >= start)
    {
        int middle = (start + end) / 2;
        
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    int temp;
    for (int i = 0; i < n; i++)
    {
        int smallest_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (values[smallest_index] > values[j])
                smallest_index = j;
        }
        // Swap values;
        temp = values[smallest_index];
        values[smallest_index] = values[i];
        values[i] = temp;
    }
    return;
}
