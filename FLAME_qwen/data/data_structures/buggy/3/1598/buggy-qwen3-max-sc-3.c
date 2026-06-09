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
    if(mark==1&&a[0]!='0'){ @@ [relies on 'mark' being set; if input has no '.', loop doesn't set 'mark', so condition uses uninitialized value]
        printf("%s",a);
        printf("e0");
    }
    else if(mark==1&&a[0]=='0'){ @@ [same issue: 'mark' may be uninitialized if no '.' in input]
        for(i=mark+1;i<len;i++){
            if(a[i]!='0'){
                max=i;
                break;
            }
        }
        printf("%c",a[max]); @@ ['max' may be uninitialized if all digits after '.' are zero (but problem says no trailing zeros, yet still unsafe)]
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
        for(i=1;i<mark;i++){ @@ [if no '.' in input, 'mark' is uninitialized → undefined behavior]
            printf("%c",a[i]);
        }
        for(i=mark+1;i<len;i++){ @@ [same: 'mark' uninitialized if no decimal point]
            printf("%c",a[i]);
        }
        printf("e%d",mark-1); @@ [uses uninitialized 'mark' if input has no decimal point]
        
    }
    
    return 0;
}