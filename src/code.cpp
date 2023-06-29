/* code by 

Fajar Julyana

*/
#include <LedControl.h> //Library LedControl
// Atur pin 
const int NilaiUdara = 620;   //Konstanta maksimum nilai kelembaban udara
const int NilaiAir = 310;     //Konstanta maksimum air
int NilaisoilMoisture = 0;
int persentasesoilmoisture = 0;
// Atur pin sesuai dengan koneksi display matrix 8x8
const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;


// Inisialisasi objek LedControl
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

// Data untuk emote senyum dengan mata terbuka
byte senyumBukaMata[8] = {
  B00000000,
  B00100110,
  B01000110,
  B01000000,
  B01000000,
  B01000110,
  B00100110,
  B00000000
};

// Data untuk emote senyum dengan mata tertutup
byte senyumTutupMata[8] = {
    B00000000,
    B00100100,
    B01000100,
    B01000000,
    B01000000,
    B01000100,
    B00100100,
    B00000000
};

// Data untuk emote marah dengan mata tertutup
byte marahBukaMata[8] = {
  B00000000,
  B10000110,
  B01000110,
  B01000000,
  B01000000,
  B01000110,
  B10000110,
  B00000000
};

// Data untuk emote marah dengan mata tertutup
byte marahEyeClose[8] = {
  B00000000,
  B10000100,
  B01000100,
  B01000000,
  B01000000,
  B01000100,
  B10000100,
  B00000000
};


// Membuat Animasi Senyum Mata berkedip 
void senyum(){
  // Tampilkan emote senyum mata terbuka pada matriks LED
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, senyumBukaMata[row]);
  }

  delay(200);  // Jeda 0.2 detik
 // Tampilkan emote senyum mata tertutup pada matriks LED
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, senyumTutupMata[row]);
  }
  delay(150); // Jeda 0.15 detik
}

// Membuat Animasi Marah Mata Berkedip
void marah(){
  // Tampilkan emote marah mata terbuka pada matriks LED
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, marahBukaMata[row]);
  }

  delay(200);  // Jeda 0.2 detik
 // Tampilkan emote marah mata tertutup pada matriks LED
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, marahEyeClose[row]);
  }
  delay(150); // Jeda 0.15 detik
}
void setup() {
  lc.shutdown(0, false);  // Aktifkan chip
  lc.setIntensity(0, 0); // Atur intensitas cahaya matriks (0-15)
  lc.clearDisplay(0);    // Hapus tampilan matriks
}

void loop() {
NilaisoilMoisture = analogRead(A0);  //Deklarasi Pin Soil
persentasesoilmoisture = map(NilaisoilMoisture, NilaiUdara, NilaiAir, 0, 100);

//percabangan jika lebih besar dari 100 maka senyum, jika lebih besar dari 0 dan kurang dari 100 maka marah
if(persentasesoilmoisture >= 100)
{
  senyum();
}
else if(persentasesoilmoisture >0 && persentasesoilmoisture < 100)
{
  marah();
}
  delay(250); // jeda 0.25 detik
}
