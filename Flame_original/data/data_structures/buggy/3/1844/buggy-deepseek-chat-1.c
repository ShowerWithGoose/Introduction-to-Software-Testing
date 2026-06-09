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
                    printf("e-%d",j-1); // @@ Error: When the input is "0.0", the loop for(j=2;j<strlen(a);j++) will not find any non-zero digit, so j remains 2, but the exponent should be 0 (since 0.0 = 0e0). Additionally, the program does not handle the case where all digits after the decimal are zero, leading to incorrect output.
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
                    for(j=1;j<strlen(a)&&a[j]!='.';j++){
                        printf("%c",a[j]);
                    }
                    printf("e%d",i-1); // @@ Error: For numbers like "10.0", i is 2, so i-1 = 1, but the correct exponent should be 1 (since 10.0 = 1.0e1). However, the output format is incorrect because it prints "1.0e1" but the problem requires no trailing zeros after the decimal point. The program does not handle the case where there are trailing zeros after the decimal point, which violates the problem specification.
            }
        }
    }
    
    return 0;
}