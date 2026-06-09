#include<stdio.h>
struct line{
		int x1;
		int y1;
		int x2;
		int y2;
	}lines[102],temp;
void bubble(int n, struct line lines[102], struct line temp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (lines[i].x1>lines[j].x1)
            {
                temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
    }
}

int main(){
	int i=1,j=1,k=1,cnt=1;//假设以每一条线段左端点开始 
	int n,max=0;
	int mark_x1=0,mark_y1=0,mark_x2=0,mark_y2=0;
	int ans_x1=0,ans_y1=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	bubble(n,lines,temp);
	for(i=1;i<=n;i++){
		mark_x1=lines[i].x1;
		mark_y1=lines[i].y1;
		mark_x2=lines[i].x2;
		mark_y2=lines[i].y2;
		cnt=1;
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
			if(i!=k&&lines[k].x1==mark_x2&&lines[k].y1==mark_y2){
				cnt++;mark_x1=lines[k].x1;mark_x2=lines[k].x2;
				mark_y1=lines[k].y1;mark_y2=lines[k].y2;
				if(cnt>max){
					max=cnt;
					ans_x1=lines[i].x1;
					ans_y1=lines[i].y1;
					}
				}
			}
		}
	}
	
	printf("%d %d %d",max,ans_x1,ans_y1);
	return 0;
}  



