#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a);
    if(a[0]=='0'){ // @@ The code only handles numbers starting with '0' (e.g., 0.xxx). It completely fails to handle numbers where the integer part is greater than or equal to 1 (like 87899.99...), resulting in no output for such cases.
        for(i=2;a[i]=='0';i++){
            
        }
        if(a[i+1]=='\0'){
            printf("%c",a[i]);printf("e");
            printf("%d",1-i);
        }
        else{
            printf("%c.",a[i]);
            for(j=i+1;a[j]!='\0';j++){
                printf("%c",a[j]);
            }
            printf("e%d",1-i);
        }
    }
    return 0;
}