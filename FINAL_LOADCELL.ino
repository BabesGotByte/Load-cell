#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0);		

void setup() {
  Serial.begin(38400);
  Serial.println("HX711 Demo");

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());			// print a raw reading 

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(3));  	// print the average of 3 reading

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(2));		// print the average of 2 readings minus the tare weight (not set yet)

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);	// print the average of 5 readings from tare weight (not set) divided 
						// by the SCALE parameter (not set yet)  

  scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights
  scale.tare();				        // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                 // print a raw reading

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       // print the average of 20 readings

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));		// print the average of 5 readings minus the tare weight, set with tare()

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);        // print the average of 5 readings minus tare weight 
						

  Serial.println("Readings:");
}

void loop() {
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 1);

  scale.power_down();			        
  delay(5000);
  scale.power_up();
}
