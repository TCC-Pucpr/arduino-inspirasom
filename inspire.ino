boolean newData = false;
const char MSG_BEGIN_CHAR = '{';
const char MSG_END_CHAR = '}';
const int MAX_MESSAGE_SIZE = 32;
char message[MAX_MESSAGE_SIZE];

String receiveMessage();
void sendMessage();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("\nArduino setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveMessage();
  sendMessage();
  //receiveAndSend();
}

String receiveMessage() {
  static boolean receivingData = false;
  static byte index = 0;
  char received;
  while(Serial.available() > 0 && newData == false) {
    received = Serial.read();
    if(receivingData == true) {
      if(received == MSG_END_CHAR) {
        message[index] = '\0';
        receivingData = false;
        newData = true;
        index = 0;
      } else {
        message[index] = received;
        index++;
        if(index >= MAX_MESSAGE_SIZE) {
          index = MAX_MESSAGE_SIZE - 1;
        }
      }
    } else if(received == MSG_BEGIN_CHAR) {
      receivingData = true;
    }
  }
}

void sendMessage() {
  if(newData == true) {
    Serial.write(MSG_BEGIN_CHAR);
    Serial.write(message);
    Serial.write(MSG_END_CHAR);
    newData = false;
  }
}