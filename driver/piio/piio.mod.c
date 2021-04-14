#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xe988ff22, "module_layout" },
	{ 0xfe990052, "gpio_free" },
	{ 0x745fda82, "class_unregister" },
	{ 0x46939b51, "device_destroy" },
	{ 0xa2691129, "class_destroy" },
	{ 0x8b9a89df, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xf132f406, "__class_create" },
	{ 0x6c056f26, "__register_chrdev" },
	{ 0x5f754e5a, "memset" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x20e5760b, "gpiod_get_raw_value" },
	{ 0xb016bbf6, "gpiod_set_raw_value" },
	{ 0xcdeba110, "gpiod_direction_output_raw" },
	{ 0x5081be58, "gpio_to_desc" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x6ff0f9bd, "try_module_get" },
	{ 0x6d682ba7, "module_put" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E500A711D8D9B98DF301535");
