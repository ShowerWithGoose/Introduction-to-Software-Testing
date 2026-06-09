#include<stdio.h>
#include<string.h>
int main()
{
    char a[300];
    gets(a);
    int i,j,l=strlen(a),zs;
    if(a[0]=='0'){
        for(i=2;a[i]=='0';i++);
        zs=-(i-1);
        printf("%c",a[i]);
        if((i+1)!=l)printf(".");
        for(j=i+1;j<l;j++){
            printf("%c",a[j]);
        }
        printf("e%d",zs);
    }
    else{
        for(i=0;a[i]!='.'&&i<l;i++);
        zs=i-1;
        if(a[0]<='9'&&a[0]>'0'&&a[1]=='\0'){
            printf("%c",a[0]);
            return 0;
        }
        else {
            printf("%c.",a[0]);
            for(i=1;i<l;i++){
                if(a[i]!='.'){
                    printf("%c",a[i]);
                }
            }
            printf("e%d",zs);
        }
    }
    return 0;
}

