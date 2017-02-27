#include "stm8s.h"
#include "mystm8sxxx.h"
#include "text_lcd.h"



volatile uint32_t f_cpu=0;



void main(void)
{

	 clk_config_16MHz_hse();
	f_cpu=CLK_GetClockFreq();

	delay_using_timer4_init();

	//Config output for led
	GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4),GPIO_MODE_OUT_PP_HIGH_FAST);

	//Config output for text lcd
	GPIO_Init(GPIOG,(GPIO_Pin_TypeDef)(GPIO_PIN_0|GPIO_PIN_1),GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(GPIOA,(GPIO_Pin_TypeDef)(GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6),GPIO_MODE_OUT_PP_LOW_FAST);

	lcd_init();

	lcd_puts(0,0,(int8_t*)"STM8S207");
	lcd_puts(1,0,(int8_t*)"Xuan Thiep :)");
	lcd_puts(2,0,(int8_t*)"Hello World");
	lcd_puts(3,0,(int8_t*)"Have a nice day!");

	while (1)
	{
		GPIO_WriteReverse(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4));
		delay_ms(100);
	}

}






















#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8* file, u32 line)
{ 
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
