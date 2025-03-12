// Definición de pines para los sensores
const int TEMP_PIN = A0;
const int HUM_PIN = A1;
const int LIGHT_PIN = A2;

void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
  
  // Configurar pines como entrada
  pinMode(TEMP_PIN, INPUT);
  pinMode(HUM_PIN, INPUT);
  pinMode(LIGHT_PIN, INPUT);
}

void loop() {
  // Leer valores de los sensores
  int tempValue = analogRead(TEMP_PIN);
  int humValue = analogRead(HUM_PIN);
  int lightValue = analogRead(LIGHT_PIN);
  
  // Enviar datos en formato CSV
  Serial.print(tempValue);
  Serial.print(",");
  Serial.print(humValue);
  Serial.print(",");
  Serial.println(lightValue);
  
  // Esperar 1 segundo antes de la siguiente lectura
  delay(1000);
}
