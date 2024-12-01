#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHImages.h>
#include <FEHRandom.h>

using namespace std;

/*  Name:  Tommy Fitzgerald	Adrienne Clymer					  */
/*  Date:  11/17/2024     						  */
/*  Assignment:  Menu 					  */
/*  Seat:  22		Instructor:  Dr. H		Time:  10:20 */

/* The function aStoryfortheAges is called after the player chooses to view the story after reading the instructions
Input parameters are the badguy image and it tells the story of how the bad guy became bad after stubbing his 
toe on a tree and then vowing to hate the environment and burn it down
Author: Tommy Fitzgerald
*/
void aStoryfortheAges(FEHImage badguy);




/*Select Difficulty takes in 5 input parameters all pointers to tracked statistics in the Menu page
Select difficulty is called after the user clicks the play game button and is then prompted to select a difficulty with the
abilty to return to the home page. 
once a difficulty has been selected the Select Difficulty calls the corresponding level function and the player begins the level
Author: Adrienne Clymer, Tommy Fitzgerald
*/
void Select_difficulty(int *score,char *lastlevel, int *gamesplayed, int *losses, int *wins);


/*Fire Objects Class public members xmax,xmin,ymax,ymin which represent the dimensions/location of a fire object and is used to track if a touch hits a fire object
The status member tracks if a Fire should be on the screen with 1 being not on the screen and 0 being on the screen
Each member function will be discussed in depth above their respective definitions
Author: Tommy Fitzgerald
*/
class fireObjects
{
public:
    int xmax, xmin, ymax, ymin;
    fireObjects();
    void fillem(int x, int y);
    void iswithin(int x, int y);
    void drawOne(FEHImage x);
    int status;

};


/*EasyModeGame takes in the same pointer inputs as Select difficulty except lastlevl as none of the gamemodes alter lastlevel inside the func
Score tracks the number of fires in each game and gets added to a cummlative count for the total fires statistic
losses tracks if you lose any of the gamemode and is shown in the statistics page as well
Wins tracks when you win the game
gamesplayed is incremented everytime any of the gamemode functions are called
The purpose of this function is to display the easy level in its entirety and track statistics throughout
it displays images fires and messages from the monster for the user to put out and win
Author: Adrienne Clymer, Tommy Fitzgerald
*/
void easyModeGame(int *score, int *losses, int *wins, int *gamesplayed);



/*level_medium takes in the same pointer inputs as the easy level
Score tracks the number of fires in each game and gets added to a cummlative count for the total fires statistic
losses tracks if you lose any of the gamemode and is shown in the statistics page as well
Wins tracks when you win the game
gamesplayed is incremented everytime any of the gamemode functions are called
The purpose of this function is to display the medium level in its entirety and track statistics throughout
it displays images, fires, and messages from the monster for the user to put out and win or lose the level
Author: Adrienne Clymer, Tommy Fitzgerald
*/

void level_medium(int *score, int *losses, int *wins, int *gamesplayed);






/*level_hard takes in the same pointer inputs as the easy level
Score tracks the number of fires in each game and gets added to a cummlative count for the total fires statistic
losses tracks if you lose any of the gamemode and is shown in the statistics page as well
Wins tracks when you win the game
gamesplayed is incremented everytime any of the gamemode functions are called
The purpose of this function is to display the hard level in its entirety and track statistics throughout
it displays images, fires, and messages from the monster for the user to put out and win or lose the level
Author: Adrienne Clymer, Tommy Fitzgerald
*/

void level_hard(int *score, int *losses, int *wins, int *gamesplayed);




/*putoutfire easy,medium,hard 
All three of these functions take in the same inputs, two fire arrays that will be iterated through to check to see if the
touchX and touchY that are also inputs for the functions are within any of the fire objects x and y values
Cycle tracks which scene of the level the fire should be
The purpose of this function is to check to see if a touch is within the bounds of the fires if it is
then remove that fire and redraw all of the other fires that should be spawned in for the respective level
Author: Tommy Fitzgerald
*/

void putoutfireMedium(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle);

void putoutfireEasy(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle);

void putoutfireHard(fireObjects firearr[100],fireObjects firearr2[100],int *score,int touchX,int touchY, int cycle);




/*SpawnFire 
    Spawn Fire takes in two fire arrays to which house the fire objects that will be drawn to the screen
    firecount is the number of fires that will be spawned from each array or half the total number of fires that will be spawned
    The purpose of this function is to one draw the fires initially to the screen but also create the fireobjects inside of the both arrays
    which house all of the information of each of the fires drawn
Author: Tommy Fitzgerald
*/

void Spawnfire(fireObjects firearr[100], fireObjects firearr2[100], int fireCount);





/*MenuPage()
This function is the game controller it hosts all of the other functions together to run the game continously until exited
Inside the function The initial menu page is created along with the variables for the tracked statistics 
The function repeats a while loop that allows for many games to be played and staitics to track across games
Author Tommy Fitzgerald, Adrienne Clymer
*/
void menuPage();


//Main function calls Menupage();
int main() {

  menuPage();

}



/*Member function drawOne frome FireObjects takes in a FEHimage for the fire
opens image and draws it in the Fire Objects respective location
Author: Tommy Fitzgerald
*/
void fireObjects::drawOne(FEHImage fire1){
    fire1.Open("fire1.png");

        fire1.Draw(xmin,ymax);
}





/*Member function fillem frome FireObjects takes in the x and y coordinates of the top left corner of the fire
sets members xmin,xmax,ymin,ymax to the proper dimensions given the inputted x and y
also sets status to 0 meaning the fire now exists on the screen
Author: Tommy Fitzgerald
*/

void fireObjects::fillem(int x, int y){
    xmin = x;
    xmax = x + 25;
    ymin = y + 65;
    ymax = y;
    status = 0;
}



/*Member function iswithin frome FireObjects takes in the x and y coordinates of a touch on the screen
checks to see if that touch is within the bounds of teh FireObject if it is
sets status to 1 meaning the fire now should not be on the screen
Author: Tommy Fitzgerald
*/
void fireObjects::iswithin(int x, int y){
    if (x > xmin && x < xmax && y < ymax && y > ymin) {
        status = 1;
    }
}


//Fireobject Constructor
//sets initial values for Fireobjects that have not been filled
//Author: Tommy Fitzgerald
fireObjects::fireObjects(){
        xmax = 0;
        xmin = 0;
        ymax = 0;
        ymin = 0;
        status = 1;
    }




void putoutfireEasy(fireObjects firearr[100], fireObjects firearr2[100], int *score, int touchX, int touchY, int cycle) {
    // Initialize images for fire, bad guy, and two town views
    FEHImage fire1, badguy, town1, town2;
    fire1.Open("fire1.png");
    badguy.Open("theOfficialBadGuy.png");
    town1.Open("town1.png");
    town2.Open("villageSecondAngle.png");

    int j, k, copy = *score; // Variables for loops and score copying

    // Check which cycle we're in (1 or 2) to determine the drawing context
    if (cycle == 1) {
        // Process the first set of fires in firearr
        for (j = 0; j < 100; j++) {
            if (firearr[j].status == 0) { // Check if the fire is active
                // Check if touch coordinates are within the fire boundaries
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                    touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                    
                    firearr[j].status = 1; // Mark fire as extinguished
                    copy++; // Increment the score
                    LCD.Clear(); // Clear the screen

                    // Redraw the updated scene
                    town1.Draw(0, 0);
                    badguy.Draw(100, 150);
                    LCD.Update();

                    // Redraw remaining fires in firearr
                    for (k = 0; k < 100; k++) {
                        if (firearr[k].status == 0) {
                            fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                        }
                    }

                    // Redraw remaining fires in firearr2
                    for (k = 0; k < 100; k++) {
                        if (firearr2[k].status == 0) {
                            fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                        }
                    }

                    break; // Exit loop once a fire is extinguished
                }
            }
        }

        // Process the second set of fires in firearr2
        for (j = 0; j < 100; j++) {
            if (firearr2[j].status == 0) { // Check if the fire is active
                // Check if touch coordinates are within the fire boundaries
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                    touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                    
                    firearr2[j].status = 1; // Mark fire as extinguished
                    copy++; // Increment the score
                    LCD.Clear(); // Clear the screen

                    // Redraw the updated scene
                    town1.Draw(0, 0);
                    badguy.Draw(100, 150);
                    LCD.Update();

                    // Redraw remaining fires in firearr
                    for (k = 0; k < 100; k++) {
                        if (firearr[k].status == 0) {
                            fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                        }
                    }

                    // Redraw remaining fires in firearr2
                    for (k = 0; k < 100; k++) {
                        if (firearr2[k].status == 0) {
                            fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                        }
                    }

                    break; // Exit loop once a fire is extinguished
                }
            }
        }
    } else if (cycle == 2) { 
        // Process for cycle 2 (different town context)
        for (j = 0; j < 100; j++) {
            if (firearr[j].status == 0) { // Check if the fire is active
                // Check if touch coordinates are within the fire boundaries
                if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                    touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                    
                    firearr[j].status = 1; // Mark fire as extinguished
                    copy++; // Increment the score
                    LCD.Clear(); // Clear the screen

                    // Redraw the updated scene
                    town2.Draw(0, 0);
                    badguy.Draw(100, 150);
                    LCD.Update();

                    // Redraw remaining fires in firearr
                    for (k = 0; k < 100; k++) {
                        if (firearr[k].status == 0) {
                            fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                        }
                    }

                    // Redraw remaining fires in firearr2
                    for (k = 0; k < 100; k++) {
                        if (firearr2[k].status == 0) {
                            fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                        }
                    }

                    break; // Exit loop once a fire is extinguished
                }
            }
        }

        // Process the second set of fires in firearr2
        for (j = 0; j < 100; j++) {
            if (firearr2[j].status == 0) { // Check if the fire is active
                // Check if touch coordinates are within the fire boundaries
                if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                    touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                    
                    firearr2[j].status = 1; // Mark fire as extinguished
                    copy++; // Increment the score
                    LCD.Clear(); // Clear the screen

                    // Redraw the updated scene
                    town2.Draw(0, 0);
                    badguy.Draw(100, 150);
                    LCD.Update();

                    // Redraw remaining fires in firearr
                    for (k = 0; k < 100; k++) {
                        if (firearr[k].status == 0) {
                            fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                        }
                    }

                    // Redraw remaining fires in firearr2
                    for (k = 0; k < 100; k++) {
                        if (firearr2[k].status == 0) {
                            fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                        }
                    }

                    break; // Exit loop once a fire is extinguished
                }
            }
        }
    }

    *score = copy; // Update the score with the modified value
}



void putoutfireMedium(fireObjects firearr[100], fireObjects firearr2[100], int *score, int touchX, int touchY, int cycle) {
    // Initialize images for fire, bad guy, and two forest views
    FEHImage fire1, badguy, forest_2, winterforest;
    fire1.Open("fire1.png");
    badguy.Open("theOfficialBadGuy.png");
    forest_2.Open("forest_2.png");
    winterforest.Open("winter_forest.png");

    int j, k, copy = *score; // Variables for loops and score copying

    // Determine the scene based on the cycle (1 or 2)
    if (cycle == 1) {
        // Process fires in the first set (firearr)
        for (j = 0; j < 100; j++) {
            // Check if the touch coordinates are within fire boundaries
            if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                
                firearr[j].status = 1; // Mark fire as extinguished
                copy++; // Increment the score
                LCD.Clear(); // Clear the screen

                // Redraw the updated scene
                forest_2.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                // Redraw remaining fires in firearr
                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) {
                        fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                    }
                }

                // Redraw remaining fires in firearr2
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) {
                        fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                    }
                }

                break; // Exit loop once a fire is extinguished
            }
        }

        // Process fires in the second set (firearr2)
        for (j = 0; j < 100; j++) {
            // Check if the touch coordinates are within fire boundaries
            if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                
                firearr2[j].status = 1; // Mark fire as extinguished
                copy++; // Increment the score
                LCD.Clear(); // Clear the screen

                // Redraw the updated scene
                forest_2.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                // Redraw remaining fires in firearr
                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) {
                        fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                    }
                }

                // Redraw remaining fires in firearr2
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) {
                        fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                    }
                }

                break; // Exit loop once a fire is extinguished
            }
        }
    } else if (cycle == 2) {
        // Process fires in the first set (firearr) for cycle 2
        for (j = 0; j < 100; j++) {
            // Check if the touch coordinates are within fire boundaries
            if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                
                firearr[j].status = 1; // Mark fire as extinguished
                copy++; // Increment the score
                LCD.Clear(); // Clear the screen

                // Redraw the updated scene
                winterforest.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                // Redraw remaining fires in firearr
                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) {
                        fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                    }
                }

                // Redraw remaining fires in firearr2
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) {
                        fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                    }
                }

                break; // Exit loop once a fire is extinguished
            }
        }

        // Process fires in the second set (firearr2) for cycle 2
        for (j = 0; j < 100; j++) {
            // Check if the touch coordinates are within fire boundaries
            if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                
                firearr2[j].status = 1; // Mark fire as extinguished
                copy++; // Increment the score
                LCD.Clear(); // Clear the screen

                // Redraw the updated scene
                winterforest.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                // Redraw remaining fires in firearr
                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) {
                        fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                    }
                }

                // Redraw remaining fires in firearr2
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) {
                        fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                    }
                }

                break; // Exit loop once a fire is extinguished
            }
        }
    }

    *score = copy; // Update the score with the modified value
}



void putoutfireHard(fireObjects firearr[100], fireObjects firearr2[100], int *score, int touchX, int touchY, int cycle) {
    // Initialize images for fire, bad guy, and environments
    FEHImage fire1, badguy, beach, desert, mountains;
    fire1.Open("fire1.png");
    badguy.Open("theOfficialBadGuy.png");
    beach.Open("beach.png");
    desert.Open("desert.png");
    mountains.Open("mountains.png");

    int j, k, copy = *score; // Loop counters and score copy for modification

    // Select behavior based on the cycle (1, 2, or 3)
    if (cycle == 1) {
        // Cycle 1: Beach scene
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                
                firearr[j].status = 1; // Mark fire as extinguished
                copy++; // Increment score
                LCD.Clear(); // Clear the screen
                beach.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                // Redraw all remaining fires
                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
        // Check and handle fire in firearr2
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                
                firearr2[j].status = 1; // Mark fire as extinguished
                copy++; // Increment score
                LCD.Clear();
                beach.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
    } else if (cycle == 2) {
        // Cycle 2: Desert scene
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                
                firearr[j].status = 1;
                copy++;
                LCD.Clear();
                desert.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                
                firearr2[j].status = 1;
                copy++;
                LCD.Clear();
                desert.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
    } else if (cycle == 3) {
        // Cycle 3: Mountain scene
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr[j].xmin + 90) && touchX < (firearr[j].xmax + 90) && 
                touchY > (firearr[j].ymax + 55) && touchY < (firearr[j].ymin + 55)) {
                
                firearr[j].status = 1;
                copy++;
                LCD.Clear();
                mountains.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
        for (j = 0; j < 100; j++) {
            if (touchX > (firearr2[j].xmin + 90) && touchX < (firearr2[j].xmax + 90) && 
                touchY > (firearr2[j].ymax + 55) && touchY < (firearr2[j].ymin + 55)) {
                
                firearr2[j].status = 1;
                copy++;
                LCD.Clear();
                mountains.Draw(0, 0);
                badguy.Draw(100, 150);
                LCD.Update();

                for (k = 0; k < 100; k++) {
                    if (firearr[k].status == 0) fire1.Draw(firearr[k].xmin, firearr[k].ymax);
                }
                for (k = 0; k < 100; k++) {
                    if (firearr2[k].status == 0) fire1.Draw(firearr2[k].xmin, firearr2[k].ymax);
                }
                break;
            }
        }
    }

    *score = copy; // Update score
}




void Spawnfire(fireObjects firearr[100], fireObjects firearr2[100], int fireCount) {
    // Initialize fire image
    FEHImage fire1;
    fire1.Open("fire1.png");

    int j;
    int x = -80; // Initial x-coordinate for the first row of fires

    // Draw and initialize the first row of fires
    for (j = 0; j < fireCount; j++) {
        fire1.Draw(x, 0);              // Draw fire image at (x, 0)
        firearr[j].fillem(x, 0);       // Fill fire object data for firearr
        x = x + 35;                   // Increment x-coordinate for spacing
    }

    x = -75; // Reset x-coordinate for the second row of fires

    // Draw and initialize the second row of fires
    for (j = 0; j < fireCount; j++) {
        fire1.Draw(x, 85);             // Draw fire image at (x, 85)
        firearr2[j].fillem(x, 85);     // Fill fire object data for firearr2
        x = x + 40;                   // Increment x-coordinate for spacing
    }

    fire1.Close(); // Close the fire image file to release resources
}




void level_medium(int *score, int *losses, int *wins, int *gamesplayed)
{
    //create the necessary variables that are used within the function
    FEHImage badguy, fire1, fire2, forest_2, other_image, winter_forest;
    int timeTracker, timer, fire_counter=0,touchX,touchY, loopTracker = 0,copy = 0;
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
        *score += copy;       // endgame
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
            copy = copy + *score;
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
    int start, fire_counter, timer, timeTracker,touchX,touchY,loopTracker = 0,copy = 0;
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
        *score += copy;       // exit game
        loopTracker = 1;      // leave loop
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


void easyModeGame(int *score, int *losses, int *wins, int *gamesplayed) {
    int loopTracker = 0, copy = 0; // Initialize loop control and score copy variable

    while (loopTracker == 0) { // Main game loop
        *score = 0; // Reset score
        fireObjects firearr1[100], firearr2[100]; // Fire objects arrays
        *gamesplayed = *gamesplayed + 1; // Increment games played

        // Initialize FEHImage objects
        FEHImage badguy, fire1, fire2, town, town2;
        float timeTracker;
        int touchX, touchY;

        // Open images for use
        badguy.Open("theOfficialBadGuy.png");
        fire1.Open("fire1.png");
        fire2.Open("fire2.png");
        town.Open("town1.png");
        town2.Open("villageSecondAngle.png");

        // Display initial game instructions
        LCD.Clear(WHITESMOKE);
        LCD.SetFontColor(BLACK);
        LCD.Write("Your mission starts in the Town, the mad man is going crazy and its up to you to drive him out of town and save the day!");
        LCD.Update();
        Sleep(5.0);
        LCD.Clear(WHITE);

        // Animation sequence
        town.Draw(0, 0); // Draw the initial town
        LCD.WriteAt("MUAHAHAH", 20, 180);
        Sleep(0.5);
        LCD.WriteAt("MUAHAHAH", 70, 130);
        Sleep(0.5);
        LCD.WriteAt("MUAHAHAH", 10, 20);
        Sleep(0.5);
        LCD.WriteAt("MUAHAHAH", 140, 100);
        Sleep(0.5);

        badguy.Draw(150, 140); // Draw the bad guy
        Sleep(0.5);

        // Clear screen for new dialog
        LCD.Clear();
        town.Draw(0, 0);
        badguy.Draw(150, 140);
        LCD.Write("Its over for you and these puny humans");
        Sleep(2.0);
        LCD.Clear();

        town.Draw(0, 0);
        badguy.Draw(150, 140);

        // Start Level 1
        int fire_counter = 1; // Level 1 fire counter
        Spawnfire(firearr1, firearr2, 4); // Spawn fires
        timeTracker = TimeNow(); // Start level timer

        // Game loop for Level 1
        while ((TimeNow() - timeTracker < 10) && *score < 8) {
            LCD.WriteAt(*score, 0, 0); // Display score
            while (!LCD.Touch(&touchX, &touchY)) {} // Wait for touch
            while (LCD.Touch(&touchX, &touchY)) {} // Wait for release
            putoutfireEasy(firearr1, firearr2, score, touchX, touchY, fire_counter); // Attempt to put out fire
        }

        // Check if player lost Level 1
        if (*score < 8) {
            // Display "YOU LOST!" screen
            LCD.Clear(WHEAT);
            LCD.SetFontColor(RED);
            LCD.Write("YOU LOST!");
            *losses += 1; // Increment loss count

            // Display options to replay or return to menu
            LCD.WriteAt("Play again", 40, 60);
            LCD.WriteAt("or return to the menu!", 40, 100);

            // Draw buttons
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(40, 150, 100, 30);  // "Return" button
            LCD.DrawRectangle(180, 150, 100, 30); // "Play" button
            LCD.SetFontColor(WHITESMOKE);
            LCD.FillRectangle(40, 150, 100, 30);
            LCD.FillRectangle(180, 150, 100, 30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Return", 45, 150);
            LCD.WriteAt("Play", 185, 150);

            // Wait for user input
            while (!LCD.Touch(&touchX, &touchY)) {}
            while (LCD.Touch(&touchX, &touchY)) {}

            // Handle user selection
            if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
                *score += copy; // Continue game
                loopTracker = 1; // Restart loop
            } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
                copy = *score; // Save score
                *score = 0;    // Reset score
            }
        } else {
            // Level 2 dialog and transition
            Sleep(1.0);
            LCD.Clear();
            town.Draw(0, 0);
            badguy.Draw(150, 140);
            LCD.Write("Oh goddddd you are pretty strong ayye");
            Sleep(2.0);

            LCD.Clear();
            town2.Draw(0, 0);
            badguy.Draw(120, 140);
            LCD.Write("Well lets see how you handle this");
            Sleep(2.0);

            LCD.Clear();
            town2.Draw(0, 0);
            badguy.Draw(120, 140);
            LCD.Update();

            // Start Level 2
            fire_counter = 2; // Level 2 fire counter
            Spawnfire(firearr1, firearr2, 6); // Spawn fires for Level 2
            timeTracker = TimeNow(); // Start level timer

            // Game loop for Level 2
            while ((TimeNow() - timeTracker < 15) && *score < 20) {
                LCD.WriteAt(*score, 0, 0); // Display score
                while (!LCD.Touch(&touchX, &touchY)) {} // Wait for touch
                while (LCD.Touch(&touchX, &touchY)) {} // Wait for release
                putoutfireEasy(firearr1, firearr2, score, touchX, touchY, fire_counter); // Attempt to put out fire
            }

            // Check if player lost Level 2
            if (*score < 20) {
                // Same "YOU LOST!" logic as Level 1
                LCD.Clear(WHEAT);
                LCD.SetFontColor(RED);
                LCD.Write("YOU LOST!");
                *losses += 1;

                // Display options and handle input (repeated logic)
                LCD.WriteAt("Play again", 40, 60);
                LCD.WriteAt("or return to the menu!", 40, 100);
                LCD.SetFontColor(BLACK);
                LCD.DrawRectangle(40, 150, 100, 30);
                LCD.DrawRectangle(180, 150, 100, 30);
                LCD.SetFontColor(WHITESMOKE);
                LCD.FillRectangle(40, 150, 100, 30);
                LCD.FillRectangle(180, 150, 100, 30);
                LCD.SetFontColor(BLACK);
                LCD.WriteAt("Return", 45, 150);
                LCD.WriteAt("Play", 185, 150);
                while (!LCD.Touch(&touchX, &touchY)) {}
                while (LCD.Touch(&touchX, &touchY)) {}
                if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
                    *score += copy;
                    loopTracker = 1;
                } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
                    copy = *score;
                    *score = 0;
                }
            } else {
                // Player won
                *wins = *wins + 1; // Increment wins
                LCD.Clear();
                town2.Draw(0, 0);
                badguy.Draw(120, 140);
                LCD.Write("OHHHHHHH god you really care about the ENVIROMENT ahhhhhhhhhh");
                Sleep(4.0);
                LCD.Clear(WHEAT);
                LCD.Write("You are INCREDBLE!!!!");

                // Play again or return menu options (repeated logic)
                LCD.WriteAt("Play again", 40, 60);
                LCD.WriteAt("or return to the menu!", 40, 100);
                LCD.SetFontColor(BLACK);
                LCD.DrawRectangle(40, 150, 100, 30);
                LCD.DrawRectangle(180, 150, 100, 30);
                LCD.SetFontColor(WHITESMOKE);
                LCD.FillRectangle(40, 150, 100, 30);
                LCD.FillRectangle(180, 150, 100, 30);
                LCD.SetFontColor(BLACK);
                LCD.WriteAt("Return", 45, 150);
                LCD.WriteAt("Play", 185, 150);
                while (!LCD.Touch(&touchX, &touchY)) {}
                while (LCD.Touch(&touchX, &touchY)) {}
                if (touchX >= 40 && touchX <= 140 && touchY >= 150 && touchY <= 180) {
                    *score += copy;
                    loopTracker = 1;
                } else if (touchX >= 180 && touchX <= 280 && touchY >= 150 && touchY <= 180) {
                    copy = *score;
                    *score = 0;
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
        break;
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
        break;
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
        break;

    }
    else if(touchX > 118 && touchX < 198 && touchY > 180 && touchY < 205){
        break;
    }
  }
}


void aStoryfortheAges(FEHImage badguy) {
    // Initialize and open the story tree image
    FEHImage storyTree;
    storyTree.Open("StoryTree.png");

    // Display the opening line of the story
    LCD.Clear(WHEAT);
    LCD.WriteLine("     It all began where mostthings begin, at the start.");
    LCD.Update();
    Sleep(3.0);

    // Display the next part of the story
    LCD.Clear(WHEAT);
    LCD.WriteLine("A Young ambitious Turtle    set out to live amongst  the trees. He liked his        life by himself and \tnever bothered anyone, until one day....");
    LCD.Update();
    Sleep(5.0);

    // Introduce the bad guy and display his image
    badguy.Open("theOfficialBadGuy.png");
    badguy.Draw(160, 100);

    // Describe the event that turned the turtle into the bad guy
    LCD.Clear(WHEAT);
    LCD.WriteLine("HE STUBBBED HIS TOE!!!!!!!");
    Sleep(1.0);
    LCD.WriteAt("But not just on anything", 30, 160);
    LCD.Update();
    Sleep(3.0);

    // Reveal what caused the turtle's transformation
    LCD.Clear(WHEAT);
    storyTree.Draw(0, 0);
    LCD.Write("IT WAS A TREEEEEEEEE");
    Sleep(3.0);

    // Explain the turtle's motivation for becoming the antagonist
    LCD.Clear(WHEAT);
    LCD.Write("From then on the turtle vowed to burn down all trees and any other plant life he deemed fit to burn. You must stop him.");
    Sleep(8.0);

    // Display a plea for help
    LCD.Clear(WHEAT);
    LCD.SetFontColor(SCARLET);
    LCD.WriteAt("PLEASE", 100, 60);
    LCD.WriteAt("WE NEED YOU", 80, 100);
    Sleep(3.0);
}

void menuPage() {
    // Initialize game statistics and variables
    int losses = 0, wins = 0;
    int score = 0, cumulativefires = 0;
    char lastleveltrack = '?';
    float touchX, touchY;
    int menutrackingvar, x = 1, gamesplayed = 0;

    // Main menu loop
    while (x == 1) {
        menutrackingvar = 0;

        // Clear and set up menu background
        LCD.SetBackgroundColor(BLACK);
        LCD.Clear();
        FEHImage TreeMenu, CottageMenu, sky, grass, badguy;

        grass.Open("grassy.png");
        grass.Draw(-45, 55);

        CottageMenu.Open("waterColor.png");
        CottageMenu.Draw(-100, -5);

        sky.Open("WC.png");
        sky.Draw(100, -5);

        TreeMenu.Open("pngwing.com.png");
        TreeMenu.Draw(-15, -25);

        // Draw menu buttons
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(20, 140, 120, 30);
        LCD.SetFontColor(GHOSTWHITE);
        LCD.FillRectangle(20, 140, 120, 30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Play Game", 25, 150);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(180, 140, 120, 30);
        LCD.SetFontColor(GHOSTWHITE);
        LCD.FillRectangle(180, 140, 120, 30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Stats", 210, 148);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(20, 190, 120, 30);
        LCD.SetFontColor(GHOSTWHITE);
        LCD.FillRectangle(20, 190, 120, 30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Instructions", 21, 198);

        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(180, 190, 120, 30);
        LCD.SetFontColor(GHOSTWHITE);
        LCD.FillRectangle(180, 190, 120, 30);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Credits", 210, 198);

        // Add decorative title
        LCD.WriteAt("X", 20, 30);
        LCD.SetFontColor(SCARLET);
        LCD.WriteAt("Environmental Man:", 60, 20);
        LCD.WriteAt("The Game!", 100, 60);
        LCD.Update();
        Sleep(0.50);

        // Wait for user input on menu
        while (!LCD.Touch(&touchX, &touchY)) {};
        while (LCD.Touch(&touchX, &touchY)) {};

        // Handle menu options based on touch location
        if (touchX >= 20 && touchX <= 30 && touchY >= 30 && touchY <= 40) {
            break;  // Exit menu
        } else if (touchX >= 180 && touchX <= 300 && touchY >= 140 && touchY <= 170) {
            // Display statistics
            while (menutrackingvar == 0) {
                LCD.Clear(WHEAT);
                LCD.SetFontColor(RED);
                LCD.WriteAt("Statistics", 100, 25);
                LCD.WriteAt("Games Played....", 10, 55);
                LCD.WriteAt(gamesplayed, 220, 55);
                LCD.WriteAt("Difficulty.... ", 10, 85);
                LCD.WriteAt(lastleveltrack, 220, 85);
                LCD.WriteAt("Fires put out.... ", 10, 115);
                LCD.WriteAt(cumulativefires, 220, 115);
                LCD.WriteAt("Wins.... ", 10, 145);
                LCD.WriteAt(wins, 220, 145);
                LCD.WriteAt("Losses.... ", 10, 175);
                LCD.WriteAt(losses, 220, 175);

                // Add reset button
                LCD.SetFontColor(BLACK);
                LCD.DrawRectangle(10, 200, 80, 25);
                LCD.SetFontColor(WHITE);
                LCD.FillRectangle(11, 199, 78, 23);
                LCD.SetFontColor(BLACK);
                LCD.WriteAt("Reset", 11, 200);

                // Add return button
                LCD.SetFontColor(BLACK);
                LCD.DrawRectangle(200, 200, 100, 30);
                LCD.SetFontColor(GHOSTWHITE);
                LCD.FillRectangle(200, 200, 100, 30);
                LCD.SetFontColor(BLACK);
                LCD.WriteAt("Return", 210, 205);

                // Wait for user input
                while (!LCD.Touch(&touchX, &touchY)) {};
                while (LCD.Touch(&touchX, &touchY)) {};

                // Handle touch events for statistics menu
                if (touchX >= 200 && touchX <= 300 && touchY >= 200 && touchY <= 230) {
                    menutrackingvar = 1;  // Return to main menu
                } else if (touchX >= 10 && touchX <= 90 && touchY >= 200 && touchY <= 225) {
                    // Reset statistics
                    wins = 0;
                    losses = 0;
                    cumulativefires = 0;
                    lastleveltrack = '?';
                    gamesplayed = 0;
                }
            }
        } else if (touchX >= 180 && touchX <= 300 && touchY >= 190 && touchY <= 210) {
            // Display credits
            LCD.Clear(WHEAT);
            LCD.WriteAt("Credits", 120, 25);
            LCD.WriteAt("Made By", 120, 120);
            LCD.WriteAt("Adrienne Clymer", 80, 140);
            LCD.WriteAt("and Thomas Fitzgerald", 40, 160);
            LCD.Update();
            while (menutrackingvar == 0) {
                LCD.SetFontColor(BLACK);
                LCD.DrawRectangle(20, 200, 100, 30);
                LCD.SetFontColor(GHOSTWHITE);
                LCD.FillRectangle(20, 200, 100, 30);
                LCD.SetFontColor(BLACK);
                LCD.WriteAt("Return", 25, 205);

                while (!LCD.Touch(&touchX, &touchY)) {};
                if (touchX >= 20 && touchX <= 120 && touchY >= 200 && touchY <= 230) {
                    menutrackingvar = 1;  // Return to main menu
                }
            }
        } else if (touchX >= 20 && touchX <= 140 && touchY >= 190 && touchY <= 210) {
            // Display instructions
            LCD.Clear(WHEAT);
            LCD.Write("A monster has appeared on the Earth. They are causing a ruckus with their fires. It is up to you to save the kingdom and win the day!");
            while (!LCD.Touch(&touchX, &touchY)) {};
            while (LCD.Touch(&touchX, &touchY)) {};
            LCD.Clear(WHEAT);
            LCD.Write("Save the trees and help our environment by clicking on the fires as they pop up. Make sure to get them in time or you will lose a life. You can select up to three levels of difficulty but be warned Hard is a real challenge.");
            LCD.Update();

            // Add story and return buttons
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(200, 200, 100, 30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(200, 200, 100, 30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Return", 210, 205);

            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(50, 200, 100, 30);
            LCD.SetFontColor(GHOSTWHITE);
            LCD.FillRectangle(50, 200, 100, 30);
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Story", 60, 205);

            while (menutrackingvar == 0) {
                while (!LCD.Touch(&touchX, &touchY)) {};
                while (LCD.Touch(&touchX, &touchY)) {};
                if (touchX >= 200 && touchX <= 300 && touchY >= 200 && touchY <= 230) {
                    menutrackingvar = 1;  // Return to main menu
                } else if (touchX >= 50 && touchX <= 150 && touchY >= 200 && touchY <= 230) {
                    aStoryfortheAges(badguy);  // Play story
                    menutrackingvar = 1;
                }
            }
        } else if (touchX >= 20 && touchX <= 140 && touchY >= 120 && touchY <= 170) {
            // Start the game and select difficulty
            score = 0;
            Select_difficulty(&score, &lastleveltrack, &gamesplayed, &losses, &wins);
            cumulativefires += score;
        }
    }
}
