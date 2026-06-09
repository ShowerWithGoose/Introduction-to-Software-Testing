#include<stdio.h>
#include<string.h>
struct article
{
    char s[100];
    int count;
};
struct article word[500],line,tmp[10];
int delete(char list[],int i,int n){
    int k;
    for(k=i+1;k<=n+1;k++){
        list[k-1]=list[k];
    }
    n--;
    return 1;
}
int search(char s[],struct article word[],int n){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(high+low)/2;
        if(strcmp(s,word[mid].s)<0){
            high=mid-1;
        }else if(strcmp(s,word[mid].s)>0){
            low=mid+1;
        }else return mid;
    }
    return low;
}
void getword(struct article word[],struct article tmp[],int n,int k,int f){
    int i;
    for(i=n-1;i>=k;i--){
        word[i+1]=word[i];
    }
    word[k]=tmp[f];
}
int main(){
    FILE *in;
    int n=1,k,i,j,key=0,a=1000,b=50,len,count,len1,l=0;
    in=fopen("article.txt","r");
    while(fscanf(in,"%s",line.s)!=EOF){
    	
      //  if(line.s==NULL) break;
    	l=0;
        for(i=0;i<strlen(line.s);i++)
		{
		if(isalpha(line.s[i])) //如果是字母，确定为单词开头 
		{
			for(j=i;j<strlen(line.s);j++)
			{
				if(!isalpha(line.s[j])) //遇到非字母的元素 
				{
					break;
				}
			}
		//	memset(tmp.s,0,sizeof(tmp.s));
			for(k=0;k<j-i;k++)
			{   if(line.s[i+k]>='A'&&line.s[i+k]<='Z') line.s[i+k]=line.s[i+k]+32;
				tmp[l].s[k]=line.s[i+k];   //存储单词 
			}
			l++;
			i=j;
		}
		else	continue;
		}
    for(i=0;i<l;i++){
        if(key==0) word[0]=tmp[0];
        key=1;
        k=search(tmp[i].s,word,n);
       // printf("%d\n",k);
        if(strcmp(tmp[i].s,word[k].s)!=0){
            tmp[i].count=1;
            getword(word,tmp,n,k,i);
            n++;
        }else{
            word[k].count++;
        }
	//printf("%d %s\n",k,tmp[i]);
        memset(&tmp[i],0,sizeof(tmp[i]));
    }
    }
    for(i=0;i<n;i++){
        printf("%s %d\n",word[i].s,word[i].count);
    }
    fclose(in);
    return 0;
}
