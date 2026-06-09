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
} // @@ [The loop does not handle the case where input has no decimal point, leading to infinite loop or undefined behavior]

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;
} // @@ [If input ends immediately after '.', this loop may read beyond intended input or miss the newline correctly]

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [If j==1, b[1] is the only digit, but exponent should be 1, not necessarily -1; also assumes input like "0.x" always leads to e-1 which is incorrect for "0.5" -> should be 5e-1, but logic fails for "0.10" though problem says no trailing zeros]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [If all digits after leading zeros are consumed, b[j] is out of valid significant digits; should use b[k] instead of b[j]]
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k);

               }


}
}



else{   printf("%d.",a[1]-'0'); // @@ [Assumes at least one digit before '.', but if input starts with non-zero digit and i>=1, a[1] is first digit; however indexing is off because a[0] is unused dummy]
        for(int m=2;m<=i;m++){
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1); // @@ [Exponent calculation assumes number of digits before decimal is i, but since a[1] is first real digit, total digits = i, so exponent = i-1 is correct only if first digit is non-zero and in correct position; however indexing inconsistency may cause wrong exponent]






}








return 0;
}