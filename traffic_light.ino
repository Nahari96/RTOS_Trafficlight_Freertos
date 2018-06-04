//pastikan kalian sudah menginstal Arduino IDE dan library FreeRTOS sebelumnya
//copy code ini ke Arduino IDE yang sudah terinstal

#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 13, d4 = 18, d5 = 19, d6 = 20, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void simpangA( void *pvParameters );

void setup() {
  xTaskCreate(simpangA,(const portCHAR *)"Blink", 128, NULL, 1, NULL);
  lcd.begin(16,2);
}

void loop()
{
}

void simpangA(void *pvParameters) //deklarasi kelengkapan task
{
  (void) pvParameters;

  //inisialisasi port
  pinMode(0, OUTPUT); //lampu merah
  pinMode(1, OUTPUT); //lampu kuning
  pinMode(2, OUTPUT); //lampu ijo
  pinMode(3, OUTPUT); //lampu merah
  pinMode(4, OUTPUT); //lampu kuning
  pinMode(5, OUTPUT); //lampu ijo
  pinMode(6, OUTPUT); //lampu merah
  pinMode(7, OUTPUT); //lampu kuning
  pinMode(8, OUTPUT); //lampu ijo
  pinMode(9, OUTPUT); //lampu merah
  pinMode(10, OUTPUT); //lampu kuning
  pinMode(11, OUTPUT); //lampu ijo

  for (;;) //perulangan, biar ga keluar
  {
    //LAMPU IJO SIMPANG A DAN C, LAMPU MERAH SIMPANG B DAN D
    //A
    digitalWrite(0, LOW);  
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Walk A&C");
    lcd.setCursor(0,0);
    lcd.print("Stop B&D");
    lcd.display();
    
    //C
    digitalWrite(6, LOW);  
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);

    //B
    digitalWrite(3, HIGH);  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    //D
    digitalWrite(9, HIGH);  
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    
    vTaskDelay( 5000 / portTICK_PERIOD_MS );
    lcd.noDisplay();
    
    
    //KUNING DI SEMUA SIMPANG
    //A
    digitalWrite(0, LOW);  
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Ready!!!");
    lcd.setCursor(0,0);
    lcd.print("Ready!!!");
    lcd.display();
    
    //C
    digitalWrite(6, LOW);  
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);

    //B
    digitalWrite(3, HIGH);  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    //D
    digitalWrite(9, HIGH);  
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    lcd.noDisplay();

    //MERAH DI A DAN C, IJO DI B DAN D
    //A
    digitalWrite(0, HIGH); 
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    lcd.setCursor(0,1);
    lcd.print("Walk B&D");
    lcd.setCursor(0,0);
    lcd.print("Stop A&C");
    lcd.display();

    //C
    digitalWrite(6, HIGH);  
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    
    //B
    digitalWrite(3, LOW);  
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    //D
    digitalWrite(9, LOW);  
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    
    vTaskDelay( 5000 / portTICK_PERIOD_MS );
    lcd.noDisplay();
    
    //KUNING DI SEMUA SIMPANG
    //A
    digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    lcd.setCursor(0,1);
    lcd.print("Ready!!!");
    lcd.setCursor(0,0);
    lcd.print("Ready!!!");
    lcd.display();
    
    //C
    digitalWrite(6, HIGH);  
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    
    //B
    digitalWrite(3, LOW);  
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    //D
    digitalWrite(9, LOW);  
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    lcd.noDisplay();
  }
}

//author : Muhammad Rizki. Semarang, 4 Juni 2018
