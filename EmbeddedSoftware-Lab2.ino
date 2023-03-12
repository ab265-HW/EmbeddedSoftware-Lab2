#define Output_Pin_1 13 //Actual Pin Selected
#define Input_Pin_1 2 //select actual pin
#define Input_Pin_2 3 //select actual pin

int const reqSamples = 4;
int readSamplesCount = 0;
int readSamples[reqSamples];

void setup() {
pinMode(Output_Pin_1, OUTPUT);
pinMode(Input_Pin_1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void Task1(int OutputPin){
  digitalWrite(OutputPin, HIGH);
  delayMicroseconds(200);
  digitalWrite(OutputPin,LOW);
  delayMicroseconds(50);
  digitalWrite(OutputPin,HIGH);
  delayMicroseconds(30);
  digitalWrite(OutputPin,LOW);
}
void Task2(int InputPin){
   bool currentState = analogRead(InputPin);
   int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 3500);
   int WaveLengthMicro = 2*halfWaveLengthMicro;
}
void Task3(int InputPin){
    bool currentState = analogRead(InputPin);
    int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 3500);
    int WaveLengthMicro = 2*halfWaveLengthMicro;
}

void task4(int InputPin) {
  //Overflow Prevention Code
  if( readSamplesCount == 2*reqSamples) { readSamplesCount == reqSamples; }

  //Read Code
  int i = readSamplesCount % reqSamples;
  readSamples[i]= analogRead(InputPin);
  readSamplesCount++;

  //Averaging Code
  int averageValue = 0;
  //this computes the Average before an adequate number of samples are obtained
  if (readSamplesCount < reqSamples) {
    for (int i = 0; i< readSamplesCount; i++) { averageValue += readSamples[i]; }
    averageValue = averageValue/readSamplesCount;
  }
  //this computes the average after an adequate number of samples are obtained
  else {
    for (int i = 0; i<reqSamples; i++) { averageValue += readSamples[i]; }
    averageValue = averageValue/reqSamples;
  }
}
