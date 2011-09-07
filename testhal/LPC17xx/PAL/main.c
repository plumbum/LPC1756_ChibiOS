/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>

#include <ch.h>
#include <hal.h>

static WORKING_AREA(led1_thread_wa, 128);
static msg_t led1_thread(void *p)
{
    (void)p;

    while(TRUE)
    {
        LPC_GPIO1->FIOSET = (1<<18);
        chThdSleepMilliseconds(500);
    }
    return 0;
}

static WORKING_AREA(led2_thread_wa, 128);
static msg_t led2_thread(void *p)
{
    (void)p;

    while(TRUE)
    {
        LPC_GPIO1->FIOCLR = (1<<18);
        chThdSleepMilliseconds(400);
    }
    return 0;
}

/*
 * Application entry point.
 */
int main(void) {
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  LPC_GPIO1->FIOSET = (1<<18);
  LPC_GPIO1->FIODIR = (1<<18);

  chThdCreateStatic(led1_thread_wa, sizeof(led1_thread_wa),
                    NORMALPRIO + 1, led1_thread, NULL);
  chThdCreateStatic(led2_thread_wa, sizeof(led2_thread_wa),
                    NORMALPRIO + 1, led2_thread, NULL);

  /*
   * Normal main() thread activity, nothing in this test.
   */
  while (TRUE) {
    chThdSleepMilliseconds(500);
  }
  return 0;
}
