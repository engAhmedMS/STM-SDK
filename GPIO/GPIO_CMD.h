#ifndef GPIO_CMD
#define GPIO_CMD

/***************************************** GPIO INPUT CONFIGS ******************************************/
#define GPIO_IN_ANALOG      0b00
#define GPIO_IN_FLOAT       0b01
#define GPIO_IN_PULLUP      0b110
#define GPIO_IN_PULLDOWN	0b010
/**************************************** GPIO OUTPUT CONFIGS ******************************************/
#define GPIO_OUT_PUSH_PULL  0b00
#define GPIO_OUT_OPEN_DRAIN 0b01
#define GPIO_ALF_PUSH_PULL  0b10
#define GPIO_ALF_OPEN_DRAIN 0b11

/********************************************* GPIO MODES **********************************************/
#define GPIO_IN             0b00
#define GPIO_OUT_S_10MHZ    0b01
#define GPIO_OUT_S_2MHZ     0b10
#define GPIO_OUT_S_50MHZ    0b11

#endif
