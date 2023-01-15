

 HAL_StatusTypeDef I2C_DataRead(I2C_HandleTypeDef* hi2c, uint8_t slave_address, uint8_t mem_address, uint8_t *val, uint8_t byte){

	    HAL_StatusTypeDef ret; // ret will give HAL_OK or HALL_ERROR if i2c fails

	    ret = HAL_I2C_Mem_Write(hi2c, slave_address, 0, 0, val, 1, 50);
		if(ret != HAL_OK)
			return ret;

		HAL_Delay(500);

		ret = HAL_I2C_Mem_Read(hi2c, (slave_address|0x01), mem_address, 1, val, byte, 50);
		if(ret != HAL_OK)
			return ret;

		return HAL_OK;
  }

  void visualiser(uint32_t val, uint16_t level[5], GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin1, uint16_t GPIO_Pin2, uint16_t GPIO_Pin3, uint16_t GPIO_Pin4, uint16_t GPIO_Pin5 ){
	    // reset LEDS
	    HAL_GPIO_WritePin(GPIOx,GPIO_Pin1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOx,GPIO_Pin2,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOx,GPIO_Pin3,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOx,GPIO_Pin4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOx,GPIO_Pin5,GPIO_PIN_RESET);

		// Turn LEDs on up to highest level
		if(val>level[0]){
			HAL_GPIO_WritePin(GPIOx,GPIO_Pin1,GPIO_PIN_SET);
			if(val>level[1]){
				HAL_GPIO_WritePin(GPIOx,GPIO_Pin2,GPIO_PIN_SET);
				if(val>level[2]){
					HAL_GPIO_WritePin(GPIOx,GPIO_Pin3,GPIO_PIN_SET);
					if(val>level[3]){
						HAL_GPIO_WritePin(GPIOx,GPIO_Pin4,GPIO_PIN_SET);
						if(val>level[4]){
							HAL_GPIO_WritePin(GPIOx,GPIO_Pin5,GPIO_PIN_SET);
						}
					}
				}
			}
		}
  }
