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

  
   if(Serial.available() > 0) //Проверяем, пришла ли команда.
  {
   char cmd = Serial.read(); //Объявим переменную, в которую будем запоминать команду.

   //Чтобы услышать звук - зажми термистор пальцами.Одновременно отправь команду
   if (cmd == 'T' || cmd == 't')      //Если пришла команда "Termistor mode"
    {
      Serial.println( temp);  
      
      if(temp < 450)  //Включаем режим термистора.          
          {
            tone(BUZZ, 3000, 1000);  
            delay(600);
          }
     }
      
      //Чтобы услышать звук- закрой фоторезистор рукой.Одновременно отправь команду
      if (cmd == 'f' || cmd == 'F')     //Если пришла команда "Fotorezistor mode"
      {
        Serial.println(light);
         if(light > 400)                //Включаем режим фоторезистора
           {
            
             tone(BUZZ, 4000, 1000);  
             delay(600);
           }
    
      }

      //Чтобы услышать звук выкрути термистор до значения больше 700 и отправь команду.
      if( cmd == 'p' || cmd == 'P')     //Если пришла команда "Potentiometr mode"
      {  
        Serial.println(value);         //Включаем режим потенциометра.
         if( value > 700)
          {
            tone(BUZZ, 5000, 1000);  
            delay(600);
          }
      }
          
  }  
}
 


