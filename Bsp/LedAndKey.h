#ifndef LED_AND_KEY
#define LED_AND_KEY

#define KEY_ON	0
#define KEY_OFF	1

#define digitalToggle(p,i)		{p->ODR ^=i;}			//Êä³ö·´×ª×´Ì¬
#define LED_TOGGLE		digitalToggle(GPIOA,GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_4);


void Led_Configuration(void);
void Key_Configuration(void);
int Key_Scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);






#endif
