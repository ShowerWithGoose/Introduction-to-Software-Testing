#include<stdio.h>
#include<string.h>
int main()
{
    char a[110];
    gets(a);
    if(a[0]=='0'){
        int k=0,i=2;
        for(;a[i]=='0';i++){
            k++;
        }
        if(i==strlen(a)-1)
        printf("%ce-%d",a[i],k+1);
        else{
        printf("%c.",a[i]);
        i++;
        for(;i<strlen(a);i++){
            printf("%c",a[i]);
        }
        printf("e-%d",k+1);
    }}
    else{
        for(int j=0;j<strlen(a);j++){
            if(a[j]=='.'){
                break;
            }
            else if(j==strlen(a)-1){
                int x=0;
                for(int k=strlen(a)-1;k>=0;k--){
                    if(a[k]=='0'){
                        x++;
                    }
                    else
                        break;
                }
                if(x==strlen(a)-1){
                    printf("%ce%d",a[0],strlen(a)-1);
                }
                else{
                    printf("%c.",a[0]);
                    for(int k=0;k<strlen(a)-x;k++){
                        printf("%c",a[k]);
                    }
                    printf("e%d",strlen(a)-1);
                }
            }
        }
        int m=0;
        for(int j=0;j<strlen(a);j++){
            if(a[j]!='.'){
                m++;
            }
            else{
                break;
            }
        }
        printf("%c.",a[0]);
        for(int j=0;j<strlen(a);j++){
            if(a[j]=='.')
                continue;
            else if(j>0)
                printf("%c",a[j]);
        }
        printf("e%d",m-1);
    }
    return 0;
}




