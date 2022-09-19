#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h> 

uint8_t PORT_A = 0x00;
int i=0;
void digitalWrite();
void blinkLED();

typedef enum {
    GPIO_PIN_0 = 1, 
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2,
    GPIO_PIN_3 = 1 << 3,
    GPIO_PIN_4 = 1 << 4,
    GPIO_PIN_5 = 1 << 5,
    GPIO_PIN_6 = 1 << 6,
    GPIO_PIN_7 = 1 << 7
}GPIO_PIN;

typedef enum{
    LOW = 0,
    HIGH
}STATUS;


void digitalWrite(GPIO_PIN PIN, STATUS STATE){
    if(STATE){
        PORT_A |= PIN;
    }else{
        PORT_A &= ~PIN;
    }
}

//Hàm thay đổi trang thai
void blinkLED(GPIO_PIN PIN ,int delaytime,int step )
// delaytime là khoảng thời gian muốn delay(second) , step là bước delay(miliseconds)
{
    while( i <= delaytime)
    
{
        digitalWrite( PIN, HIGH);
        printf("%d\n", PORT_A);
        usleep(1000*step);
        digitalWrite( PIN, LOW);
        printf("%d\n", PORT_A);
        i+= step/1000;
 }
 
    
}
int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_PIN_0, HIGH);
    printf("%d\n", PORT_A);
    digitalWrite(GPIO_PIN_2, HIGH);
    printf("%d\n", PORT_A);
    blinkLED(GPIO_PIN_3,2,1000);
    //printf("%d\n", PORT_A);

    return 0;
}
