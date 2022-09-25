#include "lcd_io.h"
SPI_HandleTypeDef* LCD_SPI;  

void LCD_IO_Init(void){
    
    LCD_CS_LOW();
    LCD_CS_HIGH();
}

void LCD_IO_WriteData(uint16_t RegValue)
{
  /* Set WRX to send data */
  LCD_WRX_HIGH();
  
  /* Reset LCD control line(/CS) and Send data */  
  LCD_CS_LOW();
  HAL_SPI_Transmit(LCD_SPI,(uint8_t *) &RegValue,1, 0x1000);
  
  /* Deselect: Chip Select high */
  LCD_CS_HIGH();

}
void LCD_IO_WriteReg(uint8_t Reg)
{
   /* Reset WRX to send command */
  LCD_WRX_LOW();
  
  /* Reset LCD control line(/CS) and Send command */
  LCD_CS_LOW();
  HAL_SPI_Transmit(LCD_SPI, &Reg,1, 0x1000);
  
  /* Deselect: Chip Select high */
  LCD_CS_HIGH();

}

uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
  uint32_t readvalue = 0;

  /* Select: Chip Select low */
  LCD_CS_LOW();

  /* Reset WRX to send command */
  LCD_WRX_LOW();
  
  HAL_SPI_Transmit(LCD_SPI,(uint8_t *) &RegValue,1, 0x1000);
  
  HAL_SPI_Receive(LCD_SPI, (uint8_t*) &readvalue, ReadSize,0x1000);

  /* Set WRX to send data */
  LCD_WRX_HIGH();

  /* Deselect: Chip Select high */
  LCD_CS_HIGH();
  
  return readvalue;
}

void LCD_Delay (uint32_t delay)
{
  HAL_Delay(delay);
}
     

