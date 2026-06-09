#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{char s[205];
gets(s);
int i,j,k,le,fir,dian=-1;
le=strlen(s);
for(i=le-1;i>=0;i--){
    if(s[i]!='0'&&s[i]!='.'){
        fir=i;
    }

    if(s[i]=='.'){
        dian=i;
    }
}

if(dian==-1){
    printf("%c.",s[0]);

    for(j=1;j<le;j++){
        printf("%c",s[j]);
    }

    printf("e%d",le-1);
}

else if(dian<fir){
    printf("%c",s[fir]);
   if(fir+1!=le){
    printf(".");
   }
    for(j=fir+1;j<le;j++){
        printf("%c",s[j]);
    }

    printf("e-%d",fir-1);
}

else if(dian>fir){
    printf("%c.",s[0]);

    for(j=1;j<le;j++){
            if(s[j]=='.'){

            }
        else printf("%c",s[j]);
    }

    printf("e%d",dian-fir-1);
}


return 0;}

