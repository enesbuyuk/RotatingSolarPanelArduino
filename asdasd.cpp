//YAPIMCI: ENESBUYUK.COM 
//GITHUB: Github.com/enesbuyuk

#include <Servo.h> // servo kütüphanesi için

Servo myservo;

#define ldr1 A0 // ldr a0 giriş pini
#define ldr2 A1 // ldr a1 giriş pini

int pos = 90; // Servo motorunun yatayda ilk konumu
int tolerance = 20; // tolerans ayarı bu sayede servo motoru sürekli hareket halinde değildir
   
void setup(){
    myservo.attach(2); // dijital pin üzerindeki servoyu yatay hareket servo motoruna bağlar
    pinMode(ldr1, INPUT); //doğu ldr pini ayarlar
    pinMode(ldr2, INPUT); //batı ldr pini ayarlar
    myservo.write(pos); //yatay hareket servo motorunun başlangıç konumunu yazdırır
    delay(1000); // hareket takibine başlamadan önce 1sn boyunca güneş panelinin başlangıç konumuna gelmesi için bekle
}

void loop(){      
    int val1 = analogRead(ldr1); // ldr1 değerini okur
    int val2 = analogRead(ldr2); // ldr2 değerini okur
          
    if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
    //eğer ldr değeri tolerans aralığında ise bir şey yapma
    }else {
        if(val1 > val2) // eğer ldr1, ldr2'den fazla ışık algılarsa
        {
            pos = pos+1; //yatay motorun 90 derecelik azaltır artırır ve doğuya doğru hareket eder
        }

        if(val1 < val2) // eğer ldr2, ldr1'den fazla ışık algılarsa
        {
            pos = pos-1; //yatay motorun 90 derecelik açısını artırır ve batıya doğru hareket eder
        }
    }
         
    if(pos > 180) {pos = 180;}  // eğer yatay açısı 180 dereceyi geçerse konumu varsayılan olarak 180'a götürür
    if(pos < 0) {pos = 0;} // eğer yatay açısı 0 dereceyi geçerse konumu varsayılan olarak 0'a götürür
    myservo.write(pos); // yatay motora başlangıç pozisyonu yazınız
    delay(50);
}
