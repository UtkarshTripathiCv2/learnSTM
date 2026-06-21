// 1. Variables to keep track of time
unsigned long previousTime = 0;   // Stores the last time the LED was updated
const long interval = 1000;       // Interval at which to blink (milliseconds)

// 2. Variable for the LED state
int ledState = LOW;             

void setup() {
  pinMode(13, OUTPUT); // Built-in LED on Arduino Uno
}

void loop() {
  // 3. Read the "stopwatch" (current time)
  unsigned long currentTime = millis();

  // 4. Check if 1000ms have passed since the last update
  if (currentTime - previousTime >= interval) {
    
    // Save the last time you blinked the LED 
    previousTime = currentTime;   

    // Toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // Apply the new state to the pin
    digitalWrite(13, ledState);
  }

  // ---> YOU CAN PUT OTHER CODE HERE <---
  // The processor is never paused. It flies through this loop 
  // thousands of times a second!
}
