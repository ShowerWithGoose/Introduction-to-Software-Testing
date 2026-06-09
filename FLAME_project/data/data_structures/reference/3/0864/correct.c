#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long
int main(){
        char s[1000000];
        gets(s);
        int len=strlen(s);
        if(s[1]=='.')
        {
            if(s[0]=='0')
            {int i=2;
                for(;i<len;i++)
                {
                    if(s[i]!='0')break;//小心这里

                }
                printf("%c",s[i]);
                if (i==len-1)
                {
                    printf("e-%d",len-2);
                }
                else
                {  printf(".");
                int k=i;
                    while(k<len-1){
                        printf("%c",s[++k]);
                    }
                    printf("e-%d",i-1);
                }
            
            }//0打头

            else
            {
                printf("%se0",s);
            
            }
        }

        else //s[1]!='.  s[0]不会等于0
        {   int j=1;
            printf("%c",s[0]);
            for(;j<len;j++)
            {
                if(s[j]=='.')break;
            }
            if(j==len-1)
            {
                for(int p=1;p<len;p++)
                {
                    printf("%c",s[p]);
                }
            }
            else
            {
                printf(".");
                for(int q=1;q<=len-1;q++){
                    if(q==j)continue;
                    printf("%c",s[q]);
                }
                printf("e%d",j-1);
            }
            

        }
}


