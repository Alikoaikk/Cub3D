*This project has been created as part of the 42 curriculum by akoaik, msafa.*

# cub3D

A 3D game engine using raycasting, inspired by the legendary Wolfenstein 3D.

---

## Table of Contents

- [Description](#description)
- [Features](#features)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Dependencies](#dependencies)
- [Instructions](#instructions)
- [Map Format](#map-format)
- [Resources](#resources)
- [Authors](#authors)

---

## Description

cub3D is a 3D graphical project that uses raycasting techniques to render a first-person perspective view of a maze-like environment from a 2D map. This technique was pioneered by id Software in games like Wolfenstein 3D (1992), allowing for pseudo-3D graphics on limited hardware.

The player navigates through a maze, with walls rendered in real-time based on their distance and orientation, creating an immersive 3D experience from simple 2D map data.

---

## Features

- **Real-time 3D Rendering** - Smooth raycasting engine running at consistent frame rates
- **Textured Walls** - Four distinct textures for North, South, East, and West walls
- **Configurable Environment** - Customizable floor and ceiling colors via RGB values
- **Fluid Movement** - Forward, backward, and lateral (strafe) movement
- **Camera Rotation** - Look left and right with smooth rotation
- **Map Parsing** - Robust parser with comprehensive error handling
- **Wand Overlay** - First-person weapon sprite display
- **Multiple Maps** - Support for various `.cub` map configurations

---

## How It Works

### Raycasting Algorithm

The engine casts rays from the player's position across the field of view. For each vertical stripe of the screen:

1. **Ray Direction** - Calculate ray direction based on player orientation and camera plane
2. **DDA Algorithm** - Use Digital Differential Analyzer to find wall intersections
3. **Wall Distance** - Calculate perpendicular distance to avoid fisheye effect
4. **Wall Height** - Determine wall stripe height based on distance
5. **Texture Mapping** - Map the appropriate texture column to the wall stripe

```
        Player POV
           /|\
          / | \
         /  |  \
        /   |   \
    ───/────┼────\───  Wall
      Ray   │   Ray
            │
         Camera
```

### Coordinate System

- **2D Map**: Grid-based where each cell is either a wall (`1`) or empty space (`0`)
- **Player Position**: Floating-point coordinates within the grid
- **Screen**: Y-axis increases downward (standard graphics convention)

---

## Project Structure

```
cub3D/
├── main.c                 # Program entry point
├── Makefile               # Build configuration
├── README.md              # Project documentation
│
├── includes/              # Header files
│   ├── data.h             # Main data structures and prototypes
│   ├── libft.h            # Libft library header
│   └── mlx.h              # MinilibX header
│
├── src/
│   ├── parsing/           # Map and configuration parsing
│   │   ├── map_parsing.c          # Main map parser
│   │   ├── map_dimensions.c       # Map size calculations
│   │   ├── textures_parsing.c     # Texture path parsing
│   │   ├── colors_parsing.c       # RGB color parsing
│   │   └── ...
│   │
│   ├── rendering/         # Graphics and raycasting
│   │   ├── raycasting.c           # Main rendering loop
│   │   ├── dda.c                  # DDA algorithm implementation
│   │   ├── dda_setup.c            # Ray initialization
│   │   ├── drawing.c              # Pixel drawing functions
│   │   ├── camera_plane.c         # Camera initialization
│   │   └── textures_images.c      # Texture loading
│   │
│   └── movements/         # Player controls
│       ├── player_movements.c     # WASD movement
│       ├── player_rotations.c     # Arrow key rotation
│       ├── control_movements.c    # Input handling
│       └── cleanup.c              # Memory cleanup
│
├── libft/                 # Custom C library
│
├── minilibx/              # Graphics library (MinilibX)
│
├── maps/                  # Map files (.cub)
│
└── textures/              # Wall and sprite textures (.xpm)
```

---

## Instructions

### Compilation

```bash
# Compile the project
make

# Clean object files
make clean

# Full clean (remove object files and executable)
make fclean

# Recompile from scratch
make re
```

### Execution

```bash
./cub3d maps/<map_name>.cub
```

Example:
```bash
./cub3d maps/hogsmade_map.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left (strafe) |
| `D` | Move right (strafe) |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit game |

---

## Map Format

Map configuration files use the `.cub` extension and must include:

### Texture Paths
```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm
```

### Colors (RGB: 0-255)
```
F 220,100,0      # Floor color
C 135,206,235    # Ceiling color
```

### Map Layout
```
111111111
100000001
100N00001
100000001
111111111
```

| Symbol | Meaning |
|--------|---------|
| `1` | Wall |
| `0` | Empty space |
| `N` | Player spawn (facing North) |
| `S` | Player spawn (facing South) |
| `E` | Player spawn (facing East) |
| `W` | Player spawn (facing West) |

### Map Rules
- Map must be surrounded by walls (`1`)
- Exactly one player spawn position required
- No empty lines within the map
- Spaces are treated as void (must be enclosed)

---

## Resources

### References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide to raycasting algorithms, DDA implementation, texture mapping, and more. Primary reference for this project.

### AI Usage

AI tools were utilized in this project for:

| Purpose | Description |
|---------|-------------|
| **Testing** | Testing with complex and edge-case maps to verify error handling |
| **Conceptual Understanding** | Understanding mathematical concepts behind raycasting (ray direction, DDA steps, perpendicular distance, texture coordinates) |
| **Visualization** | Creating mental models to understand the relationship between 2D map, player position, ray movements, and 3D projection |

---

## Authors

| Author | GitHub |
|--------|--------|
| **akoaik** | [github.com/akoaik](https://github.com/alikoaikk) |
| **msafa** | [github.com/msafa](https://github.com/mohamedsafa) |
