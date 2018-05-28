##### Quick project overview:
This is a *simple* vector/matrix library, designed specifically for games. Provides common core functions for moving, rotating, find angles between vectors, etc...

# Quick guide to source code
All code source is located in "Vectors and Matricies for games\src"

"Vector3" contains typical vector operations you might expect, dot/cross product/length functions. It also contains some functions useful for gameplay purposes.
Finding angle between two vectors, finding the direction between two vectors
Read the .h file to read comments about each function.

"4x4_Matrix" contains typical matrices operations, multiplcation/addition. It also contains common affine transformations, such as translations/rotations
Read the .h file to read comments about each function.

"MathStuff" contains useful values, such as pi and epsilon. It also contains helper functions to convert degrees to radians, and radians to degrees

"Main" contains the scene setup and game loop.

#### Application notes

You will start in the centre, the camera will constantly be looking you.

There is another two cubes in the scene. One to the right is the target cube, and one that will be following you every more and rotation

There is also some text at the top left. 
The floating point numbers represent the angle between your cubes facing vector and the static cube, and the text below will tell you if the static cube is to the left or right of you.