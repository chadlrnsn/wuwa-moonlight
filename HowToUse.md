# How to use
This guide written to provide you how to use this software.

## Description
Download archive or compile project by itself.

This project includes injector `Moonlight.exe` and DLL `moonlight.dll`. The injector is designed to inject `moonlight.dll` and `bypass.dll` into a target process.

## Archive contents
The archive contains the following files:
- `Moonlight.exe` - DLL injector executable.
- `moonlight.dll` - DLL to be injected into the target process.


## Preparation
1. Make sure that all files (`Moonlight.exe`, `moonlight.dll` and `bypass.dll`) are in the same directory.

## Usage
1. Close game if it opened.
2. Run `Moonlight.exe`.
3. Choose path to the game. (for me its `H:\Wuthering Waves\Wuthering Waves Game\Client\Binaries\Win64\Client-Win64-Shipping.exe`)


### Example Usage
1. Place `Moonlight.exe`, `moonlight.dll`, and `bypass.dll` in the same folder.
2. Run `Moonlight.exe` and wait for next instructions or opening game.
3. If you don't have cfg.ini in same folder then injector will prompt you to select the game path. ( if you want to change path just delete cfg.ini or put path manualy in cfg.ini )
5. After successful injection, `bypass.dll` will block `AntiCheat` from being loaded.

## Notes
- Required administrator privileges to successfully execute the injection.
- Injecting and locking DLLs can be considered as malicious actions, so use this tool only within the law and with the consent of the system owner.

## Feedback
If you have any issues or questions, please contact us via GitHub Issues or discord: https://discord.gg/RJuN8UG4MJ.
