
#include <PWM.h>
int32_t frequency = 20000; //pwm frequency in Hz
unsigned int n = 0, timer2_initial_value, s = 0;
void setup(){
  InitTimersSafe();
  bool success = SetPinFrequencySafe(9, frequency);
  //phase
  pinMode(7, OUTPUT);//3
  pinMode(8, OUTPUT);
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);//8
  //
  pinMode(13, OUTPUT);//led
  
  //hall
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
  
  pinMode(4, INPUT);//dir
  
  //pinMode(12, INPUT_PULLUP);
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
   if (s != analogRead(A7)){
   s = analogRead(A7); 
  pwmWrite(9,s/4);}}
 }
int fwd(){
   while(1){
if (digitalRead(4)==1){
    if (digitalRead(3)==0){
      if (digitalRead(2)==1){
        digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,1);digitalWrite(8,1);digitalWrite(7,0);}
      else {
        digitalWrite(12,1);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,1);digitalWrite(8,0);digitalWrite(7,0);}}
        
     if (digitalRead(3)==1){
      if (digitalRead(2)==0){
        digitalWrite(12,1);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,1);}}}
        
   
 if (digitalRead(4)==0){
    if (digitalRead(3)==1){
      if (digitalRead(2)==0){
        digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,1);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,1);}
      else {
        digitalWrite(12,0);digitalWrite(11,1);digitalWrite(10,1);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,0);}}
        
     if (digitalRead(3)==0){
      if (digitalRead(2)==1){
        digitalWrite(12,0);digitalWrite(11,1);digitalWrite(10,0);
        digitalWrite(9,0);digitalWrite(8,1);digitalWrite(7,0);}}}
   if (digitalRead(5)==0) break;}
}
 int bwd(){
   while(1){
if (digitalRead(4)==1){
    if (digitalRead(3)==0){
      if (digitalRead(2)==1){
        digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,1);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,1);}
      else {
        digitalWrite(12,0);digitalWrite(11,1);digitalWrite(10,1);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,0);}}
        
     if (digitalRead(3)==1){
      if (digitalRead(2)==0){
        digitalWrite(12,0);digitalWrite(11,1);digitalWrite(10,0);
        digitalWrite(9,0);digitalWrite(8,1);digitalWrite(7,0);}}}
        
   
 if (digitalRead(4)==0){
    if (digitalRead(3)==1){
      if (digitalRead(2)==0){
        digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,1);digitalWrite(8,1);digitalWrite(7,0);}
      else {
        digitalWrite(12,1);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,1);digitalWrite(8,0);digitalWrite(7,0);}}
        
     if (digitalRead(3)==0){
      if (digitalRead(2)==1){
        digitalWrite(12,1);digitalWrite(11,0);digitalWrite(10,0);
        digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,1);}}}
   if (digitalRead(5)==0) break;}
}
     
void loop(){
  digitalWrite(13, LOW);
  pwmWrite(9,s);
  digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,0);
  digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,0);
  if (digitalRead(4)==0) {digitalWrite(13, HIGH);bwd();}
  if (digitalRead(4)==1) {digitalWrite(13, HIGH);fwd();}
}
