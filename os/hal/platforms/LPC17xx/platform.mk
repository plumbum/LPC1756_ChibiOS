# List of all the LPC13xx platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/platforms/LPC17xx/hal_lld.c \
              ${CHIBIOS}/os/hal/platforms/LPC17xx/gpt_lld.c \
              ${CHIBIOS}/os/hal/platforms/LPC17xx/pal_lld.c \
              ${CHIBIOS}/os/hal/platforms/LPC17xx/serial_lld.c \
              ${CHIBIOS}/os/hal/platforms/LPC17xx/spi_lld.c \
              ${CHIBIOS}/os/hal/platforms/LPC17xx/system_LPC17xx.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/platforms/LPC17xx
