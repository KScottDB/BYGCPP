BINARY = bin/BayoudGUI.exe

CC = cl
NAMEFLAG = /Fe

FLAGS = /O2

SOURCES = Main.cc

$(BINARY): $(SOURCES)
	$(CC) $(FLAGS) $** $(NAMEFLAG)"$@

