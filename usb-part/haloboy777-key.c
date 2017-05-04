/*
 * =====================================================================================
 *
 *       Filename:  USB.c
 *
 *    Description:  usb driver for key board
 *
 *        Version:  1.0
 *        Created:  04/28/2017 08:03:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  haloboy777
 *
 * =====================================================================================
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>


// Function for insertion of device if and only if no other device is called
static int key_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
	printk(KERN_INFO "[**] haloboy777 keyboard (%04X:%04X) plugged in\n", id->idVendor, id->idProduct);
	return 0;		// Return 0 indicates that we will manage this device
}

static void key_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "[**] haloboy777 keyboard removed\n");
}
static struct usb_device_id key_board[] = { //ID of the device for the identification of the device and registering it to the linux module system
	{ USB_DEVICE(0x0b38, 0x0010)},
	{}
};

static struct usb_driver keyboard_driver =
{
	.name = "haloboy777 BELKIN USB keyboard driver",  // USB driver registering function
	.id_table = key_board,
	.probe = key_probe,
	.disconnect = key_disconnect,
};

static int __init keyboard_init(void)
{
	int ret =-1;
	printk(KERN_INFO "[**] Registering Driver with kernel");
	ret = usb_register(&keyboard_driver);
	printk(KERN_INFO "[**] \tRegistration is complete");
	return ret;
}

static void __exit keyboard_exit(void)
{
	printk(KERN_INFO "[**] Deregistering driver with kernel");
	usb_deregister(&keyboard_driver);
	printk(KERN_INFO "[**] Unregisteration complete!");	
}

module_init(keyboard_init);
module_exit(keyboard_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("haloboy777");
MODULE_DESCRIPTION("USB keyboard registration driver");

