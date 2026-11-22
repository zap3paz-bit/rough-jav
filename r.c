#include<stdio.h>

int main() {
    int refs[] = {6,8,15,25,9,19,17,11,19,25,45,8,9,15,16,14,9,6,8,25,19,34};
    int num_refs = 22;
    
    int cache_lru[4][2];
    int age_lru[4][2]; 
    int hits_lru = 0, misses_lru = 0;
    int time_lru = 0;
    
    int cache_fifo[4][2];
    int age_fifo[4][2]; 
    int hits_fifo = 0, misses_fifo = 0;
    int time_fifo = 0;
    
    for(int i=0;i<4;i++) {
        for(int w=0;w<2;w++) {
            cache_lru[i][w] = -1;
            age_lru[i][w] = 0;
            cache_fifo[i][w] = -1;
            age_fifo[i][w] = 0;
        }
    }
    
    for(int i = 0; i < num_refs; i++) {
        int block = refs[i];
        int set = block % 4;
        int hit = 0;
        time_lru++;
        
      
        for(int w = 0; w < 2; w++) {
            if(cache_lru[set][w] == block) {
                hit = 1;
                hits_lru++;
                age_lru[set][w] = time_lru;
                break;
            }
        }
     
        if(!hit) {
            misses_lru++;
            if(cache_lru[set][0] == -1) {     
                cache_lru[set][0] = block;
                age_lru[set][0] = time_lru;
            } else if(cache_lru[set][1] == -1) {
                cache_lru[set][1] = block;
                age_lru[set][1] = time_lru;
            } else {                           
                int rep = (age_lru[set][0] < age_lru[set][1]) ? 0 : 1;
                cache_lru[set][rep] = block;
                age_lru[set][rep] = time_lru;
            }
        }
    }
    
    for(int i = 0; i < num_refs; i++) {
        int block = refs[i];
        int set = block % 4;
        int hit = 0;
        time_fifo++;

        for(int w = 0; w < 2; w++) {
            if(cache_fifo[set][w] == block) {
                hit = 1;
                hits_fifo++;
                break;
            }
        }

        if(!hit) {
            misses_fifo++;
            if(cache_fifo[set][0] == -1) {     
                cache_fifo[set][0] = block;
                age_fifo[set][0] = time_fifo;
            } else if(cache_fifo[set][1] == -1) {
                cache_fifo[set][1] = block;
                age_fifo[set][1] = time_fifo;
            } else {                            
                int rep = (age_fifo[set][0] < age_fifo[set][1]) ? 0 : 1;
                cache_fifo[set][rep] = block;
                age_fifo[set][rep] = time_fifo; 
            }
        }
    }

    printf("Task-1: LRU Result for Memory Block 34\n");
    for(int i = 0; i < 4; i++) {
        for(int w = 0; w < 2; w++) {
            if(cache_lru[i][w] == 34) {
                printf("Block 34 is in Set %d, Way %d, Cache Block %d\n\n",i,w,(i*2)+w);
            }
        }
    }

    printf("Task-2: FIFO Result for Memory Block 34\n");
    for(int i = 0; i < 4; i++) {
        for(int w = 0; w < 2; w++) {
            if(cache_fifo[i][w] == 34) {
                printf("Block 34 is in Set %d, Way %d, Cache Block %d\n\n",i,w,(i*2)+w);
            }
        }
    }

    float miss_rate_lru = (float)misses_lru / num_refs * 100.0;
    float miss_rate_fifo = (float)misses_fifo / num_refs * 100.0;
    
    printf("LRU  - Hits: %d, Misses: %d, Miss Rate: %.2f%%\n", hits_lru, misses_lru, miss_rate_lru);
    printf("FIFO  - Hits: %d, Misses: %d, Miss Rate: %.2f%%\n", hits_fifo, misses_fifo, miss_rate_fifo);
    
    return 0;
    
 }