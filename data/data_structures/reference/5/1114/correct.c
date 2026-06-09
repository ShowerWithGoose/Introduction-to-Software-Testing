#include<stdio.h>
#include<stdlib.h>
struct node{
    long long coefficient,index;
    struct node*next;
};
int main(){
    int i,n=-1;
    char c;
    long long co[1000],in[1000],newco,newin,b;
    struct node AnS={},*head,*tail,*begin=&AnS;
    do{
        n++;
        scanf("%lld%lld%c",co+n,in+n,&c);
    }while(c!='\n');
    do{
        scanf("%lld%lld%c",&newco,&newin,&c);
        head=begin->next;tail=begin;
        for(i=0;i<=n;i++){
            b=newin+in[i];
            for(;head!=NULL&&head->index>b;tail=head,head=head->next);
            if(head==NULL||head->index<b){
                tail->next=(struct node*)malloc(sizeof(struct node));
                tail=tail->next;tail->next=head;
                tail->coefficient=newco*co[i];tail->index=b;
            }
            else{
                head->coefficient+=(newco*co[i]);
                if(!head->coefficient)tail->next=head->next,head=head->next;
                else tail=head,head=head->next;
            }
            if(!i)begin=tail;
        }
    }while(c!='\n');
    head=AnS.next;
    while(head!=NULL){
        printf("%lld %lld ",head->coefficient,head->index);
        head=head->next;
    }
    return 0;
}
