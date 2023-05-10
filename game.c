#include <ncurses.h>  
#include <unistd.h>


int main(){

    initscr();
    noecho();
    cbreak();
    curs_set(0);

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

    

