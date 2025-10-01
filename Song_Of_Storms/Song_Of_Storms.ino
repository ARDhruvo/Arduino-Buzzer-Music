/*
  Title: "Song of the Storms"
  Original Composition By: Koji Kondo
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer = 13;  //buzzer to arduino pin 13

// Notes
float D3 = 146.8324;
float F3 = 174.6141;
float G3 = 195.9977;
float A_3 = 220;

float C4 = 261.6254;
float D4 = 293.6648;
float E4 = 329.6276;
float F4 = 349.2282;
float G4 = 391.9954;
float A_4 = 440.0000;

float C5 = 523.2511;
float D5 = 587.3295;
float E5 = 659.2551;
float F5 = 698.4565;

// Note length
int half_Note = 125;
int full_Note = 2 * half_Note;
int double_full_Note = 2 * full_Note;

void intro(int extra) {
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, F4);
  delay(full_Note);
  noTone(buzzer);
  tone(buzzer, F4);
  delay(full_Note);
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, G4);
  delay(double_full_Note);
  noTone(buzzer);
  
  
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, A_4);
  delay(full_Note);
  noTone(buzzer);
  tone(buzzer, A_4);
  delay(full_Note);
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, G4);
  delay(double_full_Note);
  noTone(buzzer);

  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, F4);
  delay(full_Note);
  noTone(buzzer);
  tone(buzzer, F4);
  delay(full_Note);
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, G4);
  delay(double_full_Note);
  noTone(buzzer);
  
  
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, A_4);
  delay(full_Note);
  noTone(buzzer);
  tone(buzzer, A_4);
  delay(full_Note);
  tone(buzzer, D4);
  delay(full_Note);
  tone(buzzer, G4);
  delay(double_full_Note + extra);
  noTone(buzzer);
}

void verse() {
  tone(buzzer, D4);  
  delay(half_Note);         
  tone(buzzer, F4);  
  delay(half_Note);         
  tone(buzzer, D5);  
  delay(double_full_Note);
  noTone(buzzer);  

  tone(buzzer, D4);  
  delay(half_Note);         
  tone(buzzer, F4);  
  delay(half_Note);         
  tone(buzzer, D5);  
  delay(double_full_Note);
  noTone(buzzer);  

  tone(buzzer, E5);  
  delay(full_Note + half_Note);    
  tone(buzzer, F5);  
  delay(half_Note);         
  tone(buzzer, E5);  
  delay(half_Note);
  tone(buzzer, F5);  
  delay(half_Note);
  noTone(buzzer);  

  tone(buzzer, E5);  
  delay(half_Note);         
  tone(buzzer, C5);  
  delay(half_Note);         
  tone(buzzer, A_4);   
  delay(double_full_Note);
  noTone(buzzer);  

  tone(buzzer, A_4);   
  delay(full_Note);         
  tone(buzzer, D4);  
  delay(full_Note);         
  tone(buzzer, F4);  
  delay(half_Note);
  tone(buzzer, G4);  
  delay(half_Note);
  noTone(buzzer);  
}

void outro1()
{
  tone(buzzer, A_4);   
  delay(double_full_Note + full_Note);  
  noTone(buzzer);  

  tone(buzzer, A_4);   
  delay(full_Note);         
  tone(buzzer, D4);  
  delay(full_Note);         
  tone(buzzer, F4);  
  delay(half_Note);
  tone(buzzer, G4);  
  delay(half_Note);
  noTone(buzzer);  

  tone(buzzer, E4);  
  delay(double_full_Note + full_Note);  
  noTone(buzzer);  
}

void outro2()
{
  tone(buzzer, A_4);   
  delay(double_full_Note);         
  noTone(buzzer);  
  tone(buzzer, A_4); 
  delay(full_Note);       
  noTone(buzzer);  

  tone(buzzer, D4);  
  delay(2*(double_full_Note + full_Note));
  noTone(buzzer);  
}

void setup() {
  pinMode(buzzer, OUTPUT);  

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Now Playing:");
  lcd.setCursor(0, 1);
  lcd.print("Song of Storms");
}

void loop() {
  intro(0);
  verse();
  outro1();
  verse();
  outro2();

  verse();
  outro1();
  verse();
  outro2();
  
  intro(double_full_Note);
  noTone(buzzer);
  delay(double_full_Note);
}