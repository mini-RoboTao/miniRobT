<div align="center" >
  <img src="./img/minirobt.png" alt="minirt" width="175" height="175">
  <h1>&#128679; MiniRobT</h1>
  <h3>Ray Tracing</h3>
</div>

***

## Summary

- [The project](#the-project)
  - [Concept](#concept)
  - [First steps](#first-steps)
  - [Data structures](#data-structures)
  - [Functions](#functions)
  - [Render](#render)
  - [How to compile and run](#how-to-compile-and-run)
  - [References](#references)
- [What is 42?](#whats-is-42)
- [About the authors](#about-the-authors)

## The project

Lorep ipsum...

### Concept

Lorep ipsum...

### First steps

Lorep ipsum...

### Data structures

We use linked list to store data received from the RT file, where each line in the file will be one item in list.
After the processing and validate data input, each item will be transformaded into a 4x4 matrix.

### Functions

There are some functions to read and validate file and data input.
Other functions are to treat matrix and finally is render using MLX library.

### Render

We must use MLX library to render images.

### How to compile and run

Use `make` to compile the program.

Run with `./minirt {file.rt}`, where `{file.rt}` is the file with information about objects in the scene.

### References

- https://harm-smits.github.io/42docs/libs/minilibx
- The Ray Tracer Challenge: A Test-Driven Guide to Your First 3D Renderer, by Jamis Buck

## What's is 42?

Lorep ipsum...

## About the authors

Lorep ipsum...