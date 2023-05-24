#include <ncurses.h>  
#include <unistd.h>
#include <time.h>
#include <math.h>

// moves the spaceship by 0.5 'pixels' then prints the new position in the correct direction aswell as deleting the previous ship position
 void accelerate (int rotation,float *fy, float *fx,int x,int y,WINDOW *game){
            
            if(rotation == 0){
           *fy = *fy - 0.5;
            mvwprintw(game,y,x,"/\\");
            mvwprintw(game,y+1,x,"  "); //
            }
            if(rotation == 90){
            *fx = *fx + 0.5; 
            mvwprintw(game,y,x-1,"  ");//
            mvwprintw(game,y,x,">");
           
            }
            if(rotation == 180){
            *fy = *fy + 0.5;    
            mvwprintw(game,y-1,x,"  "); //
            mvwprintw(game,y,x,"\\/");
            }
            if(rotation == 270){
            *fx = *fx - 0.5;    
            mvwprintw(game,y,x+1,"  ");
            mvwprintw(game,y,x,"<");
            }
        }
   
int main(){

    initscr(); // initiates the screen
    noecho(); // doesn't display user inputs on screen
    cbreak(); //allows user to exit with control + c
    curs_set(0);// hides the curses
    //creates two windows, the one the game is played in and the one game over is displayed in
    WINDOW *gameEnd = newwin(25,80,0,0);
    WINDOW *game = newwin(25,80,0,0);
    
    refresh();
    // defines the x and y values used for positioning the spaceship
    int x;  
    int y;
    int rotation; //stores direction ship is facing
    // pointer to float points to float x value
    float *fx; 
    float fxs = 5;
    fx = &fxs; 
    // pointer to float points to float y value
    float *fy;
    float fys = 5;
    fy = &fys;
    
    clock_t lastAccel = 0;   // stores the time since last acceleration
    box(game,0,0);// creates a border
    bool playing = true; //game will run while playing = true
    
    wrefresh(game);
    mvwprintw(game, 11,40, "*"); //prints the black hole
    while (playing){
        time_t currentTime = clock();
        double elapsedSeconds = ( double)(currentTime -lastAccel); // stores the time since last accel in milliseconds
        char c = wgetch(game);
        
        // x/y =(int)fxs/fxy converts the float value to an int value so it can be used with mvwprintw
        if (c == 'w'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"/\\"); // displays the ship pointing upwards
            rotation = 0;
        }
        if (c == 'd'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"  ");// clears the previous printing of the ship
            mvwprintw(game,y,x,">"); // displays the ship pointing right
            rotation = 90;
         }
        if (c == 'a'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"  ");// clears the previous printing of the ship
            mvwprintw(game,y,x,"<"); // displays the ship pointing left
            rotation = 270; 
        }
        if (c == 's'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"\\/"); // displays the ship pointing downwards
            rotation = 180;
        }
        
        if (c == 'g' && elapsedSeconds >= 100){ // allows the user to accelerate every 0.1 seconds
            x = (int)fxs;
            y = (int)fys;
            accelerate(rotation, &fys, &fxs, x, y, game); // moves the ship
            lastAccel = currentTime; //resets the time since last acceleration
        
        }
        
         if(x ==40 && y == 11) // ends game if cursor in the same place as black hole
        {
             mvwprintw(gameEnd, 1,1, "game over you got sucked by the black hole, press any key to exit"); // game over message
             refresh();
             wrefresh(gameEnd); // refreshes game end screen so it displays message
             
             playing = false; // ends the game loop
        } 

        // these if statements mean that if the ship goes out of bounds it warps back to the other end of the arena
        if (fxs == 79){
            fxs = 2;
        }
        if (fxs == 1){
            fxs = 78;
        }
        if (fys ==24){
            fys = 2;
        }
        if (fys == 2){
            fys = 24;
        }
    }
    //ends the game after a keypress 
    wgetch(gameEnd); 
    endwin();
}  