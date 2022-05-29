# Minesweeper 1-click solution analysis tool

Project Files

* MinesweeperAnalysis.cpp: the main implementation of this application.
* MinesweeperAnalysis.h: expose the core functions to the unit test evironment.
* TestMinesweeperAnalysis.cpp: the implementation of the unit test under Microsoftware CppUnitTestFramework.
* Desgin.md: demonstrate the analysis process of this problem and how the abstraction process to translate the system requirements to the software requirements.

How to use

Clone the project and build it with Microsoft Visual Studio, in the Debug folder, there is an executable named Minesweeper.exe.

Double click it, after the welcome banner, the application asks the A B N which means the size of the board and the nubmer of mines.

If there is a valid solution, the application prints out the layout with the nubmers, shown as below:
![image](https://user-images.githubusercontent.com/18339276/170851775-b9da414c-1957-4977-9a75-a3884e432ded.png)

If there is no valid configuraiton found, then the application prints a "Impossible!" string as required.
![image](https://user-images.githubusercontent.com/18339276/170851879-6a92cc62-b9a7-4309-85ca-4f228ef764cc.png)

Inputs verification
The number of mines need to be less than the nubmer of total squares and must not be 0, the size of the board must greater than 1.
This is an example of incorrect inputs detection
![image](https://user-images.githubusercontent.com/18339276/170851984-f09fa22b-605e-444c-a66a-209c323f95d1.png)
