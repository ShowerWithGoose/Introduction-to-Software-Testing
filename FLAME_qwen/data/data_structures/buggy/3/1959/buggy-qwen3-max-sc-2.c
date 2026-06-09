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

    if(j==1){printf("%de-1",b[j]-'0');} @@ [If j==1, then b[1] is the only digit after decimal, but exponent should be 1 (not -1) because "0.x" becomes x * 10^-1; however, logic for k and exponent is inconsistent here.]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} @@ [If k==j, it means all digits after decimal up to j are zero except possibly b[j], but b[j] may be out of valid range or logic miscounts exponent. Also, if all digits are zero until last, exponent should be k+1?]
    if(k!=j){printf("%d.",b[k]-'0');
               for(int m=k+1;m<=j;m++){
                  printf("%d",b[m]-'0');

               }
               printf("e-%d",k); @@ [Exponent should be k+1, not k, because "0.00...x" has exponent -(number of leading zeros + 1). For example, 0.001 -> 1e-3, not 1e-2.]

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

      printf("e%d",i-1); @@ [This assumes there's at least one digit before decimal and first digit is non-zero, which matches problem constraints, so this part may be okay. However, if input is like "5.0", output becomes "5.e0", but expected is "5e0" (no decimal point if no fractional part in normalized form). But problem says: if base is integer, no decimal point. So printing ".0..." when j>=1 is wrong — even if trailing zeros aren't present per problem, we shouldn't print decimal point if no fractional digits remain after normalization. However, in this branch, since original had digits after decimal, but in scientific notation, we must include them only if needed. But more critically: the program always prints a decimal point in this branch, violating requirement that integer base has no decimal point.]


}








return 0;
}