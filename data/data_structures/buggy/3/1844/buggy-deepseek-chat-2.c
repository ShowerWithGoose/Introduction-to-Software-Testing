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
                    printf("e-%d",j-1); // @@ Error: When the input is "0.0", the loop may not find a non-zero digit, leaving j uninitialized or causing incorrect exponent calculation. Also, the exponent should be based on the position of the first non-zero digit after the decimal, but the logic for trailing zeros is missing.
                }
                else {
                    for(j=0;j<strlen(a);j++){
                        printf("%c",a[j]);
                    }
                    printf("e0"); // @@ Error: For numbers like "1.0" (which should not appear per problem description, but if it does), the output should be "1e0" not "1.0e0". Also, the problem states no trailing zeros, but this code doesn't handle that.
                }
                }
            else{
                    printf("%c.",a[0]);
                    for(j=1;j<strlen(a)&&a[j]!='.';j++){
                        printf("%c",a[j]);
                    }
                    printf("e%d",i-1); // @@ Error: For numbers with more than one digit before the decimal (e.g., "12.34"), the exponent should be i-1, but the base should not have a decimal point if there are no digits after the decimal? Actually, the problem requires one digit before and after decimal for decimal base, but here it prints all digits before decimal after the first digit, which is incorrect. Also, it doesn't handle the case where there are no digits after the decimal.
            }
        }
    }
    
    return 0;
}