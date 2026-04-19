#define TERM A0
#define FOTO A1
#define POT A2
#define BUZZ 3

void setup()
{
  Serial.begin(9600);
  Serial.println("Privet!");
  
  pinMode(TERM, INPUT);
  pinMode(FOTO, INPUT);
  pinMode(POT, INPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() 
{
  int temp = analogRead(TERM);
  int light = analogRead(FOTO);
  int value = analogRead(POT);

  
 if(temp < 450)
 {
  Serial.println("Achtung!It's too hot!");
  Serial.println("Temperature:");
  Serial.println(temp);
  tone(BUZZ, 3000, 1000);
  delay(2000);
 }

 if(light > 400)
 {
  Serial.println("Night is coming!");
  Serial.println("Light:");
  Serial.println(light);
  tone(BUZZ, 4000, 1000);
  delay(2000);
 }

  if(value > 700)
  {
    Serial.println("Turn it off pls");
    Serial.println("Value:");
    Serial.println(value);
    tone(BUZZ, 3000, 1000);
    delay(2000);
  }
  
}
