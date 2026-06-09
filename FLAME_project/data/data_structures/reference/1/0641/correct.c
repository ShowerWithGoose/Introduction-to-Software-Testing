#include<stdio.h>
int N;
int i,j;
int jiecheng[11];
int put[10];

int f(){
    jiecheng[0]=1;
    int i;
    for(i=1;i<10;i++){
        jiecheng[i]=i*jiecheng[i-1];
    }
}

void print(){
    int i=0;
    for(i=0;i<N-1;i++)
        printf("%d ",put[i]);
    printf("%d\n",put[i]);
}

void find(){
    for(i=N-2;i>=0;i--){
        if(put[i]<put[i+1])
            break;
    }
    int k1=i;
    int low=i+1;
    for(i=k1+1;i<N;i++){
        if(put[i]>put[k1]&&put[i]<put[low])
            low=i;
    }
    int temp;
    temp=put[k1];
    put[k1]=put[low];
    put[low]=temp;
    for(j=k1+1,i=N-1;i>j;i--,j++){
        temp=put[i];
        put[i]=put[j];
        put[j]=temp;
    }
}

int main(){
    f();
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){
        put[i]=i+1;
    }
    print();
    for(i=1;i<jiecheng[N];i++){
        find();
        print();
    }
}


