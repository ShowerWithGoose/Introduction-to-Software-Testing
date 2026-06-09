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
        int w=m-n; @@ [The exponent should be negative (n - m - 1), but here it's computed as m - n which gives a negative value with wrong magnitude. Also, the problem states input has no sign, so handling '-' is unnecessary and causes logic errors.]
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
        printf("e%d",w); @@ [Exponent 'w' is negative but printed without a minus sign because %d prints negative numbers with '-', but the calculation m-n is incorrect. Should be e-(n-m-1). Also, problem states input has no sign, so '-' handling is invalid.]
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
    
        for(i;i<=strlen(s);i++){ @@ [Loop goes to <= strlen(s), which accesses s[strlen(s)] == '\0', causing a null character to be printed in output. Should be i < strlen(s).]
            if (s[i]!='.'&&s[i]!='-')   printf("%c",s[i]);
        }
        printf("e%d",w);

    }
    return 0;
}