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
} // @@ [If input ends without '\n' (e.g., EOF), this loop may run indefinitely or access invalid memory.]

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [If j==1, b[1] is the only digit after decimal, but exponent should be 1, not -1? Also assumes input like "0.5" -> "5e-1", which is correct, but logic for k and exponent is inconsistent below.]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [If all digits after leading zeros are consumed, b[j] is out of bounds (since b indices go from 1 to j). Should be b[k], but k==j implies b[k] is '\0' or beyond valid data.]
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k); // @@ [Exponent should be k+1? For "0.005", k=2 (skipping two zeros), exponent should be -3, not -2.]

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

      printf("e%d",i-1); // @@ [For numbers like "123.45", i=3 (digits '1','2','3'), so exponent i-1=2 is correct ("1.2345e2"). But if input has no fractional part (e.g., "123."), j=0, and the loop for b doesn't run, which is okay. However, the program assumes at least one digit after '.' due to input spec, so maybe acceptable. Still, indexing starts at 1, which is unconventional and error-prone.]

}








return 0;
}