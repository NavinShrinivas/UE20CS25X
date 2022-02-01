# Process Scheduling 

- A single-core CPU can only run one process at a time. Others must wait for the CPU to free up.
- Aim of multiprogramming is to run multiple programs and maximize utilization of CPU. 
- Several processes are kept in memory.
- Using Scheduling Algorithms, CPU time is given to these processes.

Various keywords to be first defined before we can learn these Algorithms is given below.


## Bursts

CPU Burst is when a process is being process is gaining control of the CPU, it's the amount of CPU time a process gets.
I/O Burst is when a process is waiting for I/O for further execution.

After a I/O Burst the processes enters a queue waiting for CPU Burst.

An I/O bound program has many short CPU Bursts, A CPU bound program may have few long CPU Bursts. This difference is important when selecting the type of scheduling algorithm.

## Algorithms 

Selects from the ready queue and allocates CPU to one of them.
- Queue may be ordered in many ways 
  - FIFO, P-Queue, Tree, Linked List.
CPU Scheduling can take place during the following:

1. Switches from running to waiting       -> need of I/O or CPU Burst
2. Switches from running to ready state   -> Only during interrupts
3. Switches from waiting to ready         -> I/O or CPU Burst (Which ever was needed) was given
4. Terminates                             -> Process send exit code

### Preemptive Scheduling 

Scheduling under 2 and 3 is called preemptive scheduling.

What does preemptive scheduling consider before giving a process CPU or I/O time?
- Consider shared data 
- Consider preemption while in kernel mode 
- Consider interrupts occurring during crucial OS activities

### Non-Preemptive Scheduling 

Scheduling during 1 and 4 are called non-preemptive scheduling.

Windows 3.x used non-preemptive, all OS after uses preemptive.
But Preemptive has the problem of race conditions. To solve this we have Dispatcher.

### Criteria of a good scheduler 

- CPU Utilization : Keep the CPU as busy as possible                => maximum
- Throughput : # of processes completed per unit time               => maximum
- Turnaround time : Amount of time to execute a certain process     => minimum
- Waiting time : Amount of time the process is waiting in the queue => minimum
- Response time : Amount of time from read to scheduling.           => minimum

## Dispatcher

Gives control of CPU to the process selected by short-term scheduler. It does the follow there after : 

- Switching context
- Switching to user mode
- Jumping to proper location to restart program 

All this process leads to a little latency, this is called Dispatch latency.

