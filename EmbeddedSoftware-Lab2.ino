#include <Ticker.h>
#include <B31DGMonitor.h>

#define Output_Pin_1 13 //Actual Pin Selected
#define Output_Pin_2 14 //Actual Pin Selected
#define Input_Pin_1 0 //Actual Pin Selected
#define Input_Pin_2 2 //Actual Pin Selected
#define Input_Pin_3 4 //Actual Pin Selected

#define Task_Measure_Pin 21
#define Trigger 15

//--Task Results--
//Task 1 = 280us
//Task 2 = 3.1ms
//Task 3 = 2.1ms
//Task 4 = 54us
//Task 5 = 25us

int task2MinFreq = 333;
int task2MaxFreq = 1000;
float task2MeasuredFreq = 0;

int task3MinFreq = 500;
int task3MaxFreq = 1000;
float task3MeasuredFreq = 0;

int const reqSamples = 4;
int readSamplesCount = 0;
int readSamples[reqSamples];

Ticker tick;
int nextFrame = 0;
B31DGCyclicExecutiveMonitor monitor;

void setup() {

  //Setup pinmodes for testing tools
  pinMode(Task_Measure_Pin, OUTPUT);
  pinMode(Trigger, OUTPUT);
  
  //Setup all pinModes appropraitely for the executive
  pinMode(Output_Pin_1, OUTPUT);
  pinMode(Output_Pin_2, OUTPUT);
  pinMode(Input_Pin_1, INPUT);
  pinMode(Input_Pin_2, INPUT);
  pinMode(Input_Pin_3, INPUT);
  Serial.begin(9600);

  //setup ticker, monitor and call first frame
  tick.attach_ms(4,frame); //ticker will call frame() every 4ms, 4ms after instantiation
  monitor.startMonitoring();
  frame();
}
//The Frame method contains a switchcase for with 50 states, which state executes is determined by a counter that is reset every 50 frames
void frame(){

  //locally saves the current frame and increments nextFrame in preparation for the next frame() call
  //this is done at the begining of the frame so that if the frame is interupted, the next frame() call isnt the same frame again
  int currentFrame  = nextFrame;
  nextFrame++;
  //while modulo can be used to determine the frame with a standard counter, as an embedded system is intended to run potentially indefinitely, the counter would overflow
  //this prevents this and makes the code easier to read
  if (nextFrame == 50) {nextFrame = 0;}

  //each case is one of the 50 frames of the cyclic executive
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

//This is the loop() method used when testing and implementing the tasks before the cyclic executive was implemented, this is kept here for clarity sake
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

//this method send a trigger signal out of the assigned Trigger pin for aligning the occiloscope, this was used for timing tasks, its unused in the executive due to not being
//requested as part of any task, however it would potentially be useful for visualising task 1 to verify it, preventing the need to freeze the occiloscope
void trigger(){
    digitalWrite(Trigger,HIGH);
    delayMicroseconds(50);
    digitalWrite(Trigger,LOW);
}

//task one implements a signal made up of a high signal for 200ms, low signal for 50, followed by a high signal for 30ms, and back to low.
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

//task2 and task 3 implement the same logic for measuring frequencies, however use different minimum and maximum frequency values, these could be
//refactored into a single method utilising more input parameters to the methods, however I did not have time to implement this refactor in time for the deadline
void task2(int InputPin){
  monitor.jobStarted(2);
  bool currentState = digitalRead(InputPin);
  int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 3100);
  if (halfWaveLengthMicro <= 0) {task2MeasuredFreq = 0;}
  else {int WaveLengthMicro = 2*halfWaveLengthMicro; task2MeasuredFreq = 1000000/WaveLengthMicro;}
  monitor.jobEnded(2);
}

//task2 and task 3 implement the same logic for measuring frequencies, however use different minimum and maximum frequency values, these could be
//refactored into a single method utilising more input parameters to the methods, however I did not have time to implement this refactor in time for the deadline
void task3(int InputPin){
  monitor.jobStarted(3);
  bool currentState = digitalRead(InputPin);
  int halfWaveLengthMicro = pulseIn(InputPin, !currentState, 2100);
  if (halfWaveLengthMicro <= 0) {task3MeasuredFreq = 0;}
  else {int WaveLengthMicro = 2*halfWaveLengthMicro;task3MeasuredFreq = 1000000/WaveLengthMicro;}
  monitor.jobEnded(3);
}

//task4 implements the averaging code utilising a cyclic buffer, when the cyclic buffer is not full the averaging is done using the current number of readings taken.
//once the cyclic buffer is full the averaging normally, by summing all the values in the array and dividing by the array length defined in the fields at the top of the script.
void task4(int InputPin, int OutputPin) {
  monitor.jobStarted(4);
  //Overflow Prevention Code, readSamplesCount starts from 0 and counts till it reaches 2*reqSamples where its reset to reqSamples
  //this allows implementing different behaviour for before the cyclic buffer is filled, and after the cyclic buffer has filled.
  if( readSamplesCount == 2*reqSamples) { readSamplesCount == reqSamples; }

  //Read Code
  int i = readSamplesCount % reqSamples;
  readSamples[i]= analogRead(InputPin);
  readSamplesCount++;

  //Averaging Code
  int averageValue = 0;
  //this computes the Average before enough readings have been taken to fill the cyclic buffer
  if (readSamplesCount < reqSamples) {
    for (int i = 0; i< readSamplesCount; i++) { averageValue += readSamples[i]; }
    averageValue = averageValue/readSamplesCount;
  }
  //this computes the average when the cyclic buffer has been filled
  else {
    for (int i = 0; i<reqSamples; i++) { averageValue += readSamples[i]; }
    averageValue = averageValue/reqSamples;
  }

  //if the average value is half of the maximum allowed analog read value, then output a high signal on the Output pin otherwise, output a Low signal
  if(averageValue > 2047) { digitalWrite(OutputPin,HIGH);}
  else{ digitalWrite(OutputPin,LOW);}
  monitor.jobEnded(4);
}

//if the frequency is zero, will return 0 otherwise the frequency is bound and constrained according to the minimum and maximum frequency values, and the 0,99 range
int task5FreqNorm(float Frequency, int minFreq, int maxFreq){
  if(Frequency != 0) {
    float normalisedFreq = 99*(Frequency-minFreq)/(maxFreq-minFreq);
    return constrain(normalisedFreq,0,99);
  }
  return 0;
}

//prints bound and constrained values of task2 and task3 frequencies in comma deliniated format
void task5(){
  monitor.jobStarted(5);
  //print to serial the NormalisedFrequency
  Serial.print(task5FreqNorm(task2MeasuredFreq,task2MinFreq,task2MaxFreq));
  Serial.print(",");
  //print to serial the NormalisedFrequency
  Serial.print(task5FreqNorm(task3MeasuredFreq,task3MinFreq,task3MaxFreq));
  Serial.print("\n");
  monitor.jobEnded(5);
}
//arduino code require the presence of a loop function to compile, its empty as its unnecassary for a cyclical executive
void loop() {
  
}
