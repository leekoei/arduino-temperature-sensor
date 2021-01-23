/**
 * Wi-Fi Temperature Sensor
 * 
 * This Arduino script makes an Arduino MKR1000 board into a 
 * Wi-Fi temperature sensor with a TMP36GT9Z temperature
 * sensor.
 * 
 * All rights reserved.
 * 
 * Ron Li
 * 2021.01
 *                           ____
 *                          /    \__
 * |\                      /    @   \
 * \ \____________________|    \  .:|>
 *  \      ##             |    | \__/
 *   |    ####             \__/   \
 *   /  /  ##                    \|
 *  /  /_______________________\  \
 *  L_JJ                        \__JJ
 * 
 */

#include <LiquidCrystal.h>

/** 
 * Initialize the LCD display library by associating any needed 
 * LCD interface pin with the arduino pin it is connected to 
 */
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* Use A0 as temperature sensor input pin */
int tempPin = A0;

int tempValInt = 0;
float tempValFloatC = 0.0;
float tempValFloatF = 0.0;  
float tempValVol = 0.0; 

void setup() {
  /* Set temperature sensor ADC resolution */
  analogReadResolution(10); 
  /* set up the LCD's number of columns and rows: */
  lcd.begin(16, 2);
  /* Print a message to the LCD */
  lcd.print("Temperature:");
}

void loop() { 
  /* Read raw temperature value */ 
  tempValInt = analogRead(tempPin); 
  /* Raw temperature sensor reading in mV */
  tempValVol = tempValInt * (3300/1024);

  tempValFloatC = (tempValVol - 500 ) / 10; 
  tempValFloatF = 32.0 + tempValFloatC * 1.8;

  /* Set the cursor to column 0, line 1 */
  lcd.setCursor(0, 1);
  /* Print the temperature */
  lcd.print(String(tempValFloatC) + "/C" + "  " + String(tempValFloatF) + "/F");
  
  delay(500); 
} 
