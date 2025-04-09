

#define MAX 100

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completed;
} Process;

int main() {
    Process p[MAX];
    int n, tq, time = 0;
    int completed = 0;
    float total_waiting = 0, total_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for Process P%d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
        p[i].arrival_time = 0; // assuming all processes arrive at time 0
        p[i].remaining_time = p[i].burst_time;
        p[i].completed = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) queue[rear++] = i;

    while (completed != n) {
        int i = queue[front];
        front = (front + 1) % MAX;

        if (p[i].remaining_time <= tq) {
            time += p[i].remaining_time;
            p[i].remaining_time = 0;
            p[i].completed = 1;
            completed++;

            p[i].turnaround_time = time - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

            total_waiting += p[i].waiting_time;
            total_turnaround += p[i].turnaround_time;
        } else {
            time += tq;
            p[i].remaining_time -= tq;

            // Check if remaining time < tq, run immediately again
            if (p[i].remaining_time < tq && p[i].remaining_time > 0) {
                time += p[i].remaining_time;
                p[i].turnaround_time = time - p[i].arrival_time;
                p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                p[i].remaining_time = 0;
                p[i].completed = 1;
                completed++;

                total_waiting += p[i].waiting_time;
                total_turnaround += p[i].turnaround_time;
            } else {
                queue[rear] = i;
                rear = (rear + 1) % MAX;
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time = %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);

    return 0;
}
