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
  - [How to run tests](#how-to-run-tests)
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
    make run-test TEST_NAME=./unit_test/<test_folder>/<test_name.c>

    # Example
    make run-test TEST_NAME=./unit_test/utils_test/join_rgb_colors_test.c
    ```


### References

- https://harm-smits.github.io/42docs/libs/minilibx
- The Ray Tracer Challenge: A Test-Driven Guide to Your First 3D Renderer, by Jamis Buck
- https://github.com/Snaipe/Criterion

## What's is 42?

Lorep ipsum...

## About the authors

Lorep ipsum...