void setup()
{
  pinMode(0, OUTPUT); // A-IB (Green)
  pinMode(1, OUTPUT); // A-IA (Blue)
  pinMode(2, OUTPUT); // B-IB (Green)
  pinMode(3, OUTPUT); // B-IA (Blue)
}

void forward()
{
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH); 
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
}

void brake()
{
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void loop()
{
    forward();
    delay(3000); 
}
