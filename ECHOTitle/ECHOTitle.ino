#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
#include "ENums.h"
#include "Bitmaps.h"
#include "Title.h"


void setup() {
  ard.begin();
  ard.clear(); 
}

void loop() {
  if(!ard.nextFrame())
    return;
  ard.pollButtons();
  switch(gameState){
    case GameState::MainMenu:Title();
  }
  ard.display(CLEAR_BUFFER);
}
