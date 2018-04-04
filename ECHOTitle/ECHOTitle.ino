#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
#include "ENums.h"
#include "Bitmaps.h"
#include "Title.h"

void __attribute__ ((noinline)) FakeCalculations(void)
{
	// Volatile stops the compiler from optimising
	volatile Particle Parts[10];

	// Hijacking the memory the other function is using
	for(uint8_t i = 0; i < 10; ++i)
	{
		Parts[i].x = 32 + (16 * i);
		Parts[i].y = 32 + (8 * i);
		Parts[i].flicker = true;
		Parts[i].active = true;
	}

	// This is just to stop the compiler from over-optimising
	for(uint8_t i = 0; i < 10; ++i)
	{
		ard.setCursor(0, 0);
		ard.print(Parts[i].x);
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

