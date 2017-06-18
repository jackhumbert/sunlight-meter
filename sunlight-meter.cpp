#include <stdint.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "Framebuffer.h"
extern "C" {
	#include "analog.h"
}
const uint8_t image[] PROGMEM = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0x07,0x01,0xc1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xf9,0xd6,0xbe,0xdb,0xad,0xdb,0xb9,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xf6,0xaa,0xbd,0x55,0x55,0x55,0x57,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xf6,0xaa,0x7d,0xd7,0x55,0x51,0x73,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xf6,0xaa,0xbc,0xd7,0x55,0x55,0x77,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xf5,0xaa,0xbd,0xd7,0x55,0x55,0x77,0xff,0xff,0xff,0xff,0xff
,0xff,0xc7,0xc7,0xc7,0xfa,0xba,0xbd,0xd7,0x76,0xb5,0x79,0xff,0xff,0xff,0xff,0xff
,0xff,0xe7,0xc7,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xe3,0xc7,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xf1,0xc7,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xfc,0x00,0x7f,0xfb,0xba,0xeb,0x5b,0x6d,0x7c,0xad,0xdd,0xdd,0xc9,0xff,0xff
,0xff,0xff,0xc7,0xff,0xf5,0x55,0x55,0x55,0x45,0x7b,0xaa,0xaa,0xa8,0xba,0xff,0xff
,0xff,0xff,0xc7,0xff,0xf7,0x55,0x55,0x55,0x6d,0x4d,0xaa,0xaa,0xbd,0x9a,0xff,0xff
,0xff,0xff,0xc7,0xff,0xf7,0x55,0x55,0x55,0x6d,0x7e,0xa9,0x9a,0xbd,0xba,0xff,0xff
,0xff,0xff,0xc7,0xff,0xf5,0x55,0x55,0x55,0x6d,0x7e,0xab,0xba,0xbd,0xba,0xff,0xff
,0xff,0xff,0xc7,0xff,0xfb,0xb7,0x5d,0xb5,0x76,0xf9,0xdb,0xbd,0xbe,0xc9,0xff,0xff
,0xff,0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0x01,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff

};

// void adc_init()
// {
//     // AREF = AVcc
//     ADMUX = (1<<REFS0) | (0<<REFS1);
 
//     // ADC Enable and prescaler of 128
//     // 16000000/128 = 125000
//     ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
// }

// uint16_t adc_read(uint8_t ch)
// {
//   // select the corresponding channel 0~7
//   // ANDing with ’7′ will always keep the value
//   // of ‘ch’ between 0 and 7
//   ch &= 0b00000111;  // AND operation with 7
//   ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
 
//   // start single convertion
//   // write ’1′ to ADSC
//   ADCSRA |= (1<<ADSC);
 
//   // wait for conversion to complete
//   // ADSC becomes ’0′ again
//   // till then, run loop continuously
//   while(ADCSRA & (1<<ADSC));
 
//   return (ADC);
// }

// int16_t adc_read(uint8_t mux)
// {
//     uint8_t low;

//     ADCSRA = (1<<ADEN) | ADC_PRESCALER;             // enable ADC
//     ADCSRB = (1<<ADHSM) | (mux & 0x20);             // high speed mode
//     ADMUX = aref | (mux & 0x1F);                    // configure mux input
//     ADCSRA = (1<<ADEN) | ADC_PRESCALER | (1<<ADSC); // start the conversion
//     while (ADCSRA & (1<<ADSC)) ;                    // wait for result
//     low = ADCL;                                     // must read LSB first
//     return (ADCH << 8) | low;                       // must read MSB only once!
// }


int main(void) {

	DDRD |= (1<<6);
	PORTD |= (1<<6);

    Framebuffer fb;
    // adc_init();

    fb.drawBitmap(image,64,128,0,0);
    fb.show();

    uint16_t x = 0;
	char s [5];

    while (true) {
    	fb.clear();
    	x = analogRead(3);
	    fb.drawRectangle(x/8-4, 0, x/8, 31, 1);
	    fb.drawString("Sunlight", 0, 0);
	    itoa(x, s, 10);
	    fb.drawString(s, 6*9, 0);
	    fb.show();
	}
    return 0;
}