//Lire les données via bluetooth et afficher le niveau d'eau dans l'afficheur LCD


const int echoPin1 = 4; // Echo Pin de capteur ultrason(haut)

const int pingPin1 = 5; // Trigger Pin de capteur ultrason(haut)


const int echoPin = 10; // Echo Pin de capteur ultrason(bas)

const int pingPin = 9; // Echo Pin de capteur ultrason(bas)

int oldvalue = 0 ; 

int newvalue = 0;

int oldvalue1 = 0 ; 

int newvalue1 = 0;

int valeur = '2' ;




/*#include <LiquidCrystal.h>

//initialise the library with the numbers of the interface pins 

LiquidCrystal lcd(7, 6, 5, 4,3, 2); */

 

int resval = 0;  // holds the value

int respin = A3; // sensor pin used


int buzzer2 = 12;

int buzzer1 = 13;

int buzzer4 = 2;

int buzzer5 = 7;

//int led1 = 11;

//int led2 = 12;

//int led3 = 13;

//int led4 = 18;

                  

void setup() 

{

   // set up the LCD's number of columns and rows: 

  /*lcd.begin(16, 2); 

  

  // Print a message to the LCD. 

  lcd.print("  WATER LEVEL : ");*/ 

  

  Serial.begin(9600); // Starting Serial Communication

  pinMode(pingPin, OUTPUT); // initialising pin 3 as output

  pinMode(echoPin, INPUT); // initialising pin 2 as input


   pinMode(pingPin1, OUTPUT); // initialising pin 3 as output

  pinMode(echoPin1, INPUT); // initialising pin 2 as input

   //pinMode(led, OUTPUT);

   /// pinMode(led1, OUTPUT);

    pinMode(buzzer2, OUTPUT);

    pinMode(buzzer1, OUTPUT);

    //pinMode(buzzer3, OUTPUT);

    //pinMode(vibration, INPUT);

    pinMode(buzzer4, OUTPUT);

    pinMode(respin, INPUT);

     //  pinMode(led1, OUTPUT);

       // pinMode(led2, OUTPUT);

        // pinMode(led3, OUTPUT);

          // pinMode(vibration, INPUT);

}


void loop()

{

  

   // set the cursor to column 0, line 1 

 // lcd.setCursor(0, 1); 

   

  resval = analogRead(respin); //Read data from analog pin and store it to resval variable

 

  if (resval<=100)

  { 

   // lcd.println("     Empty    "); 

      Serial.print("EMPTY");

  } 

 // else if (resval>100 && resval<=300){ lcd.println("       Low      "); }

 // else if (resval>300 && resval<=330){ lcd.println("     Medium     "); } 

  else { 

    

//                        lcd.println("      High      ");

                        Serial.print("HIGH");

                       digitalWrite(buzzer5, HIGH); 

                        delay(1000);

                        digitalWrite(buzzer5, LOW);

                       

       }

  // Serial.println("water");

   //Serial.println(resval);

   

  long duration, duration1,cm1 , cm;

  

  digitalWrite(pingPin, LOW);

  delayMicroseconds(2);

  

  digitalWrite(pingPin, HIGH);

  delayMicroseconds(10);

  

  digitalWrite(pingPin, LOW);


  

  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time

  //inches = microsecondsToInches(duration); // calling method

  cm = microsecondsToCentimeters(duration); // calling method

   digitalWrite(pingPin1, LOW);

  delayMicroseconds(2);

  

  digitalWrite(pingPin1, HIGH);

  delayMicroseconds(10);

  

  digitalWrite(pingPin1, LOW);


  

  duration1 = pulseIn(echoPin1, HIGH); // using pulsin function to determine total time

  //inches = microsecondsToInches(duration); // calling method

  cm1 = microsecondsToCentimeters(duration1); // calling method

    

Serial.println("|");

    newvalue =cm;

 if (newvalue != oldvalue)

    {

       Serial.print(cm);

        if (newvalue <= 100)

        {

          digitalWrite(buzzer1, HIGH); 

          delay(1000);

          digitalWrite(buzzer1, LOW);

        }

           

       oldvalue = newvalue;

    }

 

 


Serial.println("|");

   newvalue1 =cm1;

 if (newvalue1 != oldvalue1)

    {

       Serial.print(cm1);


        if (newvalue1 <= 100)

        {

          digitalWrite(buzzer2, HIGH); 

          delay(1000);

          digitalWrite(buzzer2, LOW);

        }

       oldvalue1 = newvalue1;

    }

 Serial.println("|");

if (Serial.read()==valeur)

    {

      

      Serial.print("Alert"); 

       digitalWrite(buzzer4, HIGH); 

          delay(1000);

          digitalWrite(buzzer4, LOW);

          valeur = valeur + 1 ;

    }

  Serial.println("|");

      

  delay(1000);

  

}

//long microsecondsToInches(long microseconds) // method to covert microsec to inches 

//{

// return microseconds / 74 / 2;

//}


long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters

{

   return microseconds / 29 / 2;

}

