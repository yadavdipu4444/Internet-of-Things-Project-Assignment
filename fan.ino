int A;
void setup(){
  pinMode(13, OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop(){
  A = analogRead(A1);
  Serial.println(A);
  delay(1000);

  if (A >= 160)
  {
    digitalWrite(13,1);
    }

  else if (A <= 145)
  {
    digitalWrite(13,0);
    }
 
  else
  {
    digitalWrite(13,0);
    }
}
