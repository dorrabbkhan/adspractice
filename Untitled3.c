#include <stdio.h>
#include <string.h>
#define MAX 1000

void reverse (char c[], int len, char n[]);
int getline (char c[], int max);
void print (char c[]);
void escape(char s[], char t[]);
void expand(char a[], char b[]);
int strrindex (char [], char []);

int main(){
    char c[MAX], n[MAX], t[MAX];
    int len = getline (c, MAX);
    reverse (c, len, n);
    print (n);
    escape (t, c);
    print (t);
    expand (c, t);
    print (t);
    getline (t, MAX);
    printf("%d", strrindex(t, c));
}

int strrindex (char a[], char b[]){
    int i = strlen(a), j = strlen(b), k, l, found = 0;
    for (; i>=0 && !found; i--){
            l = i;
            for (k = j; k >= 0 && l >= 0 && !found && a[l] == b[k]; k--, l--);
            if (k < 0)
                found = 1;
    }
    if (found)
        return i-j+1;
    else return -1;
}

void expand(char a[], char b[]){
    int i, j = 0;
    char c;
    for (i = 0; a[i] != '\0'; i++){
        if (a[i] == '-' && a[i-1] && a[i+1] != '\0' && a[i-1] <= a[i+1]){
            b[j] = a[i-1];
            for (; b[j] != a[i+1];){
                c = b[j];
                b[++j] = ++c;
            }
        }
    }
    b[++j] = '\0';
}

void escape(char s[], char t[]){
    int i, j = 0;
    for (i = 0; t[i] != '\0'; i++){
        switch (t[i]){
            case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
            case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
            default:
            s[j++] = t[i];
        }
    }
}

int getline (char c[], int max){
    int i;
    for (i = 0; (((c[i] = getchar())!='\n')&&(i<=max)); i++);
    c[i+1]='\0';
    return i;
}

void reverse (char c[], int len, char n[]){
    int i, f = len;
    for (i = 0; i <= len; i++){
        n[f--] = c[i];
        n[len+1]='\0';
    }
}

void print (char c[]){
    printf("%s\n", c);
}
