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

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ Error: When j==1, b[1] is the digit after the decimal point, but the exponent should be 1 (since 0.9 = 9e-1). However, the code prints b[j]-'0' which is correct for the base, but the exponent is hardcoded as -1, which is correct for this case. The real issue is that the code does not handle the case where j==0 (no digits after decimal) or when the input has only one digit after decimal like "0.9". Actually, for "0.9", j=1, so this branch executes and prints "9e-1", which is correct. But the buggy output is empty, meaning the program likely crashes or fails to read input correctly. The problem is in the input reading: after reading up to the decimal point, the code does `ch=getchar();` which consumes the newline or next character incorrectly, causing the second while loop to fail. Specifically, after the first while loop, the next character is the first digit after the decimal (e.g., '9'), but the code does `ch=getchar();` which reads that digit and discards it, then the second while loop starts reading from the next character (which might be newline or EOF), leading to j=0 and no output. The fix would be to not have that extra `ch=getchar();` line.

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);}
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