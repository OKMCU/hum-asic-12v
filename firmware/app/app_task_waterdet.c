/******************************************************************************

 @file  app_task_waterdet.c

 @brief 

 Group: 
 Target Device: 

 ******************************************************************************
 

 ******************************************************************************
 Release Name: 
 Release Date: 
 *****************************************************************************/

/**************************************************************************************************
 * INCLUDES
 **************************************************************************************************/
#include "osal.h"
#include "hal.h"
#include "app.h"

#include "main.h"

#if APP_WATERDET_EN > 0
/**************************************************************************************************
 * TYPES
 **************************************************************************************************/

/**************************************************************************************************
 * CONSTANTS
 **************************************************************************************************/

/**************************************************************************************************
 * LOCAL FUNCTION DECLARATION
 **************************************************************************************************/

/**************************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************************/
static uint16_t water_index_iir;
static uint16_t iir_max;
static uint16_t iir_min;
static uint8_t water_index_iir_cnt;

extern void app_task_waterdet_init( void )
{
    water_index_iir = 0;
    water_index_iir_cnt = 0;
    iir_max = 0;
    iir_min = UINT16_MAX;
}


extern void app_task_waterdet ( uint8_t task_id, uint8_t event_id )
{
    task_id = task_id;
    
    switch (event_id)
    {
        case TASK_EVT_APP_WATERDET_UPDATE:
        {
            if( water_index_iir )
                water_index_iir = WATER_INDEX_IIR( water_index_iir, app_info.adc_value );     //IIR calc
            else
                water_index_iir = app_info.adc_value;                                         //init IIR filter

            if( water_index_iir_cnt < WATER_INDEX_IIR_CNT )                                     //at least proceed WATER_INDEX_IIR_CNT times of IIR calculation
            {
                water_index_iir_cnt++;
            }
            else
            {
                if( water_index_iir > iir_max )
                    iir_max = water_index_iir;
                if( water_index_iir < iir_min )
                    iir_min = water_index_iir;
                
                if( water_index_iir < WATER_INDEX_NO_WATER_LO_THRESHOLD
                  ||water_index_iir > WATER_INDEX_NO_WATER_HI_THRESHOLD )                          //if water_index_iir is too small, no water
                {
                    hal_mist_off();
                    hal_fan_off();
                    app_info.sys_state = SYS_STATE_NO_WATER;
                }
            }
        }
        break;
        
        case TASK_EVT_APP_WATERDET_RESET:
        {
            water_index_iir = 0;
            water_index_iir_cnt = 0;
        }
        break;
        
        default:
            APP_ASSERT_FORCED();
        break;
    }
}

#endif
/**************************************************************************************************
**************************************************************************************************/

