# wuwa-moonlight

**this repo created only for educational purposes**

---

<!-- ![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/chadlrnsn/wuwa-moonlight/msbuild.yml?branch=master) -->
![GitHub forks](https://img.shields.io/github/forks/chadlrnsn/wuwa-moonlight)
![GitHub Repo stars](https://img.shields.io/github/stars/chadlrnsn/wuwa-moonlight)
![GitHub License](https://img.shields.io/github/license/chadlrnsn/wuwa-moonlight)
<!-- ![GitHub Release](https://img.shields.io/github/v/release/chadlrnsn/wuwa-moonlight) -->
[![Discord](https://img.shields.io/discord/1246834050119893064?logo=discord)](https://discord.gg/RJuN8UG4MJ)

## How to use

You should use CMake to compile this project.
Download [CMake](https://cmake.org/download/) and [git](https://git-scm.com/downloads)
Then open terminal in your desired directory and run:

```bash
# Clone the repository with submodules
git clone --recursive https://github.com/chadlrnsn/wuwa-moonlight.git

# Enter project directory
cd wuwa-moonlight

# Create and configure build directory
cmake -B build -S . --preset=win-amd64

# Build the project
cmake --build build --config Release
```

> [!Tip]
> I suggest you use cmake extension for vscode to compile the project.

The compiled DLL will be in the `wuwa-moonlight.vcxproj -> H:\yourpath\wuwa-moonlight\build\Release\wuwa-moonlight.dll` directory.

![preview](https://i.imgur.com/OJwrALG.jpeg)

## Features

- [ ] Speedhack
    - [ ] World Speedhack
    - [ ] Player Speedhack
        - [ ] Player Speedhack acceleration (WIP)
- [ ] Flight
    - [ ] Free Flight
    - [ ] Noclip
- [ ] Animation speed
- [ ] MultiHit
- [ ] ESP
    - [ ] ESP Items
    - [ ] ESP Entities
- [ ] Chest TP
- [ ] GodMode
- [ ] Configs
- [ ] World Speedhack

## Thanks to

[kiero hook](https://github.com/rdbo/ImGui-DirectX-11-Kiero-Hook)</br>
[Dumper-7](https://github.com/Encryqed/Dumper-7)</br>
[ImGui](https://github.com/ocornut/imgui)
[minhook](https://github.com/TsudaKageyu/minhook)
