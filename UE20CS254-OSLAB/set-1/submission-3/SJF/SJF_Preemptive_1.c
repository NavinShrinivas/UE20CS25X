#include "SJF_Preemptive.h"
#include <stdio.h>

void fetch_proc(proc_t **list, int n) {
  printf("Enter process details : \n");
  for (int i = 0; i < n; i++) {

    printf("Next process : \n");
    printf("\t Enter process id : ");
    int c;
    scanf("%d", &c);
    bool present = false; // for avoiding breaks in C code.
    for (int j = 0; j < 1024; j++) {
      if (list[j] != NULL &&
          list[j]->id_ == c) { // NULL condition due to seg faults
        printf("\n Process with same ID has already arrived! \n");
        printf("previous input discarded! \n");
        printf(
            "If you want to enter a dummy process enter burst time as 0 \n \n");
        present = true;
      }
    }

    if (!present) {
      list[i] = (proc_t *)malloc(sizeof(proc_t));
      list[i]->id_ = c;
      list[i]->copy_ = c;
      printf("\t Enter process arrival time : ");
      scanf("%d", &(list[i]->arrival_));
      printf("\t Enter process burst time : ");
      scanf("%d", &(list[i]->burst_));
    } else {
      i--; // to make sure there is not empty gaps in the array
    }
  }
}

void exec_proc(proc_t **list, exec_t **exec_list, int n) {
  /*
   *- wait time : time of arrival to the time the CPU burst were given
   *- turnaround time : time of arrival to time of completion
   */

  list[1023] = (proc_t *)malloc(sizeof(proc_t));
  int count = 0; // keeps track of number of proc's coimpleted
  for (int time = 0; count != n; time++) {
    // find the shortest job arriving at or before the present time.
    int smallest = 1023; // if no job found at a given time it will remain 1023
    list[1023]->burst_ = 99999;
    for (int i = 0; i < n; i++) {
      if (list[i] != NULL) {
        if (list[i]->arrival_ <= time &&
            list[i]->burst_ <= list[smallest]->burst_ && list[i]->burst_ > 0) {

          smallest = i;
        }
      }
    }
    list[smallest]->burst_--;
    if (list[smallest]->burst_ == 0) { // process is complete, calculate now
      count++;
      exec_list[smallest] = (exec_t *)malloc(sizeof(exec_t));
      exec_list[smallest]->end_ = time + 1;
      exec_list[smallest]->wait_ = exec_list[smallest]->end_ -
                                   list[smallest]->arrival_ -
                                   list[smallest]->copy_;
      exec_list[smallest]->tat_ =
          exec_list[smallest]->end_ - list[smallest]->arrival_;
    }
  }
}

void print(int n, exec_t **exec_list) {
  double wait_sum = 0.0;
  double tat_sum = 0.0;
  for (int i = 0; exec_list[i] != NULL; i++) {
    wait_sum += exec_list[i]->wait_;
    tat_sum += exec_list[i]->tat_;
  }
  printf("Average wait time : %f \n", wait_sum / n);
  printf("Average turnaround time : %f \n", tat_sum / n);
}
