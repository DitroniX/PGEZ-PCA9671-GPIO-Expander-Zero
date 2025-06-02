/*
  Dave Williams, DitroniX 2019-2025 (ditronix.net)

  Example Code, to demonstrate and test the ESPuno Pi Zero, PCA9671 Cycle GPIO Test

  Example Code Note: 
  As the ESPuno Pi Zero also has a PCA9671 on default address 0x20, ensure you set the PGEZ I2C address away from the 0x20.  Then update the below PCA_Address.
  See Wiki: https://github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero/wiki/PCA9671-I2C-Addresses

  Remember to set the VCC Voltage.  See Wiki https://github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero/wiki/PGEZ-GPIO-Voltage-Select

  Further information, details and examples can be found on our website and also GitHub wiki pages:
  * ditronix.net
  * github.com/DitroniX
  * github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero
  * github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero/wiki
  * hackster.io/DitroniX/pgez-pca9671-gpio-expander-zero-28e669

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  For board configuration, see https://github.com/DitroniX/ESPuno-Pi-Zero_WiFi-BT-Zigbee-Thread-60V/wiki/Arduino-IDE

  Further information, details and examples can be found on our website pages ditronix.net and also github.com/DitroniX
*/

// Libraries
#include "PCA9671.h"  // https://github.com/RobTillaart/PCA9671

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

#define PCA_Address 0x10  // Default I2C address 0x20 with no switches or solder pads set

PCA9671 PCA(PCA_Address);

// Define I2C (Expansion Port)
#define I2C_SDA 6
#define I2C_SCL 7

// **************** FUNCTIONS AND ROUTINES ****************

// Force Raw Software Reset
void Force_Raw_Reset() {
  Wire.beginTransmission(PCA_Address);
  Wire.write(0x00);
  Wire.write(0x06);
  Wire.endTransmission();
}

// Set PCA GPIO Output
void PCAGPIO(uint8_t GPIO_Output, boolean GPIO_State = LOW) {
  PCA.write(GPIO_Output, GPIO_State);
}


// **************** SETUP ****************
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial)
    ;
  Serial.println("");

  Serial.println(__FILE__);
  Serial.print("PCA9671_LIB_VERSION:\t");
  Serial.println(PCA9671_LIB_VERSION);
  Serial.println();

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("ESPuno Pi Zero Configured...");

  PCA.begin();

  // Optional Setting as an example
  Force_Raw_Reset();

  delay(1000);
}

// **************** LOOP ****************
void loop() {

  PCAGPIO(0, LOW);
  delay(1000);

  PCAGPIO(0, HIGH);
  delay(1000);

  PCAGPIO(1, LOW);
  delay(1000);

  PCAGPIO(1, HIGH);
  delay(1000);
}