cmd_/home/hatter/pi/source/driver/piio/modules.order := {   echo /home/hatter/pi/source/driver/piio/piio.ko; :; } | awk '!x[$$0]++' - > /home/hatter/pi/source/driver/piio/modules.order
