#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, the program does not handle non-zero-leading numbers (i.e., the 'else' case is missing), leading to incorrect output or no output for inputs not starting with '0'.]
    if(a[0]=='0'){
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
    return 0; // @@ [Missing handling for numbers that do not start with '0', causing the program to output nothing for such inputs, which violates the problem requirements.]
}