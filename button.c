// Inside the main while(1) loop
while (1)
{
  // Check if button on PC13 is pressed (Assuming active LOW)
  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
  {
      // Turn ON LED (PA5)
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  }
  else
  {
      // Turn OFF LED (PA5)
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  }
}
