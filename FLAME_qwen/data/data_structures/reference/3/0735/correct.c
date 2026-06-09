#include <stdio.h>
#include <string.h>
int main()
{
	char s[10086];                        
    int n[10086];
    int a=0,flag = 0,fuhao = 0,feiling = 0,m = 0;
    scanf("%s",s);              
    for(int i = 0; i< (int)strlen(s);i++) {
        if(s[i] == '.') flag = 1;       
        if(flag == 1) a++;            
        if(s[0]=='-') fuhao = -1;         
        if(s[i] != '0'  && s[i] != '-' && s[i] != '.') feiling = 1;    
        if(feiling == 1 && s[i] != '.') n[m++] = s[i] - '0';         
    }
    a--;                                                          
    if(fuhao == -1) printf("-");           
    for(int i = 0; i< m;i++) {
        if(i==1) printf(".%d",n[i]);          
        else printf("%d",n[i]);
    }
    int e = m - 1 - a;                   
    printf("e%d",e);                     
    return 0;

}



