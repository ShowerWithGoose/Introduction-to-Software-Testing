#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],d[100],e[100];
    int i,j=0,ans,m=0,k,n=0;
    int c[100]={0};
    gets(e); // @@ [Using `gets` is unsafe and has been removed from modern C standards; may cause compilation error with strict compilers]
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
                c[m]=c[m]*10+b[k]-48; // @@ [This logic incorrectly builds the number: it should build from b[0] to b[j-1] as a whole number, but instead adds each digit repeatedly to an already scaled value]
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
    double x=0; // @@ [Using `double` for integer division violates requirement #3; also mixing integer and floating-point leads to truncation errors]
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
                x=c[i]/c[i+1]; // @@ [Integer division expected, but stored in double; also, this doesn't handle operator precedence correctly across full expression]
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
                        ans-=x; // @@ [Subtracting a double from int without proper casting; also logic for handling signs is flawed]
                    }
                    else {
                        ans+=x;
                    }
                    }
                    else if(i==0){
                        ans=x; // @@ [Assigning double to int without cast; also overwrites initial ans incorrectly]
                    }
                    break;
                }
            }
        }
    }
    
    printf("%d",ans);
}