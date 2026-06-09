#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a);
    if(a[0]=='0'){
        for(i=2;a[i]=='0';i++){
            
        }
        if(a[i+1]=='\0'){
            printf("%c",a[i]);printf("e");
            printf("%d",1-i); // @@ The exponent calculation is incorrect. For numbers like 0.001, the exponent should be -3, but 1-i gives -2 when i=3. The correct exponent is 1-i, but the loop starts at i=2, so the exponent should be 2-i, not 1-i.
        }
        else{
            printf("%c.",a[i]);
            for(j=i+1;a[j]!='\0';j++){
                printf("%c",a[j]);
            }
            printf("e%d",1-i); // @@ Same exponent error as above. For numbers like 0.001, the exponent should be -3, but 1-i gives -2 when i=3. The correct exponent is 2-i.
        }
    }
    return 0;
}