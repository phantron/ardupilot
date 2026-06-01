#pragma once

#include <stdint.h>

#include "AP_HAL_Boards.h"

/* Some embedded BSP headers define GPIO as a memory-mapped peripheral
 * pointer macro (e.g. Infineon PSoC pse846gps2dbzc4a.h:
 *   #define GPIO ((GPIO_Type*) GPIO_BASE)
 * This collides with 'class GPIO' in AP_HAL_Namespace.h.  Un-define the
 * macro here — after AP_HAL_Boards.h sets HAL_BOARD but before
 * AP_HAL_Namespace.h forward-declares class GPIO. */
#ifdef GPIO
#undef GPIO
#endif

#include "AP_HAL_Namespace.h"
#include "AP_HAL_Macros.h"
#include "AP_HAL_Main.h"

/* HAL Module Classes (all pure virtual) */
#include "UARTDriver.h"
#include "AnalogIn.h"
#include "Storage.h"
#include "GPIO.h"
#include "RCInput.h"
#include "RCOutput.h"
#include "Scheduler.h"
#include "Semaphores.h"
#include "Util.h"
#include "OpticalFlow.h"
#include "Flash.h"
#include "DSP.h"

#include "CANIface.h"

#include "utility/BetterStream.h"

/* HAL Class definition */
#include "HAL.h"

#include "system.h"
