#include<stdio.h>
int main(){

char ch;
char a[100];
char b[100];
a[0]='0';
b[0]='0';
int i=0,j=0;

while((ch=getchar())!='.'){ @@ // Error: 'ch' is declared as char, but getchar() returns int; comparing signed char to EOF (which is -1) can cause infinite loop or undefined behavior if char is unsigned.
      i++;
      a[i]=ch;

}

ch=getchar();
while((ch=getchar())!='\n'){ @@ // Same error: 'ch' should be int to properly handle EOF and avoid misinterpretation of byte values.
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');}

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} @@ // Logic error: when k == j, b[j] is out of bounds (b index runs from 1 to j), and also fails to handle case where all fractional digits are zero except last one correctly.
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

      printf("e%d",i-1); @@ // Logic error: exponent calculation assumes at least one digit before decimal, but doesn't account for numbers like "123.45" correctly in all cases; however main issue is missing handling of trailing zeros and incorrect indexing assumptions.

}








return 0;
}