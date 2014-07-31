// Bluetooth Code 
char dataIn='S';
char determinant;
char det; 
int overdrive = 13; //Press Toggle Switch #1, the pin13 LED will light up

// Motor Ports
int rightF = 2;
int rightB = 3;
int leftF = 4;
int leftB = 5;

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
      det = check(); 
     
      while(det == 'F')   // F, move forward
       {
         forward();
         delay(2000);
         det = check();
       }
     
//      while(det == 'B')   // B, move back
//       {
//        
//         det = check();
//       }
//
//      while(det == 'L')   // L, move wheels left
//       {
//         
//         det = check();
//       }
//      
//      while(det == 'R')   // R, move wheels right
//       {
//          md.setSpeeds(vel,vel/4);
//          det = check();
//       }
//    
//      while(det == 'I')   // I, turn right forward
//       {
//         md.setSpeeds(vel,vel/2);
//         det = check();
//       }
//    
//      while(det == 'J')   // J, turn right back
//       {
//         md.setSpeeds(-vel,-vel/2);
//         det = check();
//       }  
//     
//      while(det == 'G')   // G, turn left forward
//       {
//         md.setSpeeds(vel/2,vel);
//         det = check();
//       }
//    
//      while(det == 'H')   // H, turn left back
//       {
//         md.setSpeeds(-vel/2,-vel);
//         det = check();
//       }  
     
      while(det == 'S')   // S, stop
       {
         brake();
         delay(2000);
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
