
typedef struct{
	uint32_t TIM2EN			:1;
	uint32_t TIM3EN			:1;
	uint32_t TIM4EN			:1;
	uint32_t TIM5EN			:1;
	uint32_t TIM6EN			:1;
	uint32_t TIM7EN			:1;
	uint32_t TIM12EN		:1;
	uint32_t TIM13EN		:1;
	uint32_t TIM14EN		:1;
	uint32_t Reserved1		:2;
	uint32_t WWDGEN			:1;
	uint32_t Reserved2		:2;
	uint32_t BKPSRAMEN		:1;
	uint32_t SPI2EN			:1;
	uint32_t SPI3EN			:1;
	uint32_t Reserved3		:1;
	uint32_t USART2EN		:1;
	uint32_t USART3EN		:1;
	uint32_t USART4EN		:1;
	uint32_t USART5EN		:1;
	uint32_t I2C1EN			:1;
	uint32_t I2C2EN			:1;
	uint32_t I2C3EN			:1;
	uint32_t Reserved4		:1;
	uint32_t CAN1EN			:1;
	uint32_t CAN2EN			:1;
	uint32_t Reserved5		:1;
	uint32_t PWREN			:1;
	uint32_t DACEN			:1;
	uint32_t UART7EN		:1;
	uint32_t UART8EN		:1;
}RCC_APB1ENR_t;

typedef struct{
	uint32_t GPIOAEN		:1;
	uint32_t GPIOBEN		:1;
	uint32_t GPIOCEN		:1;
	uint32_t GPIODEN		:1;
	uint32_t GPIOEEN		:1;
	uint32_t GPIOFEN		:1;
	uint32_t GPIOGEN		:1;
	uint32_t GPIOHEN		:1;
	uint32_t GPIOIEN		:1;
	uint32_t Reserved1		:3;
	uint32_t CRCEN			:1;
	uint32_t Reserved2		:5;
	uint32_t BKPSRAMEN		:1;
	uint32_t CCMDATARAMEN	:1;
	uint32_t DMA1EN			:1;
	uint32_t DMA2EN			:1;
	uint32_t Reserved3		:2;
	uint32_t ETHMACEN		:1;
	uint32_t ETHMACTXEN		:1;
	uint32_t ETHMACRXEN		:1;
	uint32_t ETHMACPTPEN	:1;
	uint32_t OTGHSEN		:1;
	uint32_t OTGHSULPIEN	:1;
	uint32_t Reserved4		:1;
}RCC_AHB1ENR_t;

typedef struct{
	uint16_t PE				:1;
	uint16_t SMBUS			:1;
	uint16_t Reserved1		:1;
	uint16_t SMBTYPE		:1;
	uint16_t ENARP			:1;
	uint16_t ENPEC			:1;
	uint16_t ENGC			:1;
	uint16_t NOSTRETCH		:1;
	uint16_t START			:1;
	uint16_t STOP			:1;
	uint16_t ACK			:1;
	uint16_t POS			:1;
	uint16_t PEC			:1;
	uint16_t ALERT			:1;
	uint16_t Reserved2		:1;
	uint16_t SWRST			:1;
}I2C_CR1_t;

typedef struct{
	uint16_t SB				:1;
	uint16_t ADDR			:1;
	uint16_t BTF			:1;
	uint16_t ADD10			:1;
	uint16_t STOPF			:1;
	uint16_t Reserved1		:1;
	uint16_t RxNE			:1;
	uint16_t TxE			:1;
	uint16_t BERR			:1;
	uint16_t ARLO			:1;
	uint16_t AF				:1;
	uint16_t OVR			:1;
	uint16_t PECERR			:1;
	uint16_t Reserved2		:1;
	uint16_t TIMEOUT		:1;
	uint16_t SMBALERT		:1;
}I2C_SR1_t, I2C_SR2_t;

typedef struct{
	uint16_t FREQ			:5;
	uint16_t Reserved1		:2;
	uint16_t ITERREN		:1;
	uint16_t ITEVTEN		:1;
	uint16_t ITBUFEN		:1;
	uint16_t DMAEN			:1;
	uint16_t LAST			:1;
	uint16_t Reserved2		:3;
}I2C_CR2_t;

typedef struct{
	uint16_t CCR			:12;
	uint16_t Reserved1		:2;
	uint16_t DUTY			:1;
	uint16_t FS				:1;
}I2C_CCR_t;

typedef struct{
	uint16_t TRISE			:6;
	uint16_t Reserved1		:10;
}I2C_TRISE_t;

typedef struct{
	uint16_t DR				:8;
	uint16_t Reserved1		:8;
}I2C_DR_t;

typedef struct{
	uint32_t Pin_0			:2;
	uint32_t Pin_1			:2;
	uint32_t Pin_2			:2;
	uint32_t Pin_3			:2;
	uint32_t Pin_4			:2;
	uint32_t Pin_5			:2;
	uint32_t Pin_6			:2;
	uint32_t Pin_7			:2;
	uint32_t Pin_8			:2;
	uint32_t Pin_9			:2;
	uint32_t Pin_10			:2;
	uint32_t Pin_11			:2;
	uint32_t Pin_12			:2;
	uint32_t Pin_13			:2;
	uint32_t Pin_14			:2;
	uint32_t Pin_15			:2;
	uint32_t Pin_16			:2;
}GPIOx_MODER_t,GPIOx_OSPEEDR_t,GPIOx_PUPDR_t;

typedef struct{
	uint32_t Pin_0			:1;
	uint32_t Pin_1			:1;
	uint32_t Pin_2			:1;
	uint32_t Pin_3			:1;
	uint32_t Pin_4			:1;
	uint32_t Pin_5			:1;
	uint32_t Pin_6			:1;
	uint32_t Pin_7			:1;
	uint32_t Pin_8			:1;
	uint32_t Pin_9			:1;
	uint32_t Pin_10			:1;
	uint32_t Pin_11			:1;
	uint32_t Pin_12			:1;
	uint32_t Pin_13			:1;
	uint32_t Pin_14			:1;
	uint32_t Pin_15			:1;
	uint32_t Reserved		:16;
}GPIOx_OTYPER_t;

typedef struct{
	uint32_t AF_0_8			:4;
	uint32_t AF_1_9			:4;
	uint32_t AF_2_10		:4;
	uint32_t AF_3_12		:4;
	uint32_t AF_4_13		:4;
	uint32_t AF_5_14		:4;
	uint32_t AF_6_15		:4;
	uint32_t AF_7_16		:4;
}GPIOx_AFRL_t,GPIOx_AFRH_t;
