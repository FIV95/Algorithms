#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize);

int main()
{
    int left[] = {4, 3};
    int right[] = {0, 1};
    int result = getLastMoment(4, left, 2, right, 2);
    printf("Result: %d\n", result);
}

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {
    /*
    ## Ants are walking down a plank - N length long
    ## They can move on the left or the right

    // EXAMPLE

    left = [0,3,5]
    right = [1,4]

    n = 7

    plank visualization
    ## [0, x, x, 3, x, 5, x, x] <--- these guys are moving to the left
    ## [x, 1, x, x, 4, x, x, x] ---> these guys are moving to the right

    ## only concerned about the max distance
    ## ants wont really change directions they just pass through
    ## trade places
     /

    // for ants movin left it will be highest number
    // highest = 5
    // for ants moving right it will be lowest number
    // lowest = 1

    // we compare using n

    /
    ## highest equaton abs(0 - highest)
    0 - 5 = |5| 
    ## lowest equation (length - lowest)
    7 - 1 = 6
    */

    int leftMax = INT_MIN;
    int rightLow = INT_MAX;


    for (int i = 0; i < leftSize; i ++)
    {
        if (left[i] > leftMax)
        {
            leftMax = left[i];
        }
    }

    for (int j = 0; j < rightSize; j++)
    {
        if (right[j] < rightLow )
        {
            rightLow = right[j];
        }
    }

    if (leftMax == INT_MIN)
    {
        return n - rightLow;
    }

    if (rightLow == INT_MAX)
    {
        return leftMax;
    }

    if (abs(0 - leftMax) >  n - rightLow)
    {
        return abs(0 - leftMax);
    }

    return n - rightLow;
}

