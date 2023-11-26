//Security Alarm with Ultrasonic Sensor//

#define trigPin 6  
#define echoPin 5
#define buzzer 2
#define bulbRed 11
#define bulbYellow 10 
#define bulbGreen 9


float new_delay; 


void setup() 
{
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(bulbRed,OUTPUT);
  pinMode(bulbYellow,OUTPUT);
  pinMode(bulbGreen,OUTPUT);
  
}


void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  new_delay= (distance *3) +30;
  Serial.print(distance);
  Serial.println("  cm");

   if (distance >= 50 || distance < 0)
  {
    digitalWrite(bulbGreen, HIGH);
    digitalWrite(bulbYellow, LOW);
    digitalWrite(bulbRed, LOW);
  }
  // If beep distance is between 20 and 5, turn on the yellow bulb
  else if (distance <= 50 && distance > 15)
  {
    digitalWrite(bulbGreen, LOW);
    digitalWrite(bulbYellow, HIGH);
    digitalWrite(bulbRed, LOW);
  }
  // If beep distance is less than 5, turn on the red bulb
  else if (distance <= 15)
  {
    digitalWrite(bulbGreen, LOW);
    digitalWrite(bulbYellow, LOW);
    digitalWrite(bulbRed, HIGH);

  }
  else
  {
    // If none of the specific conditions are met, turn off all the lights
    digitalWrite(bulbGreen, LOW);
    digitalWrite(bulbYellow, LOW);
    digitalWrite(bulbRed, LOW);
  }

  if (distance < 50)
  {
   digitalWrite(buzzer,HIGH);
   delay(new_delay);
   digitalWrite(buzzer,LOW);

 
  }
  else
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(bulbGreen,HIGH);

  }
  
 delay(200);
}
