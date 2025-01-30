#include <stdio.h>
#include "pico/stdlib.h"

// Define os pinos GPIO ao qual os leds estão conectados
#define RED_LED_PIN 13 
#define GREEN_LED_PIN 12

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa as GPIO's dos LED's como saída em nivel baixo
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN,GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN,GPIO_OUT);

    while (true) {
        sleep_ms(1000); // Delay de 1 segundo
    }
}
