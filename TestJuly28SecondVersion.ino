//4 time interval
/**
 * This class measures the tempo as you tap the drum
 * and calculates the BPM and shows up on the 7 segment displays as a 3 digits
 * it measure with 4 time intervals
 * @author KeonwoongMin
 *
 */
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

int x = 0;
int y = 0;
int z = 0;

int ON = LOW;
int OFF = HIGH;

const int digit1Power = A0;
const int digit2Power = A1;
const int digit3Power = A2;

//////////////////////
//piezo
const int PIEZO_PIN = A5;
int PIEZO_VALUE1=0;
int PIEZO_VALUE2=0 ;
int PIEZO_VALUE3=0;
int PIEZO_VALUE4=0;
int PIEZO_VALUE5=0;
int PIEZO_VALUE6=0;
int PIEZO_VALUE7=0;

int BPM;
int timeInterval = 0;

float time0;
float time1;
float time2;
float time3;
float time4;
float time5;
float time6;
float time7;
int count = -1;
float tempTime = 0;
float finalTimeInterval = 0;

int tappingPower = 900;
int differencePower = 200;
int delayPower = 2;

float interval0 = 0;
float interval1 = 0;
float interval2 = 0;
float interval3 = 0;
float interval4 = 0;
float interval5 = 0;
float interval6 = 0;

int timeIntervalCount = 0;

int tempCount = 0;

//float myIntervals[4];


void setup() {
  Serial.begin(9600);

//displays
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(digit1Power, OUTPUT);
  pinMode(digit2Power, OUTPUT);
  pinMode(digit3Power, OUTPUT);
}

void loop() 
{
  delay(1);
  float myTemp = analogRead(PIEZO_PIN);
  firstDigit((BPM/ 1U) %10);
  delay(5);
  secondDigit((BPM/ 10U) %10);
  delay(5);
  thirdDigit((BPM/ 100U) %10);
  delay(5);
    
  if(analogRead(PIEZO_PIN) - myTemp > 10)
  {
    delay(100);
//    Serial.println(++tempCount);
    tempTime = millis();
    if(tempTime > 0)
    {
      count++;
      count = count%5;
      if(count == 0)
         time0 = tempTime;
      else if(count == 1)
         time1 = tempTime;
      else if(count == 2)
         time2 = tempTime;
      else if(count == 3)
         time3 = tempTime;
      else
         time4 = tempTime;
    }
    interval0 = abs(time1 - time0);
    interval1 = abs(time2 - time1);
    interval2 = abs(time3 - time2);
    interval3 = abs(time4 - time3);

    if(count == 2) 
    {
      float myIntervals[4] = {interval0, interval1,interval2,interval3};
//      finalTimeInterval = getFinalTimeInterval(myIntervals);       
      finalTimeInterval =( interval0+interval1 )/2;
      BPM = 60000/(finalTimeInterval);   

      if(BPM >200 && BPM <= 260 && count ==4)
      {
        finalTimeInterval = getFinalTimeInterval(myIntervals);
        BPM = 60000/(finalTimeInterval);
      }
      
     if(BPM > 260)
     {
        BPM = 999;
//         Serial.print("my BPM: " );
//         Serial.println(BPM);
     }
//     else
//     {
//      
//     }

    }
  }
}
void firstDigit(int x)
{
  digitalWrite(digit1Power,HIGH);
  digitalWrite(digit2Power,LOW);
  digitalWrite(digit3Power,LOW);
  switch(x)
  {
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      break;
  }
}

void secondDigit(int y)
{
  digitalWrite(digit1Power,LOW);
  digitalWrite(digit2Power,HIGH);
  digitalWrite(digit3Power,LOW);
  switch(y)
  {
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      break;
  }
}

void thirdDigit(int z)
{
  digitalWrite(digit1Power,LOW);
  digitalWrite(digit2Power,LOW);
  digitalWrite(digit3Power,HIGH);
  
  switch(z)
  {
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      break;
  }
}

//void countMethod(int count, int _tempTime)
//{
//  int tempCount = count%5;
//  int tempTime = _tempTime;
//  switch(tempCount)
//    case 0:
//      time0 = 
//    break;
//      
//  
//}

float getFinalTimeInterval(float intervals[])
{
 float result = intervals[0];
 for(int i = 1; i < 3; i++)
 {
   result = result + intervals[i];
 }

 result = result / 4;
 return result;
 
}
