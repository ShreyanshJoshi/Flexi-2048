# 2048-GUI

Welcome to my GUI implementation of the Flexi-2048 game !
<h3 align="center">A yet another implementation of the 2048 in C++!</h3>
</p>
<p align="center">
<img align="center" src="https://raw.githubusercontent.com/ShreyanshJoshi/2048/main/gui-2048/screenshots/img3.png">
</p>

## Key features - 
* Apart from the regular moves, this implementation also allows the user to undo their last move.
* Since the game is command line based, arrow keys should be used for left, down, right, up moves and the letter 'u', should be used for undo moves. In case some other key is pressed, nothing will happen.
* *This is an any-dimension (**"Flexi"**) 2048 implementation i.e the game can have any number of tiles in either direction of the board (as against only 4x4 in the regular game).*
* The size of the screen window is flexible. With the change in dimensions of screen window, as well as number of tiles on the board, the size of each tile as well as that of the rectangles at the bottom of the screen change, to ensure a great user experience.
* Finally, the game also has a background music, for which I have chosen some songs. These songs randomly change each time the "New Game" button is pressed or a new run is started from the command line.

## Requirements
- SDL2
- SDL2_ttk
- SDL2_mixer

## Installation
#### Linux / Mac
`sudo apt-get update`

`sudo apt-get install cmake libsdl2-dev libsdl2-ttf-dev libsdl2-mixer-dev`

#### Windows
Under Windows, you can download the libraries <a href="https://www.libsdl.org/download-2.0.php">here</a>. It's important that the right versions are downloaded (32-bit or 64-bit), otherwise the executable might not run due to incompatibility of DLL files.

## Compilation and Execution
#### Linux / Mac / Windows
Clone this github repository, and make a folder named 'build' inside the project root folder. Then, the game can be built inside this folder using the following commands - 

`cd build`

`cmake ..`

`make`

This will create a new folder named 'bin' inside the build folder. The compiled program should be inside. Finally, to run the executable, run the following commands - 

`cd bin`

`./2048`

NOTE: Once created, there would be the required font files and the audio resources inside the `bin` directory. They are critical are used by the game to render the text and play audio. The game won't run without these.

#### Windows
In case you are having issues running the game using `cmake` and `make` on Windows, here is another way to go ahead: Clone the repository as usual and run `cd gui-2048`.

Inside the 'gui-2048' folder, you need to have the latest versions of DLL files for the executable to run. When I tested it on Windows, mentioned below are the DLL files I had to manually download. Again, remember to maintain uniformity of versions while downloading all these (either everything should be 32-bit or everything should be 64-bit), otherwise the executable might not run.
- SDL2_mixer.dll
- SDL2_ttf.dll
- SDL2.dll
- libfreetype-6.dll
- libgcc_s_sjlj-1.dll

After this is done, run the following command to compile and create the executable -

`g++ -c src/*.cpp -std=c++11 -I C:/i686-w64-mingw32/include && g++ *.o -o run -L C:/i686-w64-mingw32/lib -lSDL2_ttf -lSDL2 -lSDL2_mixer`

Here 'i686-w64-mingw32' is the folder containing all the relevant files (32-bit) and is placed in the C: drive. Consequently, any DLL file I downloaded was also 32-bit.

The above command will create object files for each .cpp file, which is fine, but it doesn't concern us as long as the executable is also there (by the name run.exe). The command `run.exe` runs the executable and begins the game.

NOTE: In case, this is how the code is run, it's important to make the following changes in the code. Whenever importing a header file, you would need to include it's relative path now and not just the name of the file. Otherwise, the compiler won't be able to find the header files.

E.g - For importing styles.h in gui.cpp, instead of `#include "styles.h"`, the code would now be `#include "../header/styles.h"`.

## Minor code changes when running the game on Windows
C++ language does not provide a sleep function of its own. However, the operating system’s specific files like `unistd.h` for Linux and `Windows.h` for Windows provide this functionality. The header, currently in the repo is `unistd.h`, which works for Linux. Needless to say, the header file would need to be changed to `Windows.h`, in case the code is run on Windows.

Also, `usleep()` is specifically for Linux, and thus won't work on Windows. Thus, wherever it is there, it needs to be replaced with some other sleep command. One such command is `Sleep()`


## Documentation
This project uses Doxygen for managing its documentation. If you wish to read the documentation, install doxygen. Here is the command for installing Doxygen on Linux/Mac - `sudo apt-get install doxygen-gui`

Install graphviz for visualizing the relations by the running `sudo apt-get install graphviz`.

You can create the docs by running `doxygen` inside the root folder. All the documentation will be created under the `docs` folder.