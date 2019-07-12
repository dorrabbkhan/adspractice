#include <stdio.h>
int  getline(char c[], int max);
void print (char c[], int len);

int main ()
{
    char c[1000];
    int len;
    while (len != 0)
    {
        len = getline(c, 1000);
        print(c, len);
    }
}

int getline(char c[], int max)
{
    int i = 0;
    for (i = 0; (((c[i] = getchar()) != '\n')&&(i<=max)); i++);
    c[i+1]='\0';
    return i;
}
void print (char c[], int len)
{
    if (len>=5)
    {
        printf("%s", c);
    }
}
