@ECHO OFF

:main_loop
    ECHO ==============Menu===================
    ECHO     1. Prepare Camke
    ECHO     2. Build Executables
    ECHO     3. Run Test
    ECHO     4. Clean Test / Executables
    ECHO     5. Exit
    ECHO =====================================
    set /p id_main="Enter a number : "
    ECHO The entered number is %id_main%

	if %id_main%==1 (goto cmake_loop)
	if %id_main%==2 (goto build_loop)
	if %id_main%==3 (goto run_loop)
	if %id_main%==4 (goto clean_loop)
	if %id_main%==5 (goto pause_loop)
	
:cmake_loop
    ECHO ==============Menu===================
    ECHO     1. Build Camke Visual Studio Project
    ECHO     2. Build Camke Ninja CL Project
    ECHO     3. Build Camke MinGW GNU Project
    ECHO     4. Main Menu
    ECHO =====================================
    set /p id_cmake="Enter a number : "
    ECHO The entered number is %id_cmake%
    
    if %id_cmake%==1 (
        cmake -DCMAKE_CONFIGURATION_TYPES="Debug;Release" -DCMAKE_GENERATOR_PLATFORM=x64 -G "Visual Studio 16 2019" -B .\bin\VisualStudioProject
		goto cmake_loop
    )
    if %id_cmake%==2 (
		"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
	    set C=cl
	    set CXX=cl
		cmake -GNinja -B .\bin\ninja-cl 
		goto cmake_loop
    )
	if %id_cmake%==3 (
		set C=gcc
	    set CXX=g++
    	cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" -B .\bin\mingw-gnu
		set C=cl
	    set CXX=cl
		goto cmake_loop
    )
	if %id_cmake%==4 (
		goto main_loop
    )

:build_loop
    ECHO ==============Menu===================
    ECHO     1. Build Ninja-cl Tests
    ECHO     2. Build MinGW-gcc Tests
    ECHO     3. Main Menu
    ECHO =====================================
    set /p id_build="Enter a number : "
    ECHO The entered number is %id_build%

	if %id_build%==1 (
		cd bin\ninja-cl
		ninja all
		cd ..\..
		goto build_loop
	)
	if %id_build%==2 (
		cd bin\mingw-gnu
		mingw32-make all
		cd ..\..
		goto build_loop
	)
	if %id_build%==3 (
		goto main_loop
	)

:run_loop
    ECHO ==============Menu===================
    ECHO     1. Run Ninja-cl Tests
    ECHO     2. Run MinGW-gcc Tests
    ECHO     3. Main Menu
    ECHO =====================================
    set /p id_run="Enter a number : "
    ECHO The entered number is %id_run%

	if %id_run%==1 (
		cd bin\ninja-cl
		ninja CMakeFiles\test.util
		cd ..\..
		goto run_loop
	)
	if %id_run%==2 (
		cd bin\mingw-gnu
		mingw32-make test
		cd ..\..
		goto run_loop
	)
	if %id_run%==3 (
		goto main_loop
	)

:clean_loop
    ECHO ==============Menu===================
    ECHO     1. Run Ninja-cl Tests
    ECHO     2. Run MinGW-gcc Tests
    ECHO     3. Main Menu
    ECHO =====================================
    set /p id_clean="Enter a number : "
    ECHO The entered number is %id_clean%

	if %id_clean%==1 (
		cd bin\ninja-cl
		ninja clean
		cd ..\..
		goto clean_loop
	)
	if %id_clean%==2 (
		cd bin\mingw-gnu
		mingw32-make clean
		cd ..\..
		goto clean_loop
	)
	if %id_clean%==3 (
		goto main_loop
	)

:pause_loop
PAUSE