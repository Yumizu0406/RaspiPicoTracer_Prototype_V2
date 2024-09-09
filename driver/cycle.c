/***********************************************************************************************************************
* ファイル名 : cycle.c
* 説明 : 周期モジュール
*        timer.cと名付けたかったがSDK内にtimer.cがあるためcycle.cとした
***********************************************************************************************************************/

/***********************************************************************************************************************
include
***********************************************************************************************************************/
#include "cycle.h"
#include "sw.h"
//#include "../application/control.h"
//#include "lineSensor.h"
#include "pico/stdlib.h"

/***********************************************************************************************************************
prototype
***********************************************************************************************************************/
bool cycle_callback_1ms(__unused struct repeating_timer *t);

/***********************************************************************************************************************
global
***********************************************************************************************************************/
static __unused struct repeating_timer timer_out;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

/***********************************************************************************************************************
 * Function Name: init_cycle
 * Description  : 周期初期化処理
 *                特定の関数を1ms周期のタイマコールバック関数として登録する
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void init_cycle(void){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    add_repeating_timer_ms(-1, cycle_callback_1ms, NULL, &timer_out);//1msごとにtimer_callback_1ms関数をコール
}

/***********************************************************************************************************************
 * Function Name: cycle_callback_1ms
 * Description  : タイマコールバック処理
 * Arguments    : *t
 * Return Value : none
 ***********************************************************************************************************************/
bool cycle_callback_1ms(__unused struct repeating_timer *t){
    if ( gpio_get(LED_PIN) != 0 ){
        gpio_put(LED_PIN, 0);
    }
    else{
        gpio_put(LED_PIN, 1);
    }

    update_sw();
    //update_lineSensor();
    //update_control();
    return true;
}
