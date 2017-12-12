# Brute force for Graph Isomorphism

This work is a study of the implementation found at
[nauty](http://pallini.di.uniroma1.it) package that uses canonical labeling to
identify isomorphic graphs.

The work consists in:

0. implement a brute force graph isomorphism checker (see brute.c);
1. generate graphs using _geng_ (_nauty_);
2. convert the graphs to a human readable format, using _showg_ (_nauty_);
3. format the graph to the format used by *brute*;
4. run the generate inputs in brute and _dreadnaut_ (_nauty_);
5. compare the results.

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

## TODO list

For now some restrictions applies due the simpler implementation we have so far.

1. Maximum of N vertices (`1 < N < 13`) vertices for each graph
2. The v vertices must be named with numbers `0 <= v < N`

Vertices are a list of numbers 0 

Vertices adjacencies are determined by a 

A list of adjacent vertices where all numbers 
Each graph must be define on a single line as a CSV entry
