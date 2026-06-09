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
    double x=0; // @@ The variable x is declared as double, but the problem requires integer division. Using double will result in floating point results (e.g., 2.0 instead of 2) and potential precision issues or incorrect final casting to int if not handled strictly as integer arithmetic throughout. More critically, the logic below updates `ans` inside the loop which can lead to double counting or incorrect state management for chained operations.
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
                x=c[i]/c[i+1]; // @@ Integer division should be performed on integers. Since x is double, this performs floating point division if operands are promoted, or integer division then cast. However, the main logical error is that this block handles a sequence of * and /, but it modifies `ans` based on `i` which might have already been processed or skipped incorrectly in the outer loop structure. Specifically, for input `24 / 4 / 3 / 2 * 2 * 3 * 4`, the first operator is `/`. The code enters this block. It calculates `x = 24/4 = 6`. Then it loops `j` from `i+1` (1). `d[1]` is `/`. `x = 6/3 = 2`. `d[2]` is `/`. `x = 2/2 = 1`. `d[3]` is `*`. `x = 1*2 = 2`. `d[4]` is `*`. `x = 2*3 = 6`. `d[5]` is `*`. `x = 6*4 = 24`. Next `d[6]` is `=`. The `else` branch is taken. `i` is 0. `ans` becomes 24. The outer loop continues. The issue is that the outer loop index `i` is not advanced past the processed operators. The next iteration of the outer loop will process `d[1]` again? No, `i` increments. But `d[1]` was part of the chain starting at `d[0]`. The logic for skipping processed operators is missing. When `i` becomes 1, `d[1]` is `/`. It enters the `else if` block again. It recalculates a chain starting from `c[1]` (4). This leads to incorrect results because operands are reused.
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