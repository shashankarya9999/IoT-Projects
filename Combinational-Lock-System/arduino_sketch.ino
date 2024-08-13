const int button1 = 2; // first button is on pin 8
const int button2 = 3; // second button is on pin 9
const int button3 = 4; // third button is on pin 10
const int button4 = 5; // fourth button is on pin 11
const int button5 = 6; // third button is on pin 10
const int button6 = 7; // fourth button is on pin 11
const int LED[] = {14,15,16,17,18,19};
const int Red = 8; // red LED is on pin 4
const int greenLed = 9; // green LED is pin 12

// checkEntered1 function prototype 
void checkEntered1(int button);

int code[] = {6,5,5,4,3,2}; // the desired code is entered in this array(separated by commas)
int entered[7]; // create a new empty array for the code entered
// run once at sketch startup
void setup()
{ 
  Serial.begin(9600); // begin Serial
  pinMode(button1, INPUT_PULLUP); // button 1 is an input
  pinMode(button2, INPUT_PULLUP); // button 2 is an input
  pinMode(button3, INPUT_PULLUP); // button 3 is an input
  pinMode(button4, INPUT_PULLUP); // button 4 is an input
  pinMode(button5, INPUT_PULLUP); // button 3 is an input
  pinMode(button6, INPUT_PULLUP); // button 4 is an input
  pinMode(Red, OUTPUT); // the red LED is an output
  pinMode(greenLed, OUTPUT); // the green LED is an output
  setupLights(); // run the setupLights routine
  setupLights(); // run it again
  delay(650); // delay (only for effect, not needed)
  digitalWrite(Red, LOW); //turn the red LED on

  // work through numbers 0-3
  for (int i = 0; i < 6;i++)
  { 
    Serial.println(code[i]); //print each digit of the code
    Serial.println(entered[i]); //print each element of the entered[]
    //array(this was for me to check that it started at 0)
    pinMode(LED[i],OUTPUT);
  }
}

// run repeatedly
void loop()
{ 
  // if button1 is pressed
  if (digitalRead(button1) == LOW)
  { 
    checkEntered1(1); // call checkEntered and pass it a 1
    delay(250);// wait, needed for correct functioning, otherwise
    // buttons are deemed to be pressed more than once
  }
  // if button2 is pressed
  else if (digitalRead(button2) == LOW)
  { 
    checkEntered1(2); // call checkEntered1 and pass it a 2
    delay(250); // wait
  }
  // if button3 is pressed
  else if (digitalRead(button3) == LOW)
  { 
    checkEntered1(3); // call checkEntered1 and pass it a 3
    delay(250); // wait
  }
  // if button4 is pressed
  else if (digitalRead(button4) == LOW)
  { 
    checkEntered1(4); // call checkEntered1 and pass it a 4
    delay(250); // wait
  }
  // if button4 is pressed
  else if (digitalRead(button5) == LOW)
  { 
    checkEntered1(5); // call checkEntered1 and pass it a 4
    delay(250); // wait
  }
  // if button4 is pressed
  else if (digitalRead(button6) == LOW)
  { 
    checkEntered1(6); // call checkEntered1 and pass it a 4
    delay(250); // wait
  }
}

// check the first element of the entered[] array
void checkEntered1(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is not a zero, i.e. it has already been inputted
  if (entered[0] != 0)
  { 
    checkEntered2(button); // move on to checkEntered2, passing it "button"
  }
  // if it is zero, i.e. if it hasn't been defined with a button yet
  else if(entered[0] == 0)
  { 
  entered[0] = button; // set the first element as the button that has been pressed
  Serial.print("1: ");Serial.println(entered[0]); // for debugging
  }
}
// check the second element of the entered[] array
void checkEntered2(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is not a zero, i.e. it has already been inputted
  if (entered[1] != 0)
  { 
    checkEntered3(button); // move on to checkEntered3, passing it "button"
  }
  // if it is zero, i.e. if it hasn't been defined with a button yet
  else if(entered[1] == 0)
  { 
    entered[1] = button; // set the second element as the button that has been pressed
    Serial.print("2: "); Serial.println(entered[1]); //for debugging
  }
}
// check the third element of the entered[] array
void checkEntered3(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is not a zero, i.e. it has already been inputted
  if (entered[2] != 0)
  {   
    checkEntered4(button); // move on to checkEntered4, passing it "button"
  }
  // if it is zero, i.e. if it hasn't been defined with a button yet
  else if (entered[2] == 0)
  { 
    entered[2] = button; // set the third element as the button that has been pressed
    Serial.print("3: ");Serial.println(entered[2]); // for debugging
  }
}
// check the third element of the entered[] array
void checkEntered4(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is not a zero, i.e. it has already been inputted
  if (entered[3] != 0)
  { 
    checkEntered5(button); // move on to checkEntered4, passing it "button"
  }
  // if it is zero, i.e. if it hasn't been defined with a button yet
  else if (entered[3] == 0)
  {   
    entered[3] = button; // set the third element as the button that has been pressed
    Serial.print("4: ");Serial.println(entered[3]); // for debugging
  }
}
// check the third element of the entered[] array
void checkEntered5(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is not a zero, i.e. it has already been inputted
  if (entered[4] != 0)
  { 
    checkEntered6(button); // move on to checkEntered4, passing it "button"
  }
  // if it is zero, i.e. if it hasn't been defined with a button yet
  else if (entered[4] == 0)
  {  
    entered[4] = button; // set the third element as the button that has been pressed
    Serial.print("5: ");Serial.println(entered[4]); // for debugging
  }
}
// check the fourth element of the entered[] array
void checkEntered6(int button)
{ 
  digitalWrite(LED[button-1],HIGH);
  // if it is zero, i.e. if it hasn't been defined with a button yet 
  if (entered[5] == 0)
  {   
    entered[5] = button; //set the final element as the button that has been pressed
    Serial.print("6: ");Serial.println(entered[5]); //for debugging
    delay(100); //allow time for processing
    compareCode(); //call the compareCode function
  }
}
// checks if the code entered is correct by comparing the code[] array with the entered[] array
void compareCode()
{
  for (int i = 0; i<6;i++)
  { 
    // these three lines are for debugging
    Serial.println(entered[i]);
  } 
  // if all the elements of each array are equal
  if ((entered[0]==code[0]) && 
      (entered[1]==code[1]) && 
      (entered[2]==code[2]) &&
      (entered[3]==code[3]) && 
      (entered[4]==code[4]) && 
      (entered[5]==code[5]))
  {
    digitalWrite(Red, LOW); // turn the red LED off
    digitalWrite(greenLed, HIGH); // turn the green LED on
    delay(1000); // wait for a bit
    digitalWrite(greenLed, LOW); // turn the green LED off
    // this next loop is for debugging
    for (int i = 0; i < 7; i++)
    { 
      entered[i] = 0;
    } 
    loop(); // return to loop() (not really necessary)
  }
  // if you(or the intruder) get the code wrong
  else 
  {     
    digitalWrite(Red,HIGH);
    delay(1000);
    digitalWrite(Red,LOW);
    Serial.println("Red OFF");
    // this next loop is for debugging
    for (int i = 0; i < 7; i++)
    { 
      entered[i] = 0;
    }
  }
close_all();
}

void close_all()
{
  digitalWrite(LED[0],LOW);
  digitalWrite(LED[1],LOW);
  digitalWrite(LED[2],LOW);
  digitalWrite(LED[3],LOW);
  digitalWrite(LED[4],LOW);
  digitalWrite(LED[5],LOW);
}
