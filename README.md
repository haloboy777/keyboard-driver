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
