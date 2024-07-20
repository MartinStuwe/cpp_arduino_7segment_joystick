int A = 48;
int B = 49;
int F = 50;
int G = 51;
int E = 41;
int D = 40;
int C = 39;

int sw_pin = 30;
int X_pin = A1;
int Y_pin = A0;

int currentNumber = 0; // Variable to store the current number to display

void clearDisplay(void) 
{ 
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(A, LOW);
    digitalWrite(E, LOW);
    digitalWrite(D, LOW);
    digitalWrite(C, LOW);
} 

void displayC(void) { digitalWrite(C, HIGH); }
void displayD(void) { digitalWrite(D, HIGH); }
void displayE(void) { digitalWrite(E, HIGH); }
void displayA(void) { digitalWrite(A, HIGH); }
void displayB(void) { digitalWrite(B, HIGH); }
void displayF(void) { digitalWrite(F, HIGH); }
void displayG(void) { digitalWrite(G, HIGH); }

void display1(void)
{
  displayB();
  displayC();
}
void display2(void)
{
  displayA();
  displayB();
  displayG();
  displayE();
  displayD();
}
void display3(void)
{
  displayA();
  displayB();
  displayG();
  displayC();
  displayD();
}
void display4(void)
{
  displayF();
  displayG();
  displayC();
  displayB();
}
void display5(void)
{
  displayA();
  displayF();
  displayG();
  displayC();
  displayD();
}
void display6(void)
{
  displayA();
  displayF();
  displayG();
  displayC();
  displayD();
  displayE();
}
void display7(void)
{
  displayA();
  displayB();
  displayC();
}
void display8(void)
{
  displayA();
  displayF();
  displayG();
  displayC();
  displayD();
  displayE();
  displayB();
}
void display9(void)
{
  displayA();
  displayF();
  displayG();
  displayC();
  displayB();
}
void display0(void)
{
  displayA();
  displayB();
  displayC();
  displayD();
  displayE();
  displayF();
}

void setup() 
{   
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(sw_pin, INPUT);
    pinMode(X_pin, INPUT);
    pinMode(Y_pin, INPUT);

    Serial.begin(9600); // For debugging purposes
}

void loop() 
{     
    int xValue = analogRead(X_pin);
    int yValue = analogRead(Y_pin);

    // Use a threshold to determine the direction
    int threshold = 100;
    if (xValue < 512 - threshold) { // Joystick moved left
        currentNumber--;
        if (currentNumber < 0) {
            currentNumber = 9;
        }
    } else if (xValue > 512 + threshold) { // Joystick moved right
        currentNumber++;
        if (currentNumber > 9) {
            currentNumber = 0;
        }
    }

    // Add a small delay to debounce joystick movements
    delay(200);

    clearDisplay(); // Clear the previous display

    // Display the current number
    switch(currentNumber) {
        case 0: display0(); break;
        case 1: display1(); break;
        case 2: display2(); break;
        case 3: display3(); break;
        case 4: display4(); break;
        case 5: display5(); break;
        case 6: display6(); break;
        case 7: display7(); break;
        case 8: display8(); break;
        case 9: display9(); break;
    }

    delay(100); // Small delay for stability
}
