#include <linux/kernel.h> //has kernel API's 
#include <linux/module.h> //Included for all modules has start and end macros
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_AUTHOR("P K Navin Shrinivas");
MODULE_DESCRIPTION("Task: Starting from init proc, list all proc's");
MODULE_LICENSE("GPL");




static int __init listerstart(void) { //name can be anything
    //task struct :https://elixir.bootlin.com/linux/latest/source/include/linux/sched.h#L728
    //for_each_process marco : https://elixir.bootlin.com/linux/latest/source/include/linux/sched/signal.h#L629
    struct task_struct* proc;
    for_each_process(proc){
        /*printk("User mod : %d \n",proc->pid);*/
    }
    for_each_process(proc){
        printk("Process name : %s \n",proc->comm);
        printk("Process pid : %d \n",proc->pid);
    }
    return 0;
}

static void __exit listerend(void)
{     
    printk(KERN_INFO "Module Clean up,from Lister module \n"); 
}
module_init(listerstart);
module_exit(listerend);

