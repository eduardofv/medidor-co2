/*
 * Primera prueba del medidor CO2, copy paste de 
 * https://javiergarciaescobedo.es/arduino/526-sensor-de-co2-mhz19-con-arduino
 * menos LCD
 */
 
#include <MHZ19.h>
#include <SoftwareSerial.h>

// Pin RX Arduino conectado al pin TX del MHZ19
#define RX_PIN 7
// Pin TX Arduino conectado al pin RX del MHZ19
#define TX_PIN 6

// Objeto para sensor MHZ19
MHZ19 myMHZ19;
// Serial requerido por el MHZ19
SoftwareSerial mySerial(RX_PIN, TX_PIN);

// Contador para temporizar las mediciones
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  myMHZ19.begin(mySerial);
  // Turn auto calibration ON (OFF autoCalibration(false))
  myMHZ19.autoCalibration();
}

void loop() {
  // Tomar mediciones cada 2 segundos
  if (millis() - timer >= 2000) {
    
    // Obtener la medición de CO2 actual como ppm
    int nivelCO2 = myMHZ19.getCO2();

    // Mostrar el nivel de CO2 en el monitor serie
    //Serial.print("CO2 (ppm): ");                      
    Serial.println(nivelCO2);  
  

    // Obtener la temperatura actual en grados Celsius
    int8_t temperatura = myMHZ19.getTemperature();

    //Serial.print("\t"); 
    // Mostrar la temperatura en el monitor serie
    //Serial.print("Temperatura (C): ");                  
    //Serial.println(temperatura);  

    // Almacenar una referencia al momento actual para controlar tiempo transcurrido
    timer = millis();
  }
}
