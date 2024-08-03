#include <stdio.h>
#include <iostream>
#include "Window.hpp"

int main(int argc, char const *argv[])
{
    printf("Hello, world!\n");

    Window window = Window();
    if(window.init() != 0) {
        printf("Window didn't init properly, exiting.");
        return 1;
    }

    window.run();

    return 0;
}
