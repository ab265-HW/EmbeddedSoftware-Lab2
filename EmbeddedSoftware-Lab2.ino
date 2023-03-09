#define Output_Pin_1 = 13; //select actual pin
#define Input_Pin_2 = 2; //select actual pin
#define Input_Pin_3 = 3; //select actual pin

void setup() {
pinMode(Output_Pin_1)
}

void loop() {
  // put your main code here, to run repeatedly:

}

void methodTask1(int OutputPin){
  digitalWrite(Output_pin_1, HIGH);
  delayMicroseconds(200);
  digitalWrite(Output_pin_1,LOW);
  delayMicroseconds(50);
  digitalWrite(Output_pin_1,HIGH);
  delayMicroseconds(30);
  digitalWrite(Output_pin_1,LOW);
}
