<div align="center" >
  <img src="./img/minirobt.png" alt="minirt" width="175" height="175">
  <h1>&#128679; MiniRobT</h1>
  <h3>in progress...</h3>
</div>

<div align="center" >
  
[![TESTS CHECK](https://github.com/mini-RoboTao/miniRobT/actions/workflows/minirt-tests.yml/badge.svg)](https://github.com/mini-RoboTao/miniRobT/actions/workflows/minirt-tests.yml)
[![NORM CHECK](https://github.com/mini-RoboTao/miniRobT/actions/workflows/norminette-check.yml/badge.svg)](https://github.com/mini-RoboTao/miniRobT/actions/workflows/norminette-check.yml)
[![COMPILE CHECK](https://github.com/mini-RoboTao/miniRobT/actions/workflows/minirt.yml/badge.svg)](https://github.com/mini-RoboTao/miniRobT/actions/workflows/minirt.yml)

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
  - [How to run tests](#how-to-run-tests)
  - [References](#references)
- [What is 42?](#whats-is-42)
- [About the authors](#about-the-authors)

## The project

The Minirt project at School 42 is a challenging journey aimed at enhancing skills in C programming and 3D graphics. Through the implementation of an image renderer using ray tracing, participants dive into the world of ray intersection, shading, reflection, and refraction.

Ray tracing is an advanced algorithm used in realistic image rendering. It simulates the behavior of light by tracing rays through a virtual scene and calculating their interaction with objects. This results in precise shading, reflections, and refractions, delivering impressive visual quality.

In the Minirt project, students also explore the Whitted algorithm, developed by Turner Whitted in 1980. This algorithm introduced the concept of recursive rays, enabling the creation of multiple reflections and soft shadows. Combined with acceleration techniques like the Bounding Volume Hierarchy (BVH) data structure, the Whitted algorithm provides even more realistic and efficient visual results.

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

### How to run tests
To execute the tests, follow the steps below:

1. Run the script that will install the libcriterion library:
    ```shell
    source init_settings.sh
    ```
    > If you don't have execution permissions, change the permissions of the file using the following command:
    ```shell
    chmod <permission number> init_settings.sh

    # Example
    chmod 700 init_settings.sh
    ```

2. Run the `make` command to execute all the tests:
    ```shell
    make
    ```

3. Run the `make run-test` command to execute a specific test.
    > Replace `<test_folder>` with the test directory and `<test_name.c>` with the name of the test file:

    ```shell
    make run-test TEST_NAME=<test_name.c>

    # Example
    make run-test TEST_NAME=join_rgb_colors_test.c
    ```


### References

- https://harm-smits.github.io/42docs/libs/minilibx
- The Ray Tracer Challenge: A Test-Driven Guide to Your First 3D Renderer, by Jamis Buck
- https://github.com/Snaipe/Criterion

## What's is 42?

Lorep ipsum...

## About the authors

Lorep ipsum...
