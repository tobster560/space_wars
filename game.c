#include <ncurses.h>  
#include <unistd.h>
<<<<<<< HEAD
#include <time.h>
#include <math.h>


 void accelerate (int rotation, float *verAcc, float *horAcc, float *fy, float *fx,int x,int y,WINDOW *game){
            
            if(rotation == 0){
            *verAcc = *verAcc - 0.5;
           *fy = *fy - 0.5;
            mvwprintw(game,y,x,"/\\");
            mvwprintw(game,y+1,x,"  "); 
            }
            if(rotation == 90){
            *fx = *fx + 0.5;
            *horAcc = *horAcc + 0.5;
            mvwprintw(game,y,x-1,"  ");
            mvwprintw(game,y,x,">");
              
           }
            if(rotation == 180){
            *fy = *fy + 0.5;    
            *verAcc = *verAcc + 0.5;
            mvwprintw(game,y-1,x,"  ");
            mvwprintw(game,y,x,"\\/");
              
            }
            if(rotation == 270){
            *fx = *fx - 0.5;    
            *horAcc = *horAcc - 0.5;
            mvwprintw(game,y,x+1,"  ");
            mvwprintw(game,y,x,"<");
                     
            }
          
          
    }
   
  void gravity (float *verAcc, float *horAcc, float *fy, float *fx,WINDOW *game){

    if (*fy > 11){
        *verAcc = *verAcc - 0.5;
    }else{
        *verAcc = *verAcc + 0.5;
    }
       if (*fx > 40){
        *horAcc = *horAcc - 0.5;
    }else{
        *horAcc = *horAcc + 0.5;
    }
    
    mvwprintw(game,3,3,"x:%f,y:%f", *horAcc, *verAcc);
  }

=======


>>>>>>> refs/remotes/origin/master
int main(){

    initscr();
    noecho();
    cbreak();
    curs_set(0);
<<<<<<< HEAD
    
    WINDOW *game = newwin(25,80,0,0);
    refresh();
    int x;
    int y;
    int rotation = 90;
  
    float *horAcc;
    float horAccs = 0;
    horAcc = &horAccs;
    float *verAcc;
    float verAccs= 0;
    verAcc = &verAccs;

    float *fx;
    float fxs = 5;
    fx = &fxs;
    float *fy;
    float fys = 5;
    fy = &fys;
    clock_t lastAccel = 0; // stores timestamp of last acceleration
    clock_t lastGrav = 0; //stores timestampt of last gravity
    int counter=0;
    box(game,0,0);
    
    wrefresh(game);
    mvwprintw(game, 11,40, "*"); //prints the black hole
    while (1){
        time_t currentT = clock();
        double elapsedSecondsGrav = (double)(currentT - lastGrav);
       if (elapsedSecondsGrav >= 1000){
        gravity(&verAccs, &horAccs, &fys ,&fxs,game);
        lastGrav = currentT;
        mvwprintw(game, 4,5 ,"gravity activated %d", counter);
        counter = counter + 1;
        } 
        char c = wgetch(game);

        if (c == 'w'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"/\\");
            rotation = 0;
        }
        if (c == 'd'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"  ");
            mvwprintw(game,y,x,">");
            rotation = 90;
         }
        if (c == 'a'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"  ");
            mvwprintw(game,y,x,"<");
            rotation = 270; 
        }
        if (c == 's'){
            x = (int)fxs;
            y = (int)fys;
            mvwprintw(game,y,x,"\\/");
            rotation = 180;
        }
        
        if (c == 'g'){
            time_t currentTime = clock(); 
            x = (int)fxs;
            y = (int)fys;
            double elapsedSeconds = (double)(currentTime - lastAccel);
            if (elapsedSeconds >= 1000){
                mvwprintw(game,5,3,"%d",elapsedSeconds);
            accelerate(rotation, &verAccs, &horAccs, &fys, &fxs, x, y, game);
            lastAccel = currentTime;
            }
           
        
            
          

        }
    }
        
        if(x ==40 && y == 11) // ends game if cursor in the same place as black hole
        {
             mvwprintw(game, 11,40, "game over"); 
        }
       wrefresh(game);
    
    wrefresh(game);
    endwin();
    return 0;
    }
    
    

=======

    WINDOW *game = newwin(25,80,0,0);
    refresh();
    bool end = false;
    int x =5;
    int y =5;
    int ch, prev_ch = 0;
    keypad(game,true);
    box(game,0,0);
    
   
    wrefresh(game);
    while (1){
        char c = wgetch(game);
       
        if (c == 'w'){
            mvwprintw(game,y,x,"/\\");
        }
        if (c == 'd'){
            mvwprintw(game,y,x,"  ");
            mvwprintw(game,y,x,">");
        }
        if (c == 'a'){
            mvwprintw(game,y,x,"  ");
            mvwprintw(game,y,x,"<");
        }
        if (c == 's'){
            mvwprintw(game,y,x,"\\/");
        }
        
        if (c == 'q') {
            break; // exit loop if 'q' is pressed
        }
       
       wrefresh(game);
    }
        


    wrefresh(game);
    if(end = true){
          endwin();
    } 
    
    

    endwin();
    
    return 0;
  
}
>>>>>>> refs/remotes/origin/master

    

