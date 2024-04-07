#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void main()
{
    return;
}

bool checkValidString(char* s) {
    // two loops

    // one loop to consider left '(' and *
    // one loop to consider right ')' and *

    int leftBalance = 0;
    int rightBalance = 0;

    for (int l = 0; l < strlen(s); l++ )
    {
        if (leftBalance < 0)
        {
            return false;
        }
        if (s[l] == '(' || '*')
        {
            leftBalance++;
        }
        if (s[l] == ')')
        {
            leftBalance--;
        }
    }

   for (int r = 0; r < strlen(s); r++ )
   {
    if (rightBalance < 0)
    {
        return false;
    }
    if (s[r] == ')' || '*')
    {
        rightBalance++;
    }
    if (s[r] == '(')
    {
        rightBalance --;
    }
   }

    return true;

}
