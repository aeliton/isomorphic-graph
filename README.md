# Brute force for Graph Isomorphism

This work is a study of the implementation found at
[nauty](http://pallini.di.uniroma1.it) package that uses canonical labeling to
identify isomorphic graphs.

The work consists in:

1. ~~Gerador de entradas conforme descrito em python;~~
1. Um algoritmo que determina se dois grafos são isomorfos utilizando a técnica de força bruta (em ~~Python~~ C)
1. ~~Caso haja tempo, uma transcrição do algoritmo de McKay para python 3;~~
1. ~~Caso haja tempo, uma pequena introdução ao algoritmo quasi-polinomial de Babai (BABAI, 2016) (BABAI, 2017).~~
1. ~~generate graphs using _geng_ (_nauty_);~~
1. ~~convert the graphs to a human readable format, using _showg_ (_nauty_);~~
1. ~~format the graph to the format used by *brute*;~~
1. run the generate inputs in brute
1. run the generate inputs in _dreadnaut_ (_nauty_)
1. automate test executions with shell script for brute and TCL/expect for nauty
1. compare the results
1. Nauty evaluation

## Input

For *brute*, two lines must be given as input, each line describes a graph. The
input format follows these rules:

1. Vertex adjacencies are represented as a sequence of numbers separated by spaces
2. Vertices adjacencies are divided by semicolon (;) and given in order
3. A dot (.) represents the end of the input for the graph.

That structure was chosen due the input format used by dreadnaut program from
[nauty](http://pallini.di.uniroma1.it) package.

An example of input for a 6 vertices graph:

```
1 3 5; 0 2; 1; 5; 2; 1.
4 2; 1 3 5; 5; 2; 1; 0.
```

## Concepts for Canonical Labeling

Sources: nug26.pdf (_nauty_)

* **automorphism**: An automorphism of a graph is a permutation of the vertex
labels so that the set of edges remains the same;
* **equivalence**: Two vertices are equivalent if there is
an automorphism taking one to the other;
* **orbits**: A set of equivalent vertices;
* **canonical labelling**: This is an operation of placing the vertex labels in
a way that does not depend on where they were before;
* **isomorphic graphs**: Two graphs are isomorphic when their canonized
* representation are the same.

Nauty applies canonical labelling to determine isomorphic graphs.

## Nauty evaluation

### Problems

1. _dreadnaut_ is very difficult for scripting 
1. Convert from graph formats isn't done through one single tool (__showg__)
1. _geng_ doesn't allow to tell how many graphs we want, it produces all of them!
1. _geng_ drove me to 'disk full' producing +14GB of 13 vertices graphs
1. Source code isn't that good to understand (bad indentation, huge functions..)

### Kudos

1. Very fast
1. Nice documentation (pdf) provided among the package

## Experiments

The experiments consisted of running 10 instances each composed of two isomorphic graphs both in brute and _nauty_.

1. As expected, the experiments with brute took a lot of time with 13 nodes (~6 min)
1. Nauty took 0 seconds for the same inputs used in brute
1. Automated infra-structure to perform benchmarking
1. Skeleton code in C to implement isomorphism checking algorithms
1. Simple graph generator that takes the desired number of graphs as argument (learn this _geng_!)
1. Scripts that can be used as reference to further tasks automations

## TODO list

There's lots to do.. =/

For now some restrictions applies due the simpler implementation we have so far.

1. Maximum of N vertices (`1 < N < 13`) vertices for each graph
2. The v vertices must be named with numbers `0 <= v < N`

Vertices are a list of numbers 0 

Vertices adjacencies are determined by a 

A list of adjacent vertices where all numbers 
Each graph must be define on a single line as a CSV entry

