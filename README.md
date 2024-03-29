# SeniorDesign
Code for an Arduino-based Elegoo robot car to follow a track and handle obstacles in its path. 

## Known Bugs and Features to Add
- FEATURES: 
- BUGS: 

## [Team Contract](https://docs.google.com/document/d/1qSgGlHly_AZ_SWpHDw8KOmh2b5Dciv_2l8BiG0txpeQ/edit)

## Setting up your development environment

### Arduino IDE and Visual Studio Code Setup

First, download the [Arduino desktop IDE](https://www.arduino.cc/en/main/software) and follow the instructions for setup.

Try to download the hardware setup code and run it from this IDE on the bot to make sure everything's working.

You'll need to make sure you set the board to Arduino/Genuino Uno and the serial port to COM5. Verify the code and then deploy it to the board.

Then, install [Visual Studio Code](https://code.visualstudio.com/Download) and install the Arduino extension. You should be able to verify and deploy from here as well!

### Installing Command Line Git

First, download [Git for Windows](https://git-scm.com/download/win) or use a package manager to install Git on MacOS.

Check if the installation was successful by running the following in the command line: 
```bash
git --version
```

Once Git is installed and set up, navigate to the directory you want to install the project in through your command line. (No need to make a new folder, as it will download when you run the proper Git commands detailed below.)

In this directory, run 

```bash
git clone https://github.com/rshiddapur/SeniorDesign.git
```

to download the repository locally. 

If you ever get confused on what to do with git, [check out this handy cheat sheet for help](https://github.github.com/training-kit/downloads/github-git-cheat-sheet.pdf).


## APIs

### Motor Control API

Call motor() with a letter and an integer, e.g. "motor('S', 1)" will move straight ahead 1 'tick'.


S = straight ahead

s = straight backwards

L = turn left forward

l = turn left backward

R = turn right forward

r = turn right backward

C = rotate clockwise

c = rotate counter-clockwise
