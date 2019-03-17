// Outputs (###### Remeber to assign appropriate pins ######)
#define DIR_1 7 // Direction pin for left motor (Use digital pin)
#define DIR_2 4 // Direction pin for right motor (Use digital pin)
#define PWM_1 6 // PWM pin for left motor (Use analog pin)
#define PWM_2 3 // PWM pin for right motor (Use analog pin)

// Inputs (###### Remeber to assign appropriate pins ######)
  int rc_channel_1 = 3; // Steering input from receiver (Use pwm pin) 
  int rc_channel_2 = 5; // Throttle input from receiver (Use pwm pin)

void setup() {
  // Declare pins as INPUT/OUTPUT
  pinMode(rc_channel_1, INPUT);
  pinMode(rc_channel_2, INPUT);
  pinMode(DIR_1, OUTPUT);
  pinMode(DIR_2, OUTPUT);
  pinMode(PWM_1, OUTPUT);
  pinMode(PWM_2, OUTPUT);
  Serial.begin(9600);// Using Serial Monitor as display
}

void loop() {
  // Code that runs repeatedly
  int pwm = 0;// Placeholder PWM variable 
  int rc1= pulseIn(rc_channel_1, HIGH, 25000);
  int rc2 = pulseIn(rc_channel_2, HIGH, 25000);
  
  Serial.print("Channel 1 Values: ");
  Serial.print(rc1);
  Serial.print("Channel 2 Values: ");
  Serial.print(rc2);
  
  // Throttle begins

  if(rc2==0){ // If no value is received from the receiver then output nothing
      Serial.println(" no signal");
      analogWrite(PWM_1, 0);
      analogWrite(PWM_2, 0);
  }
  else if(rc2> 1530){ //Forward
      pwm = map(rc2, 1530, 2000, 0, 255); //map our speed to 0-255 range
      digitalWrite(DIR_1, LOW); // Direction of motor(To change rotation change from HIGH-LOW or vise versa)
      digitalWrite(DIR_2, LOW); // Direction of motor
      analogWrite(PWM_1, pwm); // PWM value output for motor
      analogWrite(PWM_2, pwm); // PWM value output for motor
      Serial.print("Forward Speed: ");
      Serial.println(pwm);    
  }
  else if(rc2< 1460){ //Reverse
      pwm = map(rc2, 1460, 1000, 0, 255); //map our speed to 0-255 range
      digitalWrite(DIR_1, HIGH); // Direction of motor
      digitalWrite(DIR_2, HIGH); // Direction of motor
      analogWrite(PWM_1,(255-pwm)); // PWM value output for motor
      analogWrite(PWM_2,(255-pwm)); // PWM value output for motor
      //analogWrite(PWM_1, pwm); // PWM value output for motor
      //analogWrite(PWM_2, pwm); // PWM value output for motor    
      Serial.print("Reverse Speed: ");
      Serial.println(pwm); 
  }else{// If no value is received from the receiver then output nothing
      Serial.println("Throttle centered");
      analogWrite(PWM_1, 0);
      analogWrite(PWM_2, 0); 
  }



  // Steering begins

  if(rc1==0){ // If no value is received from the receiver then output nothing
      Serial.println(" no signal");
      analogWrite(PWM_1, 0);
      analogWrite(PWM_2, 0);
  }
  else if(rc1> 1520){ //Left
      pwm = map(rc1, 1520, 2000, 0, 255); //map our speed to 0-255 range
      digitalWrite(DIR_1, LOW); // Direction of motor
      digitalWrite(DIR_2, HIGH); // Direction of motor
      analogWrite(PWM_1, pwm); // PWM value output for motor
      analogWrite(PWM_2, pwm); // PWM value output for motor
      Serial.print("Left Speed: ");
      Serial.println(pwm);
  }
  else if(rc1< 1440){ //Right
      pwm = map(rc1, 1440, 1000, 0, 255); //map our speed to 0-255 range
      digitalWrite(DIR_1, HIGH); // Direction of motor
      digitalWrite(DIR_2, LOW); // Direction of motor
      analogWrite(PWM_1, pwm); // PWM value output for motor
      analogWrite(PWM_2, pwm); // PWM value output for motor
      Serial.print("Right Speed: ");
      Serial.println(pwm);
  }else{// If no value is received from the receiver then output nothing
      Serial.println("Steering centered");
      analogWrite(PWM_1, 0);
      analogWrite(PWM_2, 0);
  }
  delay(10); // Just a tiny delay to keep things in order
}
