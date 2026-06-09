#include<stdio.h>
struct dxs{
	int x;
	int z;
}duoxiangshi1[10000],duoxiangshi2[10000],duoxiangshi[1000000];
int main(){
    int i,s,len1,len2,f,m,temp,j;
    for(i=0;;i++){
    	scanf("%d%d",&duoxiangshi1[i].x,&duoxiangshi1[i].z);
    	len1=i+1;
    	if(getchar()=='\n')
            break;
	}
	for(i=0;;i++){
    	scanf("%d%d",&duoxiangshi2[i].x,&duoxiangshi2[i].z);
    	len2=i+1;
    	if(getchar()=='\n')
            break;
	}
	for(i=0,f=0;i<len1;i++){
		for(s=0;s<len2;s++){
			duoxiangshi[f].x=duoxiangshi1[i].x*duoxiangshi2[s].x;
			duoxiangshi[f].z=duoxiangshi1[i].z+duoxiangshi2[s].z;
			f++;
		}
	}
	for(m=0;m<f;m++){
		for(j=m+1;j<f;j++)
		{
			if(duoxiangshi[m].z<duoxiangshi[j].z){
				temp=duoxiangshi[j].z;
				duoxiangshi[j].z=duoxiangshi[m].z;
				duoxiangshi[m].z=temp;
				temp=duoxiangshi[j].x;
				duoxiangshi[j].x=duoxiangshi[m].x;
				duoxiangshi[m].x=temp;
			}
            else if(duoxiangshi[m].z==duoxiangshi[j].z){
            	duoxiangshi[m].x=duoxiangshi[m].x+duoxiangshi[j].x;
            	duoxiangshi[j].z=0;
            	duoxiangshi[j].x=0;
			}

		}
	}
	for(i=0;duoxiangshi[i].x!=0&&i<f;i++){
		printf("%d %d ",duoxiangshi[i].x,duoxiangshi[i].z);
	}
} 

