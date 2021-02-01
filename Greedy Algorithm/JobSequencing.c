
#include <stdio.h>

#define MAX 100

typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
    if(x < y)
        return x;
    return y;
}


int main() {

    //number of jobs
    int n;

    printf("\n Enter the total number of Jobs : ");
    scanf("%d", &n);

    //jobs with deadline and profit
    Job jobs[n];

    //temp
    Job temp;

    printf("\n Enter job id, job deadline and job profit for all the jobs in the mentioned sequence :\n");
    for(int i=0; i<n; i++) {
        printf("\n Job[%d] :\n", i+1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    //sort the jobs profit wise in descending order
    for(int i=1; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            if(jobs[j+1].profit > jobs[j].profit) {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("\n List of Jobs in Sorted order of profit :\n");
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(int i=0; i<n; i++) {
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    jobSequencingWithDeadline(jobs, n);

    return 0;
}


void jobSequencingWithDeadline(Job jobs[], int n) {

    //variables
    int k, maxprofit;

    //free time slots
    int timeslot[MAX];

    //filled time slots
    int filledTimeSlot = 0;

    //find max deadline value
    int dmax = 0;
    for(int i=0; i<n; i++) {
        if(jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }

    //free time slots initially set to -1 [-1 denotes EMPTY]
    for(int i=1; i<=dmax; i++) {
        timeslot[i] = -1;
    }

    printf("\n\n Maximum Deadline : %d", dmax);

    for(int i=1; i<=n; i++) {
        k = minValue(dmax, jobs[i - 1].deadline);
        while(k >= 1) {
            if(timeslot[k] == -1) {
                timeslot[k] = i-1;
                filledTimeSlot = filledTimeSlot + 1;
                break;
            }
            k = k - 1;
        }

        //if all time slots are filled then stop
        if(filledTimeSlot == dmax) {
            break;
        }
    }

    //required jobs
    printf("\n\n Required Job Sequence : ");
    for(int i=1; i<=dmax; i++) {
        printf("%s", jobs[timeslot[i]].id);
        if(i < dmax) {
            printf(" --> ");
        }
    }

    //required profit
    maxprofit = 0;
    for(int i=1; i<=dmax; i++) {
        maxprofit = maxprofit + jobs[timeslot[i]].profit;
    }
    printf("\n\n Max Profit : %d\n", maxprofit);

}

