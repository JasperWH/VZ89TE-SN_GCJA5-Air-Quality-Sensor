
#include <stdint.h>  // do i need this?
#include <string.h>  // do i need this?
#include <stdlib.h>
#include <stdio.h>


//#include "Registers.h"
#include "Header.h"





int main(void)
{
	// Initialise peripherals:
	setup();

	// Create Variables for SN_GCJA5 particle sensor:
	uint8_t SN_GCJA5_slave_address = 0x33 << 1; 		// 7 bit address left shifted to be 8 bit
	uint8_t SN_GCJA5_PM2_5[4] = {0}; 					// Array to store 2.5um particle count
	int32_t valPM2_5 = 0x00;							// Variable to store 2.5um particle count

	while (1){

		// Read registers for PM2.5
		Sensor_Read(SN_GCJA5_slave_address, 0x04, &SN_GCJA5_PM2_5[0]);
		Sensor_Read(SN_GCJA5_slave_address, 0x05, &SN_GCJA5_PM2_5[1]);
		Sensor_Read(SN_GCJA5_slave_address, 0x06, &SN_GCJA5_PM2_5[2]);
		Sensor_Read(SN_GCJA5_slave_address, 0x07, &SN_GCJA5_PM2_5[3]);

		// Combine the bytes
		valPM2_5 = (int32_t)SN_GCJA5_PM2_5[3] << 24 | (int32_t)SN_GCJA5_PM2_5[2] << 16 | (int32_t)SN_GCJA5_PM2_5[1] << 8 | (int32_t)SN_GCJA5_PM2_5[0];

		printf("pm25 = %ld \n", valPM2_5/1000);


	}
}
