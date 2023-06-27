{
  description = "LeetCode C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils } @inputs:
    utils.lib.eachDefaultSystem (system:
      with import nixpkgs { inherit system; }; {
        devShells.default = mkShell {
          packages = [
            criterion
            gcc12
            glibc
            gcovr
            gnumake
            valgrind
          ];
        };
      });
}
