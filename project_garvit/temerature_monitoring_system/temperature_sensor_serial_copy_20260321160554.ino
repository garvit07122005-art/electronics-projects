float temp_live = A0;
float potentiometer = A1;
float poten_temp;

void setup()
{
  pinMode(temp_live , INPUT);S
  pinMode(potentiometer , INPUT);  
  Serial.begin(9600);
}

void loop(){
  float temperature = analogRead(temp_live);
  float temp = map(temperature , 0 , 1023 , 0 , 100);
  float po_temp = analogRead(potentiometer);
  float poten_temp = map(po_temp , 0 , 1023 , 0 , 100);
  
  Serial.print("initializing : ");
  delay(500);
  if(temp>=poten_temp){
    Serial.print("alert !!! ");   
  }
  else{
    Serial.print("temp set : " );
    Serial.println(poten_temp);
    Serial.print("temp : " );
    Serial.println(temp);
  } 
}


