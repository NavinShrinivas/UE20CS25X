#include <linux/kernel.h> //has kernel API's 
#include <linux/module.h> //Included for all modules has start and end macros
#include <linux/sched.h> //For the task_struct structure
#include <linux/sched/signal.h> //For the "for_each_proc" macro 

//Details returned during modinfo module_name.ko
MODULE_AUTHOR("P K Navin Shrinivas");
MODULE_DESCRIPTION("Task: Starting from init proc, list all proc's");
MODULE_LICENSE("GPL");


static int __init listerstart(void) { //name can be anything
    //task struct : https://elixir.bootlin.com/linux/latest/source/include/linux/sched.h#L728
    //for_each_process marco : https://elixir.bootlin.com/linux/latest/source/include/linux/sched/signal.h#L629
    ////insmod start executing from this function
    struct task_struct* proc;

    for_each_process(proc){
        printk("Process name : %s \n",proc->comm);
        printk("\t|\n");
        printk("\t|__Parent Process pid : %d \n",proc->parent->pid);
        printk("\t|__Parent Process name : %s \n",proc->parent->comm);
        printk("\t|__Process pid : %d \n",proc->pid);
        int state = proc->__state;
        char state_in_words[100];
        if(state == TASK_RUNNING)
            strcpy(state_in_words,"Task Running.");
        else if(state == TASK_INTERRUPTIBLE)
            strcpy(state_in_words,"Task is currently running but can be interrupted.");
        else if(state == TASK_UNINTERRUPTIBLE)
            strcpy(state_in_words,"Task is currently running and can not be interrupted.");
        else
            strcpy(state_in_words,"Task has stopped and is not ready to run.");
        printk("\t|__Process state : %d (%s) \n",state,state_in_words);

    }
    return 0;
}

static void __exit listerend(void)
{     
    //Executed during rmmod
    printk(KERN_INFO "Module Clean up,from Lister module \n"); 
}
module_init(listerstart);
module_exit(listerend);

