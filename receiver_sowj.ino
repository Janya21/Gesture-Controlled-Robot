#include<VirtualWire.h>

//int ledpassive = 5;
int led1 = 10;
int led2 = 11;
int led3 = 9;
int led4 = 6;
int hipin = 13;

void setup() {
  // put your setup code here, to run once:
 
  pinMode( led1 , OUTPUT);
  pinMode( led2 , OUTPUT);
  pinMode( led3 , OUTPUT);
  pinMode( led4 , OUTPUT);
  pinMode( hipin , OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(1000);
  vw_rx_start();
  Serial.begin(9600);
  digitalWrite( hipin , HIGH);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  
  digitalWrite( led1 , LOW);
  digitalWrite( led2 , LOW);
  digitalWrite( led3 , LOW);
  digitalWrite( led4 , LOW);
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if( vw_get_message( buf, &buflen))
  {
    //Serial.println(*buf);
    //buf[0]='X';
    if( buf[0]=='X')
    {
        Serial.print(*buf);
        digitalWrite(led1 , HIGH);
        digitalWrite( led2 , LOW);
        digitalWrite( led3 , HIGH); 
        digitalWrite( led4 , LOW);  
    }
    else
    if( buf[0]=='Y')
    {
        Serial.print(*buf);
        digitalWrite(led1 , LOW);
        digitalWrite( led2 , HIGH);
        digitalWrite( led3 , LOW);
        digitalWrite( led4 , HIGH);   
    }
    else
    if( buf[0]=='Z')
    {
        Serial.print(*buf);
        digitalWrite(led1 , LOW);
        digitalWrite( led2 , LOW);
        digitalWrite( led3 , LOW); 
        digitalWrite( led4 , LOW);  
    }
    delay(5000);
  }   // end vm messaage
}   // end loop
