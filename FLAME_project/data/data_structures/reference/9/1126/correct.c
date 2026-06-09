#include<stdio.h>
int a[10001],s,p[1001],i,l,m,j,flag,k,c,d,max=1;
struct point1{
		int x1;
		int y1;	
     	int x2;
		int y2;	
	};
int main(){
	struct point1 w[1001],temp;
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf("%d%d%d%d",&w[i].x1,&w[i].y1,&w[i].x2,&w[i].y2);
	}
	for(i=0;i<s;i++)
    {
        flag=0;
        for(j=i+1;j<s;j++)
        {
            if(w[j].x1<w[i].x1)
            {
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
     for(i=0;i<s;i++)
    {
        l=1;
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(w[j].x1==w[k].x2&&w[j].y1==w[k].y2)
            {
                l++;
                k=j;
            }
        }
        if(l>max)
        {
            max=l;
            c=w[i].x1;
            d=w[i].y1;
        }
    }
    printf("%d %d %d",max,c,d);



}

