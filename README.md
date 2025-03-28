# Fractol - Computer Graphics Fractals

## Project Overview
The **Fractol** project is an exploration of fractals and computer graphics. It allows you to generate complex and visually appealing fractals, including the **Julia** and **Mandelbrot** sets. By leveraging zooming and coloring techniques, you can explore the infinite complexity of these fractals.

### Project Demo (Press on Picture)

[![Fractol Project Demo](https://img.youtube.com/vi/7rXLjtTH-oY/0.jpg)](https://www.youtube.com/watch?v=7rXLjtTH-oY)


## Features
### Fractals
- **Julia Set** and **Mandelbrot Set** rendering.
- Ability to generate different **Julia sets** by passing varying parameters.

### Interactive Features
- Zoom in and out using the **mouse wheel**.
- Use the **ESC** key to exit the program gracefully.
- Smooth window management for better interactivity.

### Coloring
- Use various colors to reveal the depth and intricacy of the fractals.
- Experiment with psychedelic coloring effects for a more dynamic view.

## Installation

To get started with **Fractol**, follow these steps:

### 1. Clone the repository:
```bash
git clone git@github.com:AhmadHirzallah/Fractals.git
cd Fractals
```

### 2. Compile the project:
Ensure you have the **MiniLibX** library installed. Afterward, compile the project using the `Makefile`:
```bash
make
```

### 3. Run the program:
To view a fractal, use the following commands:
```bash
./fractol mandelbrot
./fractol burning_ship   
./fractol julia -0.8 0.10
./fractol julia -1.3999 1.3999
./fractol julia -1.9 1.9
```

## Usage
- Use the following commands to explore different fractals:
  - `./fractol julia [param1] [param2]` – Generates the **Julia set** with specified parameters.
  - `./fractol mandelbrot` – Generates the **Mandelbrot set**.
  - `./fractol burning_ship` – Generates the **Burning Ship** fractal (Bonus feature).

### Controls:
- **Zoom** in and out using the **mouse wheel**.
- **ESC** – Close the program.

## Bonus Features
If you complete the mandatory part, you can implement the following additional features for bonus points:
- **Additional fractals** – Add more types of fractals for exploration.
- **Zoom centered around mouse position**.
- **Arrow keys** – Move the view in all directions for better exploration.
- **Dynamic color range shift** – Change colors over time for a dynamic effect.

## Requirements
- **MiniLibX** library for rendering.
- **math.h** for complex mathematical operations.

## Contact
Feel free to reach out via my:
- **[LinkedIn](https://www.linkedin.com/in/ahmad-hirzallah-7721412a5/)**
- **[GitHub Profile](https://github.com/AhmadHirzallah)**
```
