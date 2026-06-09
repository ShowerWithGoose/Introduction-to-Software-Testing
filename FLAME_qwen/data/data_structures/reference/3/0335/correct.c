#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
//#define ll long long

int main()
{
    char c[10000]={0};
    scanf("%s",c);
    int i,j;
    int flag =  0;
    int len =strlen(c);
    int cnt =0 ;
    int cnt0  = 0;

    if(c[0]=='0'&&c[1]=='.')
    {
        for(i=2;i<len;i++)
        {
            if(c[i] == '0') 
                cnt0 ++;
            else if(c[i]!='0'){
                printf("%c",c[i]);      ///abc len = 3; len -1 = 2 a[0]a[1]a[2]
                if(i!=len-1){
                    printf(".");
                    for(j=i+1;j<len;j++)
                        printf("%c",c[j]);
                }
                printf("e");
                printf("-");
                printf("%d",cnt0+1);
                break;
            }
        }
        
    } else{
        for(i=0;i<len-1;i++){
        if(c[i]!='.')
            cnt++;
        else
            break;
        }
        printf("%c.",c[0]);
        for(i=1;i<len;i++)
        {
            if(c[i]!='.')   printf("%c",c[i]);
        }
        printf("e%d",cnt-1);
    }  
    
    return 0;
}
