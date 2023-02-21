int ch1; // ตัวแปรของ channel

void setup() {
pinMode(2,OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(5, INPUT);
pinMode(13,OUTPUT);
pinMode(7,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
ch1 = pulseIn(5, HIGH, 25000);
Serial.print("Channel 1:"); // Print the value of
Serial.println(ch1); // each channel
Serial.println("");

if (digitalRead(7) == LOW && ch1<=1300)
{
  digitalWrite(10, LOW);
}
else if(digitalRead(6) == LOW && ch1>=1700)
{
  digitalWrite(10, LOW);
}
else if (ch1<=1300)
{
  digitalWrite(2,HIGH);
  digitalWrite(13,HIGH); 
  digitalWrite(8,HIGH);  //모터준비
  digitalWrite(9,HIGH);  //스타트 스톱
  digitalWrite(10,HIGH); //그라운드
  digitalWrite(7,HIGH);  //방향전환
}
else if (ch1>=1700)
{
  digitalWrite(2,LOW);
  digitalWrite(8,HIGH); 
  digitalWrite(13,LOW); 
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(7,LOW);
}
else if (ch1>=1400 && ch1<=1650)
{
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(7,HIGH);
  }
}




