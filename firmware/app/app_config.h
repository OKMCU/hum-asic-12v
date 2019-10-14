/******************************************************************************

 @file  app_config.h

 @brief 

 Group: 
 Target Device: 

 ******************************************************************************
 

 ******************************************************************************
 Release Name: 
 Release Date: 
 *****************************************************************************/

#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#define FIRMWARE_VER            "V1.5.0"
#define HARDWARE_VER            "V1.1.0"
#define APP_ASSERT_EN                   1
#define APP_CLI_EN                      0
#define APP_CLI_CMD_TEST_EN             0
#define APP_CLI_CMD_SYSCLK_INC_EN       0
#define APP_CLI_CMD_SYSCLK_DEC_EN       0
#define APP_CLI_CMD_ON_EN               0
#define APP_CLI_CMD_OFF_EN              0
#define APP_FHOP_EN                     1
#define APP_WATERDET_EN                 1

#if APP_WATERDET_EN > 0
#define WATER_INDEX_IIR_WEAK(old, new)      (uint16_t)(((uint32_t)old*15+(uint32_t)new)>>4)
#define WATER_INDEX_IIR(old, new)           (uint16_t)(((uint32_t)old*15+(uint32_t)new)>>4)
#define WATER_INDEX_IIR_CNT                  20
#define WATER_INDEX_NO_WATER_HI_THRESHOLD    270 // Aug 2019: Tuned to ~500mA normal working current, setting changed from 350 to 300
#define WATER_INDEX_NO_WATER_LO_THRESHOLD    50 // Aug 2019: Tuned to ~500mA normal working current, setting changed from 50 to 110
#endif

#define APP_POR_INIT_DELAY_MS           1000


/**************************************************************************************************
 *                                        FUNCTIONS - API
 **************************************************************************************************/

#endif

