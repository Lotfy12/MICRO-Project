int BuzzerPin = 5;   // ~(PWM)
int trigPin = 9;
int echoPin = 10;

void setup(){

  Serial.begin(9600);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

/*
 * 
 * Speed = Distance / Time   =>   Distance = Time * Speed 
 * 
 * Speed of Sound = 340 m/s = 34000 cm/s = 0.034 cm/us
 * 
 */

  float distance = duration * 0.034 / 2. ;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance<100){

    analogWrite(BuzzerPin, 255);      // Almost any value can be used except 0 and 255
    delay(100);
    analogWrite(BuzzerPin, 155);      // Almost any value can be used except 0 and 255
    delay(100);
  }
  else{
    analogWrite(BuzzerPin, 0);      // Almost any value can be used except 0 and 255
    }

  delay(5);
  
}