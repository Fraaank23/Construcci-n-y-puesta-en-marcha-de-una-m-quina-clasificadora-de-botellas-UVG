

/*
  Capitulo 61 de Arduino desde cero en Español.
  Visualizacion por monitor serie de las lecturas del sensor de color
  TCS3200 en microsegundos e intercalando texto al detectar colores
  rojo, verde y azul en base a rango de valores obtenido del programa 1.

  https://www.youtube.com/c/BitwiseAr
  Autor: bitwiseAr  

*/

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8


void setup() {
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
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
  
  if ( R < 150 && G > 270 && B > 60){   // si valores dentro del rango
    Serial.println("ROJO");       // muestra texto
  } 
  
  else if (R > 18 && R < 50 && G > 20 && G < 50 && B > 50 && B < 70) {
    Serial.println("AMARILLO");    // muestra texto
  }
  else if (R > 200 && R < 220 && G > 120 && G < 150 && B > 50 && B < 70){  // si valores dentrol del rango
    Serial.println("AZUL");       // muestra texto
  
  }
    else if ( G < 300 && R > 300 && B > 80){  // si valores dentro del rango
    Serial.println("VERDE");        // muestra texto
  }
    
  else if ( B > 300 && R > 250 && G > 380){  // si valores dentrol del rango
    Serial.println("NEGRO");       // muestra texto
  }

}
