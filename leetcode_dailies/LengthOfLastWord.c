#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char* s);

int main()
{
    char s[] = "Hello World";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}

int lengthOfLastWord(char* s) {
    char * nextWord = strtok(s, " ");
    while (nextWord != NULL)
    {
        s = nextWord;
        nextWord = strtok(NULL, " ");
    }
    return strlen(s);

}
