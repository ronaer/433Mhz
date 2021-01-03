/*
  Simple example for receiving  
  https://github.com/sui77/rc-switch/
  Dr.TRonik -> YouTube tarafından 8 Kanallı röle kartı ve RF kumanda için modifie edilmiştir...
  Açık kaynak dahilinde kişisel olarak kullanılabilir, dağıtılabilir, kopylalanabilir...
  İlgili kütüphane kısıtlamalarına tabidir...
 */

#include <RCSwitch.h>//Kütüphanemiz dahil edildi...
RCSwitch mySwitch = RCSwitch();//Modülümüzün ismi mySwitch oldu...

const int role_pin[8] = {12,11,10,9,8,7,6,5}; //Röle pinleri sabit integer değişkenlerine dizi olarak atandı...
int role_gecikme;

//___SET UP___
void setup() {
  
  for(int i=0; i<9; i++){          //Dizinin tüm elemanları
  pinMode(role_pin[i], OUTPUT);    //Çıkış  ve 
  digitalWrite(role_pin[i], HIGH); // HIGH olacak şekilde tanımlandı...
  }
   
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

//__LOOP___
void loop() {
  if (mySwitch.available()) {    
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );
    
role_gecikme=300;

if(mySwitch.getReceivedValue()== 14478497) 
{
    digitalWrite(role_pin[0], !digitalRead(role_pin[0]));//Röle dizimizin 0.elemanı D12.pin... Toogle olarak çalışabilmesi için
    delay(role_gecikme);
}
if(mySwitch.getReceivedValue()== 14478498)
{
  digitalWrite(role_pin[1], !digitalRead(role_pin[1]));//Röle dizimizin 1.elemanı D11.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
}
if(mySwitch.getReceivedValue()== 14478499)
{
  digitalWrite(role_pin[2], !digitalRead(role_pin[2]));//Röle dizimizin 2.elemanı D10.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
if(mySwitch.getReceivedValue()== 14478500)
{
  digitalWrite(role_pin[3], !digitalRead(role_pin[3]));//Röle dizimizin 3.elemanı D9.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
if(mySwitch.getReceivedValue()== 14478501)
{
  digitalWrite(role_pin[4], !digitalRead(role_pin[4]));//Röle dizimizin 4.elemanı D8.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
if(mySwitch.getReceivedValue()== 14478502)
{
  digitalWrite(role_pin[5], !digitalRead(role_pin[5]));//Röle dizimizin 5.elemanı D7.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
if(mySwitch.getReceivedValue()== 14478503)
{
  digitalWrite(role_pin[6], !digitalRead(role_pin[6]));//Röle dizimizin 6.elemanı D6.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
if(mySwitch.getReceivedValue()== 14478504)
{
  digitalWrite(role_pin[7], !digitalRead(role_pin[7]));//Röle dizimizin 7.elemanı D5.pin... Toogle olarak çalışabilmesi için
   delay(role_gecikme);
} 
//Röle dizimizin hepsini kapatabilmek için   
if(mySwitch.getReceivedValue()== 14478508)
{
  for(int i=0; i<9; i++){
  digitalWrite(role_pin[i], HIGH);//Röle dizimizin hepsini 80mS ara ile tek tuş ile kapatabilmek için...
   delay(40);
} 
delay(role_gecikme);   
}  

//Röle dizimizin hepsini açabilmek için   
if(mySwitch.getReceivedValue()== 14478507)
{
  for(int i=0; i<9; i++){
  digitalWrite(role_pin[i], LOW);//Röle dizimizin hepsini 80mS ara ile tek tuş ile açabilmek için...
   delay(40);
} 
delay(role_gecikme);   
}  
if(mySwitch.getReceivedValue()== 14478505) 
{
    digitalWrite(role_pin[0], !digitalRead(role_pin[0]));//Röle dizimizin 0.elemanı D12.pin... Toogle olarak çalışabilmesi için
    digitalWrite(role_pin[1], !digitalRead(role_pin[1]));//Röle dizimizin 1.elemanı D11.pin... Toogle olarak çalışabilmesi için
    delay(role_gecikme);
}
if(mySwitch.getReceivedValue()== 14478506) 
{
    digitalWrite(role_pin[0], !digitalRead(role_pin[0]));//Röle dizimizin 0.elemanı D12.pin... Toogle olarak çalışabilmesi için
    digitalWrite(role_pin[2], !digitalRead(role_pin[2]));//Röle dizimizin 2.elemanı D10.pin... Toogle olarak çalışabilmesi için
    delay(role_gecikme);
}
    
    mySwitch.resetAvailable();
  }
   
}
//DR.TRonik >>> YouTube>>> https://www.youtube.com/channel/UCrDlm8ldOOh5cG5prINb77w
