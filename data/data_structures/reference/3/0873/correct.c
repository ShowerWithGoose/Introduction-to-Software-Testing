#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long ll;
#define eps 1e-8
int main()
{
    char num[105];
    int count = -1,len;
    gets(num);
    len = strlen(num);
    if (num[0] != '0') //大于0的小数
    {
        int i,record;
        for (i = 0; i < len; i++)
        {
            if (num[i] >= '0' && num[i] <= '9') 
                count++;
            if (num[i] == '.')
            {
                record = i;
                break;
            }
        }
        printf("%c.", num[0]);
        for (int j = 1; j < record; j++) {
            printf("%c", num[j]);
        }
        for (int m = record + 1; m < len; m++) {
            printf("%c", num[m]);
        }
        printf("e%d", count);
        
    }
    if (num[0] == '0') 
    {
        int a, record1,cnt=1;
        if(len==3){
        	printf("%ce-1",num[2]);
		}
		else{
			for (a = 2; a < len; a++) 
        {
            if (num[a] == '0'&&num[a+1]=='0')
            {
                cnt++;
            }
            if(num[a]=='0'&&num[a+1]!='0')
            {
                record1 = a+1;
                break;
            }
        }
        printf("%c", num[record1]);
        if(record1+1!=len){
        	printf(".");
		}
        for (int n = record1 + 1; n < len; n++) {
            printf("%c", num[n]);
        }
        printf("e-%d", cnt+1);
		}
        
    }
    return 0;
}




