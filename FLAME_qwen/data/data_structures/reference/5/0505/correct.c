#include<stdio.h>
struct dxs
{
	int xishu;
	int zhishu;
	
}dxs1[10000],dxs2[10000],dxs[1000000];

int main()
{ 
	int i=0,j=0,k=0;
	int len1=0,len2=0,len3=0;
	int tmp;
	for(i=0;;i++){
		scanf("%d%d",&dxs1[i].xishu,&dxs1[i].zhishu);
        len1=i+1;
        if(getchar()=='\n')
            break;
	}
	for(i=0;;i++){
		scanf("%d%d",&dxs2[i].xishu,&dxs2[i].zhishu);
        len2=i+1;
        if(getchar()=='\n')
            break;
	}
	for(i=0,k=0;i<len1;i++){
		for(j=0;j<len2;j++,k++){ 
			dxs[k].xishu=dxs1[i].xishu*dxs2[j].xishu;
			dxs[k].zhishu=dxs1[i].zhishu+dxs2[j].zhishu;
		}
	}
	
	len3=k;
	
	for(i=0;i<len3;i++){
		for(j=i+1;j<len3;j++){
			if(dxs[i].zhishu<dxs[j].zhishu){
				tmp=dxs[i].xishu;
				dxs[i].xishu=dxs[j].xishu;
				dxs[j].xishu=tmp;
				tmp=dxs[i].zhishu;
				dxs[i].zhishu=dxs[j].zhishu;
				dxs[j].zhishu=tmp;
			}
			else if(dxs[i].zhishu==dxs[j].zhishu){
				
				dxs[i].xishu+=dxs[j].xishu;
				dxs[j].xishu=0;
				dxs[j].zhishu=0;
			}
		}
	}
	
	for(i=0;dxs[i].xishu!=0;i++){
		
			printf("%d %d ",dxs[i].xishu,dxs[i].zhishu );		
	}

}

