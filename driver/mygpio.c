#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/gpio.h>
#define DEVICE_NAME "/dev/mygpio"
#define MAJOR_NUM 42
#define PIN_NUM  23

static int mygpio_open(struct inode *inode, struct file *file){
	pr_info("%s\n", __func__);
	return 0;
}
static int mygpio_release(struct inode *inode, struct file *file){
	pr_info("%s\n", __func__);
	return 0;
}
static ssize_t mygpio_read(struct file *file, char *buffer, size_t length, loff_t * offset){
	pr_info("%s %u\n", __func__, length);
	return 0;
}
static ssize_t mygpio_write(struct file *file, const char *buffer, size_t length, loff_t * offset){
	pr_info("%s %u\n", __func__, length);
	return length;
}

struct file_operations mygpio_fops = {
	.owner = THIS_MODULE,
	.open = mygpio_open,
	.release = mygpio_release,
	.read = mygpio_read,
	.write = mygpio_write,
};

int __init mygpio_init(void){
	int ret;
	pr_info("%s\n", __func__);
	printk("MYGPIO: init\n");

	if (!gpio_is_valid(Led)){
		printk(KERN_INFO "MYGPIO: Error invalid GPIO\n");
		return -ENODEV;
	}

	ret = register_chrdev(MAJOR_NUM, DEVICE_NAME, &mygpio_fops);
	if (ret != 0)
		return ret;

	gpio_request(PIN_NUM, "A1");
	gpio_direction_output(PIN_NUM, 0);
	gpio_set_value(PIN_NUM, 1);
	printk("MYGPIO: loaded\n");
	return 0;
}

void __exit mygpio_exit(void){
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
	gpio_set_value(PIN_NUM, 0);
	gpio_free(PIN_NUM);
	printk("MYGPIO: unloaded\n");
}

module_init(mygpio_init);
module_exit(mygpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Joshua Talbot - MYGPIO");
MODULE_DESCRIPTION("GPIO Device Driver");
MODULE_VERSION("0.2"); //TODO what dis?
