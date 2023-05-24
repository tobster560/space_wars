# space_wars
SSC 110 project coded in C with ncurses libary

Features: 
ship rotates using wasd.   
 Ship moves when the g key is pressed or held down.
 Upon colliding with the black hole a game over the game loop will end
and a game over screen will be displayed.
If the ship reaches one end of the map it will warp back to the other side

How to run:
'gcc -o game game.c -lncurses'
followed by 
'./game' 

how to exit: 
control + c or crash into black hole and then press any key
