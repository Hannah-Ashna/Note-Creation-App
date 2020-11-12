PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = note_app.o

#ifeq ($(BUILD_MODE),debug)
#	CFLAGS += -g
#else ifeq ($(BUILD_MODE),run)
#	CFLAGS += -O2  -std=c++11 -Wall
#else ifeq ($(BUILD_MODE),linuxtools)
#	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
#	LDFLAGS += -pg -fprofile-arcs -ftest-coverage 
#else
#    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
#endif
CFLAGS += -O2  -std=c++11 -Wall

all:	note_app

note_app:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ -lboost_program_options 

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr note_app $(OBJS)
