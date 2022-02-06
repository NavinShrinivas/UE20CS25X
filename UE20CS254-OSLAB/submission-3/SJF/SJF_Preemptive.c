#include "SJF_Preemptive.h"

int main() {
  int n;
  printf("Enter number of processes : ");
  scanf("%d", &n);
  proc_t *list[1024] = {NULL}; // initially no process in the list
  exec_t *exec_list[1024] = {NULL};
  fetch_proc(list, n); // fetches processes from the user with ID checks
  exec_proc(list, exec_list, n);
  print(n, exec_list);
  return 0;
}
