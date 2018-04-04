#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
#include "ENums.h"
#include "Bitmaps.h"
#include "Title.h"

void __attribute__ ((noinline)) FakeCalculations(void)
{
	uint16_t values[20];
  
	for(uint8_t i = 0; i < 20; ++i)
		values[i] = random();
	  
	for(uint8_t i = 0; i < 20; ++i)
	{
		ard.setCursor(0, 0);
		ard.print(values[i]);
	}
}


void setup() {
  ard.begin();
  ard.clear(); 
}

void loop() {
  if(!ard.nextFrame())
    return;
  ard.pollButtons();
  FakeCalculations();
  switch(gameState){
    case GameState::MainMenu:Title();
  }
  ard.display(CLEAR_BUFFER);
}

