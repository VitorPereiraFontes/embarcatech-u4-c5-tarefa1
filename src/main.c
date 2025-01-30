#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Define os pinos GPIO ao qual os leds estão conectados
#define RED_LED_PIN 13 
#define GREEN_LED_PIN 11

// Define o delay, em milissegundos, utilizado para o disparo da função de callback
#define CALLBACK_DELAY 3000 // 3 segundos

// Instancia a estrutura base para o timer
repeating_timer_t repeating_timer_struct;

bool RGB_LED_callback(repeating_timer_t* repeating_timer_struct){
    static uint counter = 0; // Contador cíclico, para o controle dos LED's

    printf("Passaram-se 3 segundos, mudano o estado dos LED's!\n");

    switch (counter){
    case 0:
        // Apaga os demais LED's e acende o amarelo
        gpio_put(RED_LED_PIN,true);
        gpio_put(GREEN_LED_PIN,true);
        
        counter++; // Incrementa o contador
        break;

    case 1:
        // Apaga os demais LED's e acende o verde
        gpio_put(RED_LED_PIN,false);
        gpio_put(GREEN_LED_PIN,true);

        counter++; // Incrementa o contador
    break;
    
    default:
        // Apaga os demais LED's e acende o vermelho
        gpio_put(RED_LED_PIN,true);
        gpio_put(GREEN_LED_PIN,false);
        // Reinicia o contador
        counter = 0;
        break;
    }

    return true; // Retorna 'true' para manter o timer habilitado
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa as GPIO's dos LED's como saída em nivel baixo
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN,GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN,GPIO_OUT);

    // Acende o LED vermelho
    gpio_put(RED_LED_PIN,true);

    // Configura o timer repetitivo de hardware para chamar o callback que controlará os LED's
    add_repeating_timer_ms(CALLBACK_DELAY,RGB_LED_callback,NULL,&repeating_timer_struct);

    while (true) {
        sleep_ms(1000); // Delay de 1 segundo
        uint32_t seconds_since_boot = to_ms_since_boot(get_absolute_time()) / 1000; // Obtém o tempo desde o boot do microcontrolador, converte para milissegundos e depois para segundos.
        printf("Segundos desde o boot: %d\n",seconds_since_boot);
    }
}
