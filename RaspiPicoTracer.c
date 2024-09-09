#include "pico/stdlib.h"
#include "driver/cycle.h"
#include "driver/sw.h"

const uint DISP_LED_0_BIT_PIN = 10;
const uint DISP_LED_1_BIT_PIN = 11;
const uint DISP_LED_2_BIT_PIN = 13;

void init_driver(void);
void disp_led(uint8_t value);

static uint8_t now_led_disp_value;
static uint8_t menu_no;

int main()
{
    now_led_disp_value = 8;
    menu_no = 0;

    init_driver();

    while (true) {
        if(isSwStatus(SW_EXE, click)){
            menu_no++;
            if(menu_no >= 8){
                menu_no = 0;
            }
        }
        disp_led(menu_no);
    }
}

void init_driver(void){
    gpio_init(DISP_LED_0_BIT_PIN);
    gpio_set_dir(DISP_LED_0_BIT_PIN, GPIO_OUT);
    gpio_init(DISP_LED_1_BIT_PIN);
    gpio_set_dir(DISP_LED_1_BIT_PIN, GPIO_OUT);
    gpio_init(DISP_LED_2_BIT_PIN);
    gpio_set_dir(DISP_LED_2_BIT_PIN, GPIO_OUT);

    init_sw();
    //init_lineSensor();
    init_cycle();
}

void disp_led(uint8_t value){
    uint8_t tmp_value;
    tmp_value = value & 0x07;

    if(now_led_disp_value == value){
        return;
    }

    now_led_disp_value = value;

    if(value == 0){
        gpio_put(DISP_LED_0_BIT_PIN, 1);
        gpio_put(DISP_LED_1_BIT_PIN, 1);
        gpio_put(DISP_LED_2_BIT_PIN, 1);
    } else if(value == 1){
        gpio_put(DISP_LED_0_BIT_PIN, 0);
        gpio_put(DISP_LED_1_BIT_PIN, 1);
        gpio_put(DISP_LED_2_BIT_PIN, 1);
    } else if(value == 2){
        gpio_put(DISP_LED_0_BIT_PIN, 1);
        gpio_put(DISP_LED_1_BIT_PIN, 0);
        gpio_put(DISP_LED_2_BIT_PIN, 1);
    } else if(value == 3){
        gpio_put(DISP_LED_0_BIT_PIN, 0);
        gpio_put(DISP_LED_1_BIT_PIN, 0);
        gpio_put(DISP_LED_2_BIT_PIN, 1);
    } else if(value == 4){
        gpio_put(DISP_LED_0_BIT_PIN, 1);
        gpio_put(DISP_LED_1_BIT_PIN, 1);
        gpio_put(DISP_LED_2_BIT_PIN, 0);
    } else if(value == 5){
        gpio_put(DISP_LED_0_BIT_PIN, 0);
        gpio_put(DISP_LED_1_BIT_PIN, 1);
        gpio_put(DISP_LED_2_BIT_PIN, 0);
    } else if(value == 6){
        gpio_put(DISP_LED_0_BIT_PIN, 1);
        gpio_put(DISP_LED_1_BIT_PIN, 0);
        gpio_put(DISP_LED_2_BIT_PIN, 0);
    } else if(value == 7){
        gpio_put(DISP_LED_0_BIT_PIN, 0);
        gpio_put(DISP_LED_1_BIT_PIN, 0);
        gpio_put(DISP_LED_2_BIT_PIN, 0);
    }

}