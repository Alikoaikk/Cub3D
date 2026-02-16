<div align="center">

![cub3D Banner](banner.png)

# cub3D

**A raycasting 3D engine written in C — inspired by Wolfenstein 3D**

*42 School Project · akoaik & msafa*

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/norminette-passing-brightgreen.svg)]()
[![School](https://img.shields.io/badge/school-42-black.svg)](https://42.fr)

</div>

---

## What is cub3D?

cub3D is a first-person 3D engine built from scratch in C using the **raycasting** technique — the same method that powered Wolfenstein 3D (1992) and DOOM. From a simple 2D grid map, the engine projects a fully textured 3D world in real time.

No OpenGL. No game engine. Just math, pixels, and C.

---

## Features

| Feature | Details |
|---|---|
| Real-time 3D rendering | Smooth raycasting at consistent frame rates |
| Textured walls | Unique XPM textures per direction — N, S, E, W |
| Configurable colors | Custom RGB values for floor and ceiling |
| Player movement | Forward, backward, left/right strafe |
| Camera rotation | Smooth left/right rotation via arrow keys |
| Map parsing | Full `.cub` file parser with error handling |
| Multiple maps | Load any valid `.cub` configuration |

---

## How It Works

The core idea: for every vertical column of pixels on the screen, cast a ray from the player into the map and find the nearest wall. The closer the wall, the taller it appears.

### From 2D Map to 3D World

The entire 3D view is generated from a flat 2D grid. Each cell is either a wall or empty space. The player has a position and a direction vector — and from there, everything is computed mathematically.

```
  2D MAP (what the engine reads)       3D VIEW (what the player sees)
  ┌───────────────────────┐            ╔═══════════════════════════╗
  │ 1 1 1 1 1 1 1 1 1 1 1 │            ║███████████████████████████║  ← ceiling
  │ 1 0 0 0 0 0 0 0 0 0 1 │            ║▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░░░║
  │ 1 0 0 1 1 0 0 0 0 0 1 │            ║▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░░░║  ← walls
  │ 1 0 0 1 1 0 0 0 0 0 1 │   ──────►  ║▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░░░║  (closer = taller)
  │ 1 0 0 0 0 0 N 0 0 0 1 │            ║▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░░░║
  │ 1 0 0 0 0 0 0 0 0 0 1 │            ║▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒║
  │ 1 1 1 1 1 1 1 1 1 1 1 │            ║░░░░░░░░░░░░░░░░░░░░░░░░░░░║  ← floor
  └───────────────────────┘            ╚═══════════════════════════╝
        N = player here
```

---

### The Camera & Field of View

The player has a **direction vector** and a **camera plane** perpendicular to it. Together they define the field of view. Each screen column corresponds to one ray swept across this plane.

```
                         camera plane
                    ◄──────────────────────►
                    │                      │
         left ray   │     center ray       │  right ray
              \     │         |            │    /
               \    │         |            │   /
                \   │         |            │  /
                 \  │         ↓            │ /
                  \ │    →→→ [P] →→→       │/
                   \│    direction         /
                    X ←── player ────────►/
                   /                     /
                  /    FOV ≈ 66°         /
                 /                      /
```

Each ray is a linear interpolation between the leftmost and rightmost ray of the camera plane.

---

### The Raycasting Pipeline

```
 Screen column x (0 → WIDTH)
 │
 ▼
 ┌──────────────────────────────────────────────────────┐
 │  1. Ray direction                                    │
 │     cameraX = 2 * x / WIDTH - 1  (range: -1 to 1)   │
 │     rayDir  = playerDir + cameraPlane * cameraX      │
 └────────────────────────┬─────────────────────────────┘
                          │
                          ▼
 ┌──────────────────────────────────────────────────────┐
 │  2. DDA — step through grid cells                    │
 │     compute deltaDist for X and Y axes               │
 │     step cell by cell until a wall is hit            │
 └────────────────────────┬─────────────────────────────┘
                          │
                          ▼
 ┌──────────────────────────────────────────────────────┐
 │  3. Perpendicular wall distance                      │
 │     avoid fisheye: project distance onto camera plane│
 │     perpWallDist = (mapX - posX + (1 - stepX) / 2)  │
 │                    / rayDirX                         │
 └────────────────────────┬─────────────────────────────┘
                          │
                          ▼
 ┌──────────────────────────────────────────────────────┐
 │  4. Wall slice height                                │
 │     lineHeight = HEIGHT / perpWallDist               │
 │     drawStart  = -lineHeight / 2 + HEIGHT / 2        │
 │     drawEnd    =  lineHeight / 2 + HEIGHT / 2        │
 └────────────────────────┬─────────────────────────────┘
                          │
                          ▼
 ┌──────────────────────────────────────────────────────┐
 │  5. Texture sampling                                 │
 │     wallX = exact hit position on the wall face      │
 │     texX  = wallX * TEX_WIDTH                        │
 │     for each pixel in slice → sample texY from tex   │
 └──────────────────────────────────────────────────────┘
```

---

### DDA — Stepping Through the Grid

DDA doesn't check every pixel. It computes exactly how far the ray must travel to cross the next vertical or horizontal grid line, then picks the shorter one and jumps there.

```
  ┌───────┬───────┬───────┬───────┐
  │       │       │  ███  │       │
  │       │       │  ███  │       │
  ├───────┼───────┼───────┼───────┤
  │       │   ·   │·──█   │       │   step 3 → wall hit on X side
  │       │   ·   │   █   │       │
  ├───────┼───────┼───────┼───────┤
  │  [P]──┼───────┤       │       │   step 1 → cross Y boundary
  │       │       │       │       │   step 2 → cross X boundary
  ├───────┼───────┼───────┼───────┤
  │       │       │       │       │
  └───────┴───────┴───────┴───────┘

  At each step: pick min(sideDistX, sideDistY)
  → jump to that boundary, check if it's a wall
```

---

### Fisheye Effect — The Problem & Fix

```
  WITHOUT correction (Euclidean distance)     WITH correction (perpendicular distance)
  ┌─────────────────────────────────┐         ┌─────────────────────────────────┐
  │         ░░░░░░░░░░░░░░░         │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  │       ░░            ░░░░        │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  │      ░                  ░░      │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  │      ░    bent wall     ░░      │   →→→   │  ░░░    straight wall    ░░░░░  │
  │      ░                  ░░      │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  │       ░░              ░░        │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  │         ░░░░░░░░░░░░░░          │         │  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  │
  └─────────────────────────────────┘         └─────────────────────────────────┘
  Rays at edges are longer → wall             Projected distance is constant →
  appears curved inward                       wall appears flat and correct
```

---

### Texture Mapping — Wall to Pixel

Each wall face maps to one texture. The engine finds the exact hit position on the wall, maps it to a texture column, then scales that column to fit the slice height.

```
  Wall texture (64×64):           Screen column:

  ┌──────────────────────┐        ┌──┐  ▲
  │##....####....####....│        │  │  │
  │##....####....####....│        │##│  │  wall slice height
  │##....####....####....│  ───►  │..│  │  (based on distance)
  │##....####....####....│        │##│  │
  │##....####....####....│        │  │  ▼
  └──────────────────────┘        └──┘
        ▲
        │ texX = wallX * TEX_WIDTH
        one column sampled and scaled
```

---

### What Each Screen Pixel Contains

```
  ┌────────────────────────────────────────────────────┐
  │                                                    │
  │   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   │  ← ceiling color (R,G,B)
  │   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   │
  │   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   │
  ├────────────────────────────────────────────────────┤
  │   ▓▓▓ ▒▒▒▒▒▒ ░░░░░░░░░░░░░ ▒▒▒▒▒ ▓▓▓▓▓▓▓▓▓▓▓▓   │  ← textured wall slices
  │   ▓▓▓ ▒▒▒▒▒▒ ░░░░░░░░░░░░░ ▒▒▒▒▒ ▓▓▓▓▓▓▓▓▓▓▓▓   │     (each column = 1 ray)
  │   ▓▓▓ ▒▒▒▒▒▒ ░░░░░░░░░░░░░ ▒▒▒▒▒ ▓▓▓▓▓▓▓▓▓▓▓▓   │
  │   ▓▓▓ ▒▒▒▒▒▒ ░░░░░░░░░░░░░ ▒▒▒▒▒ ▓▓▓▓▓▓▓▓▓▓▓▓   │     ▓ near  ▒ mid  ░ far
  ├────────────────────────────────────────────────────┤
  │   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   │  ← floor color (R,G,B)
  │   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   │
  │   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   │
  └────────────────────────────────────────────────────┘
```

---

## Project Structure

```
cub3D/
├── main.c                      # Entry point
├── Makefile
│
├── includes/
│   ├── data.h                  # Structs, defines, prototypes
│   ├── libft.h
│   └── mlx.h
│
├── src/
│   ├── parsing/
│   │   ├── map_parsing.c       # .cub file parser
│   │   ├── map_dimensions.c    # Grid size computation
│   │   ├── textures_parsing.c  # Texture path extraction
│   │   └── colors_parsing.c    # RGB color parsing
│   │
│   ├── rendering/
│   │   ├── raycasting.c        # Main render loop
│   │   ├── dda.c               # DDA wall detection
│   │   ├── dda_setup.c         # Ray initialization
│   │   ├── drawing.c           # Pixel-level drawing
│   │   ├── camera_plane.c      # Camera setup
│   │   └── textures_images.c   # Texture loading
│   │
│   └── movements/
│       ├── player_movements.c  # WASD movement logic
│       ├── player_rotations.c  # Camera rotation
│       ├── control_movements.c # Key input handler
│       └── cleanup.c           # Memory/resource cleanup
│
├── maps/                       # .cub map files
├── textures/                   # .xpm wall textures
├── libft/                      # Custom C library
└── minilibx/                   # Graphics library
```

---

## Getting Started

### Build

```bash
make          # compile
make clean    # remove object files
make fclean   # remove objects + executable
make re       # full rebuild
```

### Run

```bash
./cub3d maps/<map_name>.cub
./cub3d maps/hogsmade_map.cub
```

### Controls

| Key | Action |
|---|---|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate left |
| `→` | Rotate right |
| `ESC` | Quit |

---

## Map Format (`.cub`)

### Textures
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
```

### Colors
```
F 220,100,0       # floor  (R,G,B)
C 135,206,235     # ceiling (R,G,B)
```

### Map Grid

```
  ┌───────────────────────┐
  │ 1 1 1 1 1 1 1 1 1 1 1 │   ← walls enclose everything
  │ 1 0 0 0 0 0 0 0 0 0 1 │
  │ 1 0 0 1 1 0 0 0 0 0 1 │   ← interior walls
  │ 1 0 0 1 1 0 0 0 0 0 1 │
  │ 1 0 0 0 0 0 N 0 0 0 1 │   ← N = player spawn, facing north
  │ 1 0 0 0 0 0 0 0 0 0 1 │
  │ 1 1 1 1 1 1 1 1 1 1 1 │
  └───────────────────────┘
```

| Symbol | Meaning |
|---|---|
| `1` | Wall |
| `0` | Walkable space |
| `N` | Player spawn facing North |
| `S` | Player spawn facing South |
| `E` | Player spawn facing East |
| `W` | Player spawn facing West |

### Validation Rules

```
  VALID map ✓                      INVALID map ✗

  1 1 1 1 1                        1 1 1 1 1
  1 0 0 0 1                        1 0 0 0 1
  1 0 N 0 1                        1 0 N 0 0   ← open border
  1 0 0 0 1                        1 0 0 0 1
  1 1 1 1 1                        1 1 1 1 1

  1 1 1 1 1                        1 1 1 1 1
  1 0 0 0 1                        1 0 0 0 1
  1 0 N 0 1                        1 0 N 0 1
  1   0   1   ← spaces enclosed    1 0 0 0 1
  1 1 1 1 1                        (no player spawn)  ✗
```

- Map must be fully enclosed by walls
- Exactly one player spawn point
- No empty lines inside the map
- Spaces treated as void — must be enclosed by walls

---

## References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — the definitive guide to raycasting, DDA, texture mapping, and fisheye correction

---

## Authors

<div align="center">

| | Author | GitHub |
|---|---|---|
| | **akoaik** | [github.com/alikoaikk](https://github.com/alikoaikk) |
| | **msafa** | [github.com/mohamedsafa](https://github.com/mohamedsafa) |

*Built with curiosity and too many segfaults.*

</div>
