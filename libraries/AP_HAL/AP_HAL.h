#pragma once

#include <stdint.h>

/* AP_HAL_Boards.h must precede AP_HAL_Namespace.h so that board-specific
 * headers (e.g. board/zephyr.h) can #undef platform register macros (GPIO,
 * etc.) before AP_HAL_Namespace.h forward-declares class GPIO. */
#include "AP_HAL_Boards.h"
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
