#include <iostream>
#include <Windows.h>

#define PI 3.141592653589793

int main() {


    std::cout << "Running application: \n";
    std::cout << "\t | ESC to exit\n";
    std::cout << "\t | SHIFT to run\n";
    std::cout << "app designed to play https://neal.fun/perfect-circle/\n";
    std::cout << "(hold cursor in white dot)\n";
    
    bool running = true;


    POINT pos = POINT{};



    while (running) {
        if (!GetCursorPos(&pos)) {
            std::cout << "failed to read cursor position!\n";
        }



        if (GetAsyncKeyState(VK_SHIFT)) {
            int posX = pos.x;
            int posY = pos.y;
            int points = 360;

            bool firstDraw = true;
            for (int i = 0; i < points; i++) {
                float value = 2.0 * PI * i / points;
                int x = posX + 300 * cos(value);
                int y = posY + 300 * sin(value);

                SetCursorPos(x, y);
                if (firstDraw) {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
                    firstDraw = false;
                }
                Sleep(1);
            }
            mouse_event(MOUSEEVENTF_LEFTUP, posX, posY, 0, 0);
            SetCursorPos(posX, posY);
            
        }


        if (GetAsyncKeyState(VK_ESCAPE)) {
            running = false;
        }
    }
}
