int ch1; // 채널
int ch3; 
int ch6;

void setup() {

pinMode(2, INPUT);//오른
pinMode(4, INPUT);//왼
pinMode(6, INPUT);//오른쪽 위 채널6
pinMode(12, OUTPUT);//검은색 실린더
pinMode(13, OUTPUT);
pinMode(10, OUTPUT);//은색 실린더
pinMode(11, OUTPUT);
Serial.begin(9600);

digitalWrite(10,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(13,LOW);
ch1=0;
ch3=0;
ch6=0;
}

void loop() {

ch1 = pulseIn(2, HIGH, 25000); 
ch3 = pulseIn(4, HIGH, 25000); 
ch6 = pulseIn(6, HIGH, 25000); 

Serial.print("Channel 1:"); // Print the value of
Serial.println(ch1); // each channel

Serial.print("Channel 3:"); // Print the value of
Serial.println(ch3); // each channel

Serial.print("Channel 6:");
Serial.println(ch6);

Serial.println("");

if (ch1<=1300  && ch6<1000 && ch1>1)
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
}
else if (ch1>=1700 && ch6<1000 && ch1>1)
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
}

else if (ch1>=1350 && ch1<=1650 && ch1>1)
{
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
}

else if (ch1>=1700 && ch6>1000 && ch1>1)
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
}

else if (ch1<=1300 && ch6>1000 && ch1>1)
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
}

if (ch3>=1710 && ch3<=1880 && ch3>1)
{
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}

else if (ch3>=1890 && ch3<=1955&& ch3>1)
{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

else if (ch3>=1960 && ch3>1)
{
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
else if (ch3<1700 && ch3>1)
{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
delay(500);
}