#include<stdio.h>
#include<string.h>
int main()
{
    char a[300];
    int b[300];
    char ysf[300];
    int sz[300],k1=0,k2=0,sum=0;
    gets(a);
    int i,j;
    for(i=0,j=0;a[i]!='\0';){
        if(a[i]!=' '){
            b[j]=a[i];
            j++;
        }
        i++;
    }
    for(j=0;b[j]!='=';j++){
        if(b[j]==('+')||b[j]==('-')||b[j]==('*')||b[j]==('/')||b[j]=='='){
            ysf[k1]=b[j];
            k1++;
            continue;
        }
        else b[j]-=48;
        if(b[j+1]==('+')||b[j+1]==('-')||b[j+1]==('*')||b[j+1]==('/')||b[j+1]=='='){
            sz[k2]=b[j];
            k2++;
        }
        else b[j+1]=10*(b[j])+b[j+1];
    }
    ysf[k1]='=';
    for(i=0;i<k2;i++){
        if(ysf[i]=='-'){
            sz[i+1]=-sz[i+1];
        }
        if(ysf[i]=='*'){
            sz[i+1]=sz[i]*sz[i+1];
            sz[i]=0;
        }
        if(ysf[i]=='/'){
            sz[i+1]=sz[i]/sz[i+1];
            sz[i]=0;
        }
    }
    for(i=0;i<k2;i++){
        if(ysf[i]=='+'||ysf[i]=='-'||ysf[i]=='='){
            sum=sum+sz[i];
        }
    }
    printf("%d",sum);
    return 0;
}



