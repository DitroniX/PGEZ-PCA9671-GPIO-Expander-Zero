/*
  Dave Williams, DitroniX 2019-2025 (ditronix.net)

  Example Code, to demonstrate and test the ESPuno Pi Zero, PCA9671 Shift States

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

  // PCA9671 Initialise
  PCA.begin();

  delay(1000);
}

// **************** LOOP ****************
void loop() {

  for (int i = 0; i < 255; i++) {
    PCA.write16(i);
    delay(50);
  }

  PCA.write(0, 1);
  for (int i = 0; i < 15; i++) {
    PCA.shiftLeft();
    delay(50);
  }

  delay(1000);

  for (int i = 0; i < 15; i++) {
    PCA.shiftRight();
    delay(50);
  }

  delay(1000);

  for (int i = 0; i < 16; i++) {
    PCA.write(i, 1);
    delay(50);
  }

  delay(1000);

  for (int i = 0; i < 16; i++) {
    PCA.write(i, 0);
    delay(250);
  }

  delay(1000);

  for (int i = 0; i < 16; i++) {
    PCA.toggle(i);
    delay(250);
    PCA.toggle(i);
    delay(250);
  }

  delay(2000);
}