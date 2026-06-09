#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char a[BUFSIZ],b[BUFSIZ];
int c[BUFSIZ];
int i,j,k,o,t;
int x,s;

int main(){
    gets(a);
    for (i=0,j=0,k=0;i<strlen(a);i++)  //k是第一个数字的位置  i是当前位置 j是抽取出来后的位置 t是当前数字最后一位的位置
    {
        if (a[i]=='*'||a[i]=='/'||a[i]=='+'||a[i]=='-'||a[i]=='=')
        {
            if (a[i] != '=') b[j] = a[i];
            t = i-1;
            for (;t>k;)
            {
                if (a[t] != ' ') break;
                else t--;
            }
            for (o=k;o<=t;o++)
            {
                x += pow(10,t-o)*(int)(a[o]-'0');
            }
            c[j++] = x;
            x = 0;
            k = i+1;
            for (;a[k]==' ';k++);
        }
    }
    b[j] = '\0';
    if (strlen(b)==0){
        if (a[0]>=48&&a[0]<=57)
        {
            for (i = 0; a[i] != '='&&a[i] != ' '; i++)
            {
                printf("%c",a[i]);
            }
        }
        else printf("0");
    }
    else{
        for (i = 0,j = 0; i < strlen(b); i++){
            if (b[i] == '*'||b[i] == '/'){
                j = i-1;
                if (b[i] == '*') c[i+1] = c[i]*c[i+1];
                else c[i+1] = c[i]/c[i+1];
                c[i] = 0;
                if (b[j]=='-') b[i] = '-';
                else b[i] = '+';
            }
        }
        s = c[0];
        for (i = 0; i < strlen(b); i++){
            if (b[i] == '+')
            {
                s += c[i+1];
            }
            else s -= c[i+1];
        }
        printf("%d",s);
    }
    return 0;
}
