#include "mcc_generated_files/system/system.h"
#include <stdint.h>
#include <stdbool.h>

// Trimite un string prin UART1 (EUSART1)
static void UART_SendString(const char *s) {
    while (*s) {
        while(!EUSART1_IsTxReady()) { }
        EUSART1_Write((uint8_t)*s++);
    }
}

// Trimite mesaj "R<port><pin> LOW\r\n"
static void UART_SendPinLow(char portLetter, uint8_t pin) {
    while(!EUSART1_IsTxReady()) { }
    EUSART1_Write('R');
    while(!EUSART1_IsTxReady()) { }
    EUSART1_Write(portLetter);
    while(!EUSART1_IsTxReady()) { }
    EUSART1_Write('0' + pin);
    UART_SendString(" LOW\r\n");
}

// Edge detect: trimite doar când trece din HIGH în LOW
static void CheckPort(volatile uint8_t portValue, char portLetter, uint8_t maxPins, uint8_t *last, uint8_t ignoreMask) {
    for(uint8_t i=0; i<maxPins; i++) {
        if(ignoreMask & (1<<i)) continue; // ignoră pinul
        uint8_t now = (portValue & (1u << i)) ? 1u : 0u;
        if (now == 0u && last[i] == 1u) {
            UART_SendPinLow(portLetter, i);
        }
        last[i] = now;
    }
}

// Stări anterioare
static uint8_t lastA[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastB[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastC[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastD[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastE[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastF[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastG[8] = {1,1,1,1,1,1,1,1};
static uint8_t lastH[4] = {1,1,1,1};

int main(void) {
    SYSTEM_Initialize();
    UART_SendString("System Ready\r\n");

    while(1) {
        CheckPort(PORTA, 'A', 8, lastA, 0x00);
        CheckPort(PORTB, 'B', 8, lastB, 0x00);
        // RC6 și RC7 ignorate => mask = b11000000 = 0xC0
        CheckPort(PORTC, 'C', 8, lastC, 0xC0);
        CheckPort(PORTD, 'D', 8, lastD, 0x00);
        CheckPort(PORTE, 'E', 8, lastE, 0x00);
        CheckPort(PORTF, 'F', 8, lastF, 0x00);
        // RG3 ignorat => mask = b00001000 = 0x08
        CheckPort(PORTG, 'G', 5, lastG, 0x08);
        CheckPort(PORTH, 'H', 4, lastH, 0x00);

        __delay_ms(20);
    }

    return 0;
}
