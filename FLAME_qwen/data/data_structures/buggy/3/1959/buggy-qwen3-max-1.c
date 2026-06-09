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
} // @@ [The loop does not handle EOF or newline before '.', leading to undefined behavior if input lacks a decimal point.]

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;
} // @@ [If input ends without '\n' (e.g., EOF), this loop may never terminate or read invalid data.]

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [When j==1, b[1] is the only digit after decimal, but exponent should be 1, not necessarily -1; also fails if b[1] is '0'.]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [If all digits after leading zeros are consumed, b[j] is out of valid range (b[j] was last assigned at index j, but after skipping zeros, k==j implies b[k] is beyond last significant digit).]
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k);

               }


}
}



else{   printf("%d.",a[1]-'0'); // @@ [Assumes at least one digit before decimal (i>=1), but if input starts with '.' (i=0), a[1] is uninitialized.]
        for(int m=2;m<=i;m++){
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1); // @@ [Exponent calculation assumes first non-zero digit is at position 1, but doesn't account for numbers like "123.45" correctly (should be e2, and i=3 so i-1=2 is correct), however indexing errors in a[] may corrupt this.]






}








return 0;
}