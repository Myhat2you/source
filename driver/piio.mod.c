#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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
__used __section("__versions") = {
	{ 0x2e44c46d, "module_layout" },
	{ 0xfe990052, "gpio_free" },
	{ 0x5b81332b, "class_unregister" },
	{ 0xf2cca003, "device_destroy" },
	{ 0x22b6ff18, "class_destroy" },
	{ 0x7ab03cfa, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xdccbd6b3, "__class_create" },
	{ 0x79897060, "__register_chrdev" },
	{ 0x5f754e5a, "memset" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x7080fc96, "gpiod_get_raw_value" },
	{ 0x7e7758a3, "gpiod_set_raw_value" },
	{ 0x99743ec3, "gpiod_direction_output_raw" },
	{ 0x2bdd96a2, "gpio_to_desc" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x13d11ca1, "try_module_get" },
	{ 0x6198c12c, "module_put" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CF4CE3F8C635F56D118A952");
