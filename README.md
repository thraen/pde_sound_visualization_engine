A linux sound visualization engine using openGl and alsalib. 

[video] (https://www.youtube.com/embed/uh3lMbHAPew)

The visualization can be modified at runtime by changing 
active_fragment_shader.gl and pressing 'r' in the visualization window.

It's meant as a toy for playing with fragment shaders much like 
https://www.shadertoy.com/. Fourier analyzed sound data captured from an alsa 
device is made available to the fragment shader via uniform variables. 

Unlike shader toy, the last two rendered images are also fed into the shader 
as samplers, i.e. time derivative information is available which allows 
the implementation of 2D-finite-differences schemes for time-2nd-order PDEs
and opens up a whole class of cool visuals.

Examples for simple solvers for advection, diffusion and wave equations are
included. 

Dependencies:

It links against: alsalib, glut, glew, openGl, fftw3. 

Your graphics card must support openGL 4.0.

Usage:
git clone https://github.com/thraen/pde_sound_visualization_engine.git
cd pde_sound_visualization_engine; make
./a.out alsa-capture-device

for example ./a.out plughw:0,1
(I use a loopback device that can be used to capure all sound currently played)
