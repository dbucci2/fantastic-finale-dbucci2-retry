# My Development Process

These are the basic steps I took in working on this project.

## The External Library

The library I was going to use for the chess functions can be found here: https://github.com/jeromevonk/chess_console . After working for a while, I found that it would be too difficult to translate console controls to user interface controls. Instead of using this chess console repository, I ended up using an openFrameWorks add-on called ofxUIUtils in order to create image buttons. The repository for that can be found here: https://github.com/DomAmato/ofxUIUtils .

## The Process

To start, I familiarized myself with openFrameWorks and the basic things I would need to know how to do for my app to work, as planned. This included much research into the documentation as well as exploration into a new repository, ofxUIUtils. Next, I combed through the C++ of the chess repository I started with to understand better the functionality that went along with it. 

Then I acquired the chess board and chess pieces as photos from the web and used Microsoft Paint to isolate them with blank backgrounds. This allowed me to load the images into Visual Studio and use them both as buttons and as a chessboard. From there, I built and implemented my own framework for the pieces as ImageButtons and the chessboard as somewhat of a background.

The next step was getting the pieces to be drawn in proper places. For this, I created a Point class which holds an x and y value representing the x and y values in pixels relative to the top right corner of the screen. I have represented each piece as a unique index, and a vector of piece coordinates is indexed with the same indicies to match up with the pieces. This vector of Points can be adjusted and edited with helper functions to make the pieces move. Figuring out the proper coordinates and constants was done by trial and error, and the resulting system works well.

With all pieces in place and moveable, I have implemented some additional functionality to ensure turn-based gameplay and no betrayal. Pieces are represented by certain indicies, and all white pieces come in below the number 16. Anything above is a black piece. These ranges provide a simple metric for telling if a piece is white or black. These values work with a boolean function to ensure turn-based gameplay. The same ranges keep white pieces from capturing other white pieces and vice versa. Captured pieces are whisked to the right side of the board, where they sit permanently out of the game.

I have continued to fine-tune and debug the program from here, building out the interface in a way that complements easy piece movements and simplifies functionality using the Image Buttons that I have implemented. 

## Stretch Goals

This project took far longer than I anticipated; thus, I have not implemented the previously stated checkers functionality. Furthermore, writing comprehensive tests was not a feasible goal due to time management issues. Thus, all testing was done manually, with no Catch tests present. 
