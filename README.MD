- `Run_test.sh` will look for all your containers and run every test it has for each
- If one or more container name is specified, then only listed containers will be tested
- tests are stored in each `Test/container_name/mains` folder
- You can pass arguments to the tester :
	- `clean` will clean your directory and exit
	- [...]
- You can see compile logs in `container_name/logs`
- You can see valgrind output (not available on mac os) in `container_name/leaks`
- You can see test outputs in `container_name/out`
- You can see output diff in `container_name/diff`
- You can see error outputs in `container_name/stderror`

- You can add your own tests as long as you respect these conditions:
	- Tests must be named as : `name_main.cpp` and placed in `container_name/mains/`
	- Tests must use
		```#ifndef STD
		# define NAMESPACE ft
		#else
		# define NAMESPACE std
		#endif
	
		using namespace NAMESPACE;

- Test will be run once normally and once with `-D STD` option.
- Test will be considered succesfull if outputs do not differ and if valgrind finds no leaks or errors.
- There is a main template named `.empty_main.cpp` in `container_name/mains/`
- Tests must use `#include "CONTAINER_UC.HPP"`. With no path prior to the file name. Include path will be set as a variable in the bash script

## OUTPUTS :

- `*some_main.cpp*` seems to be invalid : *some_main.cpp* does not compile, even with the std container
- `*some test*` does not compile : *some_main.cpp* does not compile with YOUR container, it compiles normally with std containers
- `*some test*` seems to leak : valgrind (if available) did not find "No leaks are possible" in the output :
	- Either program did not exit normally
	- Or it leaks
- `*some test*` : valgrind detected some errors : did not find "ERROR SUMMARY: 0 errors from 0 contexts" in valgrind output

If you have any question or suggestion, please feel free to PM me on slack @hbaudet ;)

##  Notes :

- Some tests come from cplusplus.com
- Some were written by myself (hbaudet)
- Some were submitted by other users

## Thanks :

- Oroberts
- [Rofernan](http://github.com/rofernan42)
- Lmartin
- Thgermai
- Bbrunet
- [...]

// THIS IS WIP, CHECK REGULARLY FOR UPDATES

## Incomimg :
- Detection (and kill) of infinite loops during tests
