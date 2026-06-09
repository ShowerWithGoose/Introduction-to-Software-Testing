#include<stdio.h>
#include<string.h>
char s[200];
int main(){
    gets(s);
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
    printf("%c.",s[jb+1]);@@ // Error: Always prints a decimal point; for input "0.9", the base should be an integer "9" without decimal point, because there are no following digits.
    for(int nmsl=jb+2;nmsl<l;nmsl++){@@ // Error: If there are no following digits (e.g., "0.9"), the loop never executes, so the exponent is never printed. The exponent (e-1) should be printed after the base digit.
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb);
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}