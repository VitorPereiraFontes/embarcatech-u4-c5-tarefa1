# Temporizador repetitivo

## Descrição

Este repositório contém os códigos correspondentes aos requisitos solicitados pela tarefa 1 do capítulo 5 da unidade 4 do programa de capacitação em sistemas embarcados (Embarcatech). A tarefa em questão busca incitar a utilização de um temporizador repetitivo para simular o funcionamento de um semáforo. Originalmente, a solicitação era que 3 LED's com as cores de um semáforo fossem utilizadas, todavia, para permitir a execução do código na placa BitDogLab outou-se por utilizar um LED RGB.

## Requerimentos

O presente projeto deverá atender aos seguintes requerimentos:

* O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde.
* O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).
* A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback().
* A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms).

## Demonstração

Seguem os vídeos de demonstração do projeto, tanto no simulador Wokwi quanto na placa BitDogLab.

## Instruções

Para que o projeto funcione em sua máquina, é necessário ter a extensão Raspberry Pi Pico Project instalada no VSCode.

1. Realize o clone do repositório.
2. Importe o repositório como um projeto através da extensão Raspberry Pi Pico Project.
3. Compile o projeto.
4. Caso esteja usando a placa BitDogLab ou a Raspberry Pi Pico W, faça o upload do arquivo uf2, encontrado na pasta `build` após o processo de compilação, para a placa. Caso deseje simular, abra o arquivo `diagram.json` (É necessário ter a extensão do Wokwi instalada).