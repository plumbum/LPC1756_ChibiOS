# LPC1756 flasher/debugger
#
target remote :3333

#delays on reset lines
#monitor jtag_nsrst_delay 200
#monitor jtag_ntrst_delay 200
#monitor jtag_khz 500 

# LPC2000 & LPC1700 -> SRST causes TRST
monitor reset_config trst_and_srst separate
# reset_config trst_only srst_pulls_trst
# trst_and_srst separate srst_gates_jtag trst_push_pull srst_open_drain

monitor reset halt

monitor flash protect 0 0 29 off
monitor flash erase_sector 0 0 29

# LPC1768 has 512kB of user-available FLASH (bootloader is located in separate dedicated region).
# flash bank lpc1700 <base> <size> 0 0 <target#> <variant> <cclk> [calc_checksum]
#flash bank $_FLASHNAME lpc2000 0x0 0x80000 0 0 $_TARGETNAME lpc1700 4000 calc_checksum

load

monitor reset halt
#break main
continue

