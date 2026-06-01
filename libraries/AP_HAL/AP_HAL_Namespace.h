#pragma once

#include "string.h"
#include "utility/functor.h"

/* Some embedded BSP headers define GPIO as a memory-mapped peripheral
 * pointer macro (e.g. Infineon PSoC pse846gps2dbzc4a.h:
 *   #define GPIO ((GPIO_Type*) GPIO_BASE)
 * This clashes with 'class GPIO' below regardless of include order.
 * Un-define it here so the declaration always compiles cleanly. */
#ifdef GPIO
#undef GPIO
#endif

namespace AP_HAL {

    /* Toplevel pure virtual class Hal.*/
    class HAL;

    /* Toplevel class names for drivers: */
    class UARTDriver;
    class I2CDevice;
    class I2CDeviceManager;
    class Device;

    class SPIDevice;
    class SPIDeviceDriver;
    class SPIDeviceManager;

    class AnalogSource;
    class AnalogIn;
    class Storage;
    class DigitalSource;
    class PWMSource;
    class GPIO;
    class RCInput;
    class RCOutput;
    class Scheduler;
    class Semaphore;
    class BinarySemaphore;
    class OpticalFlow;
    class DSP;

    class WSPIDevice;
    class WSPIDeviceDriver;
    class WSPIDeviceManager;

    class CANIface;
    class CANFrame;

    class Util;
    class Flash;

    /* Utility Classes */
    class Print;
    class Stream;
    class BetterStream;

    /* Typdefs for function pointers (Procedure, Member Procedure)

       For member functions we use the FastDelegate delegates class
       which allows us to encapsulate a member function as a type
     */
    typedef void(*Proc)(void);
    FUNCTOR_TYPEDEF(MemberProc, void);

    /**
     * Global names for all of the existing SPI devices on all platforms.
     */

    enum SPIDeviceType {
        // Devices using AP_HAL::SPIDevice abstraction
        SPIDevice_Type              = -1,
    };

    class SIMState;

    // Must be implemented by the concrete HALs and return the same reference.
    const HAL& get_HAL();
    HAL& get_HAL_mutable();
}
