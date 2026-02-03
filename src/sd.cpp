//Inkluderer SD-kort bibliotek
#include <SD.h>

//CS (ChipSelect) er fysisk koblet til pin CS/D10
const int chipSelect = 10;
int sensorverdier[10];
int i = 0;

//Deklarasjon for et File-objekt med navn "myFile"
File myFile;


void setup() {
  //Initialiserer serial-kommunikasjon med baud rate 9600 bps
  Serial.begin(9600);

  //Feilmelding ved mislykket initialisering av serial-kommunikasjon
  if (!SD.begin(chipSelect)) {
    Serial.println("Initialisering av serial-kommunikasjon feilet. Sjekk at alt det fysiske er koblet til riktig.");
    while (true);
  }

  //Sletter original-filen, fordi jeg har lagt til masse unødvendige linjer med tekst i .txt-filen eheh
  if ("EriksFil.txt") {
    SD.remove("EriksFil.txt");
  }

  //Åpner/lager en fil med navn "Eriks_testfil.txt". Åpner den i skrivemodus.
  myFile = SD.open("EriksFil.txt", FILE_WRITE);

  //Skriver til filen, dersom det funket å åpne/lage den
  if (myFile) {
    myFile.println("Erik Elahi Fidjeland har skrevet til denne filen:) \nHan er en ganske fet kar ellerhva? \nJeg tror faktisk han er topp 3 feteste/kjekkeste karer i Norge as");

    //Lukker filen
    myFile.close();
  } 
  
  else {
    //Feilmelding dersom man ikke får åpnet/laget fil
    Serial.println("Feil ved åpning av EriksFil.txt");
  }

  //Åpner filen, men denne gang i lesemodus
  myFile = SD.open("EriksFil.txt");
  if (myFile) {
    Serial.println("Innhold i EriksFil.txt:");
    Serial.println("----------------------");

    //Leser hele filen
    while (myFile.available()) {
      Serial.write(myFile.read());
    }

    //Lukker filen
    myFile.close();
  } 
  
  else {
    //Feilmelding dersom man ikke får åpnet filen
    Serial.println("Feil ved åpning av EriksFil.txt");
  }
}

void loop() {
  delay(500);  // liten pause
  int tilfeldigTall = random(0, 101);
  sensorverdier[i] = tilfeldigTall;
  i++;

  if (i == 10) {
    // Åpne filen for skriving
    myFile = SD.open("EriksFil.txt", FILE_WRITE);
    if (myFile) {
      for (int j = 0; j < 10; j++) {
        myFile.print(sensorverdier[j]);
        myFile.print(",");
        Serial.print(sensorverdier[j]);  // <-- skriver til Serial også
        Serial.print(",");
      }
      myFile.println();
      Serial.println(); // ny linje i Serial Monitor

      myFile.close(); // må lukke filen for å lagre
      i = 0;
    } else {
      Serial.println("Kunne ikke åpne fil for skriving");
    }
  }
}



#funka dette?