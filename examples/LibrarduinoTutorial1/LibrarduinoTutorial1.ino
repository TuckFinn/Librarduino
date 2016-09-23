/*   ^  *Click on the right-hand arrow to start the tutorial!























*/
//#include<Librarino.h>
//DOER LED(3);
//DOER ONBOARD(13);
//TOGGLE BUTTON(3);
//SENSOR LIGHT(5);

//const char string_0[] PROGMEM = "Hello. I am an Arduino.";

int switcher = 1;

void TypeText(String inputs){
  for(int i = 0; i < inputs.length();i++){
    if(i == (inputs.length()) - 1){
      Serial.println(inputs[i]);
    }
    else{
      Serial.print(inputs[i]);
    }
    delay(60);
  }
}

void setup() {
  // put your setup code here, to run once:
  //LED.OFF();
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  TypeText("Hello. I am an Arduino.");
  delay(1000);
  TypeText("I'm going to tell you a little bit about what I can do.");
  delay(1000);
  TypeText("Type 'R' into the box above and click Send when you are ready.");
  char answer = Serial.read();
  while(answer != 'R'){
    answer = Serial.read();
    //Serial.println(answer);
  }
  Serial.println();
  delay(1000);

  TypeText("There are three main ways that I can interact with the world around me.");
  delay(1000);
  Serial.println();
  TypeText("DOERS:");
  Serial.println();
  delay(1000);
  TypeText("The first is pretty simple.");
  delay(1000);
  TypeText("I can turn electricity on and off.");
  delay(1000);
  TypeText("By myself, this doesn't mean much.");
  delay(1000);
  TypeText("I only have one DOER built in.");
  Serial.println();
  delay(1000);
  TypeText("I can blink this little light...");
  for(int i = 0; i<5;i++){
    /*ONBOARD.ON();
    LED.WAIT(500);
    ONBOARD.OFF();
    LED.WAIT(500);*/
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }

  delay(1000);
  Serial.println();
  TypeText("I can make it go faster...");
  delay(1000);

  for(int i = 0; i<20;i++){
    /*ONBOARD.ON();
    LED.WAIT(80);
    ONBOARD.OFF();
    LED.WAIT(80);*/
    digitalWrite(13,HIGH);
    delay(80);
    digitalWrite(13,LOW);
    delay(80);
  }

  delay(1000);
  Serial.println();
  TypeText("Or just leave it on...");

  /*ONBOARD.ON();
  ONBOARD.WAIT(3000);
  ONBOARD.OFF();

  ONBOARD.PAUSE(1000);*/
  digitalWrite(13,HIGH);
  delay(5000);
  digitalWrite(13,LOW);
  delay(1000);
  
  Serial.println();
  TypeText("But I can't do anything else without help.");
  delay(1000);
  TypeText("Fortunately, there are hundreds of electronic DOERS that I can connect to.");
  delay(1000);
  TypeText("Things like lights, motors, speakers and screens.");
  delay(1000);
  Serial.println();
  TypeText("TOGGLES:");
  delay(1000);
  Serial.println();
  TypeText("The next thing I can do is read whether a TOGGLE is on or off." );
  delay(1000);
  TypeText("A TOGGLE is a physical object that can take on one of two values.");
  delay(1000);
  TypeText("Try thinking of some things that can either be 'this' or 'that'.");
  delay(1000);
  TypeText("Type 'R' above and click send when you're ready." );
  delay(1000);
  answer = Serial.read();
  while(answer != 'R'){
    answer = Serial.read();
    //Serial.println(answer);
  }
  Serial.println();
  delay(1000);
  TypeText("Maybe you thought about how a button can either be pressed or not.");
  delay(1000);
  TypeText("Or about a switch that can either be left or right.");
  delay(1000);
  TypeText("In electronics, these are two common TOGGLES.");
  delay(1000);
  TypeText("But keep your eye out for other examples.");
  delay(1000);
  Serial.println();
  TypeText("SENSORS:");
  delay(1000);
  Serial.println();
  TypeText("The last thing I can do is read values from a SENSOR.");
  delay(1000);
  TypeText("Where a TOGGLE can only see light and dark...");
  delay(1000);
  TypeText("...a SENSOR can see light, dark, dim and everything in between.");
  delay(1000);
  TypeText("Can you think of some SENSORS that you see on a daily basis?");
  delay(1000);
  TypeText("Type 'R' above and click send when you're ready." );
  delay(1000);
  answer = Serial.read();
  while(answer != 'R'){
    answer = Serial.read();
  }
  TypeText("Did you think about a thermometer for reading the outside temperature?");
  delay(1000);
  TypeText("Or a speedometer for seeing how fast your car is going?");
  delay(1000);
  TypeText("There are plenty more sensors in everyday devices, and I can use most of them!");
  delay(3000);
  Serial.println();
  TypeText("Open the next tutorial for more!");

  while(answer != 'R'){
  }
}
