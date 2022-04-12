#include <linux/kernel.h> //has kernel API's 
#include <linux/module.h> //Included for all modules has start and end macros
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_AUTHOR("P K Navin Shrinivas");
MODULE_DESCRIPTION("Task: Starting from init proc, list all proc's");
MODULE_LICENSE("GPL");


static void child_lister(struct task_struct* parent_proc){
    struct list_head* child_list_head = &parent_proc->children;
    int n=2;
    while(child_list_head->next != NULL){
        printk("Lister mod : child proc : %d \n",n);
        n++;
        child_list_head = child_list_head -> next;
    }
}


static int __init listerstart(void) { //name can be anything
    //task struct :https://elixir.bootlin.com/linux/latest/source/include/linux/sched.h#L728
    //for_each_process marco : https://elixir.bootlin.com/linux/latest/source/include/linux/sched/signal.h#L629
    struct task_struct* proc;
    for_each_process(proc){
        /*printk("User mod : %d \n",proc->pid);*/
    }
    for_each_process(proc){
        printk("Lister mod : parent : %d \n",proc->pid);
        child_lister(proc);
        break;
    }
    return 0;
}

static void __exit listerend(void)
{     
    printk(KERN_INFO "Module Clean up,from Lister module \n"); 
}
module_init(listerstart);
module_exit(listerend);

