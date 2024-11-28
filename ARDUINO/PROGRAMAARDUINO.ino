/*
  Capitulo 61 de Arduino desde cero en Español.
  Visualizacion por monitor serie de las lecturas del sensor de color
  TCS3200 en microsegundos e intercalando texto al detectar colores
  rojo, verde y azul en base a rango de valores obtenido del programa 1.

  https://www.youtube.com/c/BitwiseAr
  Autor: bitwiseAr  
  Modificado
*/



#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

// Pines de salida digital para cada color
#define rojoPin 9    // Salida digital para rojo
#define celestePin 10  // Salida digital para amarillo
#define verdePin 11   // Salida digital para azul


void setup() {
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como entrada

  // Configuración de los pines de salida digital
  pinMode(rojoPin, OUTPUT);    // Salida para ROJO
  pinMode(celestePin, OUTPUT);  // Salida para AMARILLO
  pinMode(verdePin, OUTPUT);   // Salida para AZUL

  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(115200);   // inicializa monitor serie a 9600 bps
}

void loop() {
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,LOW);     // con filtro rojo
  int R = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,HIGH);    // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro verde
  int G = pulseIn(salidaTCS, LOW);  // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro azul
  int B = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  Serial.print("R:");     // muestra texto
  Serial.print(R);     // muestra valor de variable rojo

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("G:");     // muestra texto
  Serial.print(G);      // muestra valor de variable verde

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("B:");     // muestra texto
  Serial.println(B);     // muestra valor de variable azul
            // y salto de linea

  // Apagamos todas las salidas por defecto
  digitalWrite(rojoPin, LOW);
  
  digitalWrite(celestePin, LOW);
  digitalWrite(verdePin, LOW);

  
  if (R < 100 && G > 130 && B > 100){   // Si valores dentro del rango para ROJO
    Serial.println("ROJO");
    digitalWrite(rojoPin, HIGH);  // Activa la salida para ROJO
    delay(2000); // Mantiene el LED encendido durante 3 segundos
    digitalWrite(rojoPin, LOW); // Apaga el LED
  } 
  else if (R > 90 && R < 130 && G > 55 && G < 70 && B > 30 && B < 50) {
    Serial.println("CELESTE");
    digitalWrite(celestePin, HIGH);  // Activa la salida para AMARILLO
    delay(2000); // Mantiene el LED encendido durante 3 segundos
    digitalWrite(celestePin, LOW); // Apaga el LED
  }
  else if (R > 100 && R < 160 && G > 90 && G < 120 && B > 100 && B < 130){  // Si valores dentro del rango para AZUL
    Serial.println("VERDE");
    digitalWrite(verdePin, HIGH);  // Activa la salida para AZUL
    delay(2000); // Mantiene el LED encendido durante 3 segundos
    digitalWrite(verdePin, LOW); // Apaga el LED
  }

}
