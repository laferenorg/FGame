# MIT License
#
# Copyright (c) 2021 laferenorg
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Settings
CCOPILER       = g++
ARCOMPILER     = ar

# Flags
COPTIMIZE      = -O2 -g -Ofast -Os -Og
CINCLUDE       = -I include/ -D _REENTRANT
 
# Source
CSOURCES_CPP   := $(wildcard src/*.cpp)

# Output
COUTPUT_SRC    = obj
COUTPUT_BIN    = bin
COUTPUT_BUILD  = build
CFINISH_OUTPUT = libfgame.a

# Main
all: check_obj compile compile_binary

check_obj:
	@if [ ! -d $(COUTPUT_BUILD) ]; then \
		mkdir $(COUTPUT_BUILD); \
	fi
	@if [ ! -d $(COUTPUT_BUILD)/$(COUTPUT_SRC) ]; then \
		mkdir $(COUTPUT_BUILD)/$(COUTPUT_SRC); \
	fi
	@if [ ! -d $(COUTPUT_BUILD)/$(COUTPUT_BIN) ]; then \
		mkdir $(COUTPUT_BUILD)/$(COUTPUT_BIN); \
	fi

compile_binary:
	@$(ARCOMPILER) rcs $(COUTPUT_BUILD)/$(COUTPUT_BIN)/$(CFINISH_OUTPUT) $(COUTPUT_BUILD)/$(COUTPUT_SRC)/*.o

compile:
	@for _source_ in $(CSOURCES_CPP); do \
		printf "\033[0;32mCompile File: [\033[0;33m$$_source_\033[0m\033[0;32m]\033[0m \n"; \
		$(CCOPILER) -c $$_source_ $(CINCLUDE) $(COPTIMIZE); \
	done
	@mv *.o $(COUTPUT_BUILD)/$(COUTPUT_SRC)