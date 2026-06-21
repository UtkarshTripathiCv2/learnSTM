// Initialize PWM on Timer 2, Channel 1 before the while loop
HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

// Inside main while(1) loop
while (1)
{
  // Increase brightness
  for(int duty = 0; duty < 1000; duty += 10)
  {
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
      HAL_Delay(10);
  }
  
  // Decrease brightness
  for(int duty = 1000; duty > 0; duty -= 10)
  {
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
      HAL_Delay(10);
  }
}
