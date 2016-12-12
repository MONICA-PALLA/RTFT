int  motor1 = 8;
int  motor11 = 9;
int  motor2 = 6;
int  motor22 = 7;
int matlabData;

void setup() 
{                
  pinMode(motor1, OUTPUT);     
  pinMode(motor11,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor22,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
      int j;
      if(Serial.available()>0)           
      {    
            matlabData=Serial.read(); 
          
            if(matlabData<230)
            {           
                 for(j=0; j<150; j++) 
               {
                 digitalWrite(motor1,HIGH);
                 digitalWrite(motor11, LOW);   
                 digitalWrite(motor2,LOW); 
                 digitalWrite(motor22,LOW);
               }
               delay(40);
           
                 for(j=0;j<50;j++)
               {
                 digitalWrite(motor1,HIGH);
                 digitalWrite(motor11, LOW);   
                 digitalWrite(motor2,HIGH); 
                 digitalWrite(motor22,LOW);
               }
            }
       
            else if(matlabData>250) 
              {  
                  for(j=0;j<150;j++) 
                 {
                   digitalWrite(motor1,LOW);
                   digitalWrite(motor11, LOW);   
                   digitalWrite(motor2,HIGH); 
                   digitalWrite(motor22,LOW);
                 }
                 delay(40);
             
                 for(j=0;j<50;j++)
                 {
                   digitalWrite(motor1,HIGH);
                   digitalWrite(motor11,LOW);   
                   digitalWrite(motor2,HIGH); 
                   digitalWrite(motor22,LOW);
                 }
     
              }
        
            else 
            {

              for(j=0;j<50;j++)
              {
                 digitalWrite(motor1,HIGH);
                 digitalWrite(motor11,LOW);   
                 digitalWrite(motor2,HIGH); 
                 digitalWrite(motor22,LOW);
               }
        
            }
         
       }                 

}
