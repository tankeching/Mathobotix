int rightF = 0;
int rightB = 1;
int leftF = 2;
int leftB = 3;

void setup()
{
  pinMode(rightF, OUTPUT); // Right (Green)
  pinMode(rightB, OUTPUT); // Right (Blue)
  pinMode(leftF, OUTPUT); // Left (Green)
  pinMode(leftB, OUTPUT); // Right (Blue)
  
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
}

void forward()
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, HIGH);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, HIGH);
}

void left()
{
  digitalWrite(rightF, HIGH);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, HIGH);
}

void right()
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, HIGH);
  digitalWrite(leftF, HIGH);
  digitalWrite(leftB, LOW);
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
  forward();
  delay(2000);
  brake();
  delay(2000);
  left();
  delay(2000);
  brake();
  delay(2000);
  right();
  delay(200);
  brake();
  delay(2000);
}
