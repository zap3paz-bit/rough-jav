#include<stdio.h>

void flru(int n,int blocks[],int cache[4][2],int lru[4][2],int*hit,int*miss){

    // int h=0,m=0;
    for(int i=0;i<n;i++){
      int s=blocks[i]%4;
      int ishit=0;
      for(int j=0;j<2;j++){
        if(blocks[i]==cache[s][j]){
            (*hit)++;
            // h++;
            ishit=1;
            lru[s][0]=lru[s][1];
            lru[s][1]=cache[s][j];
            break;
        }
      }

      if(ishit==0){
            (*miss)++;
            // m++;
            if(cache[s][0]==-1){
                cache[s][0]=blocks[i];
                lru[s][0]=blocks[i];
            }else if(cache[s][1]==-1){
                cache[s][1]=blocks[i];
                lru[s][1]=blocks[i];
            }else{
                int inx;
                for(int k=0;k<2;k++){
                    if(lru[s][0]==cache[s][k]){
                        inx=k;
                    }
                }

                cache[s][inx]=blocks[i];
                lru[s][0]=lru[s][1];
                lru[s][1]=blocks[i];
            }
      }
    }
    int a=34%4;
    for(int i=0;i<2;i++){
        if(cache[a][i]==34){
            printf("LRU:\nset:%d , index in set:%d , index:%d",a,i,2*a+i);
        }
    }

}

void fifof(int n,int blocks[],int cache[4][2],int fifo[4][2],int*hit,int*miss){
     for(int i=0;i<n;i++){
        int s=blocks[i]%4;
        int ishit=0;

        for(int j=0;j<2;j++){
        if(blocks[i]==cache[s][j]){
            (*hit)++;
            ishit=1;
            break;
         }
        }

        if(ishit==0){
            (*miss)++;
            if(cache[s][0]==-1){
                cache[s][0]=blocks[i];
                fifo[s][0]=blocks[i];
            }else if(cache[s][1]==-1){
                cache[s][1]=blocks[i];
                fifo[s][1]=blocks[i];
            }else{
                int inx;
                for(int k=0;k<2;k++){
                    if(fifo[s][0]==cache[s][k]){
                        inx=k;
                    }
                }

                cache[s][inx]=blocks[i];
                fifo[s][0]=fifo[s][1];
                fifo[s][1]=blocks[i];
            }
      }


     }

    int a=34%4;
    for(int i=0;i<2;i++){
        if(cache[a][i]==34){
            printf("\n\nFIFO:\nset:%d , index in set:%d , index:%d",a,i,2*a+i);
        }
    }
}

int main(){
    int blocks[]={6, 8, 15, 25,9,19, 17, 11, 19, 25, 45,8, 9, 15, 16, 14, 9, 6, 8, 25, 19, 34};
    int size=sizeof(blocks)/sizeof(int);

    int cache1[4][2];
    int cache2[4][2];

    int lru[4][2];
    int fifo[4][2];

    int hit1=0,hit2=0,miss1=0,miss2=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cache1[i][j]=-1;
            cache2[i][j]=-1;
            lru[i][j]=-1;
        }
    }

    flru(size,blocks,cache1,lru,&hit1,&miss1);

    printf("\nhits:%d",hit1);
    printf("\nmisses:%d",miss1);

    
    printf("\n\nHIT RATE:%lf",(double)hit1/size);
    printf("\nMISS RATE:%lf",(double)miss1/size);

    fifof(size,blocks,cache2,lru,&hit2,&miss2);

    printf("\nhits:%d",hit2);
    printf("\nmisses:%d",miss2);

    
    printf("\n\nHIT RATE:%lf",(double)hit2/size);
    printf("\nMISS RATE:%lf",(double)miss2/size);

    
}