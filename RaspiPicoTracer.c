#include <stdio.h>
#include "pico/stdlib.h"
#include "driver/cycle.h"
#include "driver/sw.h"
#include "driver/lineSensor.h"

const uint DISP_LED_0_BIT_PIN = 10;
const uint DISP_LED_1_BIT_PIN = 11;
const uint DISP_LED_2_BIT_PIN = 13;

typedef enum{
    selecting_menu = 0,
	exe_menu
}menu_status_t;

void init_driver(void);
void menu_no_0(void);
void menu_no_1(void);
void menu_no_2(void);
void menu_no_3(void);
void menu_no_4(void);
void menu_no_5(void);
void menu_no_6(void);
void menu_no_7(void);
void disp_led(uint8_t value);
void exe_select_func(uint8_t select_func);

static uint8_t now_led_disp_value;
static uint8_t menu_no;
static menu_status_t menu_status;

int main()
{
    now_led_disp_value = 8;
    menu_no = 0;
    menu_status = selecting_menu;

    stdio_init_all();
    init_driver();

    while (true) {
        if(menu_status == selecting_menu){
            if(isSwStatus(SW_NEXT, click)){
                menu_no++;
                if(menu_no >= 8){
                    menu_no = 0;
                }
            }
            disp_led(menu_no);

            if(isSwStatus(SW_EXE, click)){
                menu_status = exe_menu;
            }

        } else {
            if(isSwStatus(SW_BACK, click)){
                menu_status = selecting_menu;
            }
            exe_select_func(menu_no);
        }
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
    init_lineSensor();
    init_cycle();
}

void menu_no_0(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_1(void){
    printf("sensor = %d\n", get_line_center_deff());
    sleep_ms(500);
}

void menu_no_2(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_3(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_4(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_5(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_6(void){
    if(isSwStatus(SW_EXE, click)){

    }
}

void menu_no_7(void){
    if(isSwStatus(SW_EXE, click)){

    }
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

void exe_select_func(uint8_t select_func){
    if(select_func == 0){
        menu_no_0();
    } else if(select_func == 1){
        menu_no_1();
    } else if(select_func == 2){
        menu_no_2();
    } else if(select_func == 3){
        menu_no_3();
    } else if(select_func == 4){
        menu_no_4();
    } else if(select_func == 5){
        menu_no_5();
    } else if(select_func == 6){
        menu_no_6();
    } else if(select_func == 7){
        menu_no_7();
    }
}
