#	42 / FT_CONTAINERS #

This project is a re-implementation of some of the STL containers.
It includes Vector, List, Map, Queue, Deque and Stack.
The whole project is c++98 compliant.

##	How to run tester:

`./Run_test.sh` will look for all your containers and run every test it has for each
- If one or more container name is specified, then only listed containers will be tested
- test are stored in each `container_name/ressources/mains` folder
- You can pass arguments to the tester :
	- `clean` will clean your directory and exit
	- [...]

- You can add your own tests as long as you respect these conditions:
	- Tests must be named as : `name_main.cpp` and placed in `ressources/mains/`
	- Tests must use
		```#ifndef STD
		# define NAMESPACE ft
		#else
		# define NAMESPACE std
		#endif
	
		using namespace NAMESPACE;```

- Test will be run once normally and once with `-D STD` option

- Tests must use `#include "Container.hpp"`. Include path will be set as a variable in the bash script

- There is a main template named `.empty_main.cpp` in `ressources/mains/`

If you have any question or suggestion, please feel free to PM me on slack @hbaudet ;)

## Thanks :
- oroberts
- [...]

// THIS IS WIP, CHECK REGULARLY FOR UPDATES
