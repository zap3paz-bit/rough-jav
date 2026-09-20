#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    double value;
    struct node*next;
}node;

double get_max(int n,double arr[]){
   double m=arr[0];
   for(int i=0;i<n;i++){
       if(m<arr[i]){
         m=arr[i];
       }
   }

   return m;
}

double get_min(int n,double arr[]){
   double m=arr[0];
   for(int i=0;i<n;i++){
       if(m>arr[i]){
         m=arr[i];
       }
   }

   return m;
}

node*insert(node*head,double val){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->value=val;
    if(head==NULL || head->value>val){
        newnode->next=head;
        return newnode;
    }

    node*temp=head;
    while(temp->next!=NULL && temp->next->value<=val){
        temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    return head;



}

void bucket_Sort(int n,double arr[]){
    double max=get_max(n,arr);
    double min=get_min(n,arr);
    if(max==min)return;

    node**b_arr=calloc(n,sizeof(node*));

    for(int i=0;i<n;i++){
        int idx=(int)((arr[i]-min)/(max-min) * n);
        if(idx==n)
             idx=n-1;
        b_arr[idx]=insert(b_arr[idx],arr[i]);
    }

    int k=0;
    for(int i=0;i<n;i++){
        node*temp=b_arr[i];
        while(temp!=NULL){
            arr[k++]=temp->value;
            node*t=temp;
            temp=temp->next;
            free(t);
        }
        
    }

    free(b_arr);

}

int main(){
    double arr[]={0.43,0.45,0.3,0.13,0.56,0.57,0.29,0.03,0.93,0.65};
    int n=sizeof(arr)/sizeof(arr[0]);

    bucket_Sort(n,arr);
    for(int i=0;i<n;i++){
        printf("%f ",arr[i]);
    }

    return 0;
}
