#include <stdio.h>

typedef struct {
    int addr;
    char text[15];
    char op;      
    int src1, src2, dest, imm;
    int if_c, id_c, ex_c, wb_c;
} Ins;

int simulate(Ins inst[], int n, int forwarding) {
    int reg[4] = {0, 0, 0, 0};
    int stalls = 0;

    if (forwarding == 1) {
        printf("\nCase 2: With Forwarding\n");
    } else {
        printf("\nCase 1: Without Forwarding\n");
    }
    printf("Addr\tInstruction\tIF\tID\tEX\tWB\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            inst[i].if_c = 2;
        } else {
            inst[i].if_c = inst[i-1].id_c;
        }
        inst[i].id_c = inst[i].if_c + 1;
        
        int stall = 0;
        for (int j=0;j<i;j++) {
            if (inst[j].dest != 0 &&
               (inst[i].src1 == inst[j].dest || inst[i].src2 == inst[j].dest)) {
                int ready;
                if (forwarding == 1) {
                    ready = inst[j].ex_c;
                } else {
                    ready = inst[j].wb_c;
                }

                if (ready > inst[i].id_c + stall) {
                    stall = ready - inst[i].id_c;
                }
            }
        }

        inst[i].id_c += stall;
        inst[i].ex_c = inst[i].id_c + 1;
        inst[i].wb_c = inst[i].ex_c + 1;
        stalls += stall;

        if (inst[i].op == 'M') reg[inst[i].dest] = inst[i].imm;
        if (inst[i].op == 'A') reg[inst[i].dest] += reg[inst[i].src1];
        if (inst[i].op == 'S') reg[inst[i].dest] -= reg[inst[i].src1];

        printf("%03d\t%-10s\t%2d\t%2d\t%2d\t%2d\n",
               inst[i].addr, inst[i].text,
               inst[i].if_c, inst[i].id_c, inst[i].ex_c, inst[i].wb_c);
    }

    int total_cycles = inst[n-1].wb_c;
    printf("Total Clock Cycles : %d\n", total_cycles);
    printf("Total Stalls       : %d\n", stalls);
    printf("Final Registers    : R1 = %d, R2 = %d, R3 = %d\n", reg[1], reg[2], reg[3]);

    return total_cycles;
}

int main() {
    int n = 7;

    Ins prog[7] = {
        {0, "Mov #1, R1", 'M', 0, 0, 1, 1, 0, 0, 0, 0},
        {1, "Mov #2, R2", 'M', 0, 0, 2, 2, 0, 0, 0, 0},
        {2, "Add R1, R2", 'A', 1, 2, 2, 0, 0, 0, 0, 0},
        {3, "Mov #3, R3", 'M', 0, 0, 3, 3, 0, 0, 0, 0},
        {4, "Sub R1, R3", 'S', 1, 3, 3, 0, 0, 0, 0, 0},
        {5, "Add R2, R3", 'A', 2, 3, 3, 0, 0, 0, 0, 0},
        {6, "HLT",'H', 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int c1 = simulate(prog, n, 0);
    int c2 = simulate(prog, n, 1);

    printf("\nComparison:\n");
    printf("Without Forwarding: %d cycles \t With Forwarding: %d cycles (Saved %d cycles)\n", c1, c2, c1-c2);

    return 0;
}