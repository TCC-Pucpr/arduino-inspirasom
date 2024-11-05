/*
  B1 | B2
  ---+---
  B3 | B4

(da esquerda para a direita do teclado)
  G: (o mais grave vai ser o sol)
  0 | 1
  --+--
  0 | 1

  G#/Fb:
  1 | 0
  --+--
  0 | 0

  A:
  1 | 0
  --+--
  0 | 1

  A#/Bb:
  1 | 1
  --+--
  0 | 0

  B#/Cb:
  1 | 1
  --+--
  0 | 1

  C: dó central
  1 | 1
  --+--
  1 | 1

  (nao teremos C#/Db, D#/Eb)

  D:
  1 | 0
  --+--
  1 | 1

  E:
  1 | 1
  --+--
  1 | 0

  F:
  1 | 0
  --+--
  1 | 0

  F#/Gb:
  0 | 1
  --+--
  1 | 1

  G:
  0 | 0
  --+--
  1 | 1

  G#/Ab:
  0 | 1
  --+--
  1 | 0

  A:
  0 | 0
  --+--
  1 | 0

  A#/Bb:
  0 | 0
  --+--
  0 | 1

  B:
  0 | 1
  --+--
  0 | 0

  (prox oitava)
  C:
  0 | 0
  --+--
  0 | 0
*/

#include "button_notes.hpp"

int8_t DEFAULT_NOTE = MIDI_Notes::C[5];

const int8_t combinations_array[16] = {
  DEFAULT_NOTE,
  MIDI_Notes::Ab[3],
  MIDI_Notes::B[4],
  MIDI_Notes::Bb[3],
  MIDI_Notes::A[4],
  MIDI_Notes::F[4],
  MIDI_Notes::Ab[4],
  MIDI_Notes::E[4],
  MIDI_Notes::Bb[4],
  MIDI_Notes::A[3],
  MIDI_Notes::G[3],
  MIDI_Notes::B[3],
  MIDI_Notes::G[4],
  MIDI_Notes::D[4],
  MIDI_Notes::Gb[4],
  MIDI_Notes::C[4]
};

int8_t getNote(bool button1_state, bool button2_state, bool button3_state, bool button4_state, bool airState)
{
  if(airState == false) return NO_NOTE;
  uint8_t index = (button4_state << 3) | (button3_state << 2) | (button2_state << 1) | button1_state;
  return combinations_array[index];
}
