#include<stdio.h>
#include<string.h>

char a[100],b[100];

int main()
{
    int i,j;
    int len,mark,max; // @@ Variables 'mark' and 'max' are used without initialization. If the search loops do not find the target characters, they will hold garbage values, leading to undefined behavior or incorrect results. They should be initialized.
    
    scanf("%s",a);
    printf("%s",a); // @@ This line incorrectly prints the original input string before processing, causing extra output that does not match the expected format.
    
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if(mark==1&&a[0]!='0'){
        printf("%s",a);
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