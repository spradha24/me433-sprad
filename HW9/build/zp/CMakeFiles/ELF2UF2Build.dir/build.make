# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/siddp/Documents/GitHub/me433-sprad/HW9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siddp/Documents/GitHub/me433-sprad/HW9/build

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include zp/CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include zp/CMakeFiles/ELF2UF2Build.dir/progress.make

zp/CMakeFiles/ELF2UF2Build: zp/CMakeFiles/ELF2UF2Build-complete

zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
zp/CMakeFiles/ELF2UF2Build-complete: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E make_directory /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/CMakeFiles
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/CMakeFiles/ELF2UF2Build-complete
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/elf2uf2 && $(MAKE)

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: zp/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/elf2uf2 && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make "-GUnix Makefiles" -S /Users/siddp/Pico/pico-sdk/tools/elf2uf2 -B /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/elf2uf2
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/elf2uf2 && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-source_dirinfo.txt
zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/elf2uf2 && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -Dcfgdir= -P /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/tmp/ELF2UF2Build-mkdirs.cmake
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch-info.txt
zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update-info.txt
zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/siddp/Documents/GitHub/me433-sprad/HW9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

ELF2UF2Build: zp/CMakeFiles/ELF2UF2Build
ELF2UF2Build: zp/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: zp/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: zp/CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
zp/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : zp/CMakeFiles/ELF2UF2Build.dir/build

zp/CMakeFiles/ELF2UF2Build.dir/clean:
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp && $(CMAKE_COMMAND) -P CMakeFiles/ELF2UF2Build.dir/cmake_clean.cmake
.PHONY : zp/CMakeFiles/ELF2UF2Build.dir/clean

zp/CMakeFiles/ELF2UF2Build.dir/depend:
	cd /Users/siddp/Documents/GitHub/me433-sprad/HW9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siddp/Documents/GitHub/me433-sprad/HW9 /Users/siddp/Documents/GitHub/me433-sprad/HW9/zp /Users/siddp/Documents/GitHub/me433-sprad/HW9/build /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp /Users/siddp/Documents/GitHub/me433-sprad/HW9/build/zp/CMakeFiles/ELF2UF2Build.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : zp/CMakeFiles/ELF2UF2Build.dir/depend

