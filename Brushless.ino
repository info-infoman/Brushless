
void setup(){
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
  
  
  pinMode(5, INPUT);//dir
  pinMode(6, INPUT);//dir
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
  digitalWrite(12,0);digitalWrite(11,0);digitalWrite(10,0);
  digitalWrite(9,0);digitalWrite(8,0);digitalWrite(7,0);
  if(digitalRead(5)==1){
  if (digitalRead(4)==0) {digitalWrite(13, HIGH);bwd();}
  if (digitalRead(4)==1) {digitalWrite(13, HIGH);fwd();}
  }
}
