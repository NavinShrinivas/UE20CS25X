#ifndef SJF_H
#define SJF_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct proc {
  int id_;
  int burst_;
  int copy_;
  int arrival_;
};
struct executed {
  int wait_;
  int tat_; // tat : turn around time
  int end_;
};

typedef struct executed exec_t;
typedef struct proc proc_t;

void fetch_proc(proc_t **list, int n);
void exec_proc(proc_t **list, exec_t **exec_list, int n);
void print(int n, exec_t **exec_list);
#endif
