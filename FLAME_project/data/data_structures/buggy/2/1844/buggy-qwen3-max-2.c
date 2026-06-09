#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],d[100],e[100];
    int i,j=0,ans,m=0,k,n=0;
    int c[100]={0};
    gets(e);
    for(i=0;i<strlen(e);i++){
        if(e[i]!=' '){
            a[j]=e[i];
            j++;
            
        }
    }
    
    j=0;
    
    
    for(i=0;i<strlen(a);i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[j]=a[i];
            
            j++;
        }//连续的数字读入 
        else if(a[i]>'9'||a[i]<'0'){//读到符号后停止 
            for(k=0;k<j;k++){
                c[m]=c[m]*10+b[k]-48; // @@ [This loop incorrectly builds the number: it processes each digit multiple times instead of building the number once. For example, for "24", it does c[m] = 0*10+'2'-'0' => 2, then c[m] = 2*10+'4'-'0' => 24, but because the loop runs over all digits every time a new symbol is encountered, and c[m] is not reset properly between numbers, this leads to incorrect parsing when multiple numbers exist. Also, b[] is reused without clearing, and c[m] is not reset to 0 before parsing a new number.]
            }
            
            m++;
            j=0;
        }//c[0]代表了第一个数，以此类推 m
    }
    ans=c[0];
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
            d[n]=a[i];
            n++;
        }//将符号剔除出来 d[n]
    }
    double x=0;
    for(i=0;i<m;i++){
        if((d[i]=='+'||d[i]=='-')&&d[i+1]!='*'&&d[i+1]!='/'){
            
            if(d[i]=='+'){
                ans+=c[i+1];
            }
            else if(d[i]=='-'){
                ans-=c[i+1];
            }
            
        }
        else  if(d[i]=='*'||d[i]=='/'){
            if(d[i]=='*'){
                x=c[i]*c[i+1];
            }
            else if(d[i]=='/'){
                x=c[i]/c[i+1];
            }
            for(j=i+1;j<m;j++){
                if(d[j]=='*'){
                    x*=c[j+1];
                }
                else if(d[j]=='/'){
                    x/=c[j+1];
                }
                else {
                    if(i>=1){
                    if(d[i-1]=='-'){
                        ans-=x;
                    }
                    else {
                        ans+=x;
                    }
                    }
                    else if(i==0){
                        ans=x;
                    }
                    break;
                }
            }
        }
    }
    
    printf("%d",ans);
}