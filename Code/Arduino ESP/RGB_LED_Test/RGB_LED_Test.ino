/*
  Dave Williams, DitroniX 2019-2025 (ditronix.net)

  Example Code, to demonstrate and test the ESPuno Pi Zero, RGB LED Test on GPIO18.   

  Further information, details and examples can be found on our website and also GitHub wiki pages:
  * ditronix.net
  * github.com/DitroniX
  * github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero
  * github.com/DitroniX/PGEZ-PCA9671-GPIO-Expander-Zero/wiki
  * hackster.io/DitroniX/pgez-pca9671-gpio-expander-zero-28e669

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  Further information, details and examples can be found on our github.com/DitroniX
*/

// Libraries
#include <Adafruit_NeoPixel.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Hardware Serial 0 GPIO Pins
#define RXD0 17
#define TXD0 16

// RGB
#define PIN_WS2812B 15  // The ESP32-C6 pin GPIO15 connected to Pi Header GPIO18 (Pin 12)
#define NUM_PIXELS 1   // The number of LEDs (pixels) on WS2812B LED strip

Adafruit_NeoPixel ws2812b(NUM_PIXELS, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1, RXD0, TXD0);  // U0
  while (!Serial)
    ;
  Serial.println("");

  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Set all pixel colors OFF

  Serial.println("ESPuno Pi Zero - Example Code");
}

// **************** LOOP ****************
void loop() {

  // Turn off all pixels for two seconds
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

    // turn on all pixels to RED at the same time for two seconds
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {         // for each pixel
    ws2812b.setPixelColor(pixel, ws2812b.Color(150, 0, 0));  // it only takes effect if pixels.show() is called
  }
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

    // Turn off all pixels for two seconds
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

  // turn on all pixels to BLUE at the same time for two seconds
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {         // for each pixel
    ws2812b.setPixelColor(pixel, ws2812b.Color(0, 0, 150));  // it only takes effect if pixels.show() is called
  }
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

    // Turn off all pixels for two seconds
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

  // turn pixels to GREEN one-by-one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {         // for each pixel
    ws2812b.setPixelColor(pixel, ws2812b.Color(0, 150, 0));  // it only takes effect if pixels.show() is called
  }
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);      // 500ms pause between each pixel
}
//