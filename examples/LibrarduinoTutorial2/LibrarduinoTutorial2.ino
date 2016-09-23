/*   ^  *Click on the right-hand arrow to start the tutorial!























*/
//#include<Librarino.h>
//DOER LED(3);
//DOER ONBOARD(13);
//TOGGLE BUTTON(3);
//SENSOR LIGHT(5);

//const char string_0[] PROGMEM = "Hello. I am an Arduino.";

int switcher = 1;

void TypeText(String inputs, int wait = 1000){
  for(int i = 0; i < inputs.length();i++){
    if(i == (inputs.length()) - 1){
      Serial.println(inputs[i]);
    }
    else{
      Serial.print(inputs[i]);
    }
    delay(60);
  }
  delay(wait);
}

void setup() {
  // put your setup code here, to run once:
  //LED.OFF();
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  TypeText("Welcome back!");
  TypeText("Now that you know a little bit about the 3 things I can do...");
  TypeText("...I'm going to show you how to make them happen using code.");
  Serial.println();
  TypeText("You'll need to connect me to the Librarduino intro circuit for these tutorials.");
  TypeText("If the circuit is already set up on your circuit board, you're good to go.");
  TypeText("If not, ask a librarian for help setting it up.");
  TypeText("The little holes that you plug wires into are called 'pins'.");
  TypeText("Keep an eye on the numbers each pin is labeled with.");
  Serial.println();
  
  TypeText("Type 'R' into the box above and click Send when you are ready.");
  char answer = Serial.read();
  while(answer != 'R'){
    answer = Serial.read();
    //Serial.println(answer);
  }
  Serial.println();
  delay(1000);
  
  TypeText("When you start a new programming sketch for Arduino it will look like this...");
  Serial.println();
  
  Serial.println("#include <Librarduino.h>");
  Serial.println();
  Serial.println("void setup(){");
  Serial.println();
  Serial.println("}");
  Serial.println();
  Serial.println("void loop(){");
  Serial.println();
  Serial.println("}");
  Serial.println();
  delay(5000);
  
  TypeText("The part that says '#include <Librarduino.h>' you can skip over.");
  Serial.println();
  delay(1000);
  
  TypeText("Next is an empty space where you tell me what objects are in your circuit.");
  TypeText("In the case of the intro circuit, you have an LED, a button and a light sensor.");
  TypeText("Here's how you tell me they're there.");
  Serial.println();
  delay(1000);

  TypeText("For each object, you will write whether it's a DOER, a TOGGLE, or a SENSOR.");
  TypeText("Then you can name it. Call it whatever you want.");
  TypeText("Finally, you tell me which pin it is connected to, and you're done.");
  TypeText("For example, making an LED object would look like this if it's plugged into pin 5...");
  Serial.println();
  delay(1000);

  TypeText("DOER firstLED(5);");
  Serial.println();
  delay(1000);

  TypeText("Do you see the type of object it is, its name and the pin it's connected to?");
  TypeText("Type 'R' into the box above and click Send when you are ready.");
  answer = Serial.read();
  while(answer != 'R'){
    answer = Serial.read();
    //Serial.println(answer);
  }
  Serial.println();
  delay(1000);

  TypeText("After all three of the objects on your intro circuit are made...");
  TypeText("...Your code will look like this...");
  Serial.println();
  delay(1000);

  Serial.println("#include <Librarduino.h>");
  Serial.println();
  Serial.println("DOER firstLED(5);");
  Serial.println("TOGGLE firstBUTTON(5);");
  Serial.println("DOER firstSENSOR(5);");
  Serial.println();
  Serial.println("void setup(){");
  Serial.println();
  Serial.println("}");
  Serial.println();
  Serial.println("void loop(){");
  Serial.println();
  Serial.println("}");
  Serial.println();
  delay(5000);

  TypeText("Now that you have told me what's in your circuit, it's time to make it work!");
  TypeText("Continue to the next tutorial to see how...");
  Serial.println();
  
  while(answer != 'R'){
    //Serial.println(answer);
  }
}
