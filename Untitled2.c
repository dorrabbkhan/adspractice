#include <stdio.h>
#define MAX 100
int getline(char c[], int max);
int check(char c[], int len);
void print(char c[], int len);

int main(){
    char c[MAX];
    int len;
    len = getline (c, MAX);
    len = check (c, len);
    print (c, len);
}

int getline(char c[], int max){
    int i;
    for (i = 0; (((c[i] = getchar())!='\n')&&(i<=max)); i++);
    c[i+1]='\0';
    return i;
}

int check(char c[], int len){
    int i;
    for (i = len; ((c[i] == '\n') || (c[i] == ' ') || (c[i] == '\t')); i--);
    c[++i] = '\0';
    return i;
}
void print (char c[], int len){
    printf("%s %d", c, len);
}
