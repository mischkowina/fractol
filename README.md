# fract'ol

This programm that I developed during my Core Curriculum at 42 Wolfsburg opens a graphical 
window and displays different fractals in it.
It is my first graphical project, and certainly my favorite project so far. 

### What's a fractal?
"A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale." 
In my own words: It is a cool pattern which repeats itself the further you zoom in. 

### Requirements:
The fractol project requires XQuartz to open a graphical window: https://www.xquartz.org/ 
Further it utilizes the `minilibx` of the 42 network, of which a version is included in the repo as well as my own standard library `libft`, which was my first 42 project.

### How to compile it:
`git clone` the repo on your computer. 
`cd` into `fractol/`.
Run `make` to compile.

### How to run it
Run `./fractol` to see the available options. There are different fractals and color-schemes available.
To choose an option and execute the program, run `./fractol <fractal_name> <color_scheme>`.

#### Available fractal options:
- `mandelbrot`
- `julia_1`              (Constant: -0.76 - 0.8i)
- `julia_2`              (Constant: -1.09 + 0.252i)
- `julia_3`              (Constant: 0.1071 + 0.5991i)
- `burning_ship`

#### Available color schemes:
- `bernstein`            (utilizing bernstein polynomials)
- `blue_hour`            (utilizing sine)
- `golden_hour`          (utilizing sine)
- `black_white`          (utilizing sine)

### How to operate the program:
- Use the zoom wheel of your mouse to zoom in and out.
- Use the arrow keys to move the view.
- Use the keys 1 - 4 to change the color scheme.
- Press `ESC` or the red cross to close the window and end the program.

## Cheers, enjoy my fractal!
<img width="1438" alt="Screen Shot 2022-06-01 at 10 19 21 AM" src="https://user-images.githubusercontent.com/94458598/172220604-45d39151-49e7-4c16-9a92-ce93d33bc066.png">
