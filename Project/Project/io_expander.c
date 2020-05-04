#include "io_expander.h"
static 
i2c_status_t io_expander_wait_for_write( int32_t  i2c_base)
{
  
  i2c_status_t status;
  
  if( !i2cVerifyBaseAddr(i2c_base) )
  {
    return  I2C_INVALID_BASE;
  }

  // Set the I2C address to be the EEPROM and in Write Mode
  status = i2cSetSlaveAddr(i2c_base, MCP23017_DEV_ID, I2C_WRITE);

  // Poll while the device is busy.  The  MCP24LC32AT will not ACK
  // writing an address while the write has not finished.
  do 
  {
    // The data we send does not matter.  This has been set to 0x00, but could
    // be set to anything
    status = i2cSendByte( i2c_base, 0x00, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    
    // Wait for the address to finish transmitting
    while ( I2CMasterBusy(i2c_base)) {};
    
    // If the address was not ACKed, try again.
  } while (I2CMasterAdrAck(i2c_base) == false);

  return  status;
}

//This code was modeled off of eeprom.c
bool io_expander_init(void){
	//gpio_enable_port(IO_EXPANDER_GPIO_BASE);
  // Configure SCL 
  //gpio_config_digital_enable(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PIN); 
  //gpio_config_alternate_function(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PIN);
  //gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PCTL_M, IO_EXPANDER_I2C_SCL_PIN_PCTL);
  // Configure SDA 
  //gpio_config_digital_enable(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN);
  //gpio_config_open_drain(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN); 
  //gpio_config_alternate_function(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN); 
  //gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PCTL_M, IO_EXPANDER_I2C_SDA_PIN_PCTL);
  //  Initialize the I2C peripheral
  //if(initializeI2CMaster(IO_EXPANDER_I2C_BASE)!= I2C_OK)
    //return false;
	gpio_enable_port(IO_EXPANDER_IRQ_GPIO_BASE);
	gpio_config_digital_enable(IO_EXPANDER_IRQ_GPIO_BASE, IO_EXPANDER_IRQ_PIN_NUM);
	gpio_config_enable_pullup(IO_EXPANDER_IRQ_GPIO_BASE,IO_EXPANDER_IRQ_PIN_NUM);
	gpio_config_falling_edge_irq(IO_EXPANDER_IRQ_GPIO_BASE, IO_EXPANDER_IRQ_PIN_NUM);
	NVIC_EnableIRQ(GPIOF_IRQn);
	NVIC_SetPriority(GPIOF_IRQn, 0);
	// config io expander
  io_expander_write_reg(MCP23017_IODIRA_R , 0x00);
	
	// configure all 8 pins on port B to be inputs -- switches/push buttons
	io_expander_write_reg(MCP23017_IODIRB_R , 0xFF);
	
	// set up for correct input intrrupt generation -- doing this for all 8 pins
	io_expander_write_reg(MCP23017_GPINTENB_R, 0xF); //  enable interrupt on input change

  io_expander_write_reg(MCP23017_INTCONB_R , 0x0); // compare against previous pin value
	io_expander_write_reg(MCP23017_GPPUB_R, 0xFF); // set up pull up resistors
	
  return true;	
}

void io_expander_write_reg(uint8_t reg, uint8_t data){		
	while (I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {}
	i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE); // Change addr
	io_expander_wait_for_write(IO_EXPANDER_I2C_BASE);
  i2cSendByte(IO_EXPANDER_I2C_BASE, reg, I2C_MCS_START|I2C_MCS_RUN); // Send addr
  i2cSendByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_RUN|I2C_MCS_STOP); // Send data
}

uint8_t io_expander_read_reg(uint8_t input){
	uint8_t data;
	while (I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {}
	io_expander_wait_for_write(IO_EXPANDER_I2C_BASE);
	i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
	i2cSendByte(IO_EXPANDER_I2C_BASE, input, I2C_MCS_START|I2C_MCS_RUN);
	i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_READ);
	i2cGetByte(IO_EXPANDER_I2C_BASE, &data, I2C_MCS_RUN|I2C_MCS_START|I2C_MCS_STOP);
	return data;
}

