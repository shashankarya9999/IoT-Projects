// code reads the soil moisture level from analog pin and controls three output pins based on whether soil is dry or moist

#define SOILMOISTURELEVEL = 500;

// intialize soilsensor value
int soilsensor = 0;

// setup functions
void setup()
{
  // sets the A0 pin as an input to read the analog signal from the soil moisture sensor 
  pinMode(A0, INPUT);  
  // initializes serial communication at a baud rate of 9600, allowing data to be sent to the serial monitor
  Serial.begin(9600);
  // sets pin 5 as an output
  pinMode(5, OUTPUT);
  // sets pin 11 as an output
  pinMode(11, OUTPUT);
  // sets pin 12 as an output
  pinMode(12, OUTPUT);
}

// loop function
void loop()
{
  // reads the analog value from the soil moisture sensor connected to pin A0. This value will range from 0 to 1023, depending on the moisture level
  soilsensor = analogRead(A0);
  // prints the soil sensor value to the serial monitor for debugging or monitoring
  Serial.println(soilsensor);

  // checks if the soil moisture level is below or equal to SOILMOISTURELEVEL(a threshold value that you might need to adjust based on your sensor and soil conditions)
  if (soilsensor <= SOILMOISTURELEVEL)  // relatively dry soil
  {
    digitalWrite(5, HIGH);  // turns on device connected to pin 5
    digitalWrite(11, HIGH);  // turns on device connected to pin 11
    digitalWrite(12, LOW);  // turns off device connected to pin 12
  }
  else  // sufficiently moist soil
  {
    digitalWrite(5, LOW);  // turns off device connected to pin 5
    digitalWrite(11, LOW);  // turns off device connected to pin 11
    digitalWrite(12, HIGH);  // turns on device connected to pin 12
  }
  delay(10); // adds a small delay (10 milliseconds) to reduce the frequency of sensor readings and improve performance.
}
