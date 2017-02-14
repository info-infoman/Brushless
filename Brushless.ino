
#include <PWM.h>
int32_t frequency = 20000; //pwm frequency in Hz
unsigned int n = 0, timer2_initial_value, s = 0;
void setup(){
  InitTimersSafe();
  bool success = SetPinFrequencySafe(9, frequency);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  // initialize timer2 interrupt for adc reading 
  noInterrupts();           // disable all interrupts
  TCCR2A = 0;
  TCCR2B = 0;
  timer2_initial_value = 0;  
  TCNT2 = timer2_initial_value;   // preload timer
  TCCR2B |= (1 << CS22) |(1 << CS21) | (1 << CS20); // 1024 prescaler 
  TIMSK2 |= (1 << TOIE2);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}
 ISR(TIMER2_OVF_vect)        // interrupt service routine 
 {
  TCNT2 = timer2_initial_value;   // preload timer
  n++;
  if (n>20){
    n = 0;
   if (s != analogRead(A0)){
   s = analogRead(A0); 
  pwmWrite(9,s/4);}}
 }
int fwd(){
   while(1){
if (digitalRead(2)==1){
    if (digitalRead(1)==0){
      if (digitalRead(0)==1){
        digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,1);digitalWrite(4,1);digitalWrite(3,0);}
      else {
        digitalWrite(8,1);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,1);digitalWrite(4,0);digitalWrite(3,0);}}
        
     if (digitalRead(1)==1){
      if (digitalRead(0)==0){
        digitalWrite(8,1);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,1);}}}
        
   
 if (digitalRead(2)==0){
    if (digitalRead(1)==1){
      if (digitalRead(0)==0){
        digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,1);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,1);}
      else {
        digitalWrite(8,0);digitalWrite(7,1);digitalWrite(6,1);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,0);}}
        
     if (digitalRead(1)==0){
      if (digitalRead(0)==1){
        digitalWrite(8,0);digitalWrite(7,1);digitalWrite(6,0);
        digitalWrite(5,0);digitalWrite(4,1);digitalWrite(3,0);}}}
   if (digitalRead(12)==0) break;}
}
 int bwd(){
   while(1){
if (digitalRead(2)==1){
    if (digitalRead(1)==0){
      if (digitalRead(0)==1){
        digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,1);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,1);}
      else {
        digitalWrite(8,0);digitalWrite(7,1);digitalWrite(6,1);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,0);}}
        
     if (digitalRead(1)==1){
      if (digitalRead(0)==0){
        digitalWrite(8,0);digitalWrite(7,1);digitalWrite(6,0);
        digitalWrite(5,0);digitalWrite(4,1);digitalWrite(3,0);}}}
        
   
 if (digitalRead(2)==0){
    if (digitalRead(1)==1){
      if (digitalRead(0)==0){
        digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,1);digitalWrite(4,1);digitalWrite(3,0);}
      else {
        digitalWrite(8,1);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,1);digitalWrite(4,0);digitalWrite(3,0);}}
        
     if (digitalRead(1)==0){
      if (digitalRead(0)==1){
        digitalWrite(8,1);digitalWrite(7,0);digitalWrite(6,0);
        digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,1);}}}
   if (digitalRead(12)==0) break;}
}
     
void loop(){
  digitalWrite(13, LOW);
  pwmWrite(9,s);
  digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,0);
  digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,0);
  if (digitalRead(10)==0) {digitalWrite(13, HIGH);bwd();}
  if (digitalRead(11)==0) {digitalWrite(13, HIGH);fwd();}
}
