#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include<linux/string.h>

int id=1;

module_param(id,int,S_IRUGO);

static int tasks_init(void){
    struct task_struct *p;    
    pr_info("%s: !!!Entring Module!!!\n", __func__);
    
    for_each_process(p) {
        if(p->pid==id){
        printk(KERN_INFO "Process ID       : %d",p->pid);
        printk(KERN_INFO "User ID          : %d",p->cred->uid);
        printk(KERN_INFO "Process Group ID : %d",p->cred->gid);
        printk(KERN_INFO "\n");
        }else{
            continue;
        }
         
    }
    return 0;
}

static void tasks_exit(void){
    pr_info("%s: !!!Exiting Module!!!\n", __func__);
}

MODULE_LICENSE("GPL");
module_init(tasks_init);
module_exit(tasks_exit)