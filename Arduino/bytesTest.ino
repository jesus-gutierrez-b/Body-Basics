#include <Servo.h>

Servo servo;

int ledPin= 13;
byte inbyte0;
byte inbyte1;
byte inbyte2;
byte inbyte3;

int nangle;
int angle;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  servo.attach(10);
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
}

void loop() {
  if( Serial.available() == 4 ){
    inbyte0= Serial.read();
    delay( 100 );
    inbyte1= Serial.read();
    delay( 100 );
    inbyte2= Serial.read();
    delay( 100 );
    inbyte3= Serial.read();
    delay( 100 );
    
    if( inbyte0 == 11 )
    {
      nangle = concatenar(inbyte1, inbyte2, inbyte3);
      
      angle = map( nangle, 266, 280, 0, 180 );
      servo.write( angle );
      
        inbyte0= -1;
        inbyte1= -1;
        inbyte2= -1;
        inbyte3= -1;
        
      } // end if inbyte0= 11
    } // end if serial available

} // end loop

int concatenar(byte a, byte b, byte c)
{
  String conca="";
  if(a>=0 && a<=9)
  {
    conca+= a;
    if(b>=0 && b<=9)
    {
      conca+= b;
      if(c>=0 && c<=9)
        {conca+= c;}
      } // if b
    } // if a

  return conca.toInt();
} // String concatenar
