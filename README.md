# NEWick
This is a little app for generating random Newick Tree files (`.nwk`), as well as providing a little data structure to store phylogenetic trees as an N-Tree.
## Build and run
Compiling the application is very simple on UNIX-based machines with the provided Makefile:

```make``` 

It will generate two extra folders, `bin` (where the executable is located) and `build` (where the object files are located). If you want to delete them you can use the makefile too:

```make clean```

Known issues: Dynamic memory isn't freed after the end of the object's lifespan. Also, it sometimes fails to generate correct Newick Trees for very high node count values (around 300000).
