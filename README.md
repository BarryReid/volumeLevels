# volumeLevels
C++ Program to set Microsoft Windows device volume and channel (balance) volumes.

# OS tests
I have testing this script on Windows 8.1 and Windows 10, however this should work on any Windows OS from Vista forward. It will not work with windows XP as they changed the audio system after in future versions of windows.

# Compile
This is a C++ script so it needs to be compiled with Visual Studio. Just start a new command line program project and past this code over the contents of the defalt project .cpp file. If you want to build the program without lib dependancies then be sure to set the "Runtime Library" setting to "Multi-threaded (/MT)" This can be found in the Properties of your project under "Configuration Properties" -> "C/C++" -> "Code Generation"

# Info
Just change the constants at the top of the file to the desired volumes you would like (double between 0.0 - 1.0). This has been developed to just set channels left and right, however it should be very straight forward to add extra channels.
