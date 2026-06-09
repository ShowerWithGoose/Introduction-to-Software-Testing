#include<stdio.h>
#include<string.h>
struct dxs{
	int xs;
	int zs;	
}dxs1[10000],dxs2[10000],dxs[1000000];
int main (){
	int i,j,k;
	int len=0;
	int l1=0;
	int l2=0;
	for(i=0;;i++){
		scanf("%d %d",&dxs1[i].xs,&dxs1[i].zs);
		l1++;
		if(getchar()=='\n')
			break;
	}
		for(i=0;;i++){
			scanf("%d %d",&dxs2[i].xs,&dxs2[i].zs);
			l2++;
			if(getchar()=='\n')
			break;
		}
	
	for(i=0;i<l1;i++){
		for(j=0;j<l2;j++){
			dxs[len].xs=dxs1[i].xs*dxs2[j].xs;
			dxs[len].zs=dxs1[i].zs+dxs2[j].zs;
			len++;
		}
	}
	//接下来就要进行排序了
	int mid;
	for(k=0;k<len;k++){
		for(j=k+1;j<len;j++){
			if(dxs[k].zs<dxs[j].zs){
				mid=dxs[k].zs;
				dxs[k].zs=dxs[j].zs;
				dxs[j].zs=mid;
				mid=dxs[k].xs;
				dxs[k].xs=dxs[j].xs;
				dxs[j].xs=mid;
			}
			else if(dxs[k].zs==dxs[j].zs){
				dxs[k].xs=dxs[k].xs+dxs[j].xs;
				dxs[j].xs=0;
				dxs[j].zs=0;
			}
		}
	}
	for(k=0;dxs[k].xs!=0;k++)
			printf("%d %d ",dxs[k].xs,dxs[k].zs);
	 return 0;
}


