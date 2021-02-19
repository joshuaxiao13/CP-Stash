# Shortcuts To Build + Execute In Terminal, Command Prompt, and Windows PowerShell

The shortcuts below provide an easy way to compile, build, and execute C++ code from [Terminal](https://en.wikipedia.org/wiki/Terminal_(macOS)), [Command Prompt](https://en.wikipedia.org/wiki/Cmd.exe), and [Windows PowerShell](https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/powershell).

Note the compilation code `-std=c++0x` is C++11. To use C++17, replace it with `-std=c++17`.


## Mac Terminal

1. Install `gcc`if you haven't already. Visit this [link on USACO Guide](https://usaco.guide/general/cpp-command?lang=cpp#on-mac) to install with [HomeBrew](https://brew.sh/).

2. Open terminal, and type in

```
touch ~/.zshrc
```

to create `.zshrc` if you haven't already. Now open the file with
```zshrc
open ~/.zshrc
```
3. In the text editor, copy and paste the following:

```
co() { g++ -std=c++0x -O2 -o "${1%.*}" $1 -Wall; }
run() { co $1 && ./${1%.*} & fg; }
```

4. Save `.zshrc` in the same directory as your `.cpp` files.

Now you can type in `co FILENAME` or  `run FILENAME` to compile or run your program. You'll need to be familiar with changing current working directory (`cd`). 

Source: [USACO Guide](https://usaco.guide/general/cpp-command?lang=cpp#mac-specific)

## Windows Command Prompt or Windows PowerShell

1. Install `gcc` if you haven't already. [mingw-w64](http://mingw-w64.org/doku.php/download) works well.

2. Open Notepad or any text editor, and copy and paste the following:

```bat
@echo off

echo [1] - Compiling	.....	%1
g++ -std=c++0x %1.cpp -Wall -O2 -o %1.exe

if %errorlevel% == 0 (
    echo [2] - Running	.....	%1
    echo:
    %1.exe
)

echo:
```

3. Save the file as `run.bat`, which is a batch file. Make sure this file is in the same directory as your `.cpp` files.

If you want to make a seperate function to solely compile code, make another batch file called `co.bat` and copy and paste the following: 

```bat
@echo off

echo [1] - Compiling	.....	%1
g++ -std=c++0x %1.cpp -Wall -O2 -o %1.exe

if %errorlevel% == 0 (
    echo [2] - Compilation Successful ..... %1
    echo:
)
echo:
```
You can name your batch files anything, as long as you remember what they are.


Now in Command Prompt, change the directory, and type in `run FILENAME`.
If you use PowerShell, type in `./run FILENAME`.
