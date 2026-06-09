#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max;
    
    scanf("%s",a);
    printf("%s",a); // @@ [This line prints the original input before the scientific notation, which is not part of the expected output. It causes extra characters in the output.]
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){
        printf("%s",a); // @@ [This prints the original number again instead of converting it to scientific notation with exponent 0. For example, "5.3" should become "5.3e0", but this just prints "5.35.3e0".]
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