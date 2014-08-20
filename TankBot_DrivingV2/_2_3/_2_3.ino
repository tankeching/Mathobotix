int rightF = 0;
int rightB = 1;
int leftF = 2;
int leftB = 3;
//int trigPin = 12;
//int echoPin = 13;
void setup()
{
  pinMode(rightF, OUTPUT); // Right (Green)
  pinMode(rightB, OUTPUT); // Right (Blue)
  pinMode(leftF, OUTPUT); // Left (Green)
  pinMode(leftB, OUTPUT); // Right (Blue)
  Serial.begin(115200);
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//  
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
}

void forward()
{
  digitalWrite(rightF, HIGH);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, HIGH);
  digitalWrite(leftB, LOW);
}

void left()
{
  digitalWrite(rightF, HIGH);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, HIGH);
  delay(2000);
  brake();
}

void right()
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, HIGH);
  digitalWrite(leftF, HIGH);
  digitalWrite(leftB, LOW);
  delay(2000);
  brake();
}

void backwards()
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, HIGH);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, HIGH);
}

void brake()
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
}

void loop()
{
//  long duration, distance;
//  digitalWrite(trigPin, HIGH);
//  duration = pulseIn(echoPin, HIGH);
//  distance = (duration/2)/29.1;
  /*if ( distance <= 10)
  {
  brake();
  backwards();
  delay(1000);
  brake();
  right();
  }
  else
  { */
    forward();
    delay(2000);
  //}
}
