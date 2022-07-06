#include "stm32f4xx.h"

#define LOOPARM 666.666666666
#define TEMPO 235000
#define teclaGh4 415.30
#define teclaA4 440
#define teclaB4 493.88
#define teclaC5 523.25
#define teclaD5 587.33
#define teclaE5 659.25
#define teclaF5 698.46
#define teclaG5 783.99
#define teclaGh5 830.61
#define teclaA5 880

void l(int led){
	if(led == 1) GPIOB->ODR|=0x00000002;  // liga o pino 1;
	if(led == 2) GPIOB->ODR|=0x00000004;  // liga o pino 2;
	if(led == 3) GPIOB->ODR|=0x00000008;  // liga o pino 3;
	if(led == 4) GPIOB->ODR|=0x00000020;  // liga o pino 5;
	if(led == 5) GPIOB->ODR|=0x00001000;  // liga o pino 12;
	if(led == 6) GPIOB->ODR|=0x00002000;  // liga o pino 13;
	if(led == 7) GPIOB->ODR|=0x00004000;  // liga o pino 14;
}

void dl(int led){
	if(led == 1) GPIOB->ODR&=~0x00000002;  // desliga o pino 1;
	if(led == 2) GPIOB->ODR&=~0x00000004;  // desliga o pino 2;
	if(led == 3) GPIOB->ODR&=~0x00000008;  // desliga o pino 3;
	if(led == 4) GPIOB->ODR&=~0x00000020;  // desliga o pino 5;
	if(led == 5) GPIOB->ODR&=~0x00001000;  // desliga o pino 12;
	if(led == 6) GPIOB->ODR&=~0x00002000;  // desliga o pino 13;
	if(led == 7) GPIOB->ODR&=~0x00004000;  // desliga o pino 14;
}

void pf(float freq){ // pisca freq
	float periodo = 1/freq;
	periodo *= 1000000000; // passando pra nano seg
	periodo /= LOOPARM; // passando pra loops do arm (?)
	periodo /= 3; // (ida e volta);
	int tot = 0, i = 0;

	while(tot < TEMPO){

		l(1);
		while(i < periodo){tot++; i++;}
		i = 0;

		dl(1);
		while(i < periodo){tot++; i++;}
		i = 0;
	}

}

void d1(){
	int tot = 0, i = 0;
	while(tot < TEMPO){

		l(2);
		while(i < 1000){tot++; i++;}
		i = 0;

		dl(2);
		while(i < 1000){tot++; i++;}
		i = 0;
	}
}

void d2(){
	int tot = 0, i = 0;
	while(tot < TEMPO/2){

		l(2);
		while(i < 1000){tot++; i++;}
		i = 0;

		dl(2);
		while(i < 1000){tot++; i++;}
		i = 0;
	}
}

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // habilita o clock de todas as GPIOs
  GPIOA->MODER=0x28000000;  // inicializa o modo debugger para a interface do ARM
  GPIOB->MODER=0x55000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 e B15 com a função de saída
  GPIOC->MODER=0x00000000;  // configura os pinos C como entrada

  GPIOB->ODR=0; // reset

  while(1){

	  pf(teclaE5);
	  d1();
	  pf(teclaB4);
	  pf(teclaC5);
	  pf(teclaD5);
	  d1();
	  pf(teclaC5);
	  pf(teclaB4);
	  pf(teclaA4);
	  d1();
	  pf(teclaA4);
	  pf(teclaC5);
	  pf(teclaE5);
	  d1();
	  pf(teclaD5);
	  pf(teclaC5);
	  pf(teclaB4);
	  d1();
	  pf(teclaB4);
	  pf(teclaC5);
	  pf(teclaD5);
	  d1();
	  pf(teclaE5);
	  d1();
	  pf(teclaC5);
	  d1();
	  pf(teclaA4);
	  d1();
	  pf(teclaA4);
	  d1(); d1(); d1();
	  pf(teclaD5);
	  d1();
	  pf(teclaF5);
	  d1();
	  pf(teclaA5);
	  d1();
	  pf(teclaG5);
	  pf(teclaF5);
	  pf(teclaE5);
	  d1(); d1(); d1();
	  pf(teclaC5);
	  pf(teclaE5);
	  d1();
	  pf(teclaD5);
	  pf(teclaC5);
	  pf(teclaB4);
	  d1();
	  pf(teclaB4); // 0:22
	  pf(teclaC5);
	  d1();
	  pf(teclaD5);
	  d1();
	  pf(teclaE5);
	  d1();
	  pf(teclaC5);
	  d1();
	  pf(teclaA4);
	  d1();
	  pf(teclaA4);
	  d1(); d1(); d1();

	  pf(teclaE5);
	  d1();
	  pf(teclaB4);
	  pf(teclaC5);
	  pf(teclaD5);
	  d1();
	  pf(teclaC5);
	  pf(teclaB4);
	  pf(teclaA4);
	  d1();
	  pf(teclaA4);
	  pf(teclaC5);
	  pf(teclaE5);
	  d1();
	  pf(teclaD5);
	  pf(teclaC5);
	  pf(teclaB4);
	  d1();
	  pf(teclaB4);
	  pf(teclaC5);
	  pf(teclaD5);
	  d1();
	  pf(teclaE5);
	  d1();
	  pf(teclaC5);
	  d1();
	  pf(teclaA4);
	  d1();
	  pf(teclaA4);
	  d1(); d1(); d1();
	  pf(teclaD5);
	  d1();
	  pf(teclaF5);
	  d1();
	  pf(teclaA5);
	  d1();
	  pf(teclaG5);
	  pf(teclaF5);
	  pf(teclaE5);
	  d1(); d1(); d1();
	  pf(teclaC5);
	  pf(teclaE5);
	  d1();
	  pf(teclaD5);
	  pf(teclaC5);
	  pf(teclaB4);
	  d1();
	  pf(teclaB4); // 0:40







	  d1();d1();d1();d1();d1();d1();

  }
}
