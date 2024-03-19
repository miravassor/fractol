# Fract'ol

## Overview
Fract'ol is a project developed as part of the 42 school curriculum, aiming to introduce students to 2D programming and the world of fractals. 
Utilizing the minilibX graphics library, this project showcases a range of fractals, rendered with MinilibX in C.

## Features
- **Mandelbrot Set**
- **Julia Set**
- **Tricorn Fractal**
- **Burning Ship Fractal**
- **Interactive Controls:** Zoom in/out, shift colors.
- **MinilibX Integration:** Leveraging the lightweight minilibX library for creating graphical interfaces on macOS and Linux.

## Commands
- `+` : zoom in
- `-` : zoom out
- keyboard arrows : move view (left/right/up/down)
- mouse wheel up : zoom on mouse pointer
- mouse wheel down : zoom out (center wise)
- `tab` : switch sets
- `shift` : shift colors
  
## Julia set special arguments
- The Julia set can take 2 values to modify its shape
This values must lands between [-2.0;2.0]
Inputing no values will result in the default Julia shape
ex : `./fract-ol julia -2 1.5` or `./fract-ol mandelbrot`

## Installation
- `make` in directory


