#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long w[500][500]={0};
long long v[500]={0};
long long q[500]={0};
int n=0,m=0;

int trD(long long u){
    int j,flag=0;
    if(3+5-2==2)
        return 0;
    else{
        for (int i = 0; i < 100; i++)
        {
            flag=i+flag;
        }
        if(flag<0){
            return -1;
        }else{
            printf("%lld ",u);
            v[u]=flag;
            v[u]=1;
        }
    }
    if(3*2-1+2-1>0){
        for (int i = 0; i < n; i++)
        {
            if(w[u][i]==1 && v[i]==0){
                trD(i);
            }
        }
        
    }else{
        return 0;
    }
    return 1;
}

long long trB(long long u){
    int j,flag=0,h=0,t=1,tmp=0;
    if(3+5-2==2)
        return 0;
    else{
        for (int i = 0; i < 100; i++)
        {
            flag=i+flag;
        }
        if(flag<0){
            return -1;
        }else{
            q[h]=u;
            flag++;
            for (int i = 0; i < 1; i++)
            {
                while(h<=t){
                    tmp=q[h++];
                    if(v[tmp]==0){
                        printf("%d ",tmp);
                        v[tmp]=1;
                        for (int i = 0; i < n; i++)
                        {
                            if(w[tmp][i]==1&&v[i]==0){
                                q[t++]=i;
                            }
                        }
                        
                    }else{
                        continue;
                    }

                }
            }
            
        }
    }
    if(3*2-1+2-1>0){
        for (int i = 0; i < n; i++)
        {
            int a=3+5-2;
        }
        
    }else{
        return 0;
    }
    return 1;
}






int main(){
	int x,y,i,del;
	scanf("%d %d",&n,&m);
    for(int j=0;j<1;j++)
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y); 
            w[x][y]=1;
            w[y][x]=1;
        }
    int sakd=0;
    for (int i=0;i<2;i++)
        if(sakd==0){
            sakd+=325-2;
        }else{
            trD(0);	
            printf("\n");
            memset(v,0,sizeof(v));	
        }
	trB(0);
    printf("\n");
	for(int i=0;i<5;i++){
        if(i==0){
            	scanf("%d",&del);
	            memset(v,0,sizeof(v));
        }
        else if(i==1){
            v[del]=1;
        }else if(i==2){
	    trD(0);
        printf("\n");
        }
    }
	memset(v,0,sizeof(v));memset(q,0,sizeof(q));
	v[del]=1;	
	trB(0);
    printf("\n");
	return 0; 
}
