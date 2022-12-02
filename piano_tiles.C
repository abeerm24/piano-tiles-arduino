// Define list of notes used in the song

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>  // Touchscreen commands library

// Initialize touchscreen
#if defined(SAM3X8E)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7

// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).
//   D0 connects to digital pin 22
//   D1 connects to digital pin 23
//   D2 connects to digital pin 24
//   D3 connects to digital pin 25
//   D4 connects to digital pin 26
//   D5 connects to digital pin 27
//   D6 connects to digital pin 28
//   D7 connects to digital pin 29

// For the Arduino Due, use digital pins 33 through 40
// (on the 2-row header at the end of the board).
//   D0 connects to digital pin 33
//   D1 connects to digital pin 34
//   D2 connects to digital pin 35
//   D3 connects to digital pin 36
//   D4 connects to digital pin 37
//   D5 connects to digital pin 38
//   D6 connects to digital pin 39
//   D7 connects to digital pin 40

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

// Predefined quantities for operating the touchscreen
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

// Initialize the touchscreen object to detect touches
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Initialize the tft object (used to display the graphics)
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int tempo = 144;  // Song tempo

// change this to whichever pin you want to use
int buzzer = 11;  // Pin no. used to control the buzzer

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int harrypotter[] = {


  // Hedwig's theme fromn the Harry Potter Movies
  // Socre from https://musescore.com/user/3811306/scores/4906610
  
   NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
   NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1, 
  
};

/*
 * Note durations calculated from the above data using the following C++ script:

    int noteDuration;
    int thisNote = 0;
    int wholenote = 60000*4/tempo;
    int notes = sizeof(rickroll) / sizeof(rickroll[0]) / 2;
    int noteDurations[notes];
    int cumulDurations[notes];
    int cumul = 0;
    int i=0;
    while(thisNote < 2*notes){
    int divider = harrypotter[thisNote + 1];
    if (divider > 0) {
    // regular note, just proceed
    noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
    // dotted notes are represented with negative durations!!
    noteDuration = (wholenote) / abs(divider);
    noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    noteDurations[i] = int(noteDuration/2);
    cumul+=noteDurations[i];
    cumulDurations[i] = cumul;
    thisNote += 2;
    i+=1;
    }

 */

// Array of the durations for which each note in the song must be played
int noteDuration [ ]
{263,394,131,263,526,263,789,789,394,131,263,526,263,1578,263,394,131,263,526,263,526,263,526,263,394,131,
263,526,263,1578,263,526,263,526,263,526,263,526,263,394,131,263,526,263,1578,263,526,263,526,263,526,263,526,263,394,131,263,526,263,1578};

// Variable to keep track of the cumulative note duration
int cumnoteduration = 0;

int count = 0;

// Calculate the no. of notes in the song notes array
int notes = sizeof(harrypotter) / sizeof(harrypotter[0]) / 2;
// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0;
int rate = 20;

// Define a struct box
typedef struct{
  public:
  int color;
  int colum;
  int y;

  void updatePos(int rate){
    y+=rate;
  }
} Box;

Box boxList[5];


// Store the last and the current colum no. that was randomly initialized
int lastrand; 
int currrand;


void setup(void) {
  Serial.begin(9600);   // Initialize baud rate for serial monitor
  Serial.println(F("Piano tiles!"));  // Print some welcome text (for debugging)

  tft.reset();  // Reset the LCD before begining

  // Initialize the tft lcd screen to display graphics
  uint16_t identifier = tft.readID();
  tft.begin(identifier);

  // Initialize the empty black screen
  tft.fillScreen(BLACK);

  pinMode(13, OUTPUT); // Pin 13 is used while detecting touches as seen in the main loop

  // Print the TFT screen dimensions (to check that the initialization and connection was successfull
  Serial.println(tft.width());
  Serial.println(tft.height());

  // Intialize the first element in the boxList 
  boxList[0].color = RED;
  boxList[0].y = 30;
  lastrand = rand()%4;
  boxList[0].colum = lastrand;

  tft.setTextSize(2);
  tft.setTextColor(BLACK);
}

#define MINPRESSURE 10
#define MAXPRESSURE 1000
#define BOXSIZE 60

int y = 30; // Initialize y coordinate

// if sharing pins, you'll need to fix the directions of the touchscreen pins
//pinMode(XP, OUTPUT);

//pinMode(YM, OUTPUT);

int thisNote = 0; // Track the position of the current node being played
int len = 0;      // No. of boxes in boxList, i.e. the no. of non-empty elements in the boxList array
int t1=0;         // Variable to track the current time since the game started running

void loop() {

  // Display the top part of the screen on the TFT LCD
  tft.fillRect(0,0,tft.width(),30,CYAN);
  tft.setCursor(60,15);
  tft.print("Piano tiles");
  
  // Find length of boxList
  len = 0;
  for(int i=0; i<5; i++){
    if(boxList[i].color!=NULL){ // Count the no. of non null elements at the start of the loop
      len += 1;
    }
    else{ // Stop counting on encountering null elements
      break;
    }
  } 
  // Added for debugging
  Serial.println("length");
  Serial.println(len);  

  // Detect touch
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  
  // Rescale the quantities from 0->1023 to 0 to tft.width
  p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
  p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
  // Added for caliberation
  p.x = tft.width() - p.x;
  p.y = tft.height() - p.y;

  int x0, y0, listPos = 0;
  // x0 tracks the colum no. of the box to be pressed currently
  // y0 tracks the y coordinate of the box to be pressed currently
  // listPos is the current position of the first unpressed box in the list

  // Check for the position of the first unpressed box in the boxList 
  bool firsttime = true;  // Flag to track whether the red box (i.e. the unpressed box) is the first unpressed box in the list or not
  for(int i=0; i<len;i++){  // Display all the boxes in the list
    Box box = boxList[i];
    tft.fillRect(BOXSIZE*box.colum,box.y,BOXSIZE,2*BOXSIZE,box.color); // Display the box boxList[i]
    
    if(box.color==RED && firsttime){
      listPos = i;  // Update listPos
      x0 = boxList[i].colum; // Update colum no.
      y0 = boxList[i].y;    // Update y coordinate
      firsttime = false;  // Set the firsttime flag to false
    }
  }

  // Check whether user touch is at the appropriate position
  if(p.z > MINPRESSURE && p.z < MAXPRESSURE){ // Check whether the pressure applied by the uset on touch is in the appropriate range
    // Check whether the (x,y) coordinates of touch lie inside the box to be touched    
    if(p.x < BOXSIZE*(x0+1) && p.x > BOXSIZE*x0){
      if(p.y > y0 && p.y < y0+2*BOXSIZE){
        if (boxList[listPos].color!=BLUE){
          boxList[listPos].color = BLUE;

        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(buzzer, harrypotter[thisNote], noteDuration[count]* 0.9);

        // Wait for the specief duration before playing the next note.
        //delay(noteDuration);

        // stop the waveform generation before the next note.
        //noTone(buzzer);
        
        t1 = millis();  // Record the time of touch
        thisNote+=2;    // Increment the thisNote position
        }
        if (thisNote>=2*notes){
          thisNote = 0; // Restart the loop if thisNote exceeds the array length
        }
      }
    }
  }
  int t = millis();
  delay(5); // Add a delay of 5 ms before erasing the boxes and updating their positions
  for(int i=0; i< len;i++){
    Box box = boxList[i]; // Load the i-th box in boxList
    boxList[i].updatePos(rate); // Update the position of boxList[i]
    tft.fillRect(BOXSIZE*box.colum,box.y,BOXSIZE,2*BOXSIZE, BLACK); // Erase the previous rectangle

  }
  
  if( t > cumnoteduration*2){ // Check whether threshold time limit has been exceeded or not
    // Initialize a new box
    boxList[len].color = RED; 
    boxList[len].y = 30;
    currrand = rand()%4; // Find the colum no. for the new tile to be generated
    while(currrand == lastrand ){currrand = rand()%4;}  // Change the current random variable value until it's different from the last one
    boxList[len].colum = currrand;
    count = count + 1;
    cumnoteduration += noteDuration[count];
  }
  if(boxList[0].y >= 320-2*BOXSIZE){ // Erase the blocks that have reached the bottom of the list
    Box box = boxList[0];
    tft.fillRect(BOXSIZE*box.colum,box.y,BOXSIZE,2*BOXSIZE, BLACK);

    // Remove those elements from the list
    for(int i=0; i<len-1; i++){
      boxList[i] = boxList[i+1];
    }
    for(int i=len-1; i<5; i++){
      boxList[i].color = NULL;
      boxList[i].y = NULL;
      boxList[i].colum = NULL;
    }
    
  }
}
  
