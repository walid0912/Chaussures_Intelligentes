int vibration = 8;

int val =0;

//int valeur=3;

int buzzer3 = 7;

int number = '2' ;


void setup() {

   Serial.begin(9600);

  // put your setup code here, to run once:

//pinMode(buzzer3, OUTPUT);

 pinMode(vibration, INPUT);

 pinMode(buzzer3, OUTPUT);


}


void loop() {

  // put your main code here, to run repeatedly:

 val=digitalRead(vibration);

  

 //Serial.print(val); 

  if(val==LOW)

       {

           Serial.print(number);

           number = number + 1 ;

          digitalWrite(buzzer3, HIGH); 

           delay(500);

          digitalWrite(buzzer3, LOW);

           delay(500);

          digitalWrite(buzzer3, HIGH);

           delay(500);

          digitalWrite(buzzer3, LOW);

       }

     

      

    }   