#include<stdio.h>
int main(){

char ch;
char a[100];
char b[100];
a[0]='0';
b[0]='0';
int i=0,j=0;

while((ch=getchar())!='.'){
      i++;
      a[i]=ch;

} @@ // The loop assumes there is always a '.' in input, but if input has no '.', getchar() may read past EOF or newline causing undefined behavior.

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;

} @@ // If input ends immediately after '.', this loop reads an extra character (possibly EOF or garbage), leading to incorrect parsing or runtime error.

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');}

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} @@ // When k == j, b[j] is the last digit, but if all digits after decimal are zero (which shouldn't happen per problem, but code doesn't validate), b[j] might be uninitialized or zero; also, exponent should be k, but for "0.9", j=1, so this branch isn't taken, but logic is fragile.
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k);

               }


}
}



else{   printf("%d.",a[1]-'0');
        for(int m=2;m<=i;m++){
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1); @@ // For inputs like "123.45", this prints "1.2345e2" correctly, but for single-digit before decimal like "5.6", it prints "5.6e0", which violates spec: if base is integer with one digit, should omit decimal point. Also, when i==0 (no digits before '.'), this branch fails because a[1] is invalid.

}








return 0;
}