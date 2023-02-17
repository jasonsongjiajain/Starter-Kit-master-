# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/S1kGOfGWQC8).

## Minimum Requirements

### Completed

List all the features completed.

1. Display gameboard
2. Change Game settings
3. Alien movement 
4. Random Assign Object, Alien and Zombie

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Zombie movement and Attack  
2. Alien Attack 
3. Hit gameobjects function
4. Save and Load
5. Help manual


## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.

For example:

### Song Jia Jian 

1. Randomly generate game board.
2. Default Settings
3. Gamechange settings 

### Brett Yap V-Ron 

1. Alien movement
2. Display Character
3. Generate Zombie in gameboard




## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

- Well, there are some of the problems that I face while coding untill now is that when I was doing the game change settings, I was thinking how can i pass down the value after I input it. So I search up the lectures and Lab that I have done and found out that there is a thing called pass by reference "&" and also return, at first I have to say I'm not that familiar with function, but after using that, me and my teammate found out that it can pass the value down after changing. Next up is when we were figuring out how to implement the 2d Array function into another function, we like try a lot and finally found out that pointers is very useful in initializing and storing memory for 2d Array function so after we used it, we are able to use 2d array function in another function. For the Alien movement part, we at first try a code but when we move the alien to the right, it moves back again to the center and then start moving from the centre over and over again. So we tried to change it by seperating into different functions for up, down, left and right, and implementing the 2d array fucntion into it. Next, we let the original position become '.', after that we change the position and let the new position with 'A'.