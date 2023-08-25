{
  description = "LeetCode C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        cc = pkgs.gcc12;
        libs = with pkgs; [ criterion ];

        mkTests = name: dir: pkgs.stdenv.mkDerivation {
          inherit name;
          src = ./.;

          makeFlags = [ "CC=${cc}/bin/gcc" ];
          buildInputs = libs ++ [ pkgs.ncurses ];

          hardeningDisable = [ "format" "fortify" ];
          enableParallelBuilding = true;

          buildPhase = ''
            make -sC ${dir} run_tests NO_COV=1
          '';

          installPhase = ''
            mkdir -p $out/bin
            cp ${dir}/run_tests $out/bin/${name}
          '';
        };

      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            glibc
            gcovr
            ltrace
            gnumake
            valgrind
            python311Packages.compiledb
          ] ++ [ cc ] ++ libs;
        };

        formatter = pkgs.nixpkgs-fmt;
        packages = {
          default = mkTests "run_tests" ".";
        } // builtins.mapAttrs
          (
            k: v: mkTests k ("./src/" + k)
          )
          (builtins.readDir ./src);
      });
}
