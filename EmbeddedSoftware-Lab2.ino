#include <Ticker.h>
#include <B31DGMonitor.h>

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

int nextFrame = 0;
Ticker tick;

B31DGCyclicExecutiveMonitor monitor;

void setup() {
  
  pinMode(Trigger, OUTPUT);
  pinMode(Task_Measure_Pin, OUTPUT);
  pinMode(Output_Pin_1, OUTPUT);
  pinMode(Output_Pin_2, OUTPUT);
  pinMode(Input_Pin_1, INPUT);
  pinMode(Input_Pin_2, INPUT);
  pinMode(Input_Pin_3, INPUT);
  Serial.begin(9600);

  tick.attach_ms(4,frame);
  monitor.startMonitoring();
  frame();
}

void frame(){

  int currentFrame  = nextFrame;
  nextFrame++;
  if (nextFrame == 50) {nextFrame = 0;}

  switch(currentFrame) {
    case 0:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    task4(Input_Pin_3,Output_Pin_2);
    task5();
    break;
    case 1:
    task1(Output_Pin_1);
    break;
    case 2:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 3:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 4:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 5:
    task1(Output_Pin_1);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 6:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 7:
    task1(Output_Pin_1);
    break;
    case 8:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 9:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 10:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 11:
    task1(Output_Pin_1);
    break;
    case 12:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 13:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 14:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 15:
    task1(Output_Pin_1);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 16:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 17:
    task1(Output_Pin_1);
    break;
    case 18:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 19:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 20:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 21:
    task1(Output_Pin_1);
    break;
    case 22:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 23:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 24:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 25:
    task1(Output_Pin_1);
    task4(Input_Pin_3,Output_Pin_2);
    task5();
    break;
    case 26:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 27:
    task1(Output_Pin_1);
    break;
    case 28:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 29:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 30:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 31:
    task1(Output_Pin_1);
    break;
    case 32:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 33:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 34:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 35:
    task1(Output_Pin_1);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 36:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 37:
    task1(Output_Pin_1);
    break;
    case 38:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 39:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 40:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 41:
    task1(Output_Pin_1);
    break;
    case 42:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 43:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    case 44:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 45:
    task1(Output_Pin_1);
    task4(Input_Pin_3,Output_Pin_2);
    break;
    case 46:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 47:
    task1(Output_Pin_1);
    break;
    case 48:
    task1(Output_Pin_1);
    task3(Input_Pin_2);
    break;
    case 49:
    task1(Output_Pin_1);
    task2(Input_Pin_1);
    break;
    default:
    Serial.println("all your base are belong to us");
    break;
  }
  
}

void loop() {
  
}

void testLoop() {
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
  monitor.jobStarted(1);
  digitalWrite(OutputPin, HIGH);
  delayMicroseconds(200);
  digitalWrite(OutputPin,LOW);
  delayMicroseconds(50);
  digitalWrite(OutputPin,HIGH);
  delayMicroseconds(30);
  digitalWrite(OutputPin,LOW);
  monitor.jobEnded(1);
}

void task2(int InputPin){
  monitor.jobStarted(2);
  bool currentState = digitalRead(InputPin);
  int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 3100);
  if (halfWaveLengthMicro <= 0) {task2MeasuredFreq = 0;}
  else {int WaveLengthMicro = 2*halfWaveLengthMicro; task2MeasuredFreq = 1000000/WaveLengthMicro;}
  monitor.jobEnded(2);
}

void task3(int InputPin){
  monitor.jobStarted(3);
  bool currentState = digitalRead(InputPin);
  int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 2100);
  if (halfWaveLengthMicro <= 0) {task3MeasuredFreq = 0;}
  else {int WaveLengthMicro = 2*halfWaveLengthMicro;task3MeasuredFreq = 1000000/WaveLengthMicro;}
  monitor.jobEnded(3);
}

void task4(int InputPin, int OutputPin) {
  monitor.jobStarted(4);
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
  monitor.jobEnded(4);
}

int task5FreqNorm(float Frequency, int minFreq, int maxFreq){
  if(Frequency != 0) {
    float normalisedFreq = 99*(Frequency-minFreq)/(maxFreq-minFreq);
    return normalisedFreq;
  }
  return 0;
}

void task5(){
  monitor.jobStarted(5);
  Serial.print(task5FreqNorm(task2MeasuredFreq,task2MinFreq,task2MaxFreq));
  Serial.print(",");
  Serial.print(task5FreqNorm(task3MeasuredFreq,task3MinFreq,task3MaxFreq));
  Serial.print("  ");
  monitor.jobEnded(5);
}
