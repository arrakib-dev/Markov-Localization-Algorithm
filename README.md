# Markov-Localization-Algorithm
Algorithm Desc goes here..


# Running the Code
 
In order to build the project **Cmake** in required. Cmake download and  install instructions can be found on cmake website: [https://cmake.org/](https://cmake.org/).

For Visual Studio: open the project directory with visual studio: ` File -> Open -> Folder...` and choose the root directory of the repo.

For comand line: follow the instructions in the following section.


## Build with cmake (command line)

- Clone the repository:
```
git clone https://github.com/arrakib-dev/Markov-Localization-Algorithm.git
```

- Naviigate to the root directory of the repo:
```
cd Markov-Localization-Algorithm 
```

- Create a build directory called 'out' or anything you like:
```
mkdir out
```

- Generate project buildsystem in 'out' directory:
```
camke -B out
```

- Build the project:
``` 
cmake --build out
```

- Run the Program:
	- Linux: Run the markov_localization_algorithm form 'out/markov_localization_algorithm/' directory
	```
	./out/markov_localization_algorithm/markov_localization_algorithm
	```

	- Windows: Run the markov_localization_algorithm.exe form 'out/markov_localization_algorithm/Debug' directory
	```
	out/markov_localization_algorithm/Debug/markov_localization_algorithm.exe
	```



