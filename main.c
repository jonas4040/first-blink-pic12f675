/*
 * File:   main.c
 * Author: Jonas Felipe
 *
 * Criado em 8 de Novembro de 2023, 07:52am
 */


// PIC12F675 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// END CONFIG

#include <xc.h>
#define _XTAL_FREQ 4000000      //define para utilizar funções de tempo

int main() {
    
  GPIO    = 0x00;                 //desliga todos os pinos
  TRISIObits.TRISIO5 = 0;       //configura GPIO5 como saída
  CMCON    = 0x07;                 //desliga o comparador analógico
    
    while(1){
      GPIObits.GP5 = ~GPIObits.GP5;  //inverte estado lógico do pino do LED
      __delay_ms(1000);              //aguarda 1 seg
    }

    return 0;
}
	