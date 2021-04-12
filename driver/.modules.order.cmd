cmd_/home/hatter/pi/source/driver/modules.order := {   echo /home/hatter/pi/source/driver/piio.ko; :; } | awk '!x[$$0]++' - > /home/hatter/pi/source/driver/modules.order
