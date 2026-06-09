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
	char s[1000];
    int num[1000];
    memset(num,0,sizeof(num));
    gets(s);
    int len=strlen(s);
    int i=0,j=0;
    int cnt=0;
    for(;i<len;i++){
      
        if(s[i]!=' '){
            s[j]=s[i];
            j++;
         }
         }
            s[j]='\0';//除空格
            int lenth=strlen(s);
        
        for(i=0;i<lenth;i++){
            if(s[i]=='=')break;
            if((s[i]>='0')&&(s[i]<='9')){
                int k=i;
                k++;
                num[cnt]=s[i]-'0';
                while((s[k]>='0')&&(s[k]<='9')){
                    num[cnt]=num[cnt]*10+s[k]-'0';
                    k++;
                }
               i=k-1;
            }
            else if(s[i]=='+'){
                    num[++cnt]=s[++i]-'0';
                    int p=i+1;
                      while((s[p]>='0')&&(s[p]<='9')){
                    num[cnt]=num[cnt]*10+s[p]-'0';
                    p++;
                }
               i=p-1;
            }
            else if(s[i]=='-'){
                    num[++cnt]=0-(s[++i]-'0');
                    int q=i+1;
                      while((s[q]>='0')&&(s[q]<='9')){
                    num[cnt]=num[cnt]*10-(s[q]-'0');
                    q++;
                }
               i=q-1;
            }
             else if(s[i]=='*'){
                    //num[++cnt]=0-(s[++i]-'0');
                    //int q=i+1;
                    int cheng=s[++i]-'0';
                    int r=i+1;
                       while((s[r]>='0')&&(s[r]<='9')){
                    cheng=cheng*10+s[r]-'0';
                    r++;
                }
                num[cnt]*=cheng;
               i=r-1;
            }
             else if(s[i]=='/'){
                    //num[++cnt]=0-(s[++i]-'0');
                    //int q=i+1;
                    int chu=s[++i]-'0';
                    int n=i+1;
                       while((s[n]>='0')&&(s[n]<='9')){
                    chu=chu*10+s[n]-'0';
                    n++;
                }
                num[cnt]/=chu;
               i=n-1;
            }
        }
  int sum=0;
  for(int i=0;i<=cnt;i++){
      sum+=num[i];
  }
  printf("%d",sum);
  return 0;
     }


