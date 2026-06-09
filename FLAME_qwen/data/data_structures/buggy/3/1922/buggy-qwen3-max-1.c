#include<stdio.h> 
#include<string.h>
int main(){
    char s[100]=" ";
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and removed in C11; causes compilation error with modern compilers]
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
    
        for(i;i<=strlen(s);i++){ // @@ [Loop condition should be i < strlen(s), not i <= strlen(s); accessing s[strlen(s)] reads past the null terminator, causing undefined behavior]
            if (s[i]!='.'&&s[i]!='-')   printf("%c",s[i]);
        }
        printf("e%d",w);

    }
    return 0;
}