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
    if(mark==1&&a[0]!='0'){ // @@ This condition incorrectly handles numbers like "1.23" where mark==1 but a[0]!='0'. It prints the whole number and "e0", but the correct output should be "1.23e0" only if the number is already in scientific notation form. However, the logic is flawed because it doesn't handle the case where there are multiple digits before the decimal point.
        printf("%s",a);
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){ // @@ This handles numbers like "0.9" but the logic for counting the exponent is incorrect. For "0.9", mark=1, max should be 2 (index of '9'), and the exponent should be -1, but the code prints "0.99e-1" because it prints a[0] ('0') and then the rest incorrectly.
        for(i=mark+1;i<len;i++){
            if(a[i]!='0'){
                max=i;
                break;
            }
        }
        printf("%c",a[max]); // @@ This prints the first non-zero digit after the decimal, but for "0.9", it prints '9' correctly, but then the next line prints a '.' and the remaining digits, which includes the '9' again, causing duplication.
        if(max<len-1){
            printf(".");
            for(i=max+1;i<len;i++){
                printf("%c",a[i]);
            }
        }
        printf("e-%d",max-mark); // @@ The exponent calculation is correct for this case (max-mark = 2-1 = 1), but the output is wrong due to the previous duplication.
    }
    else{ // @@ This handles numbers with more than one digit before the decimal point (e.g., "12.34"), but the output format is incorrect. It prints the first digit, then a dot, then all remaining digits (including the decimal point's position), and then "e" with the exponent. However, it should only have one digit before the decimal point in the base.
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