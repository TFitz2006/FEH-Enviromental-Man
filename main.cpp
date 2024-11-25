#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHImages.h>
#include <FEHRandom.h>

/*  Name:  Tommy Fitzgerald	Adrienne Clymer					  */
/*  Date:  11/17/2024     						  */
/*  Assignment:  Menu 					  */
/*  Seat:  22		Instructor:  Dr. H		Time:  10:20 */

// FEHImage fire, FEHImage lakeHouse, FEHImage otherImage
//This is the function for the introduction story which I am still working on
//will basically just show a bunch information/backstory with text and maybe a couple of images
void aStoryfortheAges(FEHImage badguy);

//Function for the credits page
// Shows the play Game, instructions, credits, and stats pages
//stats needs to be fixed with actual statistics, 
//play game will exit the function inside maint o call a seperate run game function or a run game function will be made

class fireObjects
{
private:
int xmax, xmin, ymax, ymin;
bool status;

public:
    fireObjects();
    bool iswithin(int inputxmax,int inputxmin, int inputymin, int inputymax);

};


void easyModeGame(FEHImage badguy, FEHImage fire1, FEHImage fire2, FEHImage town, FEHImage town2);


void menuPage();

char Select_difficulty();

int main() {
   FEHImage badguy,fire1, fire2, town,town2;

    menuPage();
    if(Select_difficulty()=='E')
    {easyModeGame(badguy,fire1, fire2, town,town2);}
   else if(Select_difficulty()=='M')
   {MediumModeGame();}
    else if(Select_difficulty()=='H')
    {HardModeGame();}

}

//Fireobject Constructor
fireObjects::fireObjects(){
        xmax = 0;
        xmin = 0;
        ymax = 0;
        ymin = 0;
        status = 0;
    }

// FEHImage fire, FEHImage lakeHouse, FEHImage otherImage

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
    float touchX, touchY, xtrash, ytrash;
    int menutrackingvar,x = 1;

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
            LCD.Clear(WHEAT);
            LCD.WriteAt("Statistics",100,25);
            LCD.WriteAt("Total Games Played.... 0",10,55);
            LCD.WriteAt("Difficulty.... Hard",10,85);
            LCD.WriteAt("Trees Saved.... 234",10,115);
            LCD.WriteAt("Trees Lost.... 0",10,145);
          
            LCD.Update();
        while (menutrackingvar == 0){
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
           
           //currently has this functionality but will most liekly be a completely different function outside of the Menupage fucntion
            LCD.Clear(WHEAT);
            LCD.WriteAt("Play Game Here",120,25);
            LCD.Update();
        while (menutrackingvar == 0){
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
            
            }  
        }
        }
    }
}

void spawnfire(FEHImage fire1, FEHImage fire2, int fireNum){
    fire1.Open("fire1.png");
    fire2.Open("fire2.png");
    fireObjects arr[25];

    int i;
    for (i = 0; i < fireNum; i++){
       if ((i % 2) > 0){
        arr[0] = 
        fire1.Draw(Random.RandInt(),Random.RandInt());
       }else{
        fire2.Draw(Random.RandInt(),Random.RandInt());
       }
    }



}

char Select_difficulty()
{
     float x_pos, y_pos, x_trash, y_trash;


     //set background color
    LCD.SetBackgroundColor(WHEAT);
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

    //waiting for the touch
        while(!LCD.Touch(&x_pos,&y_pos)){}
        //when it is touched
        while(LCD.Touch(&x_trash,&y_trash)){}

    //call the function easy to see if the user selected easy as their option
    //it will return true if they touched within the easy button 
    if(x_pos > 20 && x_pos < 80 && y_pos > 95 && y_pos < 120)
    {   
        return 'E';
    }
    //call medium to check the same thing
    else if(x_pos > 118 && x_pos < 198 && y_pos > 95 && y_pos < 120)
    {
        return 'M';
    }
    
    //call hard to check the same thing
    else if(x_pos > 235 && x_pos < 295 && y_pos > 95 && y_pos < 120)
    {
        return 'H'; 
    }
}

void easyModeGame(FEHImage badguy, FEHImage fire1, FEHImage fire2, FEHImage town, FEHImage town2){

    int loopTracker = 0;
    float timeTracker;
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
    while (loopTracker == 0)
    {
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

        LCD.WriteAt("Its over for you and these puny humans", 120,50);
        LCD.Clear();
        town.Draw(0,0);
        badguy.Draw(150,140);

        timeTracker = TimeNow();
        int timer = 60;
        while (timer > 0)
        {   


            LCD.Clear();
            town.Draw(0,0);
            badguy.Draw(150,140);
            LCD.WriteAt(timer,20,220);
            timer = timer - 5;
            Sleep(5.0);
        

        }
        


    


    }
    


    
    

}
