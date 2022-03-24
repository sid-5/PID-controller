#include <Servo.h>


const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;

int Analog_in = A0;
int Read = 0;
float distance = 0.0;
float elapsedTime, timee, timePrev;        //Variables for time control
float distance_previous_error=0, distance_error;
int period = 50;  //Refresh rate period of the loop is 50ms

float kp=10; //10
float ki=0.2; 
float kd=1000;  //3100
float distance_setpoint = 13;           //Should be the distance from sensor to the middle of the bar in cm
float PID_p, PID_i, PID_d, PID_total, PID_val;

Servo myservo;  //attatched to D6


void setup() {
  //analogReference(EXTERNAL);
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object  
  timee = millis();
}

void loop() {
  if (millis() > timee+period)
  {
    timee = millis();    
//    distance = get_dist();  
    distance = get_distt(); //for Sharp IR 
    Serial.println("Distance:");
    Serial.println(distance);
    distance_error = distance_setpoint - distance; 
//    Serial.println(distance_error);
    PID_p = kp * distance_error;
//    Serial.println(PID_p);
    float dist_difference = distance_error - distance_previous_error;     
    PID_d = kd*((dist_difference)/period);
//    Serial.println(PID_d);  
    if(-4 < distance_error && distance_error < 4)
    {
      PID_i = PID_i + (ki * distance_error);
    }
    else
    {
      PID_i = 0;
    }
//  Serial.println(PID_i);
    PID_total = PID_p + PID_i + PID_d;  
     
   // Serial.println("PID_total prev");
//    Serial.println(PID_total);

   
    
    //PID_val = -PID_val;
    PID_val = map(PID_total, -140, 40, 100, 10);
    
//    Serial.println("PID_total");
//    Serial.println(PID_total);
//    Serial.println("PID_val");
//    Serial.print("PID_val");
//    Serial.println(PID_val);
    myservo.write(PID_val);  
    distance_previous_error = distance_error;
  }
}



//For SHARP IR SENSOR
float get_distt()
{
float volts = analogRead(Analog_in)*0.0048828125;  // value from sensor * (5/1024)
//  Serial.println(volts);
  float distance = 13*pow(volts, -1); 
  return distance;
}

float get_dist(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
