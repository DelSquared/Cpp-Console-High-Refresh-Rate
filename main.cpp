#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <string> //this is a lot but I am currently working on this and need all options available

using namespace std;

#include <stdio.h>
#include <Windows.h>
#include <Winuser.h>

int width = 120;
int height = 120;

int main()
{
    wchar_t *screen = new wchar_t[width*height];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	while(1){
        clock_t begin = clock();
        for(int y=0;y<height;y++){
            for(int x=0;x<width;x++){
            //these loops are where the screen is created. For test it is randomly initialised
                if (rand()%5<1){
                    screen[x+height*y] = '#';
                }
                else{
                    screen[x+height*y] = ' ';
                }

            }
        }
        clock_t end = clock();
        unsigned int FPS = (int)(CLOCKS_PER_SEC/double(end - begin));
        screen[width * height - 1] = '\0';
        std::ostringstream fpsstr;
        fpsstr<<"FPS = "<<FPS;
        SetConsoleTitle((fpsstr).str().c_str()); //title bar of the window displays FPS
        WriteConsoleOutputCharacter(hConsole, (char*)screen, width * height, { 0,0 }, &dwBytesWritten);
	}

    return 0;
}
