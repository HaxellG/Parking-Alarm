int TRIG = 10;    // TRIG pin 10
int ECHO = 9;      // ECHO pin 9
int LED = 3;      // LED  pin 3
const int Buzzer = 5;  // BUZZER pin 5
int TIEMPO;
int DISTANCIA;
void setup()
{
  pinMode(TRIG, OUTPUT);  // TRIG como salida
  pinMode(ECHO, INPUT);    // ECHO como entrada
  pinMode(LED, OUTPUT);   // LED como salida
  pinMode(Buzzer, OUTPUT);   // BUZZER como salida
  Serial.begin(9600);     // inicializacion de comunicacion serial a 9600 bps
}

void loop()
{
  digitalWrite(TRIG, HIGH);     // generamos el pulso a enviar
  delay(1);       // Esperamos un milisegundo
  digitalWrite(TRIG, LOW);    // y lo apagamos
  TIEMPO = pulseIn(ECHO, HIGH);  // recibimos el pulso enviado con trig y lo igualamoms a la variable TIEMPO
  DISTANCIA = TIEMPO / 58.2;    // lo dividimos entre la constante 58.2 y optenemos la distancia en centimetros
  Serial.println(DISTANCIA);    // envio de valor de distancia por monitor serial
  delay(100);       // demora entre datos
  if (DISTANCIA <= 30 && DISTANCIA >= 0){ // si distancia entre 0 y 30 cms.
    digitalWrite(LED, HIGH);      // encender el LED
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    digitalWrite(LED, LOW);     // apaga LED
    analogWrite(Buzzer, 150); // brillo del LED proporcional al giro del potenciometro
    delay(100); 
    analogWrite(Buzzer, LOW);
    }
}
