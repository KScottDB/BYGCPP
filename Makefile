BINARY = bin/BayoudGUI

CC = g++
NAMEFLAG = -Fe

FLAGS = -O2

SOURCES = Main.cc

$(BINARY): $(SOURCES)
	$(CC) $(FLAGS) $^ $(NAMEFLAG)"$@"


