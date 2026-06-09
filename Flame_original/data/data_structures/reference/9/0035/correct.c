#include<stdio.h>

struct l
{
		int start_x;
		int start_y;
		int end_x;
		int end_y;
		int num;
};

int main()
{
	int n,i,j,r,l_max=0,s_line[111][5],flag,k=0;
	scanf("%d",&n);
	struct l line[111];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&s_line[i][1],&s_line[i][2],&s_line[i][3],&s_line[i][4]);
	}//¶ÁÈëÏß¶Î
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			if(j==i) continue;
			if(s_line[i][1]==s_line[j][3]&&s_line[i][2]==s_line[j][4]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			line[k].start_x=s_line[i][1];
			line[k].start_y=s_line[i][2];
			line[k].end_x=s_line[i][3];
			line[k].end_y=s_line[i][4];
			k++;
		}
		flag=0;
	}
	for(i=0;i<n;i++){
		line[i].num=1;
		for(j=0;j<n;j++){
			if(line[i].end_x==s_line[j][1]&&line[i].end_y==s_line[j][2]){
				line[i].end_x=s_line[j][3];
				line[i].end_y=s_line[j][4];
				line[i].num++;
				j=-1;
			}
		}
	}
	
	for(i=0;i<k;i++){
		if(l_max<line[i].num){
			l_max=line[i].num;
			r=i;
		}
	}	
	printf("%d %d %d",l_max,line[r].start_x,line[r].start_y);
	return 0;
}

