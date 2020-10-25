#include <winuser.h>
#include <stdio.h>

int main(){
    int screenx = GetSystemMetrics(SM_CXSCREEN);
    int screeny = GetSystemMetrics(SM_CYSCREEN);
    printf("x: %i\n", screenx);
    printf("y: %i\n", screeny);

    while(1){
        if(GetAsyncKeyState(VK_LCONTROL)){
            continue;
        }
        POINT curser;
        if(GetCursorPos(&curser)){
            if(curser.x == 0){
                SetCursorPos(screenx-2, curser.y);
            }else if(curser.x == screenx-1){
                SetCursorPos(0+1, curser.y);
            }
            if(curser.y == 0){
                SetCursorPos(curser.x, screeny-2);
            }else if(curser.y == screeny-1){
                SetCursorPos(curser.x, 0+1);
            }
        }else{
            printf("sth went wrong");
            return 0;
        }
    }
}