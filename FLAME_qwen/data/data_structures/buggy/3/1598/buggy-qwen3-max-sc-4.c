#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max;
    
    scanf("%s",a);
    printf("%s",a); // @@ [This line prints the original input before scientific notation, which is incorrect per problem requirements. The output should only be the scientific notation.]
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){
        printf("%s",a); // @@ [This prints the original number again instead of converting it to scientific notation with exponent 0. Also, "e0" should follow a normalized base (e.g., "d.e0", not the original form).]
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){
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
        printf("e-%d",max-mark); // @@ [The exponent should be -(max - mark + 1) or similar; current logic gives wrong exponent (e.g., for "0.001", mark=1, max=3, outputs e-2 but should be e-3).]
    }
    else{
        printf("%c",a[0]);
        printf(".");
        for(i=1;i<mark;i++){
            printf("%c",a[i]);
        }
        for(i=mark+1;i<len;i++){
            printf("%c",a[i]);
        }
        printf("e%d",mark-1); // @@ [This assumes there's always a decimal point and mark is set, but if input has no decimal point (e.g., "123"), mark is uninitialized, leading to undefined behavior.]
        
    }
    
    return 0;
}