#include <Control_Surface.h>
#include "button_notes.hpp"
#include "configuration.hpp"
#include "HX710B.h"

int SCK_PIN = A7;
int OUT_PIN = 8;

HX710B air_press;

const int BUTTONS_PIN[4] = { 5,4,3,2 };
const int AIR_BUTTON_PIN = 12;
const int LED_PIN = 13;
const int ANALOG_PIN = A7;
const Channel DEFAULT_CHANNEL = CHANNEL_1;

USBMIDI_Interface midiInterface;

int current_note = NO_NOTE;
int8_t current_velocity = 0;
bool should_update_velocity = false;
bool receiving_air = false;
bool is_holding_toggle_button = false;

int buttons_state[4];

void update_air_state();
void update_buttons_state();
void update_velocity();
void update_current_note();

void setup() {
  if (!air_press.init()) {
    while(1);
  }
  for(int i = 0; i < sizeof(BUTTONS_PIN) / sizeof(int); i++)
  {
    pinMode(BUTTONS_PIN[i], INPUT);
    buttons_state[i] = LOW;
  }
  pinMode(AIR_BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
  midiInterface.begin();
}

void loop() {
  update_air_state();
  update_buttons_state();
  update_velocity();
  update_current_note();
  midiInterface.update();
}

void update_air_state() {
  if(digitalRead(AIR_BUTTON_PIN) == HIGH)
  {
    if(is_holding_toggle_button == true) return;
    receiving_air = !receiving_air;
    is_holding_toggle_button = true;
  }
  else {
    is_holding_toggle_button = false;
  }
}

void update_current_note() {
  int new_note = getNote(buttons_state[0], buttons_state[1], buttons_state[2], buttons_state[3], receiving_air);
  if(new_note == NO_NOTE)
  {
    if(current_note == NO_NOTE) return;
    MIDIAddress previous_address = { current_note, DEFAULT_CHANNEL };
    midiInterface.sendNoteOff(previous_address, current_velocity);
  }
  else if(current_note != new_note || should_update_velocity == true)
  {
    if(current_note != NO_NOTE || (should_update_velocity && current_note == new_note))
    {
      MIDIAddress previous_address = { current_note, DEFAULT_CHANNEL };
      midiInterface.sendNoteOff(previous_address, current_velocity);
    }
    MIDIAddress address = { new_note, DEFAULT_CHANNEL };
    midiInterface.sendNoteOn(address, current_velocity);
  }
  current_note = new_note;
}

void update_buttons_state() {
  for(int i = 0; i < sizeof(BUTTONS_PIN) / sizeof(int); i++) { buttons_state[i] = digitalRead(BUTTONS_PIN[i]); }
}

void update_velocity() {
  //int a = air_press.read();
//  int8_t new_velocity = map(analogRead(ANALOG_PIN), 0, 1000, 0, 126);
//  int diff = abs_diff(new_velocity, current_velocity);
//  if(diff > MIN_VELOCITY_DIFF)
//  {
//    current_velocity = new_velocity;
//    should_update_velocity = true;
//  }
//  else 
//  {
//    should_update_velocity = false;
//  }
}
