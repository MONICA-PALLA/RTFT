int motor1 = 8;              //rigth motors
int motor11 = 9;
int motor2 = 6;              //left motors
int motor22 = 7;
int data,matlabData;

void setup() {
  Serial.begin(9600);

pinMode(motor1,OUTPUT);
  pinMode(motor11,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor22,OUTPUT);
}
    
void loop(){
  int k;
  if(Serial.available()>0)
  {  
     matlabData=Serial.read();
    Serial.println(matlabData);
    if(matlabData<230)
    {
        data = matlabData/10;

       digitalWrite(motor1,HIGH); 
        digitalWrite(motor11,LOW); 
         digitalWrite(motor2,LOW); 
          digitalWrite(motor22,LOW);        
        }
        
    //}

    // if(matlabData>250)
    //{
        data = matlabData/10;
      for(int k =0;k<data;k++)
      {
       digitalWrite(motor1,LOW); 
        digitalWrite(motor11,LOW); 
         digitalWrite(motor2,HIGH); 
          digitalWrite(motor22,LOW);        
        }
      
 //   }
  
 } //2

}
