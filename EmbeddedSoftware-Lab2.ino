#define Output_Pin_1 13 //Actual Pin Selected
#define Output_Pin_2 14 //Actual Pin Selected
#define Input_Pin_1 0 //Actual Pin Selected
#define Input_Pin_2 2 //Actual Pin Selected
#define Input_Pin_3 4 //Actual Pin Selected

#define Trigger 15
#define Task_Measure_Pin 21

//--Task Results--
//Task 1 = 280us
//Task 2 = 3.1ms
//Task 3 = 2.1ms
//Task 4 = 54us
//Task 5 = 25us

int const reqSamples = 4;
int readSamplesCount = 0;
int readSamples[reqSamples];

int task2MinFreq = 333;
int task2MaxFreq = 1000;
float task2MeasuredFreq = 0;
int task3MinFreq = 500;
int task3MaxFreq = 1000;
float task3MeasuredFreq = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Task_Measure_Pin, OUTPUT);
  
  pinMode(Output_Pin_1, OUTPUT);
  pinMode(Output_Pin_2, OUTPUT);
  pinMode(Input_Pin_1, INPUT);
  pinMode(Input_Pin_2, INPUT);
  pinMode(Input_Pin_3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  trigger();

  digitalWrite(Task_Measure_Pin, HIGH);
  task1(Output_Pin_1);
  digitalWrite(Task_Measure_Pin, LOW);
  task2(Input_Pin_1);
  digitalWrite(Task_Measure_Pin, HIGH);
  task3(Input_Pin_2);
  digitalWrite(Task_Measure_Pin, LOW);
  task4(Input_Pin_3,Output_Pin_2);
  digitalWrite(Task_Measure_Pin, HIGH);
  task5();
  digitalWrite(Task_Measure_Pin, LOW);
}

void trigger(){
    digitalWrite(Trigger,HIGH);
    delayMicroseconds(50);
    digitalWrite(Trigger,LOW);
}

void task1(int OutputPin){
  digitalWrite(OutputPin, HIGH);
  delayMicroseconds(200);
  digitalWrite(OutputPin,LOW);
  delayMicroseconds(50);
  digitalWrite(OutputPin,HIGH);
  delayMicroseconds(30);
  digitalWrite(OutputPin,LOW);
}

void task2(int InputPin){
   bool currentState = digitalRead(InputPin);
   int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 3100);
   if (halfWaveLengthMicro <= 0) {task2MeasuredFreq = 0;}
   else {int WaveLengthMicro = 2*halfWaveLengthMicro; task2MeasuredFreq = 1000000/WaveLengthMicro;}
}

void task3(int InputPin){
    bool currentState = digitalRead(InputPin);
    int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 2100);
   if (halfWaveLengthMicro <= 0) {task3MeasuredFreq = 0;}
   else {int WaveLengthMicro = 2*halfWaveLengthMicro;task3MeasuredFreq = 1000000/WaveLengthMicro;}
}

void task4(int InputPin, int OutputPin) {
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

  if(averageValue > 2048) { digitalWrite(OutputPin,HIGH);}
  else{ digitalWrite(OutputPin,LOW);}
}

int task5FreqNorm(float Frequency, int minFreq, int maxFreq){
  if(Frequency != 0) {
    float normalisedFreq = 99*(Frequency-minFreq)/(maxFreq-minFreq);
    return normalisedFreq;
  }
  return 0;
}

void task5(){
  Serial.print(task5FreqNorm(task2MeasuredFreq,task2MinFreq,task2MaxFreq));
  Serial.print(",");
  Serial.print(task5FreqNorm(task3MeasuredFreq,task3MinFreq,task3MaxFreq));
  Serial.print("  ");
}
