#include<stdio.h>
int line[105][5];
int main(){
	int n,mx=0,mxn;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		line[i][0]=1;
		scanf("%d%d%d%d",&line[i][1],&line[i][2],&line[i][3],&line[i][4]);
	}
	for(int i=0;i<n;i++){
		if(line[i][0]!=0)
		for(int j=0;j<n;j++){
			if(line[j][0]!=0&&i!=j){
				if(line[i][1]==line[j][3]&&line[i][2]==line[j][4]){//i起点与j终点相同 
					line[i][1]=line[j][1];
					line[i][2]=line[j][2];
					line[i][0]+=line[j][0];
					line[j][0]=0;
				}
				else if(line[i][3]==line[j][1]&&line[i][4]==line[j][1]){ //i终点与j起点相同 
					line[i][3]=line[j][3];
					line[i][4]=line[j][4];
					line[i][0]+=line[j][0];
					line[j][0]=0;
				}
			}
		}
		if(line[i][0]>mx){
			mx=line[i][0];
			mxn=i;
		}
	}
	for(int i=0;i<n;i++){
		if(line[i][0]!=0)
		for(int j=0;j<n;j++){
			if(line[j][0]!=0&&i!=j){
				if(line[i][1]==line[j][3]&&line[i][2]==line[j][4]){//i起点与j终点相同 
					line[i][1]=line[j][1];
					line[i][2]=line[j][2];
					line[i][0]+=line[j][0];
					line[j][0]=0;
				}
				else if(line[i][3]==line[j][1]&&line[i][4]==line[j][1]){ //i终点与j起点相同 
					line[i][3]=line[j][3];
					line[i][4]=line[j][4];
					line[i][0]+=line[j][0];
					line[j][0]=0;
				}
			}
		}
		if(line[i][0]>mx){
			mx=line[i][0];
			mxn=i;
		}
	}
	printf("%d %d %d",mx,line[mxn][1],line[mxn][2]);
	return 0;
}
 

