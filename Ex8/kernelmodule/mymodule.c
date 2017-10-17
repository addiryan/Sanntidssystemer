/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/proc_fs.h> 
int procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data);

struct proc_dir_entry* myproc;
MODULE_LICENSE("GPL");

int init_module(void){
	printk(KERN_INFO "Hello world 1.\n");
	myproc = create_proc_entry("myproc",0644,NULL);
	myproc->read_proc = procfile_read;
	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

int procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data){
	if (offset > 0){
		return 0;
	}
	else{
		return sprintf(buffer, "Hello world\n");
	}
}

void cleanup_module(void){
	printk(KERN_INFO "Goodbye world 1.\n");
	remove_proc_entry("myproc", NULL);
}

