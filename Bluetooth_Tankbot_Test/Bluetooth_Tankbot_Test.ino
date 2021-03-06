/*
Forward -> F
Back -> B
Left -> L
Right -> R
Forward Left -> G
Forward Right -> I
Back Left ->
Back Right -> J
Stop -> S
Speed 10 -> 1
Speed 20 -> 2
Speed 30 -> 3
Speed 40 -> 4
Speed 50 -> 5
Speed 60 -> 6
Speed 70 -> 7
Speed 80 -> 8
Speed 90 -> 9
Speed 100 -> q
Stop All -> D

*/

// Bluetooth Code 
char dataIn='S';
char determinant;
char det; 
int overdrive = 13; //Press Toggle Switch #1, the pin13 LED will light up
bool vel = HIGH;

// Motor Ports
int rightF = 2;
int rightB = 3;
int leftF = 4;
int leftB = 5;

void setup()
{
  Serial.begin(115200);
  pinMode(overdrive, OUTPUT);
  
  pinMode(rightF, OUTPUT); // (Green)
  pinMode(rightB, OUTPUT); // (Blue)
  pinMode(leftF, OUTPUT); // (Green)
  pinMode(leftB, OUTPUT); // (Blue)
  
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
}

void forward(int vel)
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, vel);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, vel);
}

void left(int vel) // One motor
{
  digitalWrite(rightF, vel);
}

void right(int vel) // One motor
{
//  digitalWrite(rightF, LOW);
//  digitalWrite(rightB, vel);
  digitalWrite(leftF, vel);
//  digitalWrite(leftB, LOW);
}

void backwards(int vel)
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, vel);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, vel);
}

void forwardLeft()
{
  
}

void forwardRight()
{
  
}

void backLeft()
{
  
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
      det = check(); 
     
      while(det == 'F')   // F, move forward
       {
         forward(vel);
         delay(4000);
         det = check();
       }
     
      while(det == 'B')   // B, move back
       {
         backwards(vel);
         delay(1000);
         det = check();
       }

      while(det == 'L')   // L, move wheel left
       {
         left(vel);
         delay(1000);
         det = check();
       }
      
      while(det == 'R')   // R, move wheel right
       {
          right(vel);
          delay(1000);
          det = check();
       }
    
      while(det == 'I')   // I, turn right forward
       {
          digitalWrite(leftB, vel);
          delay(2000);
          det = check();
       }
    
      while(det == 'J')   // J, turn right back
       {
          digitalWrite(rightB, vel);
          delay(2000);
          det = check();
       }  
     
      while(det == 'G')   // G, turn left forward
       {
          digitalWrite(rightB, vel);
          delay(2000);
          det = check();
       }
    
      while(det == 'H')   // H, turn left back
       {
          digitalWrite(rightB, vel);
          delay(2000);
          det = check();
       }  
     
      while(det == 'S')   // S, stop
       {
         brake();
         det = check();
       }
       
      //---------------------Toggle switch code------------------//
     /* while (det == 'U')  
      {digitalWrite(power, HIGH);det = check();}
      while (det == 'u')  
      {digitalWrite(power, LOW);det = check();}*/
      //---------------------Mains Power------------------//
      while (det == 'W')  
      {digitalWrite(overdrive, HIGH);det = check();}
      while (det == 'w')  
      {digitalWrite(overdrive, LOW);det = check();}
}

int check()
{
  if (Serial.available() > 0) 
  {
     dataIn = Serial.read(); 
        if (dataIn == 'F')
        {
          determinant = 'F';
        } 
        else if (dataIn == 'B')
        {
          determinant = 'B';
        }
        else if (dataIn == 'L')
        {
          determinant = 'L';
         }
        else if (dataIn == 'R')
        {
          determinant = 'R';
         }
        else if (dataIn == 'I')
        {
          determinant = 'I';
        } 
        else if (dataIn == 'J')
        {
          determinant = 'J';
        }
        else if (dataIn == 'G')
        {
          determinant = 'G';
        }   
        else if (dataIn == 'H')
        {
          determinant = 'H';
        }
        else if (dataIn == 'S')
        {
          determinant = 'S';
        }
        else if (dataIn == 'U')
        {
          determinant = 'U';
        }
        else if (dataIn == '0'){vel = LOW;}else if (dataIn == '1'){vel = HIGH;}
        else if (dataIn == '2'){vel = HIGH;}else if (dataIn == '3'){vel = HIGH;}
        else if (dataIn == '4'){vel = HIGH;}else if (dataIn == '5'){vel = HIGH;}
        else if (dataIn == '6'){vel = HIGH;}else if (dataIn == '7'){vel = HIGH;}
        else if (dataIn == '8'){vel = HIGH;}else if (dataIn == '9'){vel = HIGH;}
        else if (dataIn == 'q'){vel = HIGH;}
        else if (dataIn == 'u')
        {
          determinant = 'u';
        }
        else if (dataIn == 'W')
        {
          determinant = 'W';
        }
        else if (dataIn == 'w')
        {
          determinant = 'w';
        }
      }
    return determinant;
}
