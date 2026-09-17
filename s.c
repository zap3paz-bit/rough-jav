#include<stdio.h>
#include<stdlib.h>

int get_max(int n,int arr[n]){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }

    return m;

}

int get_min(int n,int arr[n]){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<m){
            m=arr[i];
        }
    }

    return m;

}

void c_sort(int n,int arr[n]){
    int out[n];
    int k=get_max(n,arr)-get_min(n,arr)+1;
    
    int count[k];
    
    for(int i=0;i<k;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[arr[i]-get_min(n,arr)]++;
    }

    for(int i=1;i<k;i++){
        count[i]=count[i-1]+count[i];
    }

    for(int i=(n-1);i>=0;i--){
        count[arr[i]-get_min(n,arr)]--;
        out[count[arr[i]-get_min(n,arr)]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}


int main(){

    int arr[]={1,20,3,-10,-4,6};
    int n=sizeof(arr)/sizeof(int);

    c_sort(n,arr);

    for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
    }
   

}