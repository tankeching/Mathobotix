/*
Forward -> F
Backwards -> B
Left -> L
Right -> R
Forward Left -> G
Forward Right -> I
Back Left -> H
Back Right -> J
Stop -> S
Speed 0 -> 0
Speed 10 -> 0
Speed 20 -> 0
Speed 30 -> 0
Speed 40 -> 0
Speed 50 -> 0
Speed 60 -> 0
Speed 70 -> 0
Speed 80 -> 0
Speed 90 -> 0
Speed 100 -> q
Stop All -> D
*/


// Bluetooth Code 
char dataIn='S';
char determinant;
char det;
bool vel = HIGH; 

// Motor Ports
int rightF = 2;
int rightB = 3;
int leftF = 4;
int leftB = 5;

//int power = 4;     // Remove This To Enable Tollge Switch #2
int overdrive = 13; //Press Toggle Switch #1, the pin13 LED will light up

void setup()
{
  Serial.begin(9600);
  pinMode(overdrive, OUTPUT);
  
  pinMode(rightF, OUTPUT); // Right (Green)
  pinMode(rightB, OUTPUT); // Right (Blue)
  pinMode(leftF, OUTPUT); // Left (Green)
  pinMode(leftB, OUTPUT); // Right (Blue)
  
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
}

void backwards(bool vel)
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, vel);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, vel);
}

void left(bool vel) 
{
  digitalWrite(rightF, vel);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, vel);
}

void right(bool vel)
{
  digitalWrite(rightF, LOW);
  digitalWrite(rightB, vel);
  digitalWrite(leftF, vel);
  digitalWrite(leftB, LOW);
}

void forward(bool vel)
{
  digitalWrite(rightF, vel);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, vel);
  digitalWrite(leftB, LOW);
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
         backwards(vel);
         det = check();
       }
     
      while(det == 'B')   // B, move back
       {
         forward(vel);
         det = check();
       }

      while(det == 'L')   // L, move wheels left
       {
         right(vel);
         det = check();
       }
      
      while(det == 'R')   // R, move wheels right
       {
          left(vel);
          det = check();
       }
    
//      while(det == 'I')   // I, turn right forward
//       {
//
//         det = check();
//       }
//    
//      while(det == 'J')   // J, turn right back
//       {
//
//         det = check();
//       }  
//     
//      while(det == 'G')   // G, turn left forward
//       {
//
//         det = check();
//       }
//    
//      while(det == 'H')   // H, turn left back
//       {
//
//         det = check();
//       }  
//     
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
        else if (dataIn == '0')
        {
          vel = HIGH;
        }
        else if (dataIn == '1')
        {
          vel = HIGH;
        }
        else if (dataIn == '2')
        {
          vel = HIGH;
        }
        else if (dataIn == '3')
        {
          vel = HIGH;
        }
        else if (dataIn == '4')
        {
          vel = HIGH;
        }
        else if (dataIn == '5')
        {
          vel = HIGH;
        }
        else if (dataIn == '6')
        {
          vel = HIGH;
        }
        else if (dataIn == '7')
        {
          vel = HIGH;
        }
        else if (dataIn == '8')
        {
          vel = HIGH;
        }
        else if (dataIn == '9')
        {
          vel = HIGH;
        }
        else if (dataIn == 'q')
        {
          vel = LOW;
        }
        else if (dataIn == 'U')
        {
          determinant = 'U';
        }
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
