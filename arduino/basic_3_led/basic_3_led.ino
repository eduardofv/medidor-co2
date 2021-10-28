/*
   Medidor CO2 MHZ19C con 3 LEDs (Arduino Nano)

*/

#include <MHZ19.h>
#include <SoftwareSerial.h>

//Configuración sensor MHZ19C
//  Pin RX Arduino conectado al pin TX del MHZ19
const int sensorRXpin = 7;
//  Pin TX Arduino conectado al pin RX del MHZ19
const int sensorTXpin = 6;
//  Objeto para sensor MHZ19
MHZ19 sensorCO2;
//  Puerto Serial de comunicacion con el MHZ19
SoftwareSerial puertoSerial(sensorRXpin, sensorTXpin);
//  Desactivar los mensajes de error al puerto serial del MHZ19
//  Dejarlo habilitado genera errores en cuando se conecta a algunos
//  cargadores USB
#define MHZ19_ERRORS 0

//Configuración de LEDs
//  LED nivel CO2 bueno (Verde)
const int ledBuenoPin = 2;
//  LED nivel CO2 regular (Amarillo)
const int ledRegularPin = 3;
//  LED nivel CO2 malo (Rojo)
const int ledMaloPin = 4;

//Configuración de niveles de CO2 para alertas
//  Nivel máximo para considerarlo bueno
const int maximoBueno = 700;
//    Nivel máximo para considerarlo regular
const int maximoRegular = 1000;
//    Cualquier valor por arriba, es malo

//Estas constantes nos ayudan a hacer mas claro el codigo
#define APAGADO 0
#define BUENO 1
#define REGULAR 2
#define MALO 3

//Definir el periodo de espera entre lecturas del sensor
//  si no, lo haria excesivamente rapido para el sensor (milisegundos)
const int periodoEspera = 2000;


//Encender los LEDs que correspondan al nivel
void mostrarNivel(int level) {
  //Apagar todos los pines
  digitalWrite(ledBuenoPin, LOW);
  digitalWrite(ledRegularPin, LOW);
  digitalWrite(ledMaloPin, LOW);

  switch (level) {
    case BUENO:
      digitalWrite(ledBuenoPin, HIGH);
      break;
    case REGULAR:
      digitalWrite(ledRegularPin, HIGH);
      break;
    case MALO:
      digitalWrite(ledMaloPin, HIGH);
      break;
  }
}


//Inicialización de componentes
void setup() {
  //Inicializar comunicacion a traves del USB con la computadora
  Serial.begin(9600);
  //Inicializar el puerto serial para conectar el sensor
  puertoSerial.begin(9600);

  //Asignar puerto serial al sensor
  sensorCO2.begin(puertoSerial);

  //Activar autocalibración (ver hoja de datos del sensor)
  sensorCO2.autoCalibration();

  //Inicializar pins para los LEDs
  pinMode(ledBuenoPin, OUTPUT);
  pinMode(ledRegularPin, OUTPUT);
  pinMode(ledMaloPin, OUTPUT);

  //Empezar con los LEDs apagados
  mostrarNivel(APAGADO);
}


//Ciclo iterativo
void loop() {

  //Leer el sensor de CO2
  int lecturaCO2 = sensorCO2.getCO2();
  //Mandar la lectura al USB
  Serial.println(lecturaCO2);

  //Determinar el nivel de CO2
  //  Si el nivel leido es cero es que hubo algún error, apagar los LEDs
  int nivelCO2 = APAGADO;
  if (lecturaCO2 <= maximoBueno) {
    nivelCO2 = BUENO;
  }
  else if (lecturaCO2 <= maximoRegular) {
    nivelCO2 = REGULAR;
  }
  else {
    nivelCO2 = MALO;
  }

  //Encender los LEDs que correspondan al nivel
  mostrarNivel(nivelCO2);

  //Esperar un tiempo antes de siguiente lectura
  delay(periodoEspera);
}
