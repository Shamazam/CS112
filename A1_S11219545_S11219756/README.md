Note: Microsoft Visual Studio 2022 was used to make the program

# CS112 Assignment 1

This project was designed to act as a tracking app for infected individuals during a pandemic outbreak to better monitor the movements of individuals as well as who they come in contact with.

## Features

- Simple to use & interpret
- 2D plane
- Simulated activity


## Functionality

An array of named people is declared and of class person. After which an array of type string is declared and used to generate the ID of people. 

A function is created to allocate a location to every person on a 2D plane randomly and it also designates a certain percentage of the specified population to be "infected".

The simulation then begins for a number of days that needs to be specified within the code itself, where every individual either remains in the same location or moves one unit horizontally or vertically a day. 

A function that exists within the simulation, is used to check whether a person within the simulation moves outside the 2D plane and corrects it by moving the individual back into the plane.

The code also contains a function that assesses whether an individual has come in contact with an infected person and then applies the chance of infection on that person.

After which, the code prints all the information pertaining to the people within the code. The information printed are as follows:
- ID
- location
- Infection Status
- Movement within the plane
- Daily infection rate.

A graphical plane is then printed with the following keys:

- '*' - unit of space
- '@' - healhty person on the plane
- 'T' - infected person

The printed 2D plane presents the location of every individual after the random movement that has been made for the day.

## Usage

Using the code is as simple as the press of a button, as the simulation is completely coded and does not require further input or installation.

The user only needs to run the code and the information of the first day is displayed. 

Afterwhich a prompt is given to enlarge the screen to properly view the 2D plane before it is printed by pressing the enter button which will then print the plane and all of its components.

Pressing enter once again will run the simulation once again for day 2 and by repeating this process the user may succesfully run the simulation over a number of days that have been specified within the code. Once the simulation has run for the specified number of days the code will then print out the 2D plane sequentially for all the days the simulation has been run for.

Thank you.

## Authors

- S11219756@student.usp.ac.fj - Ivan Alfred
- S11219545@student.usp.ac.fj - Shamal Prasad



