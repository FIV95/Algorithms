#include <stdbool.h>
#include <stdio.h>
#include<string.h>

bool isIsomorphic(char* s, char* t)
{
    if (strlen(s) != strlen(t))
    {
        return false;
    }

int sArray[256];
int tArray[256];
memset(sArray, 0, sizeof(sArray));
memset(tArray, 0, sizeof(tArray));
}

int main()
{
    char s[] = "egg";
    char t[] = "add";
    printf("%d\n", isIsomorphic(s, t));
    return 0;
}
