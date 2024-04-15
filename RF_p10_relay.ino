/*
  433mHz RF ile röle kontrolü, basılan tuşun P10 üzerinde gösterilmesi
  Nisan/2024 Dr.TRonik/YouTube/İzmir
 */

/********************************************************************
  GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___
*********************************************************************/
//DMD P10Panel
#include "SPI.h"        //DMD kütüphanesi için gerekli https://github.com/PaulStoffregen/SPI
#include "DMD.h"        //https://github.com/ronaer/P10-Led-Tabela-RTC-DHT/blob/master/DMD-master.zip;
#include "TimerOne.h"   //https:github.com/PaulStoffregen/TimerOne
#include "angka6x13.h"  //DMD kütüphanesine dahil edilen font, sayı fontu
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 1  //Satırda
#define DISPLAYS_DOWN 1    // ve sütunda yeralacak P10 panel sayısı
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

//RF MODUL
#include <RCSwitch.h>            //https://github.com/sui77/rc-switch/
RCSwitch mySwitch = RCSwitch();  //Modül ismi mySwitch olarak oluşturuldu...

const int role_pin[8] = { A0, A1, A2, A3, A4, A5, 3, 4 }; //Röle pin dizi tanımı(SPI nedeni ile D10/D12 seçilmemeli)

int role_gecikme; //Röle pinleri arasında geçiş için gecikme süresi

void ScanDMD()  //P10 led tabela için tarama fonksiyonu
{
  dmd.scanDisplayBySPI();
}


/********************************************************************
  SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___
*********************************************************************/
void setup() {

  Timer1.initialize(2000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);

  //Röle kartımız low level! (LOW sinyalinde kontak çeker)
  for (int i = 0; i < 9; i++) {       // Röle pinlerinin tüm elemanları için
    pinMode(role_pin[i], OUTPUT);     // Röle pinleri çıkış pini olarak tanımlandı...
    digitalWrite(role_pin[i], HIGH);  // Röle pinleri başlangıçta çekmemesi için HIGH olacak şekilde tanımlandı...
  }

  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Kritik: 0.kesme pini => D2 (0.veya 1. kesme pinine bağlı değilse çalışmaz!)
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(1, 4, "HAZIR", 5, GRAPHICS_NORMAL);  // Hazır...
}

/********************************************************************
  LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__
*********************************************************************/
void loop() {
  //Serialden uygun 433mHz. uygun sinyal okuma
  if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print(mySwitch.getReceivedValue());
    Serial.print(" / ");
    Serial.print(mySwitch.getReceivedBitlength());
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println(mySwitch.getReceivedProtocol());

    role_gecikme = 300;

    if (mySwitch.getReceivedValue() == 13403240) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "1", 1, GRAPHICS_NORMAL);  // 1.tuş...
      digitalWrite(role_pin[0], LOW);                  //Röle dizimizin 0.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403236) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "2", 1, GRAPHICS_NORMAL);  // 2.tuş...
      digitalWrite(role_pin[1], LOW);                  //Röle dizimizin 1.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403244) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "3", 1, GRAPHICS_NORMAL);  // 3.tuş...
      digitalWrite(role_pin[2], LOW);                  //Röle dizimizin 2.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403234) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "4", 1, GRAPHICS_NORMAL);  // 4.tuş...
      digitalWrite(role_pin[3], LOW);                  //Röle dizimizin 3.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403242) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "5", 1, GRAPHICS_NORMAL);  // 5.tuş...
      digitalWrite(role_pin[4], LOW);                  //Röle dizimizin 4.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403238) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "6", 1, GRAPHICS_NORMAL);  // 6.tuş...
      digitalWrite(role_pin[5], LOW);                  //Röle dizimizin 5.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403246) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "7", 1, GRAPHICS_NORMAL);  // 7.tuş...
      digitalWrite(role_pin[6], LOW);                  //Röle dizimizin 6.elemanı...
      delay(role_gecikme);
    }
    if (mySwitch.getReceivedValue() == 13403233) {
      off();
      dmd.clearScreen(true);
      dmd.selectFont(angka6x13);
      dmd.drawString(13, 0, "8", 1, GRAPHICS_NORMAL);  // 8.tuş...
      digitalWrite(role_pin[7], LOW);                  //Röle dizimizin 7.elemanı...
      delay(role_gecikme);
    }
    //Röle dizimizin hepsini kapatabilmek için
    if (mySwitch.getReceivedValue() == 14478508) {
      dmd.clearScreen(true);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(9, 5, "OFF", 3, GRAPHICS_NORMAL);  // OFF...

      off();
    }
    mySwitch.resetAvailable();
  }
}

void off() {
  for (int i = 0; i < 9; i++) {
    digitalWrite(role_pin[i], HIGH);  //Röle dizimizin hepsini 80mS ara ile tek tuş ile kapatabilmek için...
  }
}

/*___:
bilgi@ronaer.com
https://www.instagram.com/dr.tronik2023/   
YouTube: Dr.TRonik: www.youtube.com/c/DrTRonik
PCBWay: https://www.pcbway.com/project/member/shareproject/?bmbno=A0E12018-0BBC-4C
*/
