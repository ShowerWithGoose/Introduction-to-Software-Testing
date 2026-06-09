#include<stdio.h>
#include<string.h>
char a[100],b[100];
int main()
{
    int na=0,j=0;
    gets(a);
    if('0'==a[0]){
        for(int i=2;a[i]=='0';i++)
            na++;
        for(int i=2+na;a[i]!='\0';i++){
            b[j++]=a[i];
        }
        if(j!=1){
            printf("%d.",b[0]-'0');
            for(int i=1;b[i]!='\0';i++){
                printf("%d",b[i]-'0');
            }
            printf("e-%d\n",na+1);
            return 0;
        }
        else{
            printf("%de-%d\n",b[0]-'0',na+1);
            return 0;
        }
    }
    else if('.'==a[1]){
        b[0]=a[0];
        j=1;
        for(int i=2;a[i]!='\0';i++){
            b[j++]=a[i];
        }
        printf("%d.",b[0]-'0');
        for(int i=1;b[i]!='\0';i++){
            printf("%d",b[i]-'0');
        }
        printf("e0\n");
        return 0;
    }
    else{
        for(int i=0;a[i]!='\0';i++){
            if(a[i]!='.')b[j++]=a[i];
        }
        for(int i=0;a[i]!='.';i++){
            na++;
        }
        printf("%d.",b[0]-'0');
        for(int i=1;b[i]!='\0';i++){
            printf("%d",b[i]-'0');
        }
        printf("e%d\n",na-1);
        return 0;
    }
}

