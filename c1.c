#include<stdio.h>

int main(){

    int blocks[]={6, 8, 15, 25, 9, 19, 17, 11,19,25,45,8,9,15,16,14,9,6,8,25,19,34};
    int s=sizeof(blocks)/sizeof(int);
    int cache[8];
    int lru[s];
    int hit=0,miss=0;

    for(int i=0;i<8;i++){
        cache[i]=-1;
    }

    int k=0,ishit=0;

    for(int i=0;i<s;i++){
        ishit=0;
        for(int j=0;j<8;j++){
            if(blocks[i]==cache[j]){
                ishit=1;
                hit++;
                int index;
                for(int i=0;i<8;i++){
                    if(lru[i]==cache[j]){
                        index=i;
                    }
                }
                for(int i=index;i<8;i++){
                    lru[i]=lru[i+1];
                }
                lru[7]=cache[j];
                break;
            }

        }

        if(ishit==1){
            continue;
        }

        if(cache[i]==-1){
            cache[i]=blocks[i];
            lru[k++]=cache[i];
        }else{
            int index;
            for(int i=0;i<8;i++){
                if(cache[i]==lru[0]){
                    index=i;
                }
            }
            cache[index]=blocks[i];
            for(int i=0;i<8;i++){
                lru[i]=lru[i+1];
            }
            lru[7]=blocks[i];
        }
        miss++;
    }

    for(int i=0;i<8;i++){
        if(cache[i]==34){
            printf("\nindex of 34 is:%d",i);
        }
    }
    printf("\nhit:%d",hit);
    printf("\nmiss:%d",miss);

    printf("\n\nHIT RATE:%lf",(double)hit/s);
    printf("\nMISS RATE:%lf",(double)miss/s);
    return 0;
}