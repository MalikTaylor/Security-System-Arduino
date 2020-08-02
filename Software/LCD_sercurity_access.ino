#include <MD_DS1307.h>
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h> 

MD_DS1307 myRTC;  
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pirSensor 13 
#define redLED 11 //IMPLEMNT THESE
#define greenLED 12
#define buzzer 10

int detectionStatus; //Motion Detection

//System States
bool locked;
bool systemDeactive;
bool alarmArmed;
bool alarmTriggered;

//Password
const int maxPasswordLength = 7;
const int minPasswordLength = 4;

String password = "000000"; //create a password
String tmpPass;
int failedAttepmt = 0;

char passwordData[maxPasswordLength]; //Entered Password[Max Password Length]
char newPasswordData[maxPasswordLength];
int keypadPos; //keypad position

const byte keyRow = 4;
const byte keyCols = 4;

char keyMap [keyRow] [keyCols] = {

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [keyRow] = {6,7,8,9}; //defines the pins of the keypad row
byte colPins [keyCols] = {2,3,4,5}; //defines the pins of the keypad columns

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, keyRow, keyCols);
char whichKey = myKeypad.getKey(); //defines which key has been pressed

String prompt;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pirSensor, INPUT);
  lcd.begin();
  locked = true;
}

void loop() {
  while(locked)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    if(alarmArmed && alarmTriggered){
      lcd.clear();
      AlarmStatus("Active");
      locked = true;
    }
    while(systemDeactive){
      lcd.setCursor(0,0);
      lcd.print("  **ShutDown**  ");
      AlarmStatus("Active");
    }
    RequestUserLogin(" Enter Password ");
  }
  while(!locked && !alarmTriggered){
    AlarmStatus("NotActive");
    MainMenu();
  }
}

void RequestUserLogin(String _prompt){ 
  for(int i = 0; i >= 0; i++){
    prompt = _prompt;
    DisplayUserLoginGUI();
    KeypadDetection();
    if(prompt.equals("New Password")){
      if(keypadPos == maxPasswordLength-1){
        keypadPos = 0;
        //Add a set option
        lcd.clear();
        tmpPass = passwordData;
        break;
      }
    } 
    if (prompt.equals("Conf Password")){
      if(keypadPos == tmpPass.length()){    
        if(tmpPass.equals(passwordData)){
          keypadPos = 0; 
          password = tmpPass;
          tmpPass = "";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("    Password");
          lcd.setCursor(0,1);
          lcd.print("     Changed");
          delay(1000);
          lcd.clear();
          break;
        }else{
          DenyEntry(" No Match ", "   Try Again! ");
          break;
        }
      }
    }else{
      if(keypadPos == password.length()){
        if(password.equals(passwordData)){
          keypadPos = 0; 
          alarmArmed = false; //Deactivates any security messures
          AlarmStatus("NotActive");
          alarmTriggered = false;
          failedAttepmt = 0;
          locked = false; //Unlocks System
          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, HIGH);
          lcd.clear();
          if(prompt.equals(" Enter Password ")){
            EntryMessage("    Welcome", "     Malik    ");
            lcd.clear();
          }
          digitalWrite(greenLED, LOW);
          break;
        }else{
          DenyEntry("   Inncorrect ", "   Try Again! ");
          break;
        }
      }
    }  
  }
}

void DisplayUserLoginGUI(){
  lcd.setCursor(0, 0);
  lcd.print(prompt);
  lcd.setCursor(0, 1);
  lcd.print(">");
}

void KeypadDetection(){
  char whichKey = myKeypad.getKey();
  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||  //defines invalid keys
    whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){
    keypadPos=0;
    DenyEntry("  Invalid Key!", "");
  }
  else if(whichKey){
    passwordData[keypadPos] = whichKey;
    lcd.setCursor(keypadPos+1,1); //Sets the cursor after ">"
    lcd.print(passwordData[keypadPos]);
    keypadPos ++;
  }
}

void EntryMessage(String welcomeMssg_1,String welcomeMssg_2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(welcomeMssg_1);
  lcd.setCursor(0, 1);
  lcd.print(welcomeMssg_2);
  delay(1000);
}

void DenyEntry(String denyMssg_1, String denyMssg_2){
  if(denyMssg_1.equals("   Inncorrect ")){
    failedAttepmt++;
  }
  keypadPos = 0;
  if(failedAttepmt < 3){
    Serial.println(failedAttepmt);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(denyMssg_1);
    lcd.setCursor(0, 1);
    lcd.print(denyMssg_2);
    delay(1000);
    lcd.clear();
    if(prompt.equals("Conf Password")){
      RequestUserLogin("New Password");
    }else{
      RequestUserLogin(prompt);
    }
  }else{
    lcd.clear();
    Serial.print("bow");
    systemDeactive = true;
    locked = true;
  }  
}

void DisplayMainMenuGUI(){
  myRTC.readTime();
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.print((String)myRTC.h + ":" + (String)myRTC.m + ":" + (String)myRTC.s);
  if(myRTC.status(DS1307_12H) == DS1307_ON){
    lcd.print(myRTC.pm ? " PM " : " AM ");
  }
  lcd.setCursor(0, 1);
  lcd.print("#)Alarm D)Options");
}

void MainMenu(){
  char whichKey = myKeypad.getKey();
  if(alarmArmed){
      detectMotion();
  }
  DisplayMainMenuGUI();
  switch(whichKey){
    case '#':
      lcd.clear();
      SetAlarm(); 
      break;
    case 'D':
      lcd.clear();
      Options(); 
      break;  
  }
}

void detectMotion(){
  detectionStatus = digitalRead(pirSensor);
    if(detectionStatus == HIGH )
    {
      locked = true;
      alarmTriggered = true;
    }else{
      alarmTriggered = false;
    }
}

void SetAlarm(){
  lcd.setCursor(0, 0);
  lcd.print("Set Alarm");
  lcd.setCursor(0, 1);
  lcd.print("#)Yes  D) NO"); 
  
  while(1>0){
    char whichKey = myKeypad.getKey();
    if(whichKey == '#'){
      for(int i = 3; i >= 1; i--){//Alarm Countdown
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alarm set in:");
        lcd.setCursor(14, 0);
        lcd.print(i);
        tone(buzzer, 500); //Count Down beeps
        delay(500);
        noTone(buzzer);
        delay(1000);
      }  
      alarmArmed = true;
      break;
    }
    else if(whichKey == 'D'){
      break;
    }
  } 
}

void AlarmStatus(String alarmStatus){
  if(alarmStatus == "Active"){
    tone(buzzer, 1000);
  }
  if(alarmStatus == "NotActive"){
    noTone(buzzer);
  }
}

void Options(){
  bool isExiting = false;
  lcd.setCursor(0, 0);
  lcd.print("#)Edit Password");
  lcd.setCursor(0, 1);
  lcd.print("*)Cancel D)Time");
  while(!isExiting){
    char whichKey = myKeypad.getKey();
    switch(whichKey){
      case '#':
        if(!alarmArmed){
          lcd.clear();
          ChangePassword();
        }
        lcd.clear();
        isExiting = true;
      case '*':
        lcd.clear();
        isExiting = true;
      case 'D':
        lcd.clear();
        ChangeTime();  
        isExiting = true;
    }
  }
}

void ChangePassword(){
  RequestUserLogin("Current Password");
  RequestUserLogin("New Password");
  RequestUserLogin("Conf Password");
}
  
void SystemDeactivate(){
  lcd.setCursor(0,0);
  lcd.print("  **ShutDown**  ");
  AlarmStatus("Active");
}

void ChangeTime(){
  if(myRTC.status(DS1307_12H) != DS1307_ON){
    myRTC.control(DS1307_12H, DS1307_ON);
  }else{
    myRTC.control(DS1307_12H, DS1307_OFF);
  }
   EntryMessage("      Time", "     Changed");
}
