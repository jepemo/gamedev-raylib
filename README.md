# raylib-experiments
Raylib testing &amp; simple games &amp;&amp; experiments

## Installation

### Raylib (ubuntu)

```bash
# deps
sudo apt install build-essential git
sudo apt install cmake
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

# Install && compile raylib (dynamic library version)
git clone https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED
sudo make install RAYLIB_LIBTYPE=SHARED
```

## Ideas

To implement: https://gamedev.stackexchange.com/questions/854/what-are-good-games-to-earn-your-wings-with