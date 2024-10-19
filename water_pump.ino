const int bouton = 1; // the button is connected to pin 1 of the Arduino
const int relais_pompe = 2; // the relay is connected to pin 2 of the Arduino
int etatBouton;
int lastEtatBouton = HIGH; // to store the previous state of the button
int etatRelais = LOW; // to track the current state of the relay (initially OFF)

void setup() {
  pinMode(bouton, INPUT);
  pinMode(relais_pompe, OUTPUT);
  digitalWrite(relais_pompe, LOW); // ensure the relay is off at the start
}

void loop() {
  etatBouton = digitalRead(bouton); // read the current state of the button

  if (etatBouton == LOW && lastEtatBouton == HIGH) {
    // button is pressed (state changed from HIGH to LOW)
    etatRelais = !etatRelais; // toggle the relay state
    digitalWrite(relais_pompe, etatRelais); // set the relay to the new state
  }

  // update the last state of the button
  lastEtatBouton = etatBouton;

  delay(10); // debounce delay to prevent button bouncing issues
}
