int DO = 8;
int RE = 9;
int MI = 10;
int FA = 11;
int SOL = 12;
int SI = 2;
int BUZZ = 3;
int LED = 4;
int TONO;
bool SONANDO = false;
int TECLAS[] = {DO, RE, MI, FA, SOL, SI};
float FRECUENCIAS[] = {261.63, 293.66, 329.63, 349.46, 392, 523.25};
const int CORTE = 300;
long START = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(DO, INPUT);
  pinMode(RE, INPUT);
  pinMode(MI, INPUT);
  pinMode(FA, INPUT);
  pinMode(SOL, INPUT);
  pinMode(SI, INPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(LED, OUTPUT);
  
}

void suena(){
  for(int x = 0;x < 6; x++){
      while(digitalRead(TECLAS[x]) == HIGH){
        tone(BUZZ, FRECUENCIAS[x]);
        digitalWrite(LED, HIGH);
      }
      noTone(BUZZ);
      digitalWrite(LED, LOW);
    }
}
void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - START > CORTE){
    suena();
    START = 0;
  }
}
