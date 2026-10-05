# zenith-bench-test

Firmware pour le banc de test moteur — Équipe Contrôle, Zenith.

## Architecture

Teensy 4.1 → capteurs (IMU, load cell, power module) → UART → RPi 4 → dashboard web(https://app.notion.com/p/zenithpolymtl/Bench-test-3e762814d76880be9475fa3a6612a50c?source=copy_link)

## Setup

### Développement (recommandé)
1. Installer VS Code + extension PlatformIO
2. Ouvrir `firmware/` dans VS Code
3. Build : Ctrl+Alt+B

### Avec Docker (CI / sans installation)
1. `make build


## Contribuer

- Les librairies du teensy se gèrent dans `firmware/platformio.ini` sous `lib_deps`
- Ne pas commit les dossiers `.pio/` ou `.vscode/`