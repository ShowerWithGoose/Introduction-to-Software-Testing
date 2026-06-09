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

ch=getchar(); // @@ This extra getchar consumes the first digit after the decimal point, causing it to be lost. The digit should be read as part of the next while loop.
while((ch=getchar())!='\n'){ // @@ Because the first digit after decimal was already consumed, this loop starts reading the second digit (or newline), missing the correct fraction digit. Should be: while((ch=getchar())!='\n') but with ch initialized to the first digit after decimal.
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ If j==0, b[j] is uninitialized (since b[1] not set), causing undefined behavior.

    else {while(b[k]=='0'){ // @@ If j==0, b[1] is uninitialized, leading to potential runtime error or infinite loop.
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ Same uninitialized access.
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

      printf("e%d",i-1);






}








return 0;
}