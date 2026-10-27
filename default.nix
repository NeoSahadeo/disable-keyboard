{ pkgs ? import <nixpkgs> {} }:
with pkgs;

stdenv.mkDerivation {
	pname = "disable-keyboard";
	version = "1.0.0";

  src = ./.;

  nativeBuildInputs = [
    cmake
  ];
}
