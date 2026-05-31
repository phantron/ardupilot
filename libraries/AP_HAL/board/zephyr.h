/*
 * SPDX-FileCopyrightText: Copyright The Zephyr Project Contributors
 * SPDX-License-Identifier: Apache-2.0
 *
 * AP_HAL board configuration for Zephyr RTOS.
 * Included by AP_HAL/AP_HAL_Boards.h when CONFIG_HAL_BOARD == HAL_BOARD_ZEPHYR.
 */
#pragma once

#define HAL_BOARD_NAME             "ZEPHYR"
#define HAL_CPU_CLASS              HAL_CPU_CLASS_1000
#define HAL_MEM_CLASS              HAL_MEM_CLASS_1000

#ifndef HAL_STORAGE_SIZE
#define HAL_STORAGE_SIZE           16384
#endif
#define HAL_STORAGE_SIZE_AVAILABLE HAL_STORAGE_SIZE

#define HAL_INS_DEFAULT            HAL_INS_NONE
#define HAL_BARO_DEFAULT           HAL_BARO_NONE

#ifndef CONFIG_HAL_BOARD_SUBTYPE
#define CONFIG_HAL_BOARD_SUBTYPE   HAL_BOARD_SUBTYPE_NONE
#endif

#ifndef HAL_PROGRAM_SIZE_LIMIT_KB
#define HAL_PROGRAM_SIZE_LIMIT_KB  4096
#endif

#define HAL_HAVE_BOARD_VOLTAGE     0
#define HAL_HAVE_SERVO_VOLTAGE     0
#define HAL_HAVE_SAFETY_SWITCH     0

#define HAL_OS_POSIX_IO            0
#define HAL_OS_SOCKETS             0

/*
 * Disable ArduPilot scripting subsystem — Zephyr has no Lua-capable
 * filesystem and no malloc.  Must be defined before AP_Scripting_config.h
 * is reached (pulled in transitively via UARTDriver.h → GCS_config.h →
 * AP_RangeFinder_config.h → AP_Scripting_config.h).
 */
#define AP_SCRIPTING_ENABLED       0

#ifdef __cplusplus
#include <AP_HAL_Zephyr/Semaphore.h>
#define HAL_Semaphore              Zephyr::Semaphore
#define HAL_BinarySemaphore        Zephyr::BinarySemaphore
#endif

/*
 * Zephyr sys/util.h defines ARRAY_SIZE; AP_Common.h redefines it identically.
 * Undefine here so AP_Common.h wins without emitting a redefinition warning.
 */
#ifdef ARRAY_SIZE
#undef ARRAY_SIZE
#endif

/*
 * The PSoC device header (pulled in by <zephyr/kernel.h> above) defines
 * GPIO as a peripheral pointer macro.  Un-define it so that the subsequent
 * AP_HAL/GPIO.h class declaration compiles cleanly.
 */
#ifdef GPIO
#undef GPIO
#endif
