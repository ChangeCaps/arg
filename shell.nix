{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools
    pkgs.clang
    pkgs.glibcInfo
    pkgs.man-pages
  ];
}
