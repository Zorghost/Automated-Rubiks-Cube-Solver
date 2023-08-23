#include <Servo.h>
String com; 

Servo hit,rot,block;     // drei motoren hit push, block block, rot base
int i,angle=135; //  winkel 98
int j;
int correction = 0; //korrigieren winkel 
void hitman(){
  int speed = 50; 
  int dd = 1310;
  if(angle == 98) {speed = 45; dd =1170;}
       delay(100);
  hit.write(speed);
      delay(dd); 
      hit.write(85);
      delay(500);
      if(correction++ == 10){
        hit.write(95);
       delay(4500);
       hit.write(85);
       correction = 0;
       hit.write(0);
  delay(250);
  hit.write(85);
      }
}

void BUB(int angle){
      /*for(j=180;j>0;j--){
        block.write(j);
        delay(4);
      }*/
      block.write(0);
      delay(500);
      rot.write(angle);
      delay(1000);
      block.write(180);
      delay(500);
}
void setup (){
Serial.begin(9600);
hit.attach (9);
  rot.attach(10);
  block.attach (11);
/*First moves motors*/
  block.write(180);
  rot.write(135);
  delay(1000);


  /*hit.write(95);
  delay(6000);
  hit.write(0);
  delay(250);
  hit.write(85);*/
  
}

void loop (){
  //hit.write(95);
  //block.write(0);
  //rot.write(0);
  while(Serial.available()<=0); 
  com = Serial.readString();
Serial.print(com);
for(i = 0;i<com.length();i++){
  switch(com[i]){
     case 'e':
     block.write(180);
  rot.write(135);
      break;
    case 'r':
        angle=30;
      rot.write(angle);
      delay(500);
      break;
      break;
    case 'i':
      angle=135;
      rot.write(angle);
      delay(500);
      hit.write(95);
      break;
    case '1':
         angle=135;
        BUB(angle);
        angle=135;
        rot.write(angle);
        delay(500);
      break;
    case '2': 
    angle=35;
        BUB(angle);
        angle=135;
        rot.write(angle);
        hit.write(95);
        delay(500);
        angle=120;
        BUB(angle);
        angle=35;
        rot.write(angle);
        hit.write(95);
        delay(500);
        
      
      break;


      case 'x':
        hitman();
        hit.write(95);
      break;

      case 'y':
      hitman();
      hitman();
      hit.write(95);
      break;
      case 'z':
     hitman();hitman();hitman();
     hit.write(95);
      break;
      
      case 'a':
       BUB(angle);
       hit.write(95);
       break;

       case 'd':
       delay(1000);
       hit.write(95);
       break;

       case 'p':
       angle=135;
       rot.write(135);
       
       break;

       case 't':
       hit.write(95);
       delay(6000);
       hit.write(85);
       break;

        case 'b':
       hit.write(95);
       delay(6000);
       hit.write(0);
       delay(300);
       hit.write(85);
       break;
        
  }
}
Serial.println(angle);
com = " ";
}
