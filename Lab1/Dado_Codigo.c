#include <pic14/pic12f683.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF); // Desactiva el Watchdog Timer

// Funciones utilizadas
void delay (unsigned inttiempo);  // Funcion que genera un delay para ser utilizarla entre las operaciones
uint8_t rotl(const uint8_t x, int k); // Funcion que genera numeros aleatorios mediante algoritmo Xorshift
uint8_t next(void); // Funcion que va de la manos con el generador de numeros aleatorios
int rand(void); // Se limita a generar numeros aleatorios entre 1 y 6

void main(void)
{

    TRISIO = 0b00100000; // Todos los pines como salida menos GP5 que es entradas
	GPIO = 0x00; //Poner pines en bajo
 
    unsigned int time = 200;
    unsigned int num_aleatorio = 0;

    //Loop forever
    while ( 1 )
    {
        //Si la entrada está en alto
		if (GP5) {
            // Se crea el número aletorio
            num_aleatorio = rand();

            // Se crean los casos para saber cuáles LEDs deben encenderse
            switch (num_aleatorio)
            {
                case 1: // Para encender solo 1 LED
                { 
                    GP1 = 1;
			        delay(time);
			        GP1 = 0;
                    break;
                }

                case 2: // Para encender solo 2 LEDs
                { 
                    GP0 = 1;
			        delay(time);
			        GP0 = 0;
                    break;
                }

                case 3: // Para encender 3 LEDs
                { 
                    GPIO = 0b00000011;
			        delay(time);
                    GPIO = 0b00000000;
                    break;
                }

                case 4: // Para encender 4 LEDs
                { 
                    GPIO = 0b00000101;
			        delay(time);
                    GPIO = 0b00000000;
                    break;
                }

                case 5: // Para encender 5 LEDs
                {
                    GPIO = 0b00000111;
			        delay(time);
                    GPIO = 0b00000000;
                    break;
                }

                case 6: // Para encender 6 LEDs
                { 
                    GPIO = 0b00010101;
			        delay(time);
                    GPIO = 0b00000000;
                    break;
                }
                
            }
            
		} else {
            GPIO = 0x00; 
		}
    }
 
}


void delay(unsigned int tiempo) // Funcion que crea delays en el tiempo 
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}

// Esta función se utiliza para crear el número aleatorio
uint8_t rotl(const uint8_t x, int k) {
    return (x << k) | (x >> (8 - k));
}
uint8_t s[2] = { 0, 0xA3 };

uint8_t next(void) {
    uint8_t s_0 = s[0];
    uint8_t s_1 = s[1];
    uint8_t result = s_0 + s_1;

    s_1 ^= s_0;
    s[0] = rotl(s_0, 6) ^ s_1 ^ (s_1 << 1);
    s[1] = rotl(s_1, 3);

    return result;
}
// Mantener el numero entre 1 y 6
int rand(void) {
    int randi = 0;
    while (1) {
        randi = next();
        if (randi < 7 && randi > 0) {
           return randi;
        }
    }

}

