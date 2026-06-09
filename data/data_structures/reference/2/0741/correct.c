#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000
#define ll long long

int change(char r[],int *i){
    char s[10];
    int k=0,l=*i;
    while(isdigit(r[l])){
        s[k++]=r[l++];
    }
    *i=l;
    s[k]='\0';
    return atoi(s);   
}

int main() {
    char s[M],r[M];
    int a[5]={0},i,j=1,k,sum=0,part[M]={0},x=0,y,p;
    gets(s);
    r[0]='+';
    a[0]++;
    for(i=0;s[i]!='=';i++){
        if(s[i]==' '){
        }else{
            r[j++]=s[i];
            if(s[i]=='+'){
                a[0]++;
            }else if(s[i]=='-'){
                a[1]++;
            }else if(s[i]=='*'){
                a[2]++;
            }else if(s[i]=='/'){
                a[3]++;
            }
        }
    }
    r[j]='\0';
    // puts(r);
    // printf("%d\n",r[0]+r[2]-2*'0');
    // printf("+%d\n-%d\n*%d\n/%d\n",a[0],a[1],a[2],a[3]);

    for(j=0,k=0;r[j]=='+'||r[j]=='-'||r[j]!='\0';){
        x=1,y=0;
        for(i=j+1,p=1;r[i]!='+'&&r[i]!='-'&&r[i]!='\0';){    
            if(isdigit(r[i])&&isdigit(r[i+1])){
                y=change(r,&i);
            }else if(isdigit(r[i])){
                y=r[i++]-'0';
            }
            while(r[i]=='*'||r[i]=='/'){
                int m=i;
                if(p){
                    x=y;
                    p=0;
                } 
                i++;
                if(isdigit(r[i])&&isdigit(r[i+1])){
                    y=change(r,&i);
                }else if(isdigit(r[i])){
                    y=r[i++]-'0';
                }
                if(r[m]=='*'){
                    x*=y;
                }else if (r[m]=='/'){
                    x/=y;
                }     
            }if((r[i]=='+'||r[i]=='-'||r[i]=='\0')&&p){
                x=y;
            }        
        }
        if(r[j]=='+'){
            part[k++]=x;
        }if(r[j]=='-'){
            part[k++]=-x;
        }
        j=i;
        // printf("sum=%d\n",sum);
    }
    for(i=0;i<=k-1;i++){
        sum+=part[i];
    }
    printf("%d",sum);
    
	return 0;
    // system("pause");
}
