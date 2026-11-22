#include <stdio.h>

typedef struct Node {
    int op,s1,s2,d,imm;        
    char instn[20];   
    struct Node *next;
} Node;

Node nodes[7] = {
    {0, -1, -1, 1, 1, "000 Mov #1, R1", &nodes[1]},
    {0, -1, -1, 2, 2, "001 Mov #2, R2", &nodes[2]},
    {1,  1,  2, 2, 0, "002 Add R1, R2", &nodes[3]},
    {0, -1, -1, 3, 3, "003 Mov #3, R3", &nodes[4]},
    {2,  1,  3, 3, 0, "004 Sub R1, R3", &nodes[5]},
    {1,  2,  3, 3, 0, "005 Add R2, R3", &nodes[6]},
    {3, -1, -1,-1, 0, "006 HLT",NULL}
};

void sim(Node *head, int fwd) {
    int wb[4] = {0}, ex[4] = {0};
    int IF,ID;
    int prev_if = 0, prev_id = 0;
    printf("=== %s Forwarding ===\n%-16s | IF | ID | EX | WB\n", fwd ? "With" : "Without", "Instruction");

    for (Node *p = head; p != NULL; p = p->next) {
         if (p == head)
         {
         	IF =2;
         }  
         else
         {
         	 if (prev_if + 1 > prev_id) 
         	 	IF =prev_if + 1;
         	 	
         	 else
         	 	IF =prev_id;
         }
         
        int min_id = IF + 1;
        
        if (p != head && prev_id + 1 > min_id) 
        	min_id = prev_id + 1;

        int dep = 0,*ready = fwd ? ex : wb;
        
        if (p->s1 > 0 && ready[p->s1] > dep) 
        	dep = ready[p->s1];
        
        if (p->s2 > 0 && ready[p->s2] > dep) 
        	dep = ready[p->s2];

        if (min_id > dep)
        	ID = min_id;
        else
        	ID = dep;
        	
        int EX = ID + 1;
        int WB = EX + 1;

        if (p->d > 0) 
        { 
        	wb[p->d] = WB; 
        	ex[p->d] = EX; 
        }

        printf("%-16s | %2d | %2d | %2d | %2d\n", p->instn, IF, ID, EX, WB);
       
        prev_if = IF;
        prev_id = ID;
        
        if (!p->next) 
        	printf("Total Clock Cycles: %d\n\n", WB);
    }
}

int main() {
    sim(nodes, 0); 
    sim(nodes, 1);

    int R[4] = {0};
    
    for (Node *p = nodes; p != NULL; p = p->next) 
    {
        if (p->op == 0) 
        	R[p->d] = p->imm;
        else if (p->op == 1) 
        	R[p->d] += R[p->s1];
        else if (p->op == 2) 
        	R[p->d] -= R[p->s1];
    }

    printf("Final Registers: R1=%d, R2=%d, R3=%d\n", R[1], R[2], R[3]);
    return 0;
}