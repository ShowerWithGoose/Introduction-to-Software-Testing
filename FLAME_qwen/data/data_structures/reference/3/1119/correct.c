#include<stdio.h>
#include<string.h>
int main(){
    char *p,*q;
    char a[100];
    int i=0;
    int c=0, b=0,flag=0,flagg=0;
    p=a;
    gets(a);
    while(*p!='\0'){
        if(*p=='-'){
            flagg = 1;
        }
        if(*p=='.'){
            i++; 
            c = i;}
        if (*p != '0' && flag == 0 && *p != '.' && *p !='-')
        {
            i++;
            b = i;
            flag = 1;
            q = p;
        }
        else
            i++;
        p++;

    }
    if(c==0)
    	c=strlen(a)+1;
    if(flagg==1)
        printf("-"); 
    if (*(q + 1) != '\0')
        printf("%c.", *q);
    else
    	printf("%c", *q);
    
    for (p = q+1; *p != '\0';p++){
        if(*p=='.')
            continue;
        printf("%c", *p);
    }
    if(c>b)
    	printf("e%d", c - b-1);
    else
    	printf("e%d", c - b+1);
    return 0;
}


