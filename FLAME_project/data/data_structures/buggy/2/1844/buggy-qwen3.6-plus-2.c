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
                c[m]=c[m]*10+b[k]-48;
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
    double x=0; // @@ The variable x is declared as double, but the problem requires integer division. Using double will result in floating point results (e.g., 2.0 instead of 2) and potential precision issues or incorrect final integer casting if not handled strictly as integer arithmetic throughout. More critically, the logic below updates `ans` inside the loop which can lead to double counting or incorrect state management for chained operations.
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
                x=c[i]/c[i+1]; // @@ Integer division should be performed on integers. Since x is double, this performs floating point division. For example, 5/2 becomes 2.5. Later this is assigned to ans (int), truncating it. However, the main logical error is how chained operations are handled.
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