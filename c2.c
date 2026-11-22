#include<stdio.h>

int main(){
    int blocks[]={6, 8, 15, 25,9,19, 17, 11, 19, 25, 45,8, 9, 15, 16, 14, 9, 6, 8, 25, 19, 34};
    int size=sizeof(blocks)/sizeof(int);
    int cache1[8];
    int cache2[8];
    int lru[8];
    int fifo[8];

    int hit1=0,miss1=0,hit2=0,miss2=0;

    for(int i=0;i<8;i++){
        cache1[i]=-1;
        cache2[i]=-1;
        lru[i]=-1;
    }

    for(int i=0;i<size;i++){
        int s=blocks[i]%4;
        int ishit=0;

        for(int j=0;j<2;j++){
            if(blocks[i]==cache1[2*s+j]){
                hit1++;
                ishit=1;
                int index;
                for(int i=0;i<2;i++){
                    if(lru[2*s+i]==cache1[2*s+j]){
                        index=2*s+i;
                        break;
                    }
                }
                for(int i=index;i<2*s+1;i++){
                    lru[i]=lru[i+1];
                }
                lru[2*s+1]=blocks[i];
                break;
            }
        }

        if(ishit==1){
            continue;
        }

        
            if(cache1[2*s]==-1){
                cache1[2*s]=blocks[i];
                lru[2*s]=blocks[i];
            }else if(cache1[2*s+1]==-1){
                cache1[2*s+1]=blocks[i];
                lru[2*s+1]=blocks[i];
            }
            else{
                int index;
                for(int i=0;i<2;i++){
                    if(lru[2*s]==cache1[2*s+i]){
                        index=2*s+i;
                    }
                }

                cache1[index]=blocks[i];
                lru[2*s]=lru[2*s+1];
                lru[2*s+1]=blocks[i];
            }


        miss1++;
    }

    int sf=34%4;

    for(int i=0;i<2;i++){
        if(cache1[2*sf+i]==34){
            printf("%d  , set is %d",2*sf+1,sf);
            break;
        }
    }

    printf("hits:%d",hit1);
    printf("miss:%d",miss1);
    return 0;
}