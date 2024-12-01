#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHImages.h>
#include <FEHRandom.h>

using namespace std;

/*  Name:  Tommy Fitzgerald	Adrienne Clymer					  */
/*  Date:  11/17/2024     						  */
/*  Assignment:  Menu 					  */
/*  Seat:  22		Instructor:  Dr. H		Time:  10:20 */

// FEHImage fire, FEHImage lakeHouse, FEHImage otherImage
//This is the function for the introduction story which I am still working on
//will basically just show a bunch information/backstory with text and maybe a couple of images
void aStoryfortheAges(FEHImage badguy);

void Select_difficulty(int *score,char *lastlevel, int *gamesplayed, int *losses, int *wins);


//Function for the credits page
// Shows the play Game, instructions, credits, and stats pages
//stats needs to be fixed with actual statistics, 
//play game will exit the function inside maint o call a seperate run game function or a run game function will be made

class fireObjects
{
private:


public:
    int xmax, xmin, ymax, ymin;
    fireObjects();
    void fillem(int x, int y);
    void iswithin(int x, int y);
    void drawOne(FEHImage x);
    int status;

};


void easyModeGame(int *score, int *losses, int *wins, int *gamesplayed);

void level_medium(int *score, int *losses, int *wins, int *gamesplayed);

void level_hard(int *score, int *losses, int *wins, int *gamesplayed);

void putoutfireMedium(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle);

void putoutfireHard(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle);

void Spawnfire(fireObjects firearr[100], fireObjects firearr2[100], int fireCount, int spawnNumber);

void menuPage();

int main() {

  menuPage();

}


void fireObjects::drawOne(FEHImage fire1){
    fire1.Open("fire1.png");

        fire1.Draw(xmin,ymax);
}

void fireObjects::fillem(int x, int y){
    xmin = x;
    xmax = x + 25;
    ymin = y + 65;
    ymax = y;
    status = 0;
}

void fireObjects::iswithin(int x, int y){
    if (x > xmin && x < xmax && y < ymax && y > ymin) {
        status = 1;
    }
}


void putoutfireMedium(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle){

    FEHImage fire1,badguy,forest_2,winterforest;
    fire1.Open("fire1.png");
    badguy.Open("theOfficialBadGuy.png");
    forest_2.Open("forest_2.png");
    winterforest.Open("winter_forest.png");
    int j,k,copy = *score;

    if (cycle == 1){
            for (j = 0; j < 100; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    forest_2.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                   for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                    for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }
            for (j = 0; j < 100; j++){
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax+90) && touchY > (firearr2[j].ymax+55) && touchY < (firearr2[j].ymin+55)){
                    firearr2[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    forest_2.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                    for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }
    }else if (cycle == 2){
            for (j = 0; j < 100; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    winterforest.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                   for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                    for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }
            for (j = 0; j < 100; j++){
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax+90) && touchY > (firearr2[j].ymax+55) && touchY < (firearr2[j].ymin+55)){
                    firearr2[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    winterforest.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                    for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }

    }

            *score = copy;
}





void putoutfireHard(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle){

    FEHImage fire1,badguy,beach,desert,mountains;
    fire1.Open("fire1.png");
    badguy.Open("theOfficialBadGuy.png");
    beach.Open("beach.png");
    desert.Open("desert.png");
    mountains.Open("mountains.png");
    int j,k,copy = *score;

    if (cycle == 1){
            for (j = 0; j < 100; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    beach.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                   for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                    for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }
            for (j = 0; j < 100; j++){
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax+90) && touchY > (firearr2[j].ymax+55) && touchY < (firearr2[j].ymin+55)){
                    firearr2[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    beach.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                    for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                    break;
                }
            }
    }else if (cycle == 2){
            for (j = 0; j < 100; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    desert.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                   for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                    for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                     break;
                }
            }
            for (j = 0; j < 100; j++){
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax+90) && touchY > (firearr2[j].ymax+55) && touchY < (firearr2[j].ymin+55)){
                    firearr2[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    desert.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                    for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                     break;
                }
            }

    } else if (cycle == 3){
            for (j = 0; j < 100; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    mountains.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                   for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                    for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                     break;
                }
            }
            for (j = 0; j < 100; j++){
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax+90) && touchY > (firearr2[j].ymax+55) && touchY < (firearr2[j].ymin+55)){
                    firearr2[j].status = 1;
                    copy = copy + 1;
                    LCD.Clear();
                    mountains.Draw(0,0);
                    badguy.Draw(100,150);
                    LCD.Update();
                   
                    for (k = 0; k < 100; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   for (k = 0; k < 100; k++){
                    if (firearr2[k].status == 0){
                    fire1.Draw(firearr2[k].xmin,firearr2[k].ymax);    
                    }
                   }
                     break;
                }
            }

    }

            *score = copy;
}






void Spawnfire(fireObjects firearr[100],fireObjects firearr2[100], int fireCount){
FEHImage fire1;
fire1.Open("fire1.png");
  int j,k;
  int x = -80;
    for (j=0;j < fireCount; j++){
    fire1.Draw(x,0);
    firearr[j].fillem(x,0);
    x = x + 35;
    }
    x = -75;
    for (j=0;j < fireCount; j++){
    fire1.Draw(x,85);
    firearr2[j].fillem(x,85);
    x = x + 40;
    }

    fire1.Close();
    
}

//Fireobject Constructor
fireObjects::fireObjects(){
        xmax = 0;
        xmin = 0;
        ymax = 0;
        ymin = 0;
        status = 1;
    }


void level_medium(int *score, int *losses, int *wins, int *gamesplayed)
{
    //create the necessary variables that are used within the function
    FEHImage badguy, fire1, fire2, forest_2, other_image, winter_forest;
    int timeTracker, timer, fire_counter=0,touchX,touchY, loopTracker = 0,copy;
    *score = 0;
    fireObjects firearr[100], firearr2[100];

    while (loopTracker == 0){
    *gamesplayed = *gamesplayed + 1;    
    //open all of the necessary images
    winter_forest.Open("winter_forest.png");
    forest_2.Open("forest_2.png");
    badguy.Open("theOfficialBadGuy.png");
    fire1.Open("fire1.png");
    fire2.Open("fire2.png");

    //set the background color and display text that sets the scene
    LCD.SetBackgroundColor(WHEAT);
    LCD.Clear();
    LCD.SetFontColor(BLACK);
    LCD.Write("You are now in the        enchanted forest! The     trees here are thousands  of years old, you need to protect them before they  all die!     You only have 8 Seconds!");
    LCD.Update();
    Sleep(5.0);

    //draw the correct board with the background and the badguy along with text from the badguy
    LCD.SetBackgroundColor(WHEAT);
    LCD.Clear();
    forest_2.Draw(0,0);
    badguy.Draw(100,150);
    LCD.WriteAt("These trees need to burn!", 0,0);
    Sleep(3.0);

    //have the timer go for 30 seconds
    timeTracker = TimeNow();
         timer = 8;

    //call the fire spawning function to initially light things on fire
    //add one to the fire counter for how many times it is spawned
    fire_counter=1;
    Spawnfire(firearr,firearr2,5);

        while (((TimeNow()-timeTracker) < timer) && *score < 10)
        {   
        LCD.WriteAt(*score,0,0);
        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
          putoutfireMedium(firearr,firearr2,score,touchX,touchY,fire_counter);
            //call the putting out fires function so the user can do it during the entirety of the timer
            
        

        } 
        
    // Check if the user lost
if (*score < 10) {
    // Display "YOU LOST!" message
    LCD.Clear(WHEAT);
    LCD.SetFontColor(RED);
    LCD.Write("YOU LOST!");
    *losses += 1;

    // Display options: Play Again or Return to Menu
    LCD.WriteAt("Play again", 40, 60);
    LCD.WriteAt("or return to the menu!", 40, 100);

    // Draw buttons for "Return" and "Play"
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
    LCD.DrawRectangle(180, 150, 100, 30); // "Play" button

    // Fill buttons
    LCD.SetFontColor(WHITESMOKE);
    LCD.FillRectangle(40, 150, 100, 30);
    LCD.FillRectangle(180, 150, 100, 30);

    // Label buttons
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Return", 45, 150);
    LCD.WriteAt("Play", 185, 150);

    // Wait for user input
    while (!LCD.Touch(&touchX, &touchY)) {};
    while (LCD.Touch(&touchX, &touchY)) {};

    // Handle button selection
    if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
        *score += copy;       // Continue game
        loopTracker = 1;      // Restart loop
    } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
        copy = *score;        // Save current score
        *score = 0;           // Reset score
    }

}else{

    //display messege about the new setting
    LCD.SetBackgroundColor(WHEAT);
    LCD.Clear();
    LCD.SetFontColor(BLACK);
    LCD.Update();
    LCD.Write("Good work! that    should hold him off for a little . . . ");
    Sleep(4.0);

    LCD.SetBackgroundColor(LIGHTBLUE);
    LCD.Clear();
    LCD.SetFontColor(BLACK);
    LCD.Write("Oh no! It's winter now and he's  back! The trees are extra      fragile now, make sure to  click the fires and put  them out!");
    LCD.Update();
    Sleep(6.0);

    //go to the new setting
    LCD.SetBackgroundColor(LIGHTBLUE);
    LCD.Clear();
    winter_forest.Draw(0,0);
    badguy.Draw(150,170);
    LCD.Update();

    //have the timer go for 20 seconds
    timeTracker = TimeNow();
         timer = 20;

    //call the fire spawning function
    //set fire count to 2 so that the function knows to draw the winter forest
    fire_counter=2;
    Spawnfire(firearr,firearr2,5);

        while (((TimeNow()-timeTracker) < timer) && *score < 20)
        {   
        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
          putoutfireMedium(firearr,firearr2,score,touchX,touchY,fire_counter);
            //call the putting out fires function so the user can do it during the entirety of the timer
            
        

        } 
        
        //tells user they lost if they could not quench the fires in time
        if (*score < 20){
             // Display "YOU LOST!" message
    LCD.Clear(WHEAT);
    LCD.SetFontColor(RED);
    LCD.Write("YOU LOST!");
    *losses += 1;

    // Display options: Play Again or Return to Menu
    LCD.WriteAt("Play again", 40, 60);
    LCD.WriteAt("or return to the menu!", 40, 100);

    // Draw buttons for "Return" and "Play"
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
    LCD.DrawRectangle(180, 150, 100, 30); // "Play" button

    // Fill buttons
    LCD.SetFontColor(WHITESMOKE);
    LCD.FillRectangle(40, 150, 100, 30);
    LCD.FillRectangle(180, 150, 100, 30);

    // Label buttons
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Return", 45, 150);
    LCD.WriteAt("Play", 185, 150);

    // Wait for user input
    while (!LCD.Touch(&touchX, &touchY)) {};
    while (LCD.Touch(&touchX, &touchY)) {};

    // Handle button selection
    if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
        *score += copy;       // Continue game
        loopTracker = 1;      // Restart loop
    } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
        copy = *score;        // Save current score
        *score = 0;           // Reset score
    }
        }else {

        *wins = *wins + 1;
        LCD.Clear(WHEAT);
        LCD.Write("CONGRATS!");
        LCD.WriteAt("Play again",40,60);
        LCD.WriteAt("or return to the menu!",40,100);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(40,150,100,30);
        LCD.DrawRectangle(180,150,100,30);
        LCD.SetFontColor(WHITESMOKE);
        LCD.FillRectangle(40,150,100,30);
        LCD.FillRectangle(180,150,100,30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Return",45,150);
        LCD.WriteAt("Play",185,150);

        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};

        if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180){
        *score = *score + copy;
        loopTracker = 1;

        }   else if(touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180){
            copy = copy = *score;
            *score = 0;
            }
        }
        }
    }
}

void level_hard(int *score, int *losses, int *wins, int *gamesplayed)
{
    //create all of the necessary variables
    FEHImage badguy, beach, desert, mountains;
    int start, fire_counter, timer, timeTracker,touchX,touchY,loopTracker = 0,copy;
    *score = 0;
    fireObjects firearr[100], firearr2[100];

while(loopTracker == 0){
    *gamesplayed = *gamesplayed + 1;
    //open all of the necessary images
    badguy.Open("theOfficialBadGuy.png");
    beach.Open("beach.png");
    desert.Open("desert.png");
    mountains.Open("mountains.png");


    //set the background and add text to describe the situation
    LCD.SetBackgroundColor(WHEAT);
    LCD.Clear();
    LCD.SetFontColor(BLACK);
    LCD.Write("You just arrived at one of the last beaches in the  world, it's so pretty     here! These palm trees are one of a kind protect    them before they are lost      forever!");
    LCD.Update();
    Sleep(7.0);

    //draw the board 
    LCD.SetBackgroundColor(LIGHTSKYBLUE);
    LCD.Clear();
    beach.Draw(0,0);
    badguy.Draw(150,140);

    //have the timer go for 20 seconds
    timeTracker = TimeNow();
         timer = 10;

    //call the fire spawning function to initially light things on fire
    //set counter to one to know which scene to show
    fire_counter=1;
    Spawnfire(firearr,firearr2,7);

        while (((TimeNow()-timeTracker) < timer) && *score < 14)
        {   
        LCD.WriteAt(*score,0,0);
        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
          putoutfireHard(firearr,firearr2,score,touchX,touchY,fire_counter);
            //call the putting out fires function so the user can do it during the entirety of the timer
            
        } 

               //tells user they lost if they could not quench the fires in time
        if (*score < 14){
           // Display "YOU LOST!" message
    LCD.Clear(WHEAT);
    LCD.SetFontColor(RED);
    LCD.Write("YOU LOST!");
    *losses += 1;

    // Display options: Play Again or Return to Menu
    LCD.WriteAt("Play again", 40, 60);
    LCD.WriteAt("or return to the menu!", 40, 100);

    // Draw buttons for "Return" and "Play"
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
    LCD.DrawRectangle(180, 150, 100, 30); // "Play" button

    // Fill buttons
    LCD.SetFontColor(WHITESMOKE);
    LCD.FillRectangle(40, 150, 100, 30);
    LCD.FillRectangle(180, 150, 100, 30);

    // Label buttons
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Return", 45, 150);
    LCD.WriteAt("Play", 185, 150);

    // Wait for user input
    while (!LCD.Touch(&touchX, &touchY)) {};
    while (LCD.Touch(&touchX, &touchY)) {};

    // Handle button selection
    if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
        *score += copy;       // Continue game
        loopTracker = 1;      // Restart loop
    } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
        copy = *score;        // Save current score
        *score = 0;           // Reset score
    }
        }else{

    //display encouraging message about the battle
    LCD.SetBackgroundColor(WHEAT);
    LCD.Clear();
    LCD.SetFontColor(SCARLET);
    LCD.Write("Phew! Good   thing thats over,         hopefully he finally stops  with all of these fires  everywhere!");
    LCD.Update();
    Sleep(5.0);
    LCD.Clear();
    LCD.Write("What's this?  Now you're in the dessert! Some of these cacti have been alive for hundreds of years. Keep them alive   for hundreds more!");
    Sleep(8.0);
    LCD.Update();

    //draw board for second setting
    LCD.SetBackgroundColor(LIGHTPINK);
    LCD.Clear();
    desert.Draw(0,0);
    badguy.Draw(150,120);

    //set timer for 20 seconds
    timeTracker = TimeNow();
         timer = 10;

   //call the fire spawning function to initially light things on fire
    //set counter to one to know which scene to show
    fire_counter=2;
    Spawnfire(firearr,firearr2,8);

        while (((TimeNow()-timeTracker) < timer) && *score < 30)
        {   
        LCD.WriteAt(*score,0,0);
        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
          putoutfireHard(firearr,firearr2,score,touchX,touchY,fire_counter);
            //call the putting out fires function so the user can do it during the entirety of the timer
            
        } 

               //tells user they lost if they could not quench the fires in time
        if (*score < 30){
             // Display "YOU LOST!" message
    LCD.Clear(WHEAT);
    LCD.SetFontColor(RED);
    LCD.Write("YOU LOST!");
    *losses += 1;

    // Display options: Play Again or Return to Menu
    LCD.WriteAt("Play again", 40, 60);
    LCD.WriteAt("or return to the menu!", 40, 100);

    // Draw buttons for "Return" and "Play"
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
    LCD.DrawRectangle(180, 150, 100, 30); // "Play" button

    // Fill buttons
    LCD.SetFontColor(WHITESMOKE);
    LCD.FillRectangle(40, 150, 100, 30);
    LCD.FillRectangle(180, 150, 100, 30);

    // Label buttons
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Return", 45, 150);
    LCD.WriteAt("Play", 185, 150);

    // Wait for user input
    while (!LCD.Touch(&touchX, &touchY)) {};
    while (LCD.Touch(&touchX, &touchY)) {};

    // Handle button selection
    if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
        *score += copy;       // Continue game
        loopTracker = 1;      // Restart loop
    } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
        copy = *score;        // Save current score
        *score = 0;           // Reset score
    }
        }else{

        //display another messege
        LCD.SetBackgroundColor(WHEAT);
        LCD.Clear();
        LCD.Write("Wow!    you've fought off a lot offires today, it's         important to protect thesebeautiful places in our    environement");
        Sleep(6.0);
        LCD.Update();
        LCD.Clear();
        LCD.Write("You're in themountains now? Wow, what  an explorer! I wonder     where the monster could be?");
        Sleep(6.0);

        //draw the last board
        LCD.SetBackgroundColor(SKYBLUE);
        LCD.Clear();
        mountains.Draw(0,0);
        badguy.Draw(150,100);
        LCD.SetFontColor(BLACK);
        LCD.WriteRC("MUAHAHAH",0,0);
        LCD.WriteRC("This Moutain will burn!!",2,0);
        LCD.Update();
        
        //set timer for 20 seconds
    timeTracker = TimeNow();
         timer = 10;

    //call the fire spawning function to initially light things on fire
    //set counter to one to know which scene to show
    fire_counter=3;
    Spawnfire(firearr,firearr2,8);

        while (((TimeNow()-timeTracker) < timer) && *score < 46)
        {   
        LCD.WriteAt(*score,0,0);
        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
          putoutfireHard(firearr,firearr2,score,touchX,touchY,fire_counter);
            //call the putting out fires function so the user can do it during the entirety of the timer
            
        } 

               //tells user they lost if they could not quench the fires in time
        if (*score < 46){
             // Display "YOU LOST!" message
    LCD.Clear(WHEAT);
    LCD.SetFontColor(RED);
    LCD.Write("YOU LOST!");
    *losses += 1;

    // Display options: Play Again or Return to Menu
    LCD.WriteAt("Play again", 40, 60);
    LCD.WriteAt("or return to the menu!", 40, 100);

    // Draw buttons for "Return" and "Play"
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
    LCD.DrawRectangle(180, 150, 100, 30); // "Play" button

    // Fill buttons
    LCD.SetFontColor(WHITESMOKE);
    LCD.FillRectangle(40, 150, 100, 30);
    LCD.FillRectangle(180, 150, 100, 30);

    // Label buttons
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Return", 45, 150);
    LCD.WriteAt("Play", 185, 150);

    // Wait for user input
    while (!LCD.Touch(&touchX, &touchY)) {};
    while (LCD.Touch(&touchX, &touchY)) {};

    // Handle button selection
    if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
        *score += copy;       // Continue game
        loopTracker = 1;      // Restart loop
    } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
        copy = *score;        // Save current score
        *score = 0;           // Reset score
    }
        }else{

        *wins = *wins + 1;    
            //prompts user with Congrats message!
        LCD.Clear(WHEAT);
        LCD.Write("Way to go!");
        LCD.WriteAt("Thats the hardest one!",0,25);
        LCD.WriteAt("Play again",40,60);
        LCD.WriteAt("or return to the menu!",40,100);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(40,150,100,30);
        LCD.DrawRectangle(180,150,100,30);
        LCD.SetFontColor(WHITESMOKE);
        LCD.FillRectangle(40,150,100,30);
        LCD.FillRectangle(180,150,100,30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Return",45,150);
        LCD.WriteAt("Play",185,150);

        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};

        if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180){
        *score = *score + copy;
        loopTracker = 1;

        }   else if(touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180){
            copy = copy = *score;
            *score = 0;
            }

        }
    }
    }
}
}


void easyModeGame(int *score, int *losses, int *wins, int *gamesplayed){
    *score = 0;
    int loopTracker = 0;
   
    while (loopTracker == 0){
    *gamesplayed = *gamesplayed + 1;
    FEHImage badguy,fire1,fire2,town,town2;
    float timeTracker;
    int touchX,touchY;
    badguy.Open("theOfficialBadGuy.png");
    fire1.Open("fire1.png");
    fire2.Open("fire2.png");
    town.Open("town1.png");
    town2.Open("villageSecondAngle.png");

    LCD.Clear(WHITESMOKE);
    LCD.SetFontColor(BLACK);
    LCD.Write("Your mission starts in the Town, the mad man is going crazy and its up to you to drive him out of town and save the day!");
    LCD.Update();
    Sleep(5.0);
    LCD.Clear(WHITE);


           town.Draw(0,0);
    LCD.WriteAt("MUAHAHAH",20,180);
    Sleep(.5);
    LCD.WriteAt("MUAHAHAH",70,130);
        Sleep(.5);
    LCD.WriteAt("MUAHAHAH",10,20);
        Sleep(.5);
    LCD.WriteAt("MUAHAHAH",140,100);
        Sleep(.5);
    badguy.Draw(150,140);
        Sleep(.5);
        LCD.Clear();
        town.Draw(0,0);
        badguy.Draw(150,140);
        LCD.Write("Its over for you and these puny humans");
        Sleep(2.0);
        LCD.Clear();
        town.Draw(0,0);
        badguy.Draw(150,140);
    
     
        int j,k;
        int xtrack = -90,ytrack = -55;
        fireObjects firearr[100],firearrScene2[100];
        
        for (j = 0;j<4;j++){
            firearr[j].fillem(xtrack,ytrack);
            fire1.Draw(firearr[j].xmin,firearr[j].ymax);
            xtrack = xtrack + 85;

        }
        ytrack = ytrack + 85;
        xtrack = -60;
        for (j = 4;j<8;j++){
            
            firearr[j].fillem(xtrack,ytrack);
            fire1.Draw(firearr[j].xmin,firearr[j].ymin);
            xtrack = xtrack + 85;

        }
        timeTracker = TimeNow();
        int timer = 60;
        int round1 = 1;


        while ((TimeNow() - timeTracker < 10) && *score < 7){
            while(!LCD.Touch(&touchX,&touchY)) {};
            while(LCD.Touch(&touchX,&touchY)) {};

            for (j = 0; j < 8; j++){
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax+90) && touchY > (firearr[j].ymax+55) && touchY < (firearr[j].ymin+55)){
                    firearr[j].status = 1;
                    *score = *score + 1;
                    LCD.Clear();
                    town.Draw(0,0);
                    badguy.Draw(150,140);
                    LCD.Update();
                   
                   for (k = 0; k < 8; k++){
                    if (firearr[k].status == 0){
                    fire1.Draw(firearr[k].xmin,firearr[k].ymax);    
                    }
                   }
                   LCD.WriteAt(*score,0,0);

                }

            }
        }   

        if (*score < 7){
                LCD.Clear(WHEAT);
            LCD.SetFontColor(RED);
            LCD.Write("YOU LOST!");
            *losses = *losses + 1;
            Sleep(3.0);
            break;
        }else {

        Sleep(1.0);
        
        LCD.Clear();
        town.Draw(0,0);
        badguy.Draw(150,140);

        LCD.Write("Oh goddddd you are pretty strong ayye");
        Sleep(2.0);

        LCD.Clear();
        town2.Draw(0,0);
        badguy.Draw(120,140);

        LCD.Write("Well lets see how you handle this");
        Sleep(2.0);

        LCD.Clear();
        town2.Draw(0,0);
        badguy.Draw(120,140);

        xtrack = -90;
        ytrack = -55;
        for (j = 0;j<5;j++){
            firearrScene2[j].fillem(xtrack,ytrack);
            fire1.Draw(firearrScene2[j].xmin,firearrScene2[j].ymax);
            xtrack = xtrack + 55;

        }
        ytrack = ytrack + 55;
        xtrack = -60;
        for (j = 5;j<10;j++){
            firearrScene2[j].fillem(xtrack,ytrack);
            fire1.Draw(firearrScene2[j].xmin,firearrScene2[j].ymax);
            xtrack = xtrack + 85;
        }
        ytrack = ytrack + 55;
        xtrack = -60;
        for (j = 10;j<15;j++){
            firearrScene2[j].fillem(xtrack,ytrack);
            fire1.Draw(firearrScene2[j].xmin,firearrScene2[j].ymax);
            xtrack = xtrack + 85;
        }
        LCD.Update();

        timeTracker = 0;
        timeTracker = TimeNow();

        while ((TimeNow() - timeTracker < 15) && *score < 20){
            while(!LCD.Touch(&touchX,&touchY)) {};
            while(LCD.Touch(&touchX,&touchY)) {};

            for (j = 0; j < 15; j++){
                if (firearrScene2[j].status == 0){
                if (touchX > (firearrScene2[j].xmin + 90) && touchX < (firearrScene2[j].xmax+90) && touchY > (firearrScene2[j].ymax+55) && touchY < (firearrScene2[j].ymin+55)){
                    firearrScene2[j].status = 1;
                    *score = *score + 1;
                    LCD.Clear();
                    town2.Draw(0,0);
                    badguy.Draw(150,140);
                    LCD.Update();
                   
                   for (k = 0; k < 15; k++){
                    if (firearrScene2[k].status != 1){
                    fire1.Draw(firearrScene2[k].xmin,firearrScene2[k].ymax);    
                    }
                   }
                   LCD.WriteAt(*score,0,0);
                   LCD.Update();
                }
                }
            }
        }
        if (*score<20){
            LCD.Clear(WHEAT);
            LCD.SetFontColor(RED);
            LCD.Write("YOU LOST!");
            *losses = *losses + 1;
            Sleep(3.0);
            break;
            
        }else{

        *wins = *wins + 1;


        LCD.Clear();
        town2.Draw(0,0);
        badguy.Draw(120,140);
        LCD.Write("OHHHHHHH god you really care about the ENVIROMENT ahhhhhhhhhh");
        Sleep(4.0);
        LCD.Clear(WHEAT);
        LCD.Write("You are INCREDBLE!!!!");
        LCD.WriteAt("Play again",40,60);
        LCD.WriteAt("or return to the menu!",40,100);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(40,150,100,30);
        LCD.DrawRectangle(180,150,100,30);
        LCD.SetFontColor(WHITESMOKE);
        LCD.FillRectangle(40,150,100,30);
        LCD.FillRectangle(180,150,100,30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Return",45,150);
        LCD.WriteAt("Play",185,150);

        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};

        if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180){
        loopTracker = 1;

        }else if(touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180){
            
        }
        }
        }
    }
}


//create function that stores the selected difficuly in a character variable.
void Select_difficulty(int *score, char *lastlevel, int *gamesplayed, int *losses, int *wins)
{   

    *score = 0;
    int touchX,touchY;
    //set background color
    LCD.SetBackgroundColor(BEIGE);
    LCD.Clear();
    //promt the user to select their difficulty
    LCD.SetFontColor(BLACK);
    LCD.WriteRC("Select Your Difficulty",1,1);
    //create button for easy
    LCD.SetFontColor(GREEN);
    LCD.DrawRectangle(20,95,60,25);
    LCD.WriteRC("Easy",6,2);
    //create button for medium
    LCD.SetFontColor(YELLOW);
    LCD.DrawRectangle(118,95,80,25);
    LCD.WriteRC("Medium",6,10);
    //create button for hard
    LCD.SetFontColor(RED);
    LCD.DrawRectangle(235,95,60,25);
    LCD.WriteRC("Hard", 6,20);
    //create return button
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(118,180,80,25);
    LCD.WriteRC("Return", 11,10);
    //call the function easy to see if the user selected easy as their option
    //it will return true if they touched within the easy button
      while (1){
       //waiting for the touch 
    while(!LCD.Touch(&touchX,&touchY)){}
        //when it is touched
    while(LCD.Touch(&touchX,&touchY)){}

    if(touchX > 20 && touchX < 80 && touchY > 95 && touchY < 120)
    { //check by setting the screen to green and displaying the messege easy selected
        LCD.SetBackgroundColor(GREEN);
        LCD.Clear();
        LCD.WriteLine("Easy Selected!");
        Sleep(2.0);
        easyModeGame(score,losses,wins,gamesplayed);
        *lastlevel = 'E';
    }
//call medium to check the same thing
    else if(touchX > 118 && touchX < 198 && touchY > 95 && touchY < 120)
    {
        LCD.SetBackgroundColor(YELLOW);
        LCD.Clear();
        LCD.WriteLine("Medium Selected!");
        Sleep(2.0);
        level_medium(score,losses,wins,gamesplayed);
        *lastlevel = 'M';
    }
//call hard to check the same thing
    else if(touchX > 235 && touchX < 295 && touchY > 95 && touchY < 120)
    {
        LCD.SetBackgroundColor(RED);
        LCD.Clear();
        LCD.WriteLine("Hard Selected!");
        Sleep(2.0);
        level_hard(score,losses,wins,gamesplayed);
        *lastlevel = 'H';

    }
    else if(touchX > 118 && touchX < 198 && touchY > 180 && touchY < 205){
        break;
    }
  }
}

void aStoryfortheAges(FEHImage badguy){
    LCD.Clear(WHEAT);
    LCD.WriteLine("     It all began where mostthings begin, at the start.");
    LCD.Update();
    Sleep(3.0);
    LCD.Clear(WHEAT);
    LCD.WriteLine("A Young ambitous Turtle    set out to live amongst  the trees. He liked his        life by himself and \tnever bothered anyone, until one day....");
    LCD.Update();



    badguy.Open("theOfficialBadGuy.png");
    badguy.Draw(160,100);

}

void menuPage(){
 // Clear background
    int losses = 0,wins = 0;
    int score = 0,cumulativefires = 0;
    char lastleveltrack;
    float touchX, touchY, xtrash, ytrash;
    int menutrackingvar,x = 1,gamesplayed = 0;

    while (x = 1){
    menutrackingvar = 0;
   
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();
    FEHImage TreeMenu,CottageMenu,sky,grass;
    FEHImage badguy;


    grass.Open("grassy.png");
    grass.Draw(-45, 55);

    CottageMenu.Open("waterColor.png");
    CottageMenu.Draw(-100, -5);

    sky.Open("WC.png");
    sky.Draw(100, -5);

    TreeMenu.Open("pngwing.com.png");
    TreeMenu.Draw(-15, -25);

    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(20,140,120,30);
    LCD.SetFontColor(GHOSTWHITE);
    LCD.FillRectangle(20,140,120,30);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Play Game",25,150);

    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(180,140,120,30);
    LCD.SetFontColor(GHOSTWHITE);
    LCD.FillRectangle(180,140,120,30);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Stats",210,148);


    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(20,190,120,30);
    LCD.SetFontColor(GHOSTWHITE);
    LCD.FillRectangle(20,190,120,30);
     LCD.SetFontColor(BLACK);
    LCD.WriteAt("Instructions",21,198);


    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(180,190,120,30);
    LCD.SetFontColor(GHOSTWHITE);
    LCD.FillRectangle(180,190,120,30);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Credits",210,198);

    LCD.WriteAt("X",20,30);

    LCD.SetFontColor(SCARLET);
    LCD.WriteAt("Enviromental Man:",60,20);
    LCD.WriteAt("The Game!",100,60);
    LCD.Update();
    Sleep(.50);

    

        /* Wait until the user touches the screen */
    while(!LCD.Touch(&touchX,&touchY)) {};
    while(LCD.Touch(&touchX,&touchY)) {};

         if(touchX >= 20 && touchX <= 30 && touchY >= 30 && touchY <= 40){
           break;

    }else if (touchX >= 180 && touchX <= 300 && touchY >= 140 && touchY <= 170){
        while (menutrackingvar == 0){
            LCD.Clear(WHEAT);
            LCD.SetFontColor(RED);
            LCD.WriteAt("Statistics",100,25);
            LCD.WriteAt("Games Played....",10,55);
            LCD.WriteAt(gamesplayed,220,55);
            LCD.WriteAt("Difficulty.... ",10,85);
            LCD.WriteAt(lastleveltrack,220,85);
            LCD.WriteAt("Fires put out.... ",10,115);
            LCD.WriteAt(cumulativefires,220,115);
            LCD.WriteAt("Wins.... ",10,145);
            LCD.WriteAt(wins,220,145);
            LCD.WriteAt("Losses.... ",10,175);
            LCD.WriteAt(losses,220,175);
            
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(10,200,80,25);
            LCD.SetFontColor(WHITE);
            LCD.FillRectangle(11,199,78,23);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Reset",11,200);




          
            LCD.Update();
       
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(200,200,100,30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(200,200,100,30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Return",210,205);
            
            while(!LCD.Touch(&touchX,&touchY)) {};
            while(LCD.Touch(&touchX,&touchY)) {};
            if (touchX >= 200 && touchX <= 300 && touchY >= 200 && touchY <= 230){

                menutrackingvar = 1;
            
            } else if (touchX >= 10 && touchX <= 90 && touchY >= 200 && touchY <= 225){
                wins = 0;
                losses = 0;
                cumulativefires = 0;
                lastleveltrack = '?';
                gamesplayed = 0;
            }

        }
    } else if(touchX >= 180 && touchX <= 300 && touchY >= 190 && touchY <= 210){
           

            LCD.Clear(WHEAT);
            LCD.WriteAt("Credits",120,25);
            LCD.WriteAt("Made By", 120, 120);
            LCD.WriteAt("Adrienne Clymer",80,140); 
            LCD.WriteAt("and Thomas Fitzgerald",40,160);
            LCD.Update();
        while (menutrackingvar == 0){
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(20,200,100,30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(20,200,100,30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Return",25,205);
            
            while(!LCD.Touch(&touchX,&touchY)) {};
            if (touchX >= 20 && touchX <= 120 && touchY >= 200 && touchY <= 230){

                menutrackingvar = 1;
            
            }
        }
           
        

    }else if(touchX >= 20 && touchX <= 140 && touchY >= 190 && touchY <= 210){
            LCD.Clear(WHEAT);
            LCD.Write("A monster has appeared in the xyz kingdom. They are causing a ruckus with their fires. It is up to you to save the kingdom and win the day!");
            while(!LCD.Touch(&touchX,&touchY)) {};
            while(LCD.Touch(&touchX,&touchY)) {};
            LCD.Clear(WHEAT);
            LCD.Write("Save the trees and help our enviroment by clicking on the fires as they pop up. Make sure to get them in time or you will lose a life. You can select up to three levels of difficullty but be warned Hard is a real challenge.");
            LCD.Update();


            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(200,200,100,30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(200,200,100,30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Return",210,205);

            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(50,200,100,30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(50,200,100,30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Story",60,205);

        while (menutrackingvar == 0){

        while(!LCD.Touch(&touchX,&touchY)) {};
        while(LCD.Touch(&touchX,&touchY)) {};
            if (touchX >= 200 && touchX <= 300 && touchY >= 200 && touchY <= 230){

                menutrackingvar = 1;
            
            }else if (touchX >= 50 && touchX <= 150 && touchY >= 200 && touchY <= 230){
                
                aStoryfortheAges(badguy);
           
            } 
        }
    }else if(touchX >= 20 && touchX <= 140 && touchY >= 120 && touchY <= 170){
          score = 0;
          Select_difficulty(&score,&lastleveltrack,&gamesplayed,&losses,&wins);
          cumulativefires = cumulativefires + score;

    }
  }
}
