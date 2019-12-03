#include <GL/glew.h>
#include <GL/freeglut.h>

#include "math_3d.h"
#include "globals.h"

class Rect {
    private:
        GLuint vbo;
        GLuint vao;
        GLuint shader_program;

        const char *vert_src_name;
        const char *frag_src_name;

        GLuint _normX_;
        GLuint _nfreq_;

        GLuint _E_;
        GLuint _nband_;

        GLuint _low_;
        GLuint _mid_;
        GLuint _hig_;


        GLuint _elapsed_t_;
        GLuint _w_;
        GLuint _h_;

        // textures
        GLuint u_now_;
        GLuint u_prv_;  

        void setup_draw( GLuint shader_program, GLuint vao );
        void cleanup_draw( );

    public:
        void init( const char *vert_src_name, const char *frag_src_name, bool assert_uniform );
        void recompile_shaders( bool assert_uniform );
        void set_global_uniforms();

        void draw();
        void draw( GLuint texture );
        void draw( GLuint tex1, GLuint tex2 );

};


