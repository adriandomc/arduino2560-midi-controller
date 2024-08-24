const int bankUp = 51;
const int bankDown = 50;
const int butL = 52;
const int butR = 53;

const int pot1 = A0;  // potentiometer pins
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;

int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;
int potVal4 = 0;

int lastPotVal1 = 0;
int lastPotVal2 = 0;
int lastPotVal3 = 0;
int lastPotVal4 = 0;

int d1A = 22;
int d1B = 24;
int d1C = 26;
int d1D = 28;
int d1E = 30;
int d1F = 32;
int d1G = 34;

int d2A = 23;
int d2B = 25;
int d2C = 27;
int d2D = 29;
int d2E = 31;
int d2F = 33;
int d2G = 35;

int display1_val;
int display2_val;

void MIDImessage(byte status, byte data1, byte data2)
{
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);
}

void display1(int n) {
  switch(n) {
    case 0:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, HIGH);
      break;

    case 1:
      digitalWrite(d1A, HIGH);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, HIGH);
      digitalWrite(d1G, HIGH);
      break;

    case 2:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, HIGH);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, HIGH);
      digitalWrite(d1G, LOW);
      break;

    case 3:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, HIGH);
      digitalWrite(d1G, LOW);
      break;

    case 4:
      digitalWrite(d1A, HIGH);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 5:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 6:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 7:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, HIGH);
      digitalWrite(d1G, HIGH);
      break;

    case 8:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 9:
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, HIGH);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 10:    // A
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 11:    // B
      digitalWrite(d1A, HIGH);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 12:    // C
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, HIGH);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, HIGH);
      break;

    case 13:    // D
      digitalWrite(d1A, HIGH);
      digitalWrite(d1B, LOW);
      digitalWrite(d1C, LOW);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, HIGH);
      digitalWrite(d1G, LOW);
      break;

    case 14:    // E
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, HIGH);
      digitalWrite(d1D, LOW);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;

    case 15:    // F
      digitalWrite(d1A, LOW);
      digitalWrite(d1B, HIGH);
      digitalWrite(d1C, HIGH);
      digitalWrite(d1D, HIGH);
      digitalWrite(d1E, LOW);
      digitalWrite(d1F, LOW);
      digitalWrite(d1G, LOW);
      break;
  }
}

void display2(int n) {
  switch(n) {
    case 0:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, LOW);
      break;

    case 1:
      digitalWrite(d2A, LOW);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, LOW);
      digitalWrite(d2G, LOW);
      break;

    case 2:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, LOW);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, LOW);
      digitalWrite(d2G, HIGH);
      break;

    case 3:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, LOW);
      digitalWrite(d2G, HIGH);
      break;

    case 4:
      digitalWrite(d2A, LOW);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 5:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 6:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 7:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, LOW);
      digitalWrite(d2G, LOW);
      break;

    case 8:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 9:
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, LOW);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 10:    // A
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 11:    // B
      digitalWrite(d2A, LOW);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 12:    // C
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, LOW);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, LOW);
      break;

    case 13:    // D
      digitalWrite(d2A, LOW);
      digitalWrite(d2B, HIGH);
      digitalWrite(d2C, HIGH);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, LOW);
      digitalWrite(d2G, HIGH);
      break;

    case 14:    // E
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, LOW);
      digitalWrite(d2D, HIGH);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;

    case 15:    // F
      digitalWrite(d2A, HIGH);
      digitalWrite(d2B, LOW);
      digitalWrite(d2C, LOW);
      digitalWrite(d2D, LOW);
      digitalWrite(d2E, HIGH);
      digitalWrite(d2F, HIGH);
      digitalWrite(d2G, HIGH);
      break;
  }
}

void readPots() {

  int diff = 4;


  
  potVal1 = analogRead(pot1);
  potVal2 = analogRead(pot2);
  potVal3 = analogRead(pot3);
  potVal4 = analogRead(pot4);


  
  int potVal1diff = potVal1 - lastPotVal1;
  int potVal2diff = potVal2 - lastPotVal2;
  int potVal3diff = potVal3 - lastPotVal3;
  int potVal4diff = potVal4 - lastPotVal4;

  
  if (abs(potVal1diff) > diff)
  {
    MIDImessage(177, 0, map(potVal1, 0, 1023, 0, 127)); 
    lastPotVal1 = potVal1;
    display1_val = floor(map(lastPotVal1, 0, 1023, 0, 127) / 16.0);
    display2_val = map(lastPotVal1, 0, 1023, 0, 127) % 16;
    display1(display1_val);
    display2(display2_val);
    
  }

  if (abs(potVal2diff) > diff)
  {
    MIDImessage(177, 1, map(potVal2, 0, 1023, 0, 127));
    lastPotVal2 = potVal2;
    display1_val = floor(map(lastPotVal2, 0, 1023, 0, 127) / 16.0);
    display2_val = map(lastPotVal2, 0, 1023, 0, 127) % 16;
    display1(display1_val);
    display2(display2_val);
    
  }

  if (abs(potVal3diff) > diff)
  {
    MIDImessage(177, 2, map(potVal3, 0, 1023, 0, 127));
    lastPotVal3 = potVal3;
    display1_val = floor(map(lastPotVal3, 0, 1023, 0, 127) / 16.0);
    display2_val = map(lastPotVal3, 0, 1023, 0, 127) % 16;
    display1(display1_val);
    display2(display2_val);
    
  }

  if (abs(potVal4diff) > diff)
  {
    MIDImessage(177, 3, map(potVal4, 1023, 0, 0, 127));
    lastPotVal4 = potVal4;
    display1_val = floor(map(lastPotVal4, 0, 1023, 0, 127) / 16.0);
    display2_val = map(lastPotVal4, 0, 1023, 0, 127) % 16;
    display1(display1_val);
    display2(display2_val);
   
  }

  delay(2);

}

void setup() {
  Serial.begin(115200);
  pinMode(bankUp,   INPUT_PULLUP);
  pinMode(bankDown, INPUT_PULLUP);
  pinMode(butL,     INPUT_PULLUP);
  pinMode(butR,     INPUT_PULLUP);
  for (int i = 22; i <= 35; i++) {
    pinMode(i, OUTPUT);
  }
  display1(0);
  display2(0);
  
}

void loop() {
  readPots();

}
