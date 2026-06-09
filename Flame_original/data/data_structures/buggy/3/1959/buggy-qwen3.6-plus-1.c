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

    if(j==1){printf("%de-1",b[j]-'0');}

    else {while(b[k]=='0'){ // @@ Missing bounds check (k <= j) may cause out-of-bounds array access or infinite loop if the fractional part contains only zeros or if k exceeds j.
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ Should be 'else if' to avoid redundant condition evaluation and improve logical flow.
    if(k!=j){printf("%d.",b[k]-'0'); // @@ Should be 'else' to correctly handle the mutually exclusive branch when k != j.
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