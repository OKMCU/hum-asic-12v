/******************************************************************************

 @file  hal_drivers.h

 @brief Describe the purpose and contents of the file.

 Group: 
 Target Device: 

 ******************************************************************************

 ******************************************************************************
 Release Name: 
 Release Date: 
 *****************************************************************************/

#ifndef __HAL_DRIVERS_H__
#define __HAL_DRIVERS_H__

#include "stdint.h"


/* ------------------------------------------------------------------------------------------------
 *                                           Macros
 * ------------------------------------------------------------------------------------------------
 */

/* ------------------------------------------------------------------------------------------------
 *                                          Prototypes
 * ------------------------------------------------------------------------------------------------
 */
extern void hal_driver_init        ( void );
extern void hal_task_driver_basic  ( uint8_t task_id, uint8_t event_id );


/**************************************************************************************************
 */

/**************************************************************************************************
 *                                        FUNCTIONS - API
 **************************************************************************************************/

#endif

