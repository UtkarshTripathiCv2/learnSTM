// Variables
char msg[] = "Hello from STM32!\r\n";

// Inside main while(1) loop
while (1)
{
  // Transmit data via UART2, timeout of 100ms
  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
  
  HAL_Delay(1000);
}
