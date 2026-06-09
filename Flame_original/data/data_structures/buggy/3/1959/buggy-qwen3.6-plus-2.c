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

    if(j==1){printf("%de-1",b[j]-'0');} // @@ Assumes b[1] is non-zero; if input violates spec and is "0.0", it incorrectly prints "0e-1".

    else {while(b[k]=='0'){ // @@ Lacks bounds check (k < j); if all fractional digits are '0', this causes an infinite loop or out-of-bounds memory access.
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);}
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){ // @@ Variable declaration inside for loop is a C99 feature; may trigger a compilation error in strict C89/C90 environments.
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k);

               }


}
}



else{   printf("%d.",a[1]-'0');
        for(int m=2;m<=i;m++){ // @@ Variable declaration inside for loop is a C99 feature; may trigger a compilation error in strict C89/C90 environments.
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){ // @@ Variable declaration inside for loop is a C99 feature; may trigger a compilation error in strict C89/C90 environments.
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1);






}








return 0;
}