#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max; @@ [variable 'mark' and 'max' are used without initialization; if no '.' is found, 'mark' remains uninitialized, leading to undefined behavior]
    
    scanf("%s",a);
    printf("%s",a); @@ [this prints the input as-is before scientific notation, which is incorrect per problem requirements]
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){ @@ [relies on 'mark' being set, but if input has no '.', 'mark' is uninitialized]
        printf("%s",a);
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){ @@ [same issue: assumes 'mark' is 1, but if no decimal point exists, this condition is invalid]
        for(i=mark+1;i<len;i++){
            if(a[i]!='0'){
                max=i;
                break;
            }
        }
        printf("%c",a[max]); @@ ['max' may be uninitialized if all digits after '.' are zero, but problem states no trailing zeros, yet logic still fragile]
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
        for(i=1;i<mark;i++){ @@ [if there's no decimal point, 'mark' is uninitialized, causing undefined loop bounds]
            printf("%c",a[i]);
        }
        for(i=mark+1;i<len;i++){ @@ [same: uses uninitialized 'mark' if no '.' in input]
            printf("%c",a[i]);
        }
        printf("e%d",mark-1); @@ [uses uninitialized 'mark']
        
    }
    
    return 0;
}