# Fract'ol (with bonus)

## Overview
Fract'ol is a project developed as part of the 42 school curriculum, aiming to introduce students to 2D programming and the world of fractals. 
This project showcases a range of fractals, rendered with MinilibX in C.

![Burning Ship Fractal](/img/preview.png)

## Features
- **Mandelbrot Set**
- **Julia Set**
- **Tricorn Fractal**
- **Burning Ship Fractal**
- **Interactive Controls:** Zoom in/out, move around, shift colors.
- **MinilibX Integration:** Leveraging the lightweight minilibX library for creating graphical interfaces on Linux.

## Commands
- `+` : zoom in
- `-` : zoom out
- keyboard arrows : move view (left/right/up/down)
- mouse wheel up : zoom on mouse pointer
- mouse wheel down : zoom out (center wise)
- `tab` : switch sets
- `shift` : shift colors

## Usage
- Program needs an argument (the set name) to start:
- `./fract-ol mandelbrot`
- `./fract-ol julia`
- `./fract-ol tricorn`
- `./fract-ol burn`

## Julia set special arguments
- The Julia set can take 2 values to modify its shape, this values must lands between [-2.0;2.0]
- Inputing no values will result in the default Julia shape

## Installation
- `make` in directory (require gcc)


