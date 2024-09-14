Cub3D
Cub3D is a 3D graphical project inspired by the classic Wolfenstein game, built using the principles of raycasting and a simple graphics engine. The project was developed as part of the 42 school curriculum.

About the Project
Cub3D is a minimalistic 3D game engine based on raycasting techniques. It simulates a first-person shooter environment, allowing players to navigate a maze-like world. The project takes heavy inspiration from classic 90s games like Wolfenstein 3D.

This project was designed to:

Demonstrate the basics of raycasting to create a 3D perspective.
Learn more about low-level graphics rendering.
Handle user input and collision detection in real-time.
Features
Raycasting engine: Displays a 3D world using 2D data.
Player movement and collision detection: Navigate through a maze with proper collision physics.
Textured walls and objects: Add realism to the environment with textures.
Map editor compatibility: Import custom maps for new levels.
Minimap overlay: Displays a 2D overview of the current map.

Installation
Clone the repository:
bash
Copy code
git clone https://github.com/yourusername/cub3d.git
cd cub3d
Compile the project:

bash
Copy code
make
Run the game:

bash
Copy code
./cub3D <map_file>
Dependencies: Make sure to have the necessary libraries installed, such as:

minilibx for graphics
Standard C libraries
Usage
To launch the game, provide a valid map file as an argument:

bash
Copy code
./cub3D maps/valid/
You can create your own maps by using a custom map editor, following the .cub format.

Controls
W / S – Move forward / backward
A / D – Strafe left / right
Arrow Left / Right – Rotate the player view
Esc – Exit the game
