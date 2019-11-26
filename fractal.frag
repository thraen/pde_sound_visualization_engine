#version 330
//	in vec2 uv;

out vec4 color;
uniform float mid;
uniform float hig;
uniform float low;

uniform int _w;
uniform int _h;
uniform int _elapsed_t;

float t = float(_elapsed_t);

layout(pixel_center_integer) in vec4 gl_FragCoord;
void main() {
	vec2 z, c;
	//int iter	= 50;
	int iter	= int(200-100*low);
	float scale = 0.0010;//*(1-0.1*low);

	c.x = (gl_FragCoord.x -_w/2) * scale - 1;
	c.y = (gl_FragCoord.y -_h/2) * scale - 0.1;

	int i;
	z = c;
	for(i=0; i<iter; i++) {
		float x = (z.x * z.x - z.y * z.y) + c.x;
		float y = (z.y * z.x + z.x * z.y) + c.y;

		if((x * x + y * y) > 4.0) break;
		z.x = x;
		z.y = y;
	}

//	color = vec4( (i == iter) ? 1.0 : 0.0, 0, 0, 1);
	color = vec4( float(i) / float(iter) , 0, 0.001, 1);
	//color = vec4( float(i) / float(iter) , float(i)/hig/10, gl_FragCoord.x*0.001, 1);
}