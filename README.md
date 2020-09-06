# Corewar

A 42 School Silicon Valley algorithms project.

_image below is not our own visualizer_

![Corewar](corewar.png)

## Getting Started

### Downloading

```
git clone https://github.com/chimpansiets/Corewar.git
```
### Installing

Running 'make' in the directory will install all dependencies and create two executables.
- asm (for the assembler, which compiles .s files into .cor files)
- corewar (for the virtual machine, which runs the main program)

```
make
```

### Running

#### Assembler

First off you want to compile your champions from pseudo-assembly (.s) into the corresponding Corewar language.

```
./asm redcode_file.s
```

#### Corewar

The main executable handles up to 4 champions.
To see how the actual corewar operates, please reference the corewar.pdf.

```
./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...
```

There are many options, including (again, read corewar.pdf for more info):

```
-dump number		To dump memory after 'number' of cycles.
-s			To set the optional speed of the game (1 is fast, 100 is slow)
-viz			To display the visualizer.
-n playernum champion	To set the player number of the Champion.
-a / -activity		To show an activity monitor, which displays the number of processes being executed in the current cycle.
-r / -rainbow [1 - 10]	To enable rainbow mode, with optional speed of 1 to 10.
```

## Resources / External Links

* [Wikipedia](https://en.wikipedia.org/wiki/Core_War) - Wikipedia entry for Corewar

## Authors

* **Chesco coers** - [Chesco coers](https://github.com/*)
* **Annelein van Reijen** - [Annelein van Reijen](https://github.com/*)
* **Sietse Voort** - [Sietse Voort](https://github.com/chimpansiets)

[![Chimpansiets's github stats](https://github-readme-stats.vercel.app/api?username=chimpansiets&theme=great-gatsby&show_icons=true)](https://github.com/anuraghazra/github-readme-stats)
[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=chimpansiets&theme=great-gatsby&show_icons=true)](https://github.com/anuraghazra/github-readme-stats)

## License

MIT License. jk, I actually have no idea what license.
