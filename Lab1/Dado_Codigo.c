#include <pic12f683.h>
#include <stdbool.h>

#define _XTAL_FREQ 20000000

void delay(unsigned int tiempo);
bool botonPresionado();

void main(void)
{
    ANSEL = 0;
    
    TRISIO = 0b00001000;
    GPIO = 0x00;
    
    while (1)
    {
        if (botonPresionado())
        {
            GP0 = 1;
            delay(50);
            GP0 = 0;
            
            GP1 = 1;
            delay(50);
            GP1 = 0;
            
            GP2 = 1;
            delay(50);
            GP2 = 0;
        }
    }
}

void delay(unsigned int tiempo)
{
    unsigned int i, j;

    for (i = 0; i < tiempo; i++)
        for (j = 0; j < 1275; j++);
}

bool botonPresionado()
{
    return (!GP3);
}
