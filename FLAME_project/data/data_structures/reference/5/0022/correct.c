#include "stdio.h"
#include "stdlib.h"

struct dxs{
	int sd,sz;//sd底数  sz指数 
}in1[1001],in2[1001],out[1001],s;

/*int seq(void)
{
	 for(i=0;i<n;i++)
    {
 		for(j=i+1;j<n;j++)
        {
            if(dxs[j].sz<dxs[i].sz)
            {
                s=dxs[j];
                dxs[j]=dxs[i];
                dxs[i]=s;
            }
        }
	}
} */

int main(){
	int i,j,k,a,b;
	char c = 'c';
	i = 0;
	while (c != '\n'){
		scanf ("%d",&in1[i].sd);
		getchar();
		scanf ("%d",&in1[i].sz);
		c = getchar();
		//printf ("%c",c);
		i++;
	}
	a = i;
	c = 'c';
	i = 0;
	while (c != '\n'){
		scanf ("%d",&in2[i].sd);
		getchar();
		scanf ("%d",&in2[i].sz);
		c = getchar();
		i++;
	}
	b = i;
	/*for(i=0;i<a;i++)
    {
 		for(j=i+1;j<a;j++)
        {
            if(in1[j].sz<in1[i].sz)
            {
                s=in1[j];
                in1[j]=in1[i];
                in1[i]=s;
            }
        }
	}
	for(i=0;i<b;i++)
    {
 		for(j=i+1;j<b;j++)
        {
            if(in2[j].sz<in2[i].sz)
            {
                s=in2[j];
                in2[j]=in2[i];
                in2[i]=s;
            }
        }
	}*/
	k = 0;
	for(i=0;i<a;i++) // 多项式相乘 
	{
		for(j=0;j<b;j++,k++) // in1每一项都乘in2每一项 
		{
			out[k].sd = in1[i].sd * in2[j].sd; // 
			out[k].sz = in1[i].sz + in2[j].sz;		
		}
	}//用k计算 计算后结果的数据个数 
	for(i=0;i<k;i++) //根据指数排序 
    {
 		for(j=i+1;j<k;j++)
        {
            if(out[j].sz>out[i].sz)
            {
                s=out[j];
                out[j]=out[i];
                out[i]=s;
            }
        }
	}
	for (i=0;i<=k;i++){
		for (j=i+1;j<k;j++){
			if (out[i].sz == out[j].sz&&out[i].sz != 0){ //若指数相等 
			out[i].sd += out[j].sd; //底数相加 
			out[j].sz = 0; 
			out[j].sd = 0; 
			//i = i+1;
		}
		}
		
	}
	for(i=0;i<k;i++)
	{
		if (out[i].sz != 0 || out[i].sd != 0)
		{
			printf ("%d %d ",out[i].sd , out[i].sz);
		}
	}
	
	
	
	return 0;
}

