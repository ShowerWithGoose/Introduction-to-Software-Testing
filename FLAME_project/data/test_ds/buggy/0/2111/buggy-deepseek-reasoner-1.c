#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int read(){
    char c;
    c=getchar();
    int a=0;
    int f=1;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        a=(a<<1)+(a<<3)+c-'0';
        c=getchar();
    }
    return f*a;
}
char s[20000001]; // @@ Stack overflow: Declaring a local array of 20 million characters (about 19 MB) exceeds typical stack size limits, causing a crash or undefined behavior. Should be declared globally or allocated dynamically.
int main(){
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;++i){
        if(s[i]!='-'){
             putchar(s[i]);
        }
        else{
            if(i!=0&&i!=l-1){
                if(s[i-1]<s[i+1]){
                    if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'){
                        for(int j=s[i-1]+1;j<s[i+1];++j)
                            putchar(j);
                        goto A;
                    }
                    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'){
                        for(int j=s[i-1]+1;j<s[i+1];++j)
                            putchar(j);
                        goto A;
                    }
                    if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'){
                        for(int j=s[i-1]+1;i<s[i+1];++j) // @@ Infinite loop: Loop condition uses 'i' instead of 'j', causing an infinite loop because 'i' never changes. Should be j < s[i+1].
                            putchar(j);
                        goto A;
                    }
                    putchar('-');
                    A:;
                }
                else{
                putchar('-');
                }    
            }else{
                putchar('-');
            }
        }
    }
    return 0;
}