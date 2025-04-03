# Morse Code Blink LED – Project Summary

## Project Overview

This project focused on developing a Morse code translator in C that controls an LED on the Milk-V Duo embedded system. The program takes alphanumeric input, translates it into Morse code, and uses precise timing logic to blink the LED according to standard Morse transmission rules. The project emphasized embedded C development, GPIO control, cross-compilation for RISC-V, and unit testing using the Unity framework.

## Major Achievements

- **Morse Encoding Logic**: Implemented functions to convert characters and strings into Morse code, including support for alphabetic, numeric, and word spacing.
- **Hardware LED Blinking**: Developed LED blink functionality that adheres to Morse timing conventions using WiringX for GPIO control on the Duo board.
- **Cross-Compilation Toolchain**:
  - Integrated the RISC-V `x-tools` toolchain into a custom Docker image.
  - Created a `milkv_duo.cmake` CMake toolchain file for cross-compiling the application for the Milk-V Duo.
  - Successfully built separate binaries for host testing and Duo deployment (`build_host`, `build_duo`, `build_duo_test`).
- **Testing Infrastructure**:
  - Wrote a comprehensive suite of unit tests using the Unity framework to validate Morse encoding logic, edge cases, and timing behavior.
  - Verified LED blink behavior on physical hardware with accurate signal timing.
- **Containerized Build System**:
  - Created a Docker-based development environment for reproducible builds.
  - Automated WiringX setup and toolchain extraction in the Dockerfile.
- **GitHub Integration**:
  - Synchronized code between collaborators.
  - Resolved divergent branches and ensured version consistency across development machines.

## Challenges Encountered

- **Toolchain and Architecture Mismatch**: Initially compiled host (x86_64) binaries instead of RISC-V binaries, which led to runtime errors on the Duo. This was resolved by confirming cross-compilation settings and verifying binaries with the `file` command.
- **WiringX Integration Issues**: Faced challenges running the WiringX install script in Docker due to GitHub authentication and script logic. This was mitigated by modifying or manually executing the build steps outside the container as needed.
- **Git Conflicts and Merge Errors**: Encountered issues pushing changes due to remote updates. Addressed this with `git pull --rebase` and removal of untracked build artifacts.
- **Symbolic Link Requirement**: On the Duo, required manually creating a symbolic link for the dynamic linker:  
  `ln -sf /lib/ld-musl-riscv64v0p7_xthead.so.1 /lib/ld-musl-riscv64xthead.so.1`

## Final Project Status

- Host unit tests passed successfully using the `build_host` target.
- RISC-V binaries built and deployed to the Milk-V Duo.
- Morse code successfully displayed through LED blinking with correct timing and translation logic.
- Codebase is organized, documented, and version-controlled via GitHub.

