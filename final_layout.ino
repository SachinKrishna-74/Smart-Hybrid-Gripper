#include <Servo.h>

Servo servo1;
Servo servo2;

const int relayMagPin = D5;  // Electromagnet relay
const int relayVacPin = D6;  // Vacuum motor relay

void setup() {
  Serial.begin(115200);
  
  servo1.attach(D1);
  servo2.attach(D2);
  
  
  
  
  // Initialize states
  digitalWrite(relayMagPin, LOW);
  digitalWrite(relayVacPin, LOW);
  servo1.write(0);
  servo2.write(0);

  Serial.println("System Ready. Enter Part Number:");
}

void loop() {
  if (Serial.available() > 0) {
    int a = Serial.parseInt();
    while(Serial.available()) Serial.read();

    if (a != 0) {
      int b = 0;
      
      // Decision Logic
      if (a == 1) { b = 1; } 
      else if (a == 2) { b = 2; } 
      else { b = 3; }

      // Action Logic
      if (b == 1) {
        Serial.println("Action: Mechanical (Moving Servos)");
        // Move servos to 120 degrees gradually
        for (int pos = 0; pos <= 120; pos++) {
          servo1.write(pos);
          servo2.write(pos);
          delay(20);
        }
        delay(1000);
        // Reset servos
        servo1.write(0);
        servo2.write(0);
        
      } else if (b == 2) {
        Serial.println("Action: Magnetic (Enabling Electromagnet)");
        Serial.println("Triggering Relay 1");
  digitalWrite(relayMagPin, LOW); pinMode(relayMagPin, OUTPUT);
  delay(5000);
  
  pinMode(relayMagPin, INPUT);
        
      } else {
        Serial.println("Action: Vacuum (Enabling Vacuum Motor)");
        Serial.println("Triggering Relay 1");
  digitalWrite(relayVacPin, LOW); pinMode(relayVacPin, OUTPUT);
  delay(5000);
  
  pinMode(relayVacPin, INPUT);
      }
      
      Serial.println("\nAction Complete. Enter next Part Number:");
    }
  }
}