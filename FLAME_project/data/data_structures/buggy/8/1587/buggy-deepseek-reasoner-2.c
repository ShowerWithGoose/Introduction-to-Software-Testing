#include<stdio.h>
#include<stdlib.h>
int visted[100];
int visited[100];
int visited1[20];
typedef struct Node{
   int num;
   struct Node*next;
}V,E;

V*initV(V*Node,int num){
   Node=(V*)malloc(sizeof(V));
   Node->num=num;
   Node->next=NULL;
   return Node;
}

E*initE(int num){
   E*newnode=(E*)malloc(sizeof(E));
   newnode->num=num;
   newnode->next=NULL;
   return newnode;
}

void CreateGraphList(V*DisGraph[],int start,int end){
     if(visted[start]==0){
        DisGraph[start]=initV(DisGraph[start],start);
        visted[start]=1;
     }
      V*cur=DisGraph[start];
      while(cur->next){
        cur=cur->next;
      }
      E*newE=initE(end);
      cur->next=newE;
}

V*SearchMinForDFT(V*Start){
    V*cur=Start->next;
    V*min=NULL;
   while(cur){
      if(visited[cur->num]==1){
        cur=cur->next;
      }
      else{
        if(min==NULL){
            min=cur;
        }
        else{
            if(min->num>cur->num){
            min=cur;
             }
        }
        cur=cur->next;
      }
   }
   return min;
}

V*SearchMinForBFT(V*Start){
    V*cur=Start->next;
    V*min=NULL;
   while(cur){
      if(visited1[cur->num]==1){
        cur=cur->next;
      }
      else{
        if(min==NULL){
            min=cur;
        }
        else{
            if(min->num>cur->num){
            min=cur;
             }
        }
        cur=cur->next;
      }
   }
   return min;
}

void DFT(V*Disgraph[],int start){
    printf("%d ",Disgraph[start]->num);
    visited[start]=1;
    V*min;
    while(1){
       min=SearchMinForDFT(Disgraph[start]);
       if(min){
        DFT(Disgraph,min->num);
       }
       else{
         break;
       }
    }
}

void BFT(V*Disgraph[]){
   V* quene[20]; // @@ [Queue size fixed to 20, but the graph can have up to 100 vertices, causing buffer overflow]
   int size=1;
   int head=0;int tail=0;
   quene[0]=Disgraph[0];
   visited1[quene[head]->num]=1;
   tail++;
   while(size>0){
      printf("%d ",quene[head]->num);
      head++;
      size--;
      V*min;
      while(1){
       min=SearchMinForBFT(Disgraph[quene[head-1]->num]);
       if(min){
        visited1[min->num]=1;
        quene[tail++]=min;
        size++;
       }
       else{
        break;
       }
      }
   }
}

void CleanVisited(int size){
     for(int i=0;i<size;i++){
        visited[i]=0;
     }
}

void CleanVisited1(int size){
     for(int i=0;i<size;i++){
        visited1[i]=0;
     }
}

E*DFS(V*Disgraph[],int start,int key){
    visited[start]=1;
    V*cur=Disgraph[start]->next;
    V*res=NULL;
    while(cur){
        if(visited[cur->num]==0){
            if(cur->num==key){
                return cur;
            }
             else{
                res=DFS(Disgraph,cur->num,key);
                if(res){
                    return res;
                }
            }
        }
        cur=cur->next;
    }
    return res;
}

void Delete(V*Disgraph[],int key){
     E*cur=Disgraph[key]->next;
     while(cur){
         V*temp=Disgraph[cur->num];
         while(temp->next){
            if(temp->next->num==key){
                V*del=temp->next;
                temp->next=del->next;
                free(del);
            }
            else{
                temp=temp->next;
            }
         }
         cur=cur->next;
     }
}

int main(){
   int Num_V,Num_E;
   int start,end;
   scanf("%d%d",&Num_V,&Num_E);
   V*DisGraph[Num_V];
   for(int i=0;i<Num_E;i++){
      scanf("%d%d",&start,&end);
      CreateGraphList(DisGraph,start,end);
      CreateGraphList(DisGraph,end,start);
   }
    /*for(int i=0;i<Num_V;i++){
     V*cur=DisGraph[i];
     while(cur){
        printf("%d ",cur->num);
        cur=cur->next;
     }
     printf("\n");
   }*/
   DFT(DisGraph,0);
   printf("\n");
   BFT(DisGraph);
   printf("\n");
   CleanVisited1(Num_V);
   CleanVisited(Num_V);
   int key;
   scanf("%d",&key);
   Delete(DisGraph,key);
   DFT(DisGraph,0);
   printf("\n");
   BFT(DisGraph);
}