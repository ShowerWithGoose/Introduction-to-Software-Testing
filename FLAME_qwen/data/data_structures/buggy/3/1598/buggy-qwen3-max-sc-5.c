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
    if(mark==1&&a[0]!='0'){ // @@ [Variable 'mark' may be uninitialized if input has no decimal point, leading to undefined behavior.]
        printf("%s",a);
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){ // @@ [Same issue: 'mark' may be uninitialized if there's no '.' in input. Also, condition assumes decimal point is at index 1, but what if input is "0.0"?]
        for(i=mark+1;i<len;i++){
            if(a[i]!='0'){
                max=i;
                break;
            }
        }
        printf("%c",a[max]); // @@ ['max' may be uninitialized if all digits after '.' are zero, causing undefined behavior.]
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