// Inside the main while(1) loop
while (1)
{
  // Toggle the pin state (e.g., Port A, Pin 5)
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

  // Wait for 1000 milliseconds (1 second)
  HAL_Delay(1000); 
}
