#include <linux/interrupt.h>
#include <asm/io.h>
#include <asm/irq_vectors.h>
#include "driver.h"
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <linux/module.h>


int ret=1;

void replace_ISR(int irq)
{
	ret = request_irq(irq, (irq_handler_t) irq_handler, IRQF_SHARED, "test_keyboard_irq_handler", "mycookie");
}

int get_msb(unsigned char str)
{
	return (str & 0x80);
}

void my_printk(char *string)
{
	struct tty_struct *my_tty;
	my_tty=current->signal->tty;
	
	if(my_tty!=NULL)
	{
		(*my_tty->driver->ops->write)(my_tty, string, strlen(string));
		(*my_tty->driver->ops->write)(my_tty, "\015\012", 2);
	}
}


irq_handler_t irq_handler(int irq, void *dev_id, struct pt_regs *regs)
{
	int  MSB;
	unsigned char scancode;
	scancode = inb(0x60);
	MSB = get_msb(scancode);
	
	if(MSB==0)
	{
		my_printk('A');
	}
	
	else
	{
		printk("\nKey not released");
	}
	
	return (irq_handler_t) IRQ_HANDLED;
}


static int __init entry_func(void)
{
	
	while(ret!=0)
	{
		replace_ISR(1);
	}
	my_printk("\nKeyboard Driver successfully loaded. Type some letters : ");
	printk(KERN_DEBUG "Module loaded\n");
	
	return 0;

}

void __exit exit_func(void)
{
	printk(KERN_DEBUG "Unloading module.\n");
	free_irq(1,"mycookie");
}

module_init(entry_func);
module_exit(exit_func); 	
