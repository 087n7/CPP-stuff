#include <windows.h>
#include <math.h>

// GDI Thread: Horizontal Sine Wave Screen Distortion
DWORD WINAPI gdi(LPVOID lpParam) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int sliceHeight = 10;
    double amplitude = 15.0;
    double frequency = 0.05;
    int frameOffset = 0;

    while (1) {
        HDC hdc = GetDC(NULL);
        for (int y = 0; y < screenHeight; y += sliceHeight) {
            int xShift = (int)(sin((y + frameOffset) * frequency) * amplitude);
            BitBlt(hdc, xShift, y, screenWidth, sliceHeight, hdc, 0, y, SRCCOPY);
        }
        ReleaseDC(NULL, hdc);
        frameOffset += 5;
        //Sleep(16);
    }
    return 0;
}
