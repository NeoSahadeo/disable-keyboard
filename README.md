## Keyboard blocker

An even lighterweight and stripped down version of evtest.

Usage:

```
sudo disable-keyboard /dev/input/event0
```

## CMake

```
cmake -B build
cmake --build build -D CMAKE_BUILD_TYPE=Release
```

## NixOS Install

```nix
let
  disable-keyboard-src = pkgs.fetchFromGitHub {
    owner = "NeoSahadeo";
    repo  = "disable-keyboard";
    rev   = "master";
    sha256 = "sha256-2O39hGVDH5POV3eOsKYwa4DJS0Qvle7WAubeiSsG7Dg="; # This will probably change, it will generate the correct one for you
  };

  disable-keyboard = pkgs.callPackage (disable-keyboard-src + "/default.nix") {};
in

  home.packages = with pkgs; [
#...
    disable-keyboard
#...
]

```
