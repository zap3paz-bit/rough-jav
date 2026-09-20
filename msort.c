#include<stdio.h>
#include<stdlib.h>

void Merge(int n,int arr[n],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;

    int left[n1+1];
    int right[n2+1];

    for(int i=0;i<n1;i++){
        left[i]=arr[p+i];
    }

    for(int i=0;i<n2;i++){
        right[i]=arr[q+i+1];
    }

    left[n1]=1000000;
    right[n2]=1000000;

    int i=0,j=0;

    for(int k=p;k<=r;k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
    }

}

void m_sort(int n,int arr[n],int p,int r){
   
    if(p>=r){
       return;
    }

     int q=(int)((r+p)/2);;

    m_sort(n,arr,p,q);
    m_sort(n,arr,q+1,r);
    Merge(n,arr,p,q,r);  
}

int main(){

    int arr[]={12,34,23,54,67,78,29};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    m_sort(n,arr,0,n-1);

    for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
    }

    return 0;

}