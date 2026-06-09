#include <stdio.h>
#include <string.h>
#include <math.h>
char s[1000];                       
int num[1000];
int main()
{
    int n=0,i,flag = 0,fu = 0,fcnt = 0,x = 0;
    scanf("%s",s);            
    for(i = 0; i< strlen(s);i++) {
    	if(s[0]=='-') fu=-1;   
        if(s[i] == '.') flag = 1;       
        if(flag == 1) n++;                 
        if(s[i] != '0'  && s[i] != '-' && s[i] != '.') fcnt = 1;    
        if(fcnt == 1 && s[i] != '.') num[x++] = s[i] - '0';        
    }
    n-=1;                                                          
    if(fu == -1) printf("-");           
    for(i = 0; i< x;i++) {
        if(i==1) printf(".%d",num[i]);          
        else printf("%d",num[i]);
    }
    int zhishu = x - 1 - n;                  
    printf("e%d",zhishu);                     
    return 0;

}


