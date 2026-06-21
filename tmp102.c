/* ... (CubeMX Auto-Generated License and Header) ... */

#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

// 👇 YOU WRITE THIS 👇 (Needed for printf)
#include <stdio.h> 
// 👆 ---------------- 👆

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// 👇 YOU WRITE THIS 👇 (Sensor Addresses)
#define TMP102_ADDR (0x48 << 1) 
#define TMP102_TEMP_REG 0x00
// 👆 ---------------- 👆

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

// 👇 YOU WRITE THIS 👇 (Global Variable)
float currentTemperature = 0.0;
// 👆 ---------------- 👆

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// 👇 YOU WRITE THIS ENTIRE BLOCK 👇
/* --- MAGIC CODE FOR PRINTF --- */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE {
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

/* --- SENSOR READING FUNCTION --- */
void Read_Temperature(void) {
    uint8_t buffer[2]; 
    int16_t raw_temp;  

    if (HAL_I2C_Mem_Read(&hi2c1, TMP102_ADDR, TMP102_TEMP_REG, 1, buffer, 2, 100) == HAL_OK) {
        raw_temp = (buffer[0] << 4) | (buffer[1] >> 4);

        if (raw_temp > 0x7FF) {
            raw_temp |= 0xF000; 
        }

        currentTemperature = raw_temp * 0.0625;
    } else {
        printf("Error: Could not read sensor!\r\n");
    }
}
// 👆 --------------------------- 👆

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();
  SystemClock_Config();
  
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init(); 

  /* USER CODE BEGIN 2 */

  // 👇 YOU WRITE THIS 👇 (Startup Message)
  printf("Starting TMP102 Sensor...\r\n");
  // 👆 ---------------- 👆

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // 👇 YOU WRITE THIS 👇 (The Main Loop)
    Read_Temperature();
    printf("Temperature: %.2f C\r\n", currentTemperature);
    HAL_Delay(1000); 
    // 👆 ---------------- 👆

    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* ... (CubeMX Auto-Generated Error Handlers below) ... */
