int trig = 10;    // trig pin 10
int echo = 9;      // echo pin 9
int led = 3;      // led pin 3
const int buzzer = 5;  // buzzer pin 5
int time;
int distance;

void setup()
{
  pinMode(trig, OUTPUT);  // trig as an output
  pinMode(echo, INPUT);    // echo as an input
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);     // Initialize serial communication (9600 bps)
}

void loop()
{
  digitalWrite(trig, HIGH);     // Generate the pulse to send
  delay(1);       
  digitalWrite(trig, LOW);    // Turn off trig
  time = pulseIn(echo, HIGH);  // Receive the pulse sent with trig and equalize it to the variable time
  distance = time / 58.2;    // Divide the time with the constant 58.2 and get the distance (cm)
  Serial.println(distance);    
  delay(100);       

  if (distance <= 30 && distance >= 0){ 
    digitalWrite(led, HIGH);      
    delay(distance * 10);      // Delay proportional to distance
    digitalWrite(led, LOW);
    analogWrite(buzzer, 150); 
    delay(100); 
    analogWrite(buzzer, LOW);
    }
}