#include<stdio.h>
int main(){

char ch; // @@ [Using `char` for `getchar()` return value is incorrect because `getchar()` returns `int` to properly handle EOF]
char a[100];
char b[100];
a[0]='0';
b[0]='0';
int i=0,j=0;

while((ch=getchar())!='.'){ // @@ [Assigning `getchar()` result to `char` may cause incorrect comparison with '.' due to sign extension or loss of EOF information]
      i++;
      a[i]=ch;

}

ch=getchar(); // @@ [Same issue: `getchar()` returns `int`, storing in `char` loses information]
while((ch=getchar())!='\n'){ // @@ [Same issue: comparing potentially truncated/misinterpreted `char` value with '\n']
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [If input has only one digit after decimal (e.g., "0.5"), this prints "5e-1" which is correct, but logic fails for cases like "0.05"]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [If all digits after leading zeros are consumed, `b[j]` is out of bounds (since `b` indices go from 1 to j), and `k==j` implies `b[k]` is beyond last digit]
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

      printf("e%d",i-1); // @@ [This assumes there's always more than one digit before decimal when not in the zero-leading case, but doesn't handle single non-zero digit correctly per spec (should omit decimal if only one digit?)]






}








return 0;
}