/**************************************************************************
  433Mhz RF Kumanda Kod Çözücü
  Dr.TRonik / YouTube / Ağustos / 2023 / İzmir / Türkiye
  WL101 RF MODUL, ST7735s TFT Ekran, Nano, Anten, Buzzer
  RCSwitch.h: https://github.com/sui77/rc-switch/
  YouTube: https://youtu.be/uTa1gNQ9SEU
 **************************************************************************/

/********************************************************************
  GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___
 ********************************************************************/
//ST7735
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>
//RF
#include <RCSwitch.h> // https://github.com/sui77/rc-switch/

//Arduino nano için pin bağlantıları - Pin Connections for nano
#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
//SCL D13
//SDA D11

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
RCSwitch mySwitch = RCSwitch();

#define buzzer_pin 4

/********************************************************************
  SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___
 ********************************************************************/
void setup(void) {
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2


  tft.initR(INITR_BLACKTAB);
  tft.setTextWrap(false);        // Allow text to run off right edge
  tft.fillScreen(ST77XX_BLACK);  // Ekranı temizlemek VE canvası siyah yapabilmek için
  tft.setRotation(3);            // 0_0°, 1_90°, 2_180°, 3_270° rotasyon...

  wait_text();
  buzzer();
}

/********************************************************************
  LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__
 ********************************************************************/
void loop() {

  if (mySwitch.available()) {
    decoder();
  }
}
/********************************************************************
  VOIDs__VOIDs__VOIDs__VOIDs__VOIDs__VOIDs__VOIDs__VOIDs__VOIDs__VOIDs
********************************************************************/
void wait_text() {
  tft.fillScreen(0);
  tft.setCursor(20, 20);
  tft.setTextColor(0xFFFF, 0x0000);  // Veriler değiştiğinde ekranda üst üste binmesini engeller...
  tft.setTextSize(2);
  tft.print("433Mhz. RF");
  tft.setCursor(10, 40);
  tft.print("CODE DECODER");
  tft.setTextColor(0xFFE0, 0x0000);
  tft.setCursor(10, 75);
  tft.print("Dr.TRonik");
  tft.setCursor(68, 95);
  tft.print("YouTube");
  delay(5000);
  tft.fillScreen(0);

  tft.setTextColor(0xF800, 0x0000);
  tft.setCursor(10, 15);
  tft.setTextSize(2);
  tft.print("433 Mhz.");
  tft.setCursor(10, 43);
  tft.setTextSize(3);
  tft.print("KOD");
  tft.setTextSize(2);
  tft.setCursor(10, 80);
  tft.print("BEKLENiYOR!");

  tft.setTextSize(2);
  tft.setTextColor(0x001F, 0x0000);
  tft.setCursor(5, 110);
  tft.print("((((...))))");
}

void decoder() {

  Serial.print("Received ");
  Serial.print(mySwitch.getReceivedValue());
  Serial.print(" / ");
  Serial.print(mySwitch.getReceivedBitlength());
  Serial.print("bit ");
  Serial.print("Protocol: ");
  Serial.println(mySwitch.getReceivedProtocol());
  Serial.println(mySwitch.getReceivedDelay());  

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(20, 0);
  tft.setTextColor(0xFFE0, 0x0000);  // Veriler değiştiğinde ekranda üst üste binmesini engeller...
  tft.setTextSize(2);
  tft.print("_ 433Mhz _");
  tft.setCursor(0, 0);
  tft.setCursor(0, 20);
  tft.print("Decoded: <<>>");
  buzzer();
  tft.setCursor(5, 40);
  tft.print("Kod:");
  tft.setCursor(5, 60);
  tft.print("Bit:");
  tft.setCursor(5, 80);
  tft.print("Protokol:");
  tft.setCursor(5, 100);
  tft.print("RDelay:");

  tft.setTextColor(0xFFFF, 0x0000);
  tft.setCursor(55, 40);
  tft.print(mySwitch.getReceivedValue());
  tft.setCursor(55, 60);
  tft.print(mySwitch.getReceivedBitlength());
  tft.setCursor(113, 80);
  tft.print(mySwitch.getReceivedProtocol());
  tft.setCursor(90, 100);
  tft.print(mySwitch.getReceivedDelay());

  tft.setTextColor(0xF81F, 0x0000);
  tft.setCursor(0, 121);
  tft.setTextSize(1);
  tft.print("Dr.TRonik <<<>>> YouTube");

  mySwitch.resetAvailable();  
}

void buzzer() {
  digitalWrite(buzzer_pin, HIGH);
  delay(50);
  digitalWrite(buzzer_pin, LOW);
}
/*
Color definitions for tft:
 #define BLACK 0x0000
 #define BLUE 0x001F
 #define RED 0xF800
 #define GREEN 0x07E0
 #define CYAN 0x07FF
 #define MAGENTA 0xF81F
 #define YELLOW 0xFFE0
 #define WHITE 0xFFFF

bilgi@ronaer.com
https://www.instagram.com/dr.tronik2023/   
YouTube: Dr.TRonik: www.youtube.com/c/DrTRonik
PCBWay: https://www.pcbway.com/project/member/shareproject/?bmbno=A0E12018-0BBC-4C

 */


