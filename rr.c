#include <stdio.h>

int main() {
    int i, n, tq, bt[10], rem_bt[10], wt[10]={0}, tat[10], t = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > tq) {
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P[%d] - WT: %d, TAT: %d\n", i+1, wt[i], tat[i]);
    }

    return 0;
}
