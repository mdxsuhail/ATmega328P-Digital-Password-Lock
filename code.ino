#include <Keypad.h>
#include <LiquidCrystal.h>

// Define the password
const char secretPassword[] = "1234"; 
char enteredPassword[5]; // FIXED: Now properly holds up to 4 characters + null terminator
int passwordIndex = 0;

// Hardware Pins matching your TQFP ATmega328P layout
const int ledPin = A2; // Pin 25 is PC2 (Analog Pin A2 in Arduino)

// LCD Configuration: RS=PB5 (D13), E=PB4 (D12), D4=PB0 (D8), D5=PB1 (D9), D6=PB2 (D10), D7=PB3 (D11)
LiquidCrystal lcd(13, 12, 8, 9, 10, 11);

// Keypad Configuration (4 Rows, 3 Columns)
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Row pins: PD2 (D2), PD3 (D3), PD4 (D4), PD5 (D5)
byte rowPins[ROWS] = {2, 3, 4, 5}; 
// Column pins: PD6 (D6), PD7 (D7), PC0 (A0)
byte colPins[COLS] = {6, 7, A0}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  lcd.begin(16, 2);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key == '#') { // Press '#' to enter
      checkPassword();
    } else if (key == '*') { // Press '*' to reset
      resetLock();
    } else if (passwordIndex < 4) {
      enteredPassword[passwordIndex++] = key;
      lcd.print('*'); // Hide password input with asterisks
    }
  }
}

void checkPassword() {
  enteredPassword[passwordIndex] = '\0'; // Null-terminate string
  lcd.clear();
  
  if (strcmp(enteredPassword, secretPassword) == 0) {
    lcd.print("Access Granted");
    digitalWrite(ledPin, HIGH); // Turn on LED-GREEN
  } else {
    lcd.print("Access Denied");
    digitalWrite(ledPin, LOW);
  }
  delay(3000);
  resetLock();
}

void resetLock() {
  passwordIndex = 0;
  digitalWrite(ledPin, LOW);
  lcd.clear();
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

