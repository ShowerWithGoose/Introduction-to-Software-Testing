#include<stdio.h> 
#include<string.h>
int main(){
    char s[100]=" ";
    gets(s);
    int i=0;
    int z1=0,z2=0,z3=0;

    for(i;i<strlen(s);i++){
        if(s[i]!='.') z1++;
    }
    if(z1==strlen(s)){
        if(s[0]=='-'){
            printf("-%c.",s[1]);
            i=2;
            z1=z1-1;
        }
    else {
    printf("%c.",s[0]);
    i=1;
    }    
        
        for(i;i<strlen(s);i++){
            if(s[i]!='.') printf("%c",s[i]);
        }
        printf("e%d",z1-1);
    }//
    int m,n;//用来定位 . 和第一个非零数字的位置 
    
    if(z1!=strlen(s)){
        i=0;
    for(i;i<strlen(s);i++){
        if(s[i]!='0'&&s[i]!='.'&&s[i]!='-'){
            n=i;//第一个非零 
            break;
        }
    }
    i=0;
    for(i;i<strlen(s);i++){
        if(s[i]=='.'){
            m=i;//这是 。 的位置 
            break;
        }
    }
}
    if(m<n) {// 这是描述<1的数 
        int w=m-n;
        if(n==strlen(s)-1){
            if(s[0]=='-')
            printf("-%ce%d",s[n],w);
            else
            printf("%ce%d",s[n],w);
        }
     
    if(n!=strlen(s)-1)    {
       if(s[0]!='-')
        printf("%c.",s[n]);
    else
    printf("-%c.",s[n]);
        i=n+1;
        for(i;i<strlen(s);i++){
        printf("%c",s[i]);
        }
        printf("e%d",w);
}
    }
   
    //
    if(m>n){
            int w=m-n-1;
            if(s[0]!='-'){
                    i=1;    
        printf("%c.",s[n]);
}
        else {printf("-%c.",s[n]);
        i=2;
        }
    
        for(i;i<=strlen(s);i++){ // @@ The loop condition `i<=strlen(s)` causes the loop to access `s[strlen(s)]`, which is the null terminator `\0`. While `printf` might ignore it or print nothing visible depending on implementation, strictly speaking, it processes beyond the significant digits. More importantly, in the specific test case `87899.9999999999000999`, the logic for `m>n` (number >= 10) is executed. The variable `n` is correctly identified as 0 (first non-zero digit '8'). The loop starts at `i=1`. It prints all characters except '.' and '-'. This part seems logically okay for constructing the mantissa digits. However, looking at the Buggy Output `8.78999999999999000999 e4` vs Expected `8.78999999999999000999e4`, there is no space in the expected output. The provided buggy output in the prompt description has a weird character `` which often represents a null byte or unprintable character. The loop `i<=strlen(s)` will eventually hit `s[strlen(s)]` which is `\0`. `printf("%c", '\0')` prints a null character. This null character is likely what appears as the artifact before `e4` or causes the comparison failure. The loop should be `i<strlen(s)`.
            if (s[i]!='.'&&s[i]!='-')   printf("%c",s[i]);
        }
        printf("e%d",w);

    }
    return 0;
}