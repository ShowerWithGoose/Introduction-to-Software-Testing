#include <stdio.h>
#include <string.h>

int main(){
char ch[105]={NULL};
gets (ch);
int posp=0,posn=0,status=0;
for(int i=0;i<strlen(ch);i++){

    if(ch[i]=='.')
        posp=i;
    if(ch[i]>='1'&&ch[i]<='9'&&status==0){
        posn=i;status=1;
    }
}
if(posn==strlen(ch)-1){
    printf("%ce%d",ch[posn],posp-posn);
    return 0;
}
if(posp==0){
    printf("%c.",ch[0]);
    for(int i=1;i<strlen(ch);i++)
        printf("%c",ch[i]);
    printf("e%d",strlen(ch)-1);
}//整数情况
else{
    printf("%c.",ch[posn]);
    for(int i=posn+1;i<strlen(ch);i++)
        if(ch[i]!='.')
            printf("%c",ch[i]);
    printf("e%d",posp<posn?posp-posn:posp-posn-1);
}
return 0;
}




