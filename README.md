# Physics Simulation - Bouncing Balls

A real-time physics simulation featuring multiple bouncing balls with collision detection and resolution, built with Raylib 5.0 and C++.

## Features

- **Multiple Ball Physics**: Simulates 7 balls with different sizes, colors, and initial velocities
- **Collision Detection**: Implements ball-to-ball collision detection with proper physics
- **Mass-Based Resolution**: Collision resolution accounts for ball mass (calculated from radius)
- **Wall Bouncing**: Balls bounce off window boundaries with proper velocity reflection
- **Real-Time Rendering**: Runs at 120 FPS for smooth animation
- **Elastic Collisions**: Uses restitution coefficient (0.97) for realistic energy loss

## Physics Implementation

The simulation implements realistic 2D physics:

- **Mass Calculation**: `mass = radius²`
- **Collision Response**: Uses impulse-based collision resolution
- **Position Correction**: Prevents ball overlap by pushing balls apart proportional to inverse mass
- **Velocity Updates**: Applies impulse along collision normal based on relative velocity and restitution

## Project Structure

```
physicsSimulation/
├── src/
│   ├── main.cpp      # Main entry point and game loop
│   ├── ball.h        # Ball class header
│   └── ball.cpp      # Ball physics implementation
├── lib/              # Windows DLL dependencies
├── output/           # Compiled executables
├── Makefile          # Build configuration
└── preview.jpg      # Screenshot of the simulation
```

## Building the Project

### Prerequisites

- Raylib 5.0 installed
- C++ compiler (g++ on Linux, MinGW on Windows, clang++ on macOS)
- Make utility

### Build Commands

**Linux:**
```bash
make
```

**Windows (MinGW):**
```bash
mingw32-make
```

**macOS:**
```bash
make
```

### Clean Build

```bash
make clean
```

## Running the Simulation

After building, run the executable:

**Linux/macOS:**
```bash
./game
```

**Windows:**
```bash
game.exe
```

Or run from the `output/` directory if built there.

## Controls

- **ESC** or **Close Window**: Exit the simulation
- The simulation runs automatically with no user interaction required

## Screenshot

<p align="center">
  <img src="preview.jpg" alt="Physics Simulation Screenshot" width="800">
</p>

## Technical Details

- **Window Size**: 800x600 pixels
- **Target FPS**: 120
- **Physics Update**: Delta-time based for consistent simulation speed
- **Collision Algorithm**: O(n²) pairwise collision detection (suitable for small number of balls)
- **Rendering**: Raylib's hardware-accelerated drawing

## Code Overview

### Ball Class (`ball.h`, `ball.cpp`)

The `Ball` class encapsulates:
- Position and velocity vectors
- Radius and mass
- Color properties
- Update method for movement and wall collision
- Static `ResolveCollision` method for ball-to-ball collision
- Draw method for rendering

### Main Loop (`main.cpp`)

The main loop:
1. Initializes the window and creates 7 balls with different properties
2. Updates each ball's position
3. Checks and resolves all pairwise collisions
4. Renders the scene with white background
5. Displays FPS counter

## Dependencies

- **Raylib 5.0**: C library for game programming
- **Standard C++14**: For vector containers and math functions
- **OpenGL**: For rendering (via Raylib)

## Platform Support

Tested on:
- Linux (Ubuntu/Debian)
- Windows 10/11
- macOS

## License

This project uses Raylib, which is licensed under the zlib/libpng license. See Raylib's license for details.
