#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    int i,j,k,flag=0;
    gets(a);
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='.'){
            if(i==1){
                if(a[0]=='0'){
                    for(j=2;j<strlen(a);j++){
                        if(a[j]!='0'){
                            if(j==strlen(a)-1){
                                printf("%c",a[j]);
                            }
                            else{
                            printf("%c.",a[j]);
                            for(k=j+1;k<strlen(a);k++){
                                printf("%c",a[k]);
                            }
                            }
                            
                            break;
                        }
                    }
                    printf("e-%d",j-1);
                }
                else {
                    for(j=0;j<strlen(a);j++){
                        printf("%c",a[j]);
                    }
                    printf("e0");
                }
                }
            else{
                    printf("%c.",a[0]);
                    for(j=1;j<strlen(a)&&a[j]!='.';j++){ // @@ This loop condition stops at the decimal point, but it should also include digits after the decimal point. The loop should continue to the end of the string to print all digits after the decimal point.
                        printf("%c",a[j]);
                    }
                    printf("e%d",i-1);
            }
        }
    }
    
    return 0;
}