#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max;
    
    scanf("%s",a);
    printf("%s",a); // @@ This line prints the input again, which is not part of the required output. It should be removed.
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){ // @@ This condition incorrectly handles numbers like "1.23" where mark==1 but a[0]!='0'. It should output scientific notation, not just the original number with "e0".
        printf("%s",a);
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){ // @@ This handles numbers like "0.9" but the logic for counting exponent is flawed. For "0.9", max=2, mark=1, so exponent is -(2-1) = -1, but the output should be "9e-1", not "0.99e-1". The issue is that the loop prints a[max] and then all remaining digits, but for "0.9", a[max]='9' and there are no more digits, so it prints "9", but the buggy output shows "0.99e-1", indicating a different error.
        for(i=mark+1;i<len;i++){
            if(a[i]!='0'){
                max=i;
                break;
            }
        }
        printf("%c",a[max]);
        if(max<len-1){
            printf(".");
            for(i=max+1;i<len;i++){
                printf("%c",a[i]);
            }
        }
        printf("e-%d",max-mark);
    }
    else{ // @@ This handles numbers with more than one digit before decimal (e.g., "12.34"), but the output format is incorrect. It prints the first digit, then a dot, then all remaining digits (including those before the decimal point), which is not the correct scientific notation.
        printf("%c",a[0]);
        printf(".");
        for(i=1;i<mark;i++){
            printf("%c",a[i]);
        }
        for(i=mark+1;i<len;i++){
            printf("%c",a[i]);
        }
        printf("e%d",mark-1);
        
    }
    
    return 0;
}