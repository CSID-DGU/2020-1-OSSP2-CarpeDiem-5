
# 2020-1-OSSP2-CarpeDiem-5
OSSP project group

NOTE: This project is currently on hold because I want to explore other
areas of programming. I may or may not come back to this specific project,
but I will definitely be coming back to game development in the future. As
of the time of writing, the game is playable wth one level and a boss fight.

sdl-space-shooter
=================
(last updated README.md on June 22, 2015)

A 2D space shooter named... Space Shooter...

Currently supported on Linux and Windows. An OS X build is planned for the
future.

Due to copyright issues, the music I used will not be included. If you want
to use your own music, create the directory "data/audio/music" and put your
music in there. The file extention must be ".ogg".

The following audio file names will correspond to the state it will be played
in:

- Menu State: menu.ogg
- Game State: level1.ogg
- Boss Fight: boss.ogg
- Victory State: win.ogg
- Game Over State: lose.ogg

Assets are courtesy of Kenney, who can be found here: http://kenney.nl/


Screetshots
=================

![Menu Screen](http://i.imgur.com/Ddb9l4b.png)

![Game](http://i.imgur.com/1WmAAGh.png)


Language
=================

C++


Libraries
=================

버전 주의!
SDL2 library


Building
=================

Dependancies: lSDL2, lSDL2_image, lSDL2_ttf, and lSDL2_mixer.


Linux (Debian) -리눅스에서 설치 방법 
=================

[1] Run the following commands on bash:

- sudo apt-get update

- apt-cache search libsdl2

- sudo apt-get install libsdl2-dev

- sudo apt-get install libsdl2-image-dev

- sudo apt-get install libsdl2-ttf-dev

- sudo apt-get install libsdl2-mixer-dev

[2] Navigate to the directory where you want the project to be cloned
   and run the following commands:

- git clone https://github.com/brandonto/sdl-space-shooter

- make all

- cd bin

- ./SpaceShooter



Contributors
=================

Thanks to the following people for contributing to this project:

Sergey Matyunin (https://github.com/serge-m)

Yuriy Rivniy (https://github.com/YR17)
=======
