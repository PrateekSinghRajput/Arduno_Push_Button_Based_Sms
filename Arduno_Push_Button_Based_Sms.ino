#include <SoftwareSerial.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(11, 10); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define PAUSETIME 20000

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial sim800l(3, 2); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted

#define button1 8//Button pin, on the other pin it's wired with GND
#define button2 7
#define button3 6
#define button4 5
#define button5 4

bool button_State; //Button state
bool button_State1;
bool button_State2;
bool button_State3;
bool button_State4;


void setup()
{
mySoftwareSerial.begin(9600);
  Serial.begin(115200);
   Serial.println();
  Serial.println(F("Initializing DFPlayer..."));

  //Use softwareSerial to communicate with MP3
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  //Set volume value (From 0 to 30)
  myDFPlayer.volume(25);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Welcome To");
  lcd.setCursor(0, 1);
  lcd.print(" Our Projects");
  delay(2000);
  lcd.clear();
  pinMode(button1, INPUT_PULLUP); //The button is always on HIGH level, when pressed it goes LOW
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  sim800l.begin(9600);   //Module baude rate, this is on max, it depends on the version
  Serial.begin(9600);
  delay(1000);
}

void loop()
{


  button_State = digitalRead(button1);   //We are constantly reading the button State
  button_State1 = digitalRead(button2);
  button_State2 = digitalRead(button3);
  button_State3 = digitalRead(button4);
  button_State4 = digitalRead(button5);

  if (button_State == LOW) {            //And if it's pressed
    Serial.println("Button pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    lcd.setCursor(0, 0);
    lcd.print("Give Me Food....");
    SendSMS();           
    myDFPlayer.play(1);

  }

  if (button_State1 == LOW) {            //And if it's pressed
    Serial.println("Button pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    lcd.setCursor(0, 0);
    lcd.print("Give me Drink...");
    SendSMS1();  
     myDFPlayer.play(2);//And this function is called

  }
  if (button_State2 == LOW) {            //And if it's pressed
    Serial.println("Button pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    lcd.setCursor(0, 0);
    lcd.print("Give Me Medicine");
    SendSMS2();    
     myDFPlayer.play(3);//And this function is called

  }
  if (button_State3 == LOW) {            //And if it's pressed
    Serial.println("Button pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    lcd.setCursor(0, 0);
    lcd.print("Give Me Dinner..");
    SendSMS3();         
     myDFPlayer.play(4);//And this function is called

  }
  if (button_State4 == LOW) {            //And if it's pressed
    Serial.println("Button pressed");
    lcd.setCursor(0, 0);
    lcd.print("Wheelchair Damage...");//Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    SendSMS4();    
     myDFPlayer.play(5); //And this function is called

  }

  if (sim800l.available()) {           //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read());
  }
}

void SendSMS()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919624869633\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print(" Give Me Food..");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println(" Give Me Food..");
  delay(500);

}

void SendSMS1()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919624869633\"\r");  //Your phone number don't forget to include your country code, example 
  delay(500);
  sim800l.print(" Give Me Water...");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println(" Give Me water...");
  delay(500);

}

void SendSMS2()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919624869633\"\r");  //Your phone number don't forget to include your country code, example 
  delay(500);
  sim800l.print("Give Me Medicine");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println(" Give Me Medicine");
  delay(500);

}
void SendSMS3()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919624869633\"\r");  //Your phone number don't forget to include your country code, example 
  delay(500);
  sim800l.print(" Give Me Dinner..");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println(" Give Me Dinner..");
  delay(500);

}
void SendSMS4()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919624869633\"\r");  //Your phone number don't forget to include your country code, example 
  delay(500);
  sim800l.print("Plz Check Wheelchair Damage");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Plz Check Whelchair Damage");
  delay(500);

}
