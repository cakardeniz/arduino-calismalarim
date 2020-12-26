int trigPin = 13 ;
int echopin = 12;
int led = 10;
long sure;
long uzaklik;
int led_parlakligi=0;

void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  // Uzaklik Hesabi yapılmıştır.
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echopin,HIGH);
  uzaklik= sure/56.8;

 // Uzaklık 255 ten büyükse led kapatılır.
 // <255 ise led parlaklığı artırılır.
  if(uzaklik>255)
  {
    led_parlakligi=0;
 	analogWrite(led,led_parlakligi);
  }
  else
  {
    led_parlakligi=uzaklik; 
    led_parlakligi = 255-uzaklik;
    analogWrite(led,led_parlakligi);
  }
  

  // Uzaklık ve led parlaklıgı loglanır.
  Serial.print(uzaklik);
  Serial.println(" olarak olculmustur");
  delay(100);               
  Serial.print(led_parlakligi);
  Serial.println(" olarak olculmustur");

}
