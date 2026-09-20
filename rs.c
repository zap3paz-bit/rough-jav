#include<stdio.h>

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

void c_sort(int n,int arr[],int pos){
    int out[n];

    int count[10];

    for(int i=0;i<10;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=(n-1);i>=0;i--){
        count[(arr[i]/pos)%10]--;
        out[count[(arr[i]/pos)%10]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}

void r_sort(int n,int arr[]){
    int max=get_max(n,arr);
    for(int i=1;max/i>0;i*=10){
        c_sort(n,arr,i);
    }
}

int main(){
    int arr[]={234,567,23,789,6,43,34,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    r_sort(n,arr);

    for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
    }

    return 0;

}