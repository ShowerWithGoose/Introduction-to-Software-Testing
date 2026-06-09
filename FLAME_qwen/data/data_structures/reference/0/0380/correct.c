#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    gets(a);
    int i=0;
    int len=strlen(a);
    char b;
    for(i=0; i<len; i++) {
        if(a[i+1]=='-'&&a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i]<a[i+2]) {

            for(b=a[i]; b<a[i+2]; b++) {
                printf("%c",b);
            }i++;
        }
        else if(a[i+1]=='-'&&a[i]>='a'&&a[i]<='z'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i]<a[i+2]) {

            for(b=a[i];b<a[i+2]; b++) {
                printf("%c",b);
            
            }i++;
        }
        else if(a[i+1]=='-'&&a[i]>='A'&&a[i]<='Z'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i]<a[i+2]) {

            for(b=a[i]; b<a[i+2]; b++) {
                printf("%c",b);
           
            }i++;
        }
        else {
            printf("%c",a[i]);
        }
       
    }
    return 0;
    }


