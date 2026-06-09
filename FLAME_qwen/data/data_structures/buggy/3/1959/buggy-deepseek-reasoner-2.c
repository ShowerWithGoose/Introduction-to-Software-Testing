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

}

ch=getchar(); // @@ This line reads the first digit after the decimal point but does not store it, causing the loss of that digit.
while((ch=getchar())!='\n'){ // @@ This loop starts reading from the second digit after decimal, so the first fractional digit is never stored in b.
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ j==1 would mean only one digit stored (the second digit after decimal), but the actual first digit is missing, so output is incorrect.

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ Uses b[j] which is not the leading non-zero digit due to missing first digit; exponent also incorrect.
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

       for(int m=1;m<=j;m++){ // @@ This loop prints fractional digits starting from index 1 (b[1]), but the first fractional digit is stored nowhere, so output omits it.
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1);






}








return 0;
}