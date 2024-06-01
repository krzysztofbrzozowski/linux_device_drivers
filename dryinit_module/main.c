#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

MODULE_AUTHOR("");
MODULE_DESCRIPTION("Dryinit driver");
MODULE_LICENSE("GPL");

static int __init custom_init(void) {
    printk(KERN_INFO "DRIVER LOADED");
    return 0;
}

static void __exit custom_exit(void){
    printk(KERN_INFO "DRIVER UNLOADED");
}

module_init(custom_init);
module_exit(custom_exit);