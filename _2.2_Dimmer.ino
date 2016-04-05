//Arduino Básico
//Dimmer con led y potenciometro

const int sensor = A0;  // Analog input pin that the potentiometer is attached to
const int led2 = 9; // Analog output pin that the LED is attached to

int valorSensor = 0;        // valor leido del pot
int valorSalida = 0;        // valor PWM

void setup() {
  // inicializa la comunicación serial a 9600 bps:
  Serial.begin(9600);
}

void loop() {
  //lectura de puerto analog
  valorSensor = analogRead(sensor);
  valorSalida = map(valorSensor, 0, 1023, 0, 255); //limita el rango entre 0-255 para PWM
  analogWrite(led2, valorSalida); //asigna valor de salida al pin 8 (led1)

  // Imprime los resultados en el monitor
  Serial.print("sensor = " );
  Serial.print(valorSensor);
  Serial.print("\t PWM = ");
  Serial.println(valorSalida);

  delay(100);//espera para proxima lectura
}
