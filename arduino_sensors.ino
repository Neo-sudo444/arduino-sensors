#include <SoftwareSerial.h>

// Definición de pines para comunicación serial
const int RX_PIN = 2;  // Pin digital 2 para RX
const int TX_PIN = 3;  // Pin digital 3 para TX

// Definición de pines para los sensores
const int TEMP_PIN = A0;
const int HUM_PIN = A1;
const int LIGHT_PIN = A2;

// Crear objeto SoftwareSerial
SoftwareSerial sensorSerial(RX_PIN, TX_PIN); // RX, TX

void setup() {
  // Iniciar comunicación serial por software
  sensorSerial.begin(9600);
  
  // Configurar pines como entrada
  pinMode(TEMP_PIN, INPUT);
  pinMode(HUM_PIN, INPUT);
  pinMode(LIGHT_PIN, INPUT);
  
  // Configurar pines TX/RX
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);
}

void loop() {
  // Leer valores de los sensores
  int tempValue = analogRead(TEMP_PIN);
  int humValue = analogRead(HUM_PIN);
  int lightValue = analogRead(LIGHT_PIN);
  
  // Enviar datos en formato CSV por el puerto serie por software
  sensorSerial.print(tempValue);
  sensorSerial.print(",");
  sensorSerial.print(humValue);
  sensorSerial.print(",");
  sensorSerial.println(lightValue);
  
  // Esperar 1 segundo antes de la siguiente lectura
  delay(1000);
}
