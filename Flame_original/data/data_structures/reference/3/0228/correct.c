#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{   int i,j=0;
    char a[200];
    for(i=0;i<200;i++){
        scanf("%c",&a[i]);
        if(a[i]=='\n'){
            a[i]='\0';
            break;
        }
        //printf("%c\n",a[i]);
    }
    if(a[0]=='0'&&a[1]=='.'){
        for(i=2;i<strlen(a);i++){
            if(a[i]=='0')
                j++;
            if(a[i]!='0')
                break;
        }
        //printf("%d\n",j);
        //printf("%d\n",strlen(a));
        if(a[j+3]=='\0'){
                printf("%c",a[j+2]);
                printf("e-%d",j+1);
            }
        else{
            printf("%c.",a[j+2]);
            for(i=j+3;i<strlen(a);i++)
                printf("%c",a[i]);
            printf("e-%d",j+1);
        }

    }
    else if(a[0]!='0'&&a[1]=='.'){
        for(i=0;i<strlen(a);i++){
            printf("%c",a[i]);
        }
        printf("e0");
    }
    else if(a[1]!='.'){
        for(i=0;i<strlen(a);i++){
            if(a[i]!='.')
                j++;
            if(a[i]=='.')
                break;
        }
        /*printf("%d\n",j);
        printf("%d\n",strlen(a));
        printf("%s",a);*/
            if(j==strlen(a)){
                printf("%c.",a[0]);
                for(i=1;i<strlen(a);i++)
                    printf("%c",a[i]);
                printf("e%d",j-1);
            }
            else{
                printf("%c.",a[0]);
                for(i=1;i<strlen(a);i++){
                    if(a[i]!='.')
                        printf("%c",a[i]);
                }
                printf("e%d",j-1);
            }
    }



    return 0;
}

