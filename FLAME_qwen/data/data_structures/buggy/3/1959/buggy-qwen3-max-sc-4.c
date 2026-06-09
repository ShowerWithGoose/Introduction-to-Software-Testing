#include<stdio.h>
int main(){

char ch;
char a[100];
char b[100];
a[0]='0';
b[0]='0';
int i=0,j=0;

while((ch=getchar())!='.'){ @@ // Error: 'ch' is declared as char, but getchar() returns int; using char may cause EOF comparison issues and misinterpretation of high-bit characters.
      i++;
      a[i]=ch;

}

ch=getchar(); @@ // Error: Same issue—getchar() returns int, but stored in char 'ch', which can lead to incorrect behavior when handling EOF or extended ASCII.
while((ch=getchar())!='\n'){ @@ // Error: Again, 'ch' should be int to correctly handle all possible return values from getchar(), including EOF.
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} @@ // Error: If input has only one digit after decimal (e.g., "0.5"), this prints "5e-1", which is correct, but logic assumes b[1] exists; however, if input ends immediately after '.', j remains 0, leading to out-of-bound access.

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} @@ // Error: When k == j, b[j] is beyond the last valid digit (since b indices go from 1 to j), so b[j] is uninitialized or '\0'; should use b[k] instead.
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k);

               }


}
}



else{   printf("%d.",a[1]-'0'); @@ // Error: Assumes at least one digit before decimal (i==1 means a[1] is first digit), but if input starts with multi-digit like "123.45", this prints "1." then rest—but if i==0 (no digits before '.'), this accesses a[1] which is invalid. However, per problem, there are digits before and after '.', so i>=1. Still, indexing starts at a[1], skipping a[0] which was set to '0' unnecessarily.
        for(int m=2;m<=i;m++){
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1); @@ // Error: Exponent calculation assumes number is >=1. For example, "123.45" → i=3, exponent=2 → "1.2345e2", correct. But logic fails to handle cases where leading zeros exist before non-zero (but problem states no leading zeros except single zero). However, main issue is array indexing starting at 1, making code fragile.






}








return 0;
}