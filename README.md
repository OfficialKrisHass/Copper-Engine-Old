# Copper-Engine
Copper Engine is a primitive Game Engine Developed by Chris Husky.

Copper Engine Design Document: https://docs.google.com/document/d/1h_l3XcwuL_V9ATmodBqnZHSiIaWdZlpnKkB__3bXMx0/edit?usp=sharing

## How To Build
### Windows
1. Download Visual Studio 2022.
You can skip this step if you already have Visual studio 2022 instaless. Go on the https://visualstudio.microsoft.com website and choose the 'Visual Studio' option and select which type you want (Community,
Professional or Enterprise). a 'VisualStudioSetup.exe' file will be downloaded. Open the file. You will be most likely prompted to allow the file to make changes to your OS, press Yes. After that it will open
a small window, press Continue, Wait for it to instal things it will need (this can take some time) After that you will have a window opened with a bunch of things you want to install with Visual Studio, Make
sure that you selected 'Desktop Development with C++' and 'Game Development with C++', After that press the 'Install while Downloading' button in the bottom left corner. This will downloa the Visual Studio 2022
IDE and any plugins you are going to need.

2. Open the 'GenerateFiles.bat' file
This is a file that is going to generate the Project Files and correctly link everything together, at the current time this takes very little time aroun 1-2 seconds. After it's done you can press Enter or Close
the Console window. You will see that there is now a new 'Copper-Engine.sln' file in the root directory. This is the main Solution file for Visual Studio.

3. Open the newly generated 'Copper-Engine.sln' file
This will Open Visual Studio 2022. This might take a bit of time but at the current time it takes around 5-15 seconds but might depend on your computer.

4. Set the Configuration to Debug
Simply, on the tool bar on the upper side of the window you will have a little dropdown, if you click on it you should have 3 options, 'Debug' and 'Release' and 'Configuration Manager' (you can ignore the last 
option), select the Debug option.

4. Build and Launch
You have multiple ways of doing this. At the Current time you can right click on the 'Engine' Project (on the Right side in the Solution Explorer window) and select the 'Build' Option. In this commit time this can
take from 10 to 15 seconds to build, After this you can open the Root directory and open the new 'Build' Folder there you will have a Intermediate Folder (you can ignore this) and then a folder 
'windows-x86_64-Debug'. Open the 'windows-x86_64-Debug' folder and then the 'Engine' Folder, there you will have a 'Engine.exe' file, open that file.

### Linux
Copper Engine Currently doesn't support Linux

### Mac
Copper Engine Currently doesn't support Mac.