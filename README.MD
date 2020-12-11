#	42 / FT_CONTAINERS #

##	How to run tester:

./test.sh will run every tests available in ressources/mains

You can pass arguments to the tester :
- "clean" will clean your directory and exit
- [...]

You can add your own tests as long as you respect these conditions:

- Tests must be named as : 'name_main.cpp' and placed in ressources/mains/
- Tests must use
	* #ifndef STD
	* #define NAMESPACE ft
	* #else
	* #define NAMESPACE std
	* #endif
	*
	* using namespace NAMESPACE

	they will be run once normally and once with -D STD option

- Tests must '#include "Container.hpp"'. Include path will be set as a variable in the bash script

If you have anhy question or suggestion, please feel free to PM on slack @hbaudet ;)
