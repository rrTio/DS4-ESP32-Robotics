#include <PS4Controller.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>
#include <MOTORDRIVER.h>

int enableA  = 26;
int in_1 = 25;
int in_2 = 33;

int enableB = 5;
int in_3 = 18;
int in_4 = 19;

int connectionLed = 12;

motorDriver motorDriver(enableA, enableB, in_1, in_2, in_3, in_4);

int normalSpeed = 175;
int overdrive = 255;

void notify()
{
  if(PS4.Cross())
  {
    motorDriver.forward(normalSpeed, normalSpeed);
    Serial.println("CROSS BUTTON - FORWARD");
  }

  if(PS4.Square())
  {
    motorDriver.backward(normalSpeed, normalSpeed);
    Serial.println("SQUARE BUTTON - BACKWARD");
  }

  if(PS4.Circle())
  {
    motorDriver.halt();
    Serial.println("CIRCLE BUTTON - STOP");
  }

  if(PS4.Left())
  {
    motorDriver.left(100, normalSpeed);
    Serial.println("LEFT BUTTON - LEFT");
  }

  if(PS4.Right())
  {
    motorDriver.right(normalSpeed,100);
    Serial.println("RIGHT BUTTON - RIGHT");
  }

  if(PS4.L1())
  {
    motorDriver.rotateCCW(normalSpeed, normalSpeed);
    Serial.println("L1 BUTTON - ROTATE COUNTER CLOCKWISE");
  }

  if(PS4.R1())
  {
    motorDriver.rotateCW(normalSpeed, normalSpeed);
    Serial.println("R1 BUTTON - ROTATE CLOCKWISE");
  }

  if(PS4.R2())
  {
    motorDriver.forward(overdrive, overdrive);
    Serial.println("R2 BUTTON - OVERDRIVE");
  }

  if(PS4.L2())
  {
    motorDriver.backward(overdrive, overdrive);
    Serial.println("L2 BUTTON - OVERDRIVE");
  }
  else 
  {
    motorDriver.halt();
  }
}

void onConnect()
{
  Serial.println("Connected!.");
  digitalWrite(connectionLed, HIGH);
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setup() 
{
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin("ec:62:60:9a:3d:a6");
  const uint8_t* address = esp_bt_dev_get_address();
  char str[100];
  sprintf(str, "ESP32's Bluetooth MAC address is - %02x:%02x:%02x:%02x:%02x:%02x", address[0],address[1],address[2],address[3],address[4],address[5]);
  Serial.println(str);
  Serial.println("Ready.");
  pinMode(connectionLed, OUTPUT);
}

void loop() 
{
//blank
}
