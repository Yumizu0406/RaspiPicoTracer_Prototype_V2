#include <stdio.h>
#include "pico/stdlib.h"
#include "driver/cycle.h"

void init_driver(void);

int main()
{
    stdio_init_all();
    init_driver();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

void init_driver(void){
    //init_sw();
    //init_lineSensor();
    init_cycle();
}
