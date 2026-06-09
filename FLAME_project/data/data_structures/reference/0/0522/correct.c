#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    gets(a);
    printf("%c",a[0]);
    for(int i=1;i<strlen(a)-1;i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]))
            {
                for(int k=1;k<a[i+1]-a[i-1];k++){
                    printf("%c",a[i-1]+k);
                }
            }
            else{
                printf("%c",a[i]);}
        }
        else{
            printf("%c",a[i]);}
    }
    printf("%c",a[strlen(a)-1]);
    return 0;
}



