#include <SPI.h>
#include <LoRa.h>
#include <SSD1306.h>
#include <Arduino.h>
#include <DHT.h>;

#include <OneWire.h>
#include <DS18B20.h>

#define ONE_WIRE_BUS 17

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

#define DHTPIN 22     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//OLED pins to ESP32 GPIOs via this connecthin:
//OLED_SDA -- GPIO4
//OLED_SCL -- GPIO15
//OLED_RST -- GPIO16

SSD1306  display(0x3c, 4, 15);


// WIFI_LoRa_32 ports

// GPIO5  -- SX1278's SCK
// GPIO19 -- SX1278's MISO
// GPIO27 -- SX1278's MOSI
// GPIO18 -- SX1278's CS
// GPIO14 -- SX1278's RESET
// GPIO26 -- SX1278's IRQ(Interrupt Request)

#define SS      18
#define RST     14
#define DI0     26
#define BAND    868E6//915E6 

int counter = 0;

void setup() {
  pinMode(25,OUTPUT); //Send success, LED will bright 1 second
  
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH);
  
  Serial.begin(115200);
  while (!Serial); //If just the the basic function, must connect to a computer
 
  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(5,5,"LoRa Sender");
  display.display();
  
  SPI.begin(5,19,27,18);
  LoRa.setPins(SS,RST,DI0);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initial OK!");
  display.drawString(5,20,"LoRa Initializing OK!");
  display.display();
  delay(2000);
  
  sensor.begin();
   dht.begin();
}

void loop() {

  delay(2000);
  sensor.requestTemperatures();
  
  while (!sensor.isConversionComplete());  // wait until sensor is ready

 
  Serial.print("Sending packet: ");
  Serial.println(counter);
  
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(3, 5, "Sending packet ");
  display.drawString(50, 30, String(sensor.getTempC()));
  display.drawString(50, 46, String(dht.readHumidity()));
  
  display.display();

  
  Serial.print("Temp: ");
  Serial.println(sensor.getTempC());
  
  // send packet
  LoRa.beginPacket();
  LoRa.print("Hello..");
  LoRa.print(sensor.getTempC());
  LoRa.print(dht.readHumidity());
  LoRa.endPacket();
  
  //counter++;
  digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  
}
