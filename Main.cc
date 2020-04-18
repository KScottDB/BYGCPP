#include <string>
#include <iostream>

#include "Main.hh"
#include "YoutubeDL.hh"

int main() {
	YoutubeDL::YoutubeInterface ytInterface = YoutubeDL::YoutubeInterface();

	ytInterface.tmpDbg();

	return 0;
}