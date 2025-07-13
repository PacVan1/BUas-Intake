# Aysteroids

## Description
An asteroids-like game made in C++ and SFML for the BUas CMGT intake procedure (numerus-fixus).<br>
**Result**: Accepted!

![Opening](examples/opening.png)
![Gameplay](examples/gameplay.png)

## Features
- 2D elastic collisions based on [this article](https://www.vobarian.com/collisions/2dcollisions2.pdf)
- Fixed 2560x1600px resolution, because I did not have time for dynamic scaling

## Installation and Setup
The project uses **vcpkg manifests** to install dependencies and include source code. Therefore to build the project, [vcpkg](https://github.com/microsoft/vcpkg) is required.<br><br>
In the root folder of the project (next to vcpkg.json):
```bash
vcpkg install --triplet x86-windows
```

## Controls
| Action    | Key     | Description                                      |
|-----------|---------|--------------------------------------------------|
| Fly Right | D       | Ship flies right                                 |
| Fly Up    | W       | Ship flies up                                    |
| Fly Left  | A       | Ship flies left                                  |
| Fly Down  | S       | Ship flies down                                  |
| Fire      | Left MB | Ship fires projectile at the facing direction    |
| Aim       | Cursor  | Ship faces the cursor                            |

## Dependencies
The project depends on [SFML](https://github.com/SFML/SFML), a Simple and Fast Multimedia Library. This includes:
- Audio and sound effects
- Inputs
- Windows
- Graphics

## Patches
I wanted to keep the repository as vanilla as possible, but there were some major bugs/disturbances that had to be fixed:
- Added vcpkg manifests to not bloat the repository with dependencies
- Added an asset folder (for the fonts) to remove the build folders
- Fixed the game on 2560x1600px resolution
- Fixed the game starting in game over state
- Fixed the player speed-up at the first run
- Changed folder names and moved source files
