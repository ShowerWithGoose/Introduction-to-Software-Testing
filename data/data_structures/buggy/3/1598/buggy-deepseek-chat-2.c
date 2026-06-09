#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max;
    
    scanf("%s",a);
    printf("%s",a); // @@ This line prints the input again, which is not part of the expected output. The program should only output the scientific notation, not the original number.
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){
        printf("%s",a); // @@ This prints the entire original number including the decimal point, but the base should have only one digit before the decimal point. For example, "1.23" should become "1.23e0", but this prints "1.23e0" which is correct only if there's exactly one digit before the decimal. However, the problem requires the base to have one significant digit before and after the decimal point, so this is incorrect for cases like "12.3" (should be "1.23e1").
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
        printf("e-%d",max-mark);
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
        printf("e%d",mark-1);
        
    }
    
    return 0;
}