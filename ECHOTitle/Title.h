#pragma once

uint8_t Time;

struct Particle{
  uint8_t x;
  uint8_t y;
  bool active;
};

void Title(){
  Particle Parts[5];
  const short int wind = -1;
  if (ard.everyXFrames(30))
    {
    Time += 1;
    if (Time == 12) Time = 1;
    }
  switch(Time){
    case 7:ard.drawLine(0,32,0,10); break;
    case 6:ard.drawLine(0,32,11,14); break;
    case 5:ard.drawLine(0,32,17,22); break;
    case 4:ard.drawLine(0,32,23,32); break;
    case 3:ard.drawLine(0,32,18,42); break;
    case 2:ard.drawLine(0,32,10,49); break;
    case 1:ard.drawLine(0,32,0,53); break;
  }

  
    for (uint8_t i=0;i<5;i++){
      if((!Parts[i].active)&&(random(20) == 0)){
        Parts[i].x = random(125);
        Parts[i].y = 0;
        Parts[i].active = true;
      }
    }
    
    for (uint8_t i=0;i<5;i++){
      if (Parts[i].active){
        Parts[i].x += wind;
        Parts[i].y += 1;
        if (Parts[i].y >= 66 || Parts[i].x > 127) {
          Parts[i].active = false;
        } else {
          sprites.drawSelfMasked(Parts[i].x,Parts[i].y-4,Dust,0);
        }
      }
    }
    sprites.drawSelfMasked(0,0,EchoTitle,0);
  
}

