#include <DHT.h>

#define DHTPIN1 2 // DHT11 sensor pin
#define DHTPIN2 3

const int LED1 = 25;
const int LED2 = 33;

DHT dht1(DHTPIN1, DHT11); // Initialize DHT11 sensors
DHT dht2(DHTPIN2, DHT11);

int num_people = 0; // Initialize counter variable

void setup() {
  Serial.begin(115200); // Start serial communication

  pinMode(TRIGGER_PIN1, OUTPUT); // Ultrasonic sensor pins as output
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  dht1.begin(); // Start DHT11 sensors
  dht2.begin();
}

void loop() {
  float temperature1 = dht1.readTemperature(); // Read temperature from DHT11 sensors
  float temperature2 = dht2.readTemperature();
  float average_temperature = (temperature1 + temperature2) / 2; // Calculate average temperature (assuming only 2 sensors)

  Serial.print("Average temperature: ");
  Serial.println(average_temperature);

  long duration1, distance1, duration2, distance2; // Variables for ultrasonic sensor

  digitalWrite(TRIGGER_PIN1, LOW); // Clear the trigger pin
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN1, HIGH); // Send a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH); // Measure the time for echo to return
  distance1 = duration1 / 58.2; // Convert time to distance (cm)

  digitalWrite(TRIGGER_PIN2, LOW); // Clear the trigger pin
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN2, HIGH); // Send a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH); // Measure the time for echo to return
  distance2 = duration2 / 58.2; // Convert time to distance (cm)

  if (distance1 < 100 && distance2 > 100) { // Person entering
    num_people++;
    Serial.print("Person entered the room. ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else if (distance2 < 100 && distance1 > 100) { // Person leaving
    if (num_people > 0) {
      num_people--;
      Serial.print("Person left the room. ");
    }
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }

  Serial.println(num_people);
  Serial.println(" people present in the room");
  delay(490);
}
