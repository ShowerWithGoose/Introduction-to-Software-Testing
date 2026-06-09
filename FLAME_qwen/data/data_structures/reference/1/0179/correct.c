
    #include<stdio.h>
	#include<string.h>
	int N,i,j,k,l,m;
	int sum[11],now[11];  
      
    int main()  
    {  
      scanf("%d",&N);
      sum[0]=1;
      for(i=1;i<=N;i++){
      	sum[i]=i*sum[i-1];
	  }
      for(i=0;i<N;i++)
         now[i]=i+1;
      for(i=0;i<N-1;i++)
         printf("%d ",now[i]);
         printf("%d\n",now[N-1]);
    for(m=1;m<sum[N];m++){
      for(i=N-2;i>=0;i--){//Ñ°ÕÒÄæÐò 
        if(now[i]<now[i+1]){
        	   break;
		}
        }  
	  int k=i,tp1=i+1,tp2;	
      for(l=k+1;l<N;l++){
      	if(now[l]>now[k]&&now[l]<now[tp1])
      	   tp1=l;
	  }
	      tp2=now[k];//»¥»» 
    now[k]=now[tp1];
    now[tp1]=tp2;
    for(j=k+1,i=N-1;i>j;j++,i--){//·­×ª 
        tp2=now[i];
        now[i]=now[j];
        now[j]=tp2;
    }
       for(i=0;i<N-1;i++)
         printf("%d ",now[i]);
         printf("%d\n",now[N-1]);   
    
	}
        return 0;  
    }  



