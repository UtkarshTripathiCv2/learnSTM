// Variable to store value
uint16_t rawValue;

// Inside main while(1) loop
while (1)
{
  // Start ADC Conversion
  HAL_ADC_Start(&hadc1);

  // Poll for conversion to complete (timeout 1ms)
  if (HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
  {
      // Get the converted value
      rawValue = HAL_ADC_GetValue(&hadc1);
  }
  
  // Stop ADC
  HAL_ADC_Stop(&hadc1);
  
  HAL_Delay(100);
}
