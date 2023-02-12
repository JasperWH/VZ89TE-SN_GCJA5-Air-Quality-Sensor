#include "Registers.h"

//--------------------------------------------------
// Address Variable:
// create pointer variable of the struct and initialise to address (this is the first member)
// volatile data which the pointer is pointing to, const to guard pointer so coder doesn't change it
// RCC   = 0x4002 3800
// I2C1  = 0x4000 5400
// GPIOB = 0x4002 0400
//--------------------------------------------------
	// Enable I2C clock:    0x40023800 + 0x40 = 0x40023840 (see Memory Map for base address of RCC register & offset see RCC APB1 peripheral clock enable register)
	RCC_APB1ENR_t volatile  *const pClock_APB1ENR = (RCC_APB1ENR_t*)0x40023840;
	// Enable PGPIOB clock: 0x40023800 + 0x30 = 0x40023830 (see Memory Map for base address of RCC register & offset see RCC AHB1 peripheral clock register)
	RCC_AHB1ENR_t volatile  *const pClock_AHB1ENR = (RCC_AHB1ENR_t*)0x40023830;

	// Configure the GPIOB Pins for I2C: 0x40020400 + 0x00 = 0x40020400 (see Memory Map for base address of GPIOB register & offset see GPIO port mode register)
	GPIOx_MODER_t volatile *const pGPIO_MODER = (GPIOx_MODER_t*)0x40020400;

	// Select Open Drain Output: 0x40020400 + 0x04 = 0x40020404 (see Memory Map for base address of I2C1 register & offset see GPIO port output type register)
	GPIOx_OTYPER_t volatile *const pGPIO_OTYPER = (GPIOx_OTYPER_t*)0x40020404;

	// Select High SPEED for the PINs: 0x40020400 + 0x08 = 0x40020408 (see Memory Map for base address of GPIOB register & offset see GPIO port output speed register)
	GPIOx_OSPEEDR_t volatile *const pGPIO_OSPEEDR = (GPIOx_OSPEEDR_t*)0x40020408;

	// Configure the Alternate Function in AFR Low Register:  0x40020400 + 0x20 = 0x40020420 (see Memory Map for base address of GPIOB register & offset see GPIO alternate function low register)
	GPIOx_AFRL_t volatile *const pGPIO_AFRL = (GPIOx_AFRL_t*)0x40020420;
	// Configure the Alternate Function in AFR high Register: 0x40020400 + 0x24 = 0x40020424 (see Memory Map for base address of GPIOB register & offset see GPIO alternate function high register)
	GPIOx_AFRH_t volatile *const pGPIO_AFRH = (GPIOx_AFRH_t*)0x40020424;

	// Set pull up resistor for both pins:  0x40020400 + 0x0C = 0x4002040C (see Memory Map for base address of GPIOB register & offset see GPIO port pull-up/pull-down register)
	GPIOx_PUPDR_t volatile *const pGPIO_PUPDR = (GPIOx_PUPDR_t*)0x4002040C;

	// Reset the I2C: 0x40005400 + 0x00 = 0x40005400 (see Memory Map for base address of I2C register & offset see I2C Control Register 1)
	I2C_CR1_t volatile *const pI2C_CR1 = (I2C_CR1_t*)0x40005400;

	// Set the I2C clock speed: 0x40005400 + 0x04 = 0x40005404 (see Memory Map for base address of I2C register & offset see I2C Control register 2)
	I2C_CR2_t volatile *const pI2C_CR2 = (I2C_CR2_t*)0x40005404;

	// Set the I2C clock control: 0x40005400 + 0x1C = 0x4000541C (see Memory Map for base address of I2C register & offset see I2C Clock control register)
	I2C_CCR_t volatile *const pI2C_CCR = (I2C_CCR_t*)0x4000541C;

	// Set the I2C rise time: 0x40005400 + 0x20 = 0x40005420 (see Memory Map for base address of I2C register & offset see I2C TRISE register)
	I2C_TRISE_t volatile *const pI2C_TRISE = (I2C_TRISE_t*)0x40005420;

	// Access the I2C  Data register: 0x40005400 + 0x10 = 0x40005410 (see Memory Map for base address of I2C register & offset see I2C Data register)
	I2C_DR_t volatile *const pI2C_DR = (I2C_DR_t*)0x40005410;

	// Access the I2C Status register 1: 0x40005400 + 0x14 = 0x40005414 (see Memory Map for base address of I2C register & offset see I2C Status register 1)
	I2C_SR1_t volatile *const pI2C_SR1 = (I2C_SR1_t*)0x40005414;

	// Access the I2C Status register 2: 0x40005400 + 0x18 = 0x40005418 (see Memory Map for base address of I2C register & offset see I2C Status register 2)
	I2C_SR2_t volatile *const pI2C_SR2 = (I2C_SR2_t*)0x40005418;

//--------------------------------------------------
// I2C Functions:
//--------------------------------------------------

	// Start I2C:
	void I2C_Start(){
		pI2C_CR1->ACK   = 0x0001; 		// Enable the ACK
		pI2C_CR1->START = 0x0001; 		// Send the START condition
		while (!(pI2C_SR1->SB == 1));  	// Wait for the SB to set. This indicates that the start condition is generated
	}

	// Stop I2C:
	void I2C_Stop (){
		pI2C_CR1->STOP = 1;  			// Stop I2C
	}

	// Write to I2C:
	void I2C_Write(uint8_t data){
		while (!(pI2C_SR1->TxE == 1));  // Wait for the TXE to set. This indicates that the DR is empty

		pI2C_DR->DR = data;				// Send the DATA to the DR Register

		while (!(pI2C_SR1->BTF == 1));  // Wait for the BTF to set. This indicates the end of LAST DATA transmission
	}

	// Send Address:
	void I2C_Address(uint8_t Address){
		pI2C_DR->DR = Address; 			// Send the Address of the slave Device by copying it into the DR (Data Register)
		while(!(pI2C_SR1->ADDR == 1));  // Wait for the ADDR (Bit 1 in SR1) to set. This will indicate that the Address Transmission is finished

		I2C_SR1_t temp1 = *pI2C_SR1; 	// Clear the ADDR bit by performing a dummy read in Status Registers SR1 and SR2
		I2C_SR2_t temp2 = *pI2C_SR2;  	// Clear the ADDR bit by performing a dummy read in Status Registers SR1 and SR2
	}

	// Read I2C:
	void I2C_Read(uint8_t Address, uint8_t *buffer){

		pI2C_DR->DR = Address;  		// send the address
		while (!(pI2C_SR1->ADDR == 1)); // wait for ADDR bit to set

		pI2C_CR1->ACK = 0;  			// clear the ACK bit
		I2C_SR1_t temp1 = *pI2C_SR1; 	// read SR1 and SR2 to clear the ADDR bit
		I2C_SR2_t temp2 = *pI2C_SR2;  	// read SR1 and SR2 to clear the ADDR bit

		pI2C_CR1->STOP = 1;  			// Stop I2C

		while (!(pI2C_SR1->RxNE == 1));	// wait for RxNE to set

		buffer[0] = pI2C_DR->DR;		// Read the data from the DATA REGISTER

	}

	void Sensor_Read (uint8_t Address, uint8_t Reg, uint8_t *buffer){
		I2C_Start ();
		I2C_Address(Address);
		I2C_Write (Reg);
		I2C_Start ();
		I2C_Read ((Address|0x01), buffer);
		I2C_Stop ();
	}

//--------------------------------------------------
// Pin Configuration for I2C:
//--------------------------------------------------
	void setup(){
		// Enable the I2C and GPIO CLOCKS to activate peripherals:
		pClock_APB1ENR->I2C1EN  = 1;
	    pClock_AHB1ENR->GPIOBEN = 1;

	    // Configure the Pins for I2C:
		pGPIO_MODER->Pin_7   = 0x0002;  // PB7 = I2C_SDA set to Alternate functions mode 10 (2 in hex)
		pGPIO_MODER->Pin_8   = 0x0002;  // PB8 = I2C_SCL set to Alternate functions mode 10 (2 in hex)

		// Select Open Drain Output:
		pGPIO_OTYPER->Pin_7  = 0x0001;  // PB7 = I2C_SDA set to Output open-drain
		pGPIO_OTYPER->Pin_8  = 0x0001;  // PB8 = I2C_SCL set to Output open-drain

	    // Select High SPEED for the PINs:
		pGPIO_OSPEEDR->Pin_7 = 0x0003;  // PB7 = I2C_SDA set to High speed mode 11 (3 in hex)
		pGPIO_OSPEEDR->Pin_8 = 0x0003;  // PB8 = I2C_SCL set to High speed mode 11 (3 in hex)

		// Set pull up resistor for both pins:
		pGPIO_PUPDR->Pin_7   = 0x0001; // pull up for PIN PB7 01 (1 in hex)
		pGPIO_PUPDR->Pin_8   = 0x0001; // pull up for PIN PB8 01 (1 in hex)

	    // Configure the Alternate Function in AFR Low & High Register:
		pGPIO_AFRL->AF_7_16  = 0x0004;  // PB7 = I2C_SDA set to High speed mode 0100 (4 in hex)
		pGPIO_AFRH->AF_0_8   = 0x0004;  // PB8 = I2C_SCL set to High speed mode 0100 (4 in hex)

	    // Reset the I2C:
		pI2C_CR1->SWRST      = 0x0001;  // 1 to reset
		pI2C_CR1->SWRST      = 0x0000;  // 0 to take it out of reset

	    // Set the I2C clock speed:
		pI2C_CR2->FREQ       = 0x0010;  //  APB = HSI (High speed internal clock) = 16 MHz  (min 2Mhz / max APB frequency 42 MHz) -> TPCLK1 = 1/16 = 62.5ns

	    // Set the I2C clock control:
		pI2C_CCR->CCR        = 0x0050;  // If FREQR = 16, TPCLK1 = 62.5ns so CCR must be programmed with 0x50 (Thigh = CCR * TPCLK1  -> CCR = 5000ns/62.5ns = 80 = 0x50hex)

	    // Set the I2C rise time:
		pI2C_TRISE->TRISE    = 0x0011;  // 1000ns/62.5ns = 16, + 1 = 17

	    // Enable the I2C Peripheral:
		pI2C_CR1->PE         = 0x0001;  // Peripheral Enable bit
	}
