void setup() {
  Serial.begin(115200);
  Serial.println("Enter Part Number:");
}

void loop() {
  if (Serial.available() > 0) {
    int a = Serial.parseInt();
    
    // Clear the remaining newline characters from the buffer
    while(Serial.available()) Serial.read();

    if (a != 0) { // Only process if a valid number was entered
      int b = 0;
      Serial.print("Fetching data for part: ");
      Serial.println(a);

      // Decision Logic
      if (a == 1) {
        Serial.println("Part Name: Motor Housing");
        Serial.println("Material: Mild Steel");
        b = 1;
      } else if (a == 2) {
        Serial.println("Part Name: Motor Shaft");
        Serial.println("Material: Mild Steel");
        Serial.println("No Proper Edges Found");
        b = 2;
      } else {
        Serial.println("Part Name: Electronic Board");
        Serial.println("Material: Plastic");
        Serial.println("No Proper Edges Found");
        b = 3;
      }

      // Action Logic
      if (b == 1) {
        Serial.println("The Suitable Gripping action: Mechanical");
      } else if (b == 2) {
        Serial.println("The Suitable Gripping action: Magnetic");
      } else {
        Serial.println("The Suitable Gripping action: Vacuum");
      }
      
      Serial.println("\n--------------------------");
      Serial.println("Enter next Part Number:");
    }
  }
}