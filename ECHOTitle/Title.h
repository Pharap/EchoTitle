#pragma once

struct Particle{
  uint8_t x;
  uint8_t y;
  bool active;
};

void Title(){
  Particle Parts[5];
  const short int wind = -1;
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

