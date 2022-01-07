#    MIT License
#    Copyright (c) 2017 Luigi Capogrosso

CC = gcc
SRC = main.c gauss.h gauss.c
TX1 = "default"
TX2 = "default"
DST = gauss

all:
	$(CC) $(SRC) -o $(DST)

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

run:
	./$(DST) $(RUN_ARGS)

clean:
	rm -f $(DST)
