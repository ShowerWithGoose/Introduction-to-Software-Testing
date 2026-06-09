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
    else if(mark==1&&a[0]=='0'){ // @@ [Same issue: 'mark' may be uninitialized; also logic assumes decimal exists at position 1, which may not hold.]
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
        for(i=1;i<mark;i++){ // @@ ['mark' may be uninitialized if no '.' in input, causing invalid loop bounds and undefined behavior.]
            printf("%c",a[i]);
        }
        for(i=mark+1;i<len;i++){ // @@ [Same: 'mark' may be uninitialized, leading to reading beyond array or incorrect indexing.]
            printf("%c",a[i]);
        }
        printf("e%d",mark-1); // @@ ['mark' may be uninitialized; if no decimal point, this uses garbage value.]
        
    }
    
    return 0;
}