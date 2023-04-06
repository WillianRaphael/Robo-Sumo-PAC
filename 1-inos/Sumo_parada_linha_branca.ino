#include <Arduino.h>
#include <bridgeH_new.h>
#include <sharp_new.h>
#include <qtr_new.h>
#include <sumo_new_linha_branca.h>


int speedD=0;
int speedE=0;
int distance;
int distanceQtrD;
int distanceQtrE;
bool corBrancaD;
bool corBrancaE;


sharp_n sharp1(A0);   
qtr_n qtrD(A1, 400);
qtr_n qtrE(A2, 400);



void setup() {

 Serial.begin(9600);

  Serial.println("Sumo_Teste 0");
}


void loop() {


bridgeH_n bridgeH_D(3,4,5,speedD);
bridgeH_n bridgeH_E(7,8,6,speedE);


distance = sharp1.getDistance();
distanceQtrD= qtrD.getValue();
distanceQtrE= qtrE.getValue();

corBrancaD =qtrD.getcolorWhite();
corBrancaE =qtrE.getcolorWhite();



sumo_n sumoV1(corBrancaD,corBrancaE,distance,30,500,800);

speedD = sumoV1.getRSpeed();
speedE = sumoV1.getLSpeed();



  Serial.print(distance);
    Serial.print("  ");
  Serial.print(distanceQtrE);
   Serial.print("  ");
  Serial.print(corBrancaD);
    Serial.print(" ");
     Serial.print(corBrancaE);
    Serial.print(" "); 
  Serial.println(sumoV1.getIndex());
  
/
}
