#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],d[100],e[100];
    int i,j=0,ans,m=0,k,n=0;
    int c[100]={0};
    gets(e); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
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
                c[m]=c[m]*10+b[k]-48; // @@ [This logic incorrectly processes multi-digit numbers; it should convert the entire string in `b` at once, not digit-by-digit in a loop that runs `j` times on the same `c[m]`]
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
    double x=0; // @@ [Using `double` for integer division violates requirement #3; all operations must use integer arithmetic]
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
                x=c[i]*c[i+1]; // @@ [Mixing integer array `c` with `double` variable `x` leads to type inconsistency and incorrect integer division behavior]
            }
            else if(d[i]=='/'){
                x=c[i]/c[i+1]; // @@ [Integer division is performed here but stored in `double`; however, subsequent operations on `x` (like `x/=c[j+1]`) become floating-point, violating problem requirements]
            }
            for(j=i+1;j<m;j++){
                if(d[j]=='*'){
                    x*=c[j+1];
                }
                else if(d[j]=='/'){
                    x/=c[j+1]; // @@ [Floating-point division used instead of integer division]
                }
                else {
                    if(i>=1){
                    if(d[i-1]=='-'){
                        ans-=x; // @@ [Subtracting `double` from `int` without casting; also logic for operator precedence and grouping is flawed]
                    }
                    else {
                        ans+=x;
                    }
                    }
                    else if(i==0){
                        ans=x; // @@ [Assigning `double` to `int` without explicit cast may work but hides logic errors; more importantly, the overall algorithm fails to correctly handle operator precedence across the entire expression]
                    }
                    break;
                }
            }
        }
    }
    
    printf("%d",ans);
}