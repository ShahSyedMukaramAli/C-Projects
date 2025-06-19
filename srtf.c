#include <stdio.h>
#define MAX 100

int main() {
    int at[MAX], bt[MAX], rt[MAX], wt[MAX], tat[MAX];
    int n, i, smallest, count = 0, time, end;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter arrival and burst time for P[%d]: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = 9999; // Sentinel value

    for(time = 0; count != n; time++) {
        smallest = 9;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                smallest = i;
        }

        rt[smallest]--;

        if(rt[smallest] == 0) {
            count++;
            end = time + 1;
            wt[smallest] = end - at[smallest] - bt[smallest];
            tat[smallest] = end - at[smallest];
            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat/n);
    return 0;
}
