#include<stdio.h>
#include<string.h>
int main(){
    char a[1000],*p,c='+';
    int m=0, n, i=0,j,b[1000]={0},sum=0;
    p = a;
    gets(a);
    while(*p!='\0'){
        if(*p<='9'&&*p>='0'){
            m = *p-'0'+m*10;
            p++;
        }
        else if(*p==' '){
            p++;
            
            
            }
        else{
            
            if (c == '+')
            {
                b[i] = m;
                i++;
                m = 0;
            }
            else if(c=='-'){
                b[i] = -m;
                i++;
                m = 0;
            }
            else if(c=='*'){
                b[i - 1] *= m;
                m = 0;
            }

            else if(c=='/'){
                b[i - 1] /= m;
                m = 0;
            }
            c = *p;
            p++;
            }
        }
        for (j = 0; j < i;j++){
            sum += b[j];
        }
        printf("%d", sum);
        return 0;
}


