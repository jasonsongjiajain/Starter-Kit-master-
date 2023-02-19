# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/F72tbLTqVLQ).

## Minimum Requirements

### Completed

List all the features completed.

1. Default Settings
2. Change settings
3. Difficulty settings
4. Generate gameboard, objects, alien and zombie
5. Alien movement and attack 
6. Alien after move leaves trail and refresh 
7. Zombie movement, attack, range
8. Function of all game objects(including additional features)
9. Game controls
10. Additional features

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. -
2. -

## Additional Features

1. Additional feature 1 - Mystery box
2. Additional feature 2 - Difficulty 

## Contributions

List down the contribution of each group members.

For example:

### Song Jia Jian 

1. Display gameboard
2. Change Game settings & default settings
3. Alien movement 
4. Random Assign Object, Alien and Zombie
5. Alien attack 
6. Function of objects when hit objects
7. Additional features 1


### Brett Yap V-Ron

1. Quit
2. Display Character info
3. Generate Zombie in gameboard
4. Zombie attack, range, movement
5. Save and load
6. helpsettings
7. Additional features 2


## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

First off, When we tried to add the new features difficulty, we are finding a way how to change the zombie's life, attack and range to a larger value after input hard, so we tried to modify the zombie class and while doing it I kept trying to initialize the zombielife, attack and range to a newer value after it has input easy/hard, but still didn't work so I try to seperate into two different variables and I turns out it work!

After that, while finding a way when hitting the object "p", it will find the nearest zombie to it but I still can't think out of a way to do so. So, I thought of using the old-fashioned mathematics way by using the finding euclidean distance to see which zombie is the closest to my alien and turns out it works!

Next, We encounter a problem whereby when my alien reaches the end of the column or the start of the column, it just stucks and keep repeating the same action of the last object hit. So I debug and found out it was my if-else statement wrong in the beginning 

In addition, our alien was not stopping after the zombie has hit zero and override the zombie, so want we do is using bool function to as when it hits the zombie and the zombielife becomes zero, it will become false and the zombie stops moving 

Finally, we encounter a problem where by our zombie can't move after the alien action is finished. So I found out the problem which is our zombie 2d array which is use to store our zombie position only is use for zombielife which is wrong as it should be using vector of the zombie info, so I change it and finally the whole code is complete. 

