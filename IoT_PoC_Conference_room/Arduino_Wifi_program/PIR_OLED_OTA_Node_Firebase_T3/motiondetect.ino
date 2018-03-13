void Motiondetect()
{
if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state       
       obj = true;
    objval = 1;
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         int stsec = millis()/1000;
           Firebase.setString("PIR_Sensor Status", "Motion started at "+ String(stsec) +" sec");
           display.clearDisplay();
      display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
      display.print("motion detected at ");
         display.print(millis()/1000);
         display.println(" sec");
      display.display();
      delay(500);
      display.clearDisplay();
         delay(100);
         Serial.println("");
         
}
  else {
    Serial.println("No Motion");
      display.clearDisplay();
      display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
      display.println("no Motion");
      display.display();
    obj = false;
    objval = 0;
    digitalWrite(led, LOW);  //the led visualizes the sensors output pin state              
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
 int endsec = (millis() - pause)/1000;
           Firebase.setString("PIR_Sensor Status", "Motion ended at "+ String(endsec) +" sec");
      display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
     display.print("motion ended at ");      //output
           display.print((millis() - pause)/1000);
           display.println(" sec");
      display.display();
      delay(500);
      display.clearDisplay();
         }
       }
