
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "procfs_hello_world"

static struct proc_dir_entry *parent_dir;
char* message;
int len;
int bar_temp;

static ssize_t read_hello(struct file *filp,char __user *buf,size_t count,loff_t *offp ) {	
	printk(KERN_INFO"count=%d\n", count);
	if (count>bar_temp)
		count=bar_temp;
	bar_temp=bar_temp-count;
	copy_to_user(buf, message, count);
	if (count==0)
		bar_temp=len;
	return count;
}

static const struct file_operations proc_fops={
	.read=read_hello
};


static int __init init_hello_world(void)
{
	parent_dir=proc_mkdir("hello", NULL);
	if (parent_dir==NULL)
	{
		printk(KERN_INFO "ERROR CREATING PROC ENTRY");
	}
	proc_create("world",0,parent_dir,&proc_fops);
	message="hello world\n";
	len=strlen(message);
	return 0;
}

static void __exit cleanup_hello_world(void){
	printk(KERN_INFO"%s%s removed\n", MODULE_NAME, MODULE_VERS);
	remove_proc_entry("hello",parent_dir);
	remove_proc_entry("world",NULL);
}

module_init(init_hello_world);
module_exit(cleanup_hello_world);
MODULE_LICENSE("GPL");   //模块许可声明
MODULE_AUTHOR("Tiansheng Huang");
MODULE_DESCRIPTION("hello world");
