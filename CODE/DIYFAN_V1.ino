const byte OC1A_PIN = 9;  // Pin for PWM output (D9)
const byte BUTTON_PIN = 2; // Button connected to pin D2
const byte RED_PIN = 5;    // Red channel of the RGB LED (D3)
const byte GREEN_PIN = 6;  // Green channel of the RGB LED (D5)
const byte BLUE_PIN = 3;   // Blue channel of the RGB LED (D6)

const word PWM_FREQ_HZ = 25000; // PWM frequency
const word TCNT1_TOP = 16000000 / (2 * PWM_FREQ_HZ); // Timer value calculation

// The three PWM levels (33%, 66%, 100%)
const byte PWM_STAGES[3] = {33, 66, 100};
byte currentStage = 0; // Start with level 1 (index 0, i.e. 33%)

void setup() {
  pinMode(OC1A_PIN, OUTPUT); // Set pin D9 as output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up resistor on pin D2

  pinMode(RED_PIN, OUTPUT);   // Set pin D5 as output for red
  pinMode(GREEN_PIN, OUTPUT); // Set pin D6 as output for green
  pinMode(BLUE_PIN, OUTPUT);  // Set pin D3 as output for blue

  // Initialize Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // Configure Timer1 (Phase Correct PWM)
  TCCR1A |= (1 << COM1A1) | (1 << WGM11);  // Clear on compare match, Phase correct PWM
  TCCR1B |= (1 << WGM13) | (1 << CS10);    // Phase correct PWM, no prescaler
  ICR1 = TCNT1_TOP;  // Set top value for timer

  // Set PWM to the first level (33%)
  setPwmDuty(PWM_STAGES[currentStage]);
  // Set RGB LED to initial value (pulsing white)
  setRgbColor(currentStage);
}

void loop() {
  // Check if the button was pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(BUTTON_PIN) == LOW) { // Confirm button press
      // Select next PWM level
      currentStage = (currentStage + 1) % 3; // Cycle through levels
      setPwmDuty(PWM_STAGES[currentStage]);
      setRgbColor(currentStage);  // Adjust RGB LED to new level
    }
  }
}

// Function to set PWM duty cycle
void setPwmDuty(byte duty) {
  OCR1A = (word)(duty * TCNT1_TOP) / 100; // Set OCR1A for corresponding PWM duty
}

// Function to set RGB LED color based on PWM stage
void setRgbColor(byte stage) {
  switch (stage) {
    case 0: // Stage 1
      pulseRgb(0, 0, 255); // Blue
      break;
    case 1: // Stage 2
      pulseRgb(0, 255, 0); // Green
      break;
    case 2: // Stage 3 
      pulseRgb(0, 255, 255); // cyan
      break;
  }
}

// Function to pulse the RGB LED
void pulseRgb(byte red, byte green, byte blue) {
  for (int i = 0; i < 255; i++) {  // PWM value from 0 to 255
    analogWrite(RED_PIN, red * i / 255);   // Pulse red light
    analogWrite(GREEN_PIN, green * i / 255); // Pulse green light
    analogWrite(BLUE_PIN, blue * i / 255);  // Pulse blue light
    delay(10); // Short delay for pulsing
  }
  for (int i = 255; i > 30; i--) {
    analogWrite(RED_PIN, red * i / 255);   // Pulse red light
    analogWrite(GREEN_PIN, green * i / 255); // Pulse green light
    analogWrite(BLUE_PIN, blue * i / 255);  // Pulse blue light
    delay(10); // Short delay for pulsing
  }
}
