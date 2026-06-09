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
} // @@ [The program uses `getchar()` in a way that may read past the input or mishandle EOF; also, variable `ch` should be of type `int` to properly detect EOF, not `char`. Additionally, the logic for handling numbers with leading zeros after the decimal point is flawed — it assumes at least one digit exists in `b`, but doesn't validate input length or handle cases where all fractional digits are zero correctly. Moreover, array indices start storing from index 1 instead of 0, causing off-by-one errors in digit processing and output formatting.]