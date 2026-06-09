#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ &a is incorrect type for scanf, should use a
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){
            if(a[i]==0){ // @@ Compares with null terminator 0 instead of character '0', should be a[i]=='0'
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0');
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){
            printf("%d",a[j]-'0'); // @@ Should print current character a[i]-'0', not repeatedly printing a[j]-'0'
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ main should return 0 to indicate successful execution
 }