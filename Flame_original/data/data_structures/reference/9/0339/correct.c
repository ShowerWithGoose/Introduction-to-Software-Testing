#include<stdio.h>

struct LINE{
	int a[2],b[2];
	int cnt;
};

struct LINE line[100];

int main(){
	int n,i = 0,j = 0,k = 0,x1,x2,y1,y2,flag = 0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(j = 0;j<k;j++){
			if(x1 == line[j].b[0]&&y1 == line[j].b[1]){
				line[j].b[0] = x2;
				line[j].b[1] = y2;
				line[j].cnt++;
				flag = 1;
				break;
			}
			else if(x2 == line[j].a[0]&&y2 == line[j].a[1]){
				line[j].a[0] = x1;
				line[j].a[1] = y1;
				line[j].cnt++;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			line[k].a[0] = x1;
			line[k].a[1] = y1;
			line[k].b[0] = x2;
			line[k].b[1] = y2;
			line[k].cnt =1;
			k++;
		}
		flag = 0;
		i++;
	}
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			if(j == i)
				continue;
			if((line[i].a[0] == line[j].b[0])&&(line[i].a[1] == line[j].b[1])){
				line[i].a[0] = line[j].a[0];
				line[i].a[1] = line[j].a[1];
				line[i].cnt = line[i].cnt + line[j].cnt;
			}
			else if((line[i].b[0] == line[j].a[0])&&(line[i].b[1] == line[j].a[1])){
				line[i].b[0] = line[j].b[0];
				line[i].b[1] = line[j].b[1];
				line[i].cnt = line[i].cnt + line[j].cnt;
			}
		}
	}
	int longest = 0;
	for(j = 0;j<n;j++){
		if(line[longest].cnt<line[j].cnt){
			longest = j;
		}
	}
	printf("%d %d %d",line[longest].cnt,line[longest].a[0],line[longest].a[1]);
	return 0;
}

