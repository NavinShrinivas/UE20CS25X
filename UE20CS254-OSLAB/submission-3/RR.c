// Program to show working of Preemptive Round Robin scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

struct proc {
  int id_;
  int arrival_;
  int burst_;
  int copy_;
  int end_;
};
typedef struct proc proc_t;

int main() {
  int n;
  printf("Enter number of processes : ");
  scanf("%d", &n);
  proc_t *proc_list[1024] = {NULL};
  for (int i = 0; i < n; i++) {
    proc_list[i] = (proc_t *)malloc(sizeof(proc_t));
    printf("Enter details of %d process \n", i + 1);
    printf("\tArrival time of process : ");
    scanf("%d", &(proc_list[i]->arrival_));
    printf("\tEnter burst time of the process : ");
    scanf("%d", &(proc_list[i]->burst_));
    proc_list[i]->copy_ = proc_list[i]->burst_;
    proc_list[i]->id_ = i + 1;
  }
  int quantum;
  printf("Enter time quantum : ");
  scanf("%d", &quantum);

  // sorting wtr to arrival time
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (proc_list[j]->arrival_ > proc_list[j + 1]->arrival_) {
        proc_t *temp = proc_list[i];
        proc_list[i] = proc_list[i + 1];
        proc_list[i + 1] = temp;
      }
    }
  }
  // unlike most algorithms, I'll actually move the jobs to the last
  int count = 0;
  int move_to = n;
  for (int time = 0; count < n;) {
    int fon = 0;
    for (int j = 0; j < move_to; j++) {
      if (proc_list[j]) {
        if (proc_list[j]->arrival_ <= time && proc_list[j]->burst_ > 0) {
          fon = 1;
          if (proc_list[j]->burst_ <= quantum) {
            time += proc_list[j]->burst_;
            proc_list[j]->burst_ = 0;
            proc_list[j]->end_ = time;
            count++;
          } else if (proc_list[j]->burst_ > 0) {
            proc_list[j]->burst_ -= quantum;
            time += quantum;
            proc_t *move = proc_list[j];
            proc_list[j] = NULL;
            proc_list[move_to] = move;
            move_to++;
          }
        }
      }
    }
    if (!fon)
      time++;
  }

  // printing all the stuff
  int tot_tat = 0, tot_wt = 0;
  printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
  for (int i = 0; i < move_to; i++) {
    if (proc_list[i]) {
      int tat = proc_list[i]->end_ - proc_list[i]->arrival_;
      int wt = tat - proc_list[i]->copy_;
      tot_tat += tat;
      tot_wt += wt;
      printf("\nProcess No %d \t\t %d\t\t\t\t %d\t\t\t %d", proc_list[i]->id_,
             proc_list[i]->copy_, tat, wt);
    }
  }
  printf("\nAverage Turn around time : %f \n", tot_tat / (n + 0.0));
  printf("Average waiting time : %f \n", tot_wt / (n + 0.0));
  printf("\n");
}
