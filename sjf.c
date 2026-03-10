
#include <stdio.h>
#include <string.h>
struct Process {
    char pid[10];
    int at, bt;
    int wt, tat;
    int completed;
};
int main() {
    int n, i, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].completed = 0;
    }
    while(completed < n) {
        int idx = -1;
        int min_bt = 100000;
        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].completed == 0) {
                if(p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }
        if(idx != -1) {
            time += p[idx].bt;
            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;
            avg_wt += p[idx].wt;
            avg_tat += p[idx].tat;
            completed++;
        }
        else {
            time++;
        }
    }
    printf("\nWaiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }
    printf("\nTurnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);
    return 0;
}
