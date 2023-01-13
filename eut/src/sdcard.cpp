#include <string.h>
/*
https://github.com/espressif/arduino-esp32/blob/master/libraries/SD/examples/SD_Test/SD_Test.
*/

//The SD library allows for reading from and writing to SD cards, the library also include "FS.h" and "SPI.h".
#include "sdcard.h"
extern char summary[7][32];
String readStr = "";
void testSD(){
  //HSPI, SPI bus mapped to pins 12 - 15
  SPIClass spi = SPIClass();
  Serial.print("Initializing SD card...\n");
  spi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);//HSPI

  if(!SD.begin(SD_CS, spi)){
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();

    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return;
    }
    //Show SD card type
    Serial.print("SD Card Type: ");
    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }
    //Show SD card size
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);
    Serial.println("------------------------------");
    //Write and read file
    const char * writeMeg = "Hello";
    writeFile(SD, "/hello.txt", writeMeg);//Overwrite a file

    readFile(SD, "/hello.txt");
    Serial.println("------------------------------");
    //Delete and rename a file
    deleteFile(SD, "/hello.txt");
    Serial.println("------------------------------");
    //測試成功條件:比較write跟read字串是否相等
    if(strcmp(readStr.c_str(), writeMeg)==0){
      Serial.println("SDcard test is OK");
      summary[SDCARD][1] = '0';
    }
    else {
      Serial.println("SDcard test is failed");
      summary[SDCARD][1] = '1';
    }
    

}
void readFile(fs::FS &fs, const char * path){
    
    Serial.printf("Reading file: %s\n", path);

    File file = fs.open(path);
    if(!file){
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.print("Read from file: ");
    while(file.available()){
        // Serial.write(file.read());
        readStr = file.readString();
    }
    Serial.println(readStr);
    file.close();
    
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);//file write
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written\n");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}


void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\n", path);
    if(fs.remove(path)){
        Serial.println("File deleted");
    } else {
        Serial.println("Delete failed");
    }
}