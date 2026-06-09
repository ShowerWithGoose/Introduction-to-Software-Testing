#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a); // @@ [Use of unsafe function 'gets' which has been removed from C11 standard and causes compilation error with modern compilers]
    if(a[0]=='0'){
        for(i=2;a[i]=='甬';i++){ // @@ [This appears to be a corrupted character; should be '0' instead of '甬', causing syntax/semantic error]
            
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