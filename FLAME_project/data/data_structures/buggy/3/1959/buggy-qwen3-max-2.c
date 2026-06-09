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

} // @@ [If input starts with '.', this loop never runs and i remains 0, but more critically, if input has no '.' at all, this causes infinite loop or undefined behavior. However, per problem statement input always has digits before and after '.', so main issue is uninitialized `ch` on first use and potential out-of-bound writes.]

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;

} // @@ [This skips the first digit after the decimal point because `ch=getchar()` is called twice: once before the loop and once in the condition. Thus, the first character after '.' is lost.]

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [Since the first digit after '.' was skipped, b[1] may be uninitialized or hold wrong value; for input "0.9", j becomes 0 (no digits read in second loop), leading to undefined behavior accessing b[1].]

    else {while(b[k]=='0'){
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [Same issue: b array doesn't contain the correct digits due to skipping first char after '.']
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

      printf("e%d",i-1); // @@ [This branch assumes there are digits before decimal, but due to incorrect reading logic (especially losing first digit after '.'), output will be wrong even if this branch is taken.]

}








return 0;
}