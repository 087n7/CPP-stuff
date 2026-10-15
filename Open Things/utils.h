#pragma once
#define UTILS_H
#ifndef UTILS_H 

#define WIN32_LEAN_AND_MEAN 

#include <iostream>
#include <windows.h>
#include <string>
#include <shellapi.h>
#include <vector>
#include <chrono>

using namespace std;

/* This is optional */
inline void HideConsoleWindow() {
    HWND HIDEMENOWWWW = GetConsoleWindow();
    if (HIDEMENOWWWW) {
        ShowWindow(HIDEMENOWWWW, SW_HIDE);
    }
}

inline void ShellAPIOpen(const string& action = "open", const string& target = "cmd.exe", const string& params = "") {
    HideConsoleWindow();
    ShellExecuteA(NULL, action.c_str(), target.c_str(), params.empty() ? NULL : params.c_str(), NULL, SW_SHOWDEFAULT);
}

inline void OpenRandomStuff() {
    ShellAPIOpen("open", "cmd.exe");
}

#endif
