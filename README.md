# keyboard-driver

Implementation of linux USB keyboard driver for Even sem evaluation.
Major code has been inspired from linux kernel USB keyboard driver.

Main code is in usb-part/

~~~
sudo make
sudo insmod usbkbd.ko
~~~

Generally this will not work cause the inbuilt module will always be called first by the usbcore.
So to make it work.
Install libhid module on your linux PC.
By installing libhid, You will also automatically install a programme named

`libhid-detach-device`

and then its all easy-peasy, type the following commands

~~~
sudo libhid-detach-device [VENDOR ID]:[PRODUCT ID]
sudo insmod usbkbd.ko [remove it first if you already inserted the driver first and insert it again]
~~~

Done

Type to your heart's content.. :D


## Some links for further read

* [Prevent autoloading of other modules/drivers](https://www.cyberciti.biz/tips/avoid-linux-kernel-module-driver-autoloading.html)
* [Linux-USB HID configuratiion](http://www.linux-usb.org/USB-guide/x194.html)
* [Essential stuff stated in kernel](http://elixir.free-electrons.com/linux/latest/source/drivers/usb/README)
* [How to find the name of your device](https://superuser.com/questions/352598/how-to-find-the-dev-name-of-my-usb-device)
* [Some functions explained in usbkbd.c](https://ubuntuforums.org/showthread.php?t=1626711)
* [Map a keyboard](http://www.edaboard.com/thread52563.html)

### Some tips
* Use 'sudo modprobe usbmon' and then wireshark to monitor 'usbmon/usbmon0' to capture USB request block for better understanding
* Insert print statemnets in the usbkbd.c code to print the scancode of the key as it is pressed. THIS WILL GREATLY HELP YOU TO MAP THE KEYBOARD.
* Use a USB keyboard if its not obvious by this point, Because if you tamper with your original PC keyboard which is driven by atkbd.c in the kernel you will have to reinstall the whole kernel via SSh (belive me you don't want that headache if you are on a deadline/or use a virtual machine[lol])

If you have any questions hit me up in issues.
