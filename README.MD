If you want to be a good developer, please make your own tests. You should only use testers when you're correcting someone or just before submitting your work to see what tests you haven't thought of doing. If you finish a project without testing it yourself, you've only done a quarter of it.

- `git clone` wherever you prefer and `cd` to the folder
- `./Run_test.sh` will ask for the path to your project the first time you run it, you can change the paths in `.path` and `.include_path` if you need to change
- You can run `./Run_test.sh` with one or more arguments :
	- `clean`
	- `map` `vector` `list` ... (if you want to test specific containers)
- Each container name folder will store your errors (`diff`, `stderror`, `leaks`...)
- There is a main template named `.empty_main.cpp` in `container_name/mains/` if you want to add your own tests.
	- You must rename your file with the format `***_main.cpp`
	- Please make a pull request if you have interesting tests to add.

This tester was forked from hbaudet, thanks to him and to oroberts, rofernan, lmartin, thgermai and bbrunet for their contribution.
