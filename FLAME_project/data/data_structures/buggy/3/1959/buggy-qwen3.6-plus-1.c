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

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [Logic Error: The condition k==j is checked later, but for input "0.9" (j=1), this branch prints "9e-1". However, the else block below handles j>1. The issue is likely in the else block's logic or the handling of the 'k' variable initialization and loop bounds which might lead to incorrect output or access issues if not carefully managed, but specifically for 0.9, j=1 enters the first if. Wait, if input is 0.9, i=1, a[1]='0'. j=1, b[1]='9'. The code enters if(j==1). It prints printf("%de-1", b[1]-'0') which is printf("%de-1", 9). Output: 9e-1. This matches expected. Why Runtime Error? ]

    else {while(b[k]=='0'){ // @@ [Runtime Error: Potential out-of-bounds access or infinite loop if b[k] is not '0' and k exceeds j. Also, b is not null-terminated, but getchar loop fills it. If b contains no zeros after decimal, loop doesn't run. If it does, k increments. If k becomes > j, accessing b[k] is out of bounds if b[j] was the last char read. The array b has size 100, so unlikely overflow unless input is huge, but logical error exists.]
       k++;


    }
    if(k==j){printf("%de-%d",b[j]-'0',k);} // @@ [Logic Error: If all digits after decimal are zero except the last one, or similar edge cases. But main issue is likely below.]
    if(k!=j){printf("%d.",b[k]-'0'); // @@ [Logic Error: Formatting. Should be %c or handle char correctly. b[k] is a char digit. '9'-'0'=9. printf("%d.", 9) prints "9.". Correct so far. ]
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