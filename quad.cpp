void Quad::init(const char *v_src_name, const char *f_src_name){
    vert_src_name = v_src_name;
    frag_src_name = f_src_name;

    Vector3f Vertices[6];
    Vertices[0] = Vector3f(-1.0f, -1.0f,  0.0f);
    Vertices[1] = Vector3f( 1.0f, -1.0f,  0.0f);
    Vertices[2] = Vector3f(-1.0f,  1.0f,  0.0f);
    Vertices[3] = Vector3f(-1.0f,  1.0f,  0.0f);
    Vertices[4] = Vector3f( 1.0f, -1.0f,  0.0f);
    Vertices[5] = Vector3f( 1.0f,  1.0f,  0.0f);

    glGenBuffers(1, &vbo);
    fprintf(stderr, "Quad init. %o %lu\n", vbo, sizeof(Vertices));

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // free vertices?
    shader_program = glCreateProgram();
        if (shader_program == 0) { fprintf(stderr, "Error creating shader program\n"); exit(1); }
    recompile_shaders();

    u_now_      = glGetUniformLocation(shader_program, "u_now");
    //     assert(u_now_    != 0xFFFFFFFF);
    u_prv_      = glGetUniformLocation(shader_program, "u_prv");
    //     assert(u_prv_    != 0xFFFFFFFF);
}

void Quad::draw(){
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glUseProgram(shader_program);

    set_global_uniforms();

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
}

void Quad::draw(GLuint texture){
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glUseProgram(shader_program);

    set_global_uniforms();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(u_now_, 0);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
}

void Quad::draw(GLuint tex1, GLuint tex2){
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glUseProgram(shader_program);

    set_global_uniforms();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex1);
    glUniform1i(u_now_, 0);

    glActiveTexture(GL_TEXTURE0+1);
    glBindTexture(GL_TEXTURE_2D, tex2);
    glUniform1i(u_prv_, 1);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
}
