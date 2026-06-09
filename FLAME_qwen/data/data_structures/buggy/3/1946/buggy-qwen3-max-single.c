#include<stdio.h>
#include<string.h>
char s[200];
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in many modern environments, 'gets' is not available, leading to compilation error.]
    int l=strlen(s);
    int nt=-1;
    int r;
    int op=0;
    if(l>1){
    
    if(s[0]!='0'){
        if(s[1]=='.'){
            printf("%se0",s);
        }
        else if(s[1]!='.'){
            for(int i=0;i<l;i++){
                if(s[i]!='.'){
                    op++;
                }
                if(s[i]=='.')break;
            }
            printf("%c.",s[0]);
            for(int zn=1;zn<op;zn++){
                printf("%c",s[zn]);
            }
            for(int xc=op+1;xc<l;xc++){
                if(xc!=l-1)printf("%c",s[xc]);
                if(xc==l-1)printf("%ce%d",s[xc],op-1);
            }
        }
        
    }
    int jb=0;
    int nz=0;
if(s[0]=='0'){

for(int xy=0;xy<l;xy++){
    if(s[xy]=='0')jb++;
    if(s[xy]!='.'&&s[xy]!='0')break;
}        
        
        
        
        
        
            int sb=-(jb);
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ [If the input is "0.0", then jb becomes 2 (counting '0', '.', '0'), so s[jb+1] = s[3] which is out of bounds. Also, logic fails when all digits after decimal are zero except last one. More critically, if input is like "0.0001", jb counts initial zeros including before '.', but indexing assumes jb+1 is valid non-zero digit — but loop breaks at first non-zero or non-dot, so jb may point beyond string or to '.'.]
    for(int nmsl=jb+2;nmsl<l;nmsl++){
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb);
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}