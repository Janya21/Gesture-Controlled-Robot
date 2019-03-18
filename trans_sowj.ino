#include<VirtualWire.h>
char *message = "Merry Christmas";
int xpin = A3;
int ypin = A2;
int zpin = A1;
int led1 = 13;
int led2 = 11;
int led3 = 10;

void setup() 
{
  // put your setup code here, to run once: 
  pinMode(led1 , OUTPUT);
  pinMode( led2 , OUTPUT);
  pinMode( led3 , OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(1000);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  int val = analogRead(ypin);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  delay(100);
  if( val >350)
  {
    message = "X";
    vw_send((uint8_t *)message , strlen(message));
    vw_wait_tx();
    digitalWrite( led1 , HIGH);
    digitalWrite(led2 , LOW);
    digitalWrite( led3 , LOW);
    delay(2000);
  }
  else
  if( val <= 150)
  {
    message = "Y";
    vw_send((uint8_t *)message , strlen(message));
    vw_wait_tx();
    digitalWrite( led1 , LOW);
    digitalWrite( led2 , LOW);
    digitalWrite( led3 , HIGH);
    delay(2000);
  }
  else
  {
    message = "Z";
    vw_send((uint8_t *)message , strlen(message));
    vw_wait_tx();
    digitalWrite( led1 , LOW);
    digitalWrite( led2 , HIGH);
    digitalWrite( led3 , LOW);
    delay(2000);
    
  }
   
}

