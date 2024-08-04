#include <stdio.h>
#include <iostream>
#include "Window.hpp"

int main(int argc, char const *argv[])
{
	printf("Hello, world!\n");

	Window window = Window();
	if(window.init() != 0) {
		fprintf(stderr, "Window didn't init properly, exiting.\n");
		return 1;
	}

	window.run();

	return 0;
}
