const uint8_t btn1 = 2;
const uint8_t btn2 = 3;
const uint8_t btn3 = 4;
const uint8_t btn4 = 5;

/*

  B1 | B2
  ---+---
  B3 | B4

  B + index

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
int buttonsPressedState[] = {LOW, LOW, LOW, LOW};

/*
  n = next (proxima oitava)
  p = past (oitava anterior)
  h = sharp
  b = bemol

  vamos pegar o valor por index convertendo o array com o estado dos botoes em binario
*/
enum PressedNote {
  C, 
  Cn, 
  D, 
  E, 
  F, 
  G, 
  Gp, 
  A, 
  Ap, 
  B, 
  Bp,
  Cb, 
  Eh, 
  Fh, 
  Fb, 
  Gh, 
  Gb, 
  Ah, 
  Ab, 
  Bh, 
  Bb
} currentNote;

void setupButtons() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
}

void updateCurrentNote() {
  buttonsPressedState[0] = digitalRead(btn1);
  buttonsPressedState[1] = digitalRead(btn2);
  buttonsPressedState[2] = digitalRead(btn2);
  buttonsPressedState[3] = digitalRead(btn2);

  if(buttonsPressedState[0] == HIGH) {
    fPressedState();
  }
}

void fPressedState() {
  if(buttonsPressedState[1] == HIGH) {
    fsPressedState();
  } else if (buttonsPressedState[2] == HIGH) {
    ftPressedState();  
  } else if (buttonsPressedState[3] == HIGH) {
    currentNote = Ap;
  } else {
    currentNote = Gh;
  }
}

// quando o B1 e B2 estiver sendo pressionado
void fsPressedState() {
  if(buttonsPressedState[2] == HIGH) {
    fstPressedState();
  } else if (buttonsPressedState[3] == HIGH) {
    currentNote = Bp;
  } else {
    currentNote = Ah;
  }
}

// quando o B1, B2 e B3 estiver sendo pressionado
void fstPressedState() {
  if(buttonsPressedState[3] == HIGH) {
    currentNote = C;
  } else {
    currentNote = E;
  }
}

// quando o B1 e o B3 estiver sendo pressionado
// vai chegar aqui apenas se o primeiro estiver, mas o segundo nao
void ftPressedState() {
  if(buttonsPressedState[3] == HIGH) {
    currentNote == D;
  } else {
    currentNote = F;
  }
}











