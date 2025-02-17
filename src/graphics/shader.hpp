/**
 * A wrapper around a complete shader program.
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include <system/string.hpp>

#include <glad/glad.h>

#ifdef __APPLE__
typedef const GLchar * FileContents;
#else
typedef std::string_view FileContents;
#endif // __APPLE__

namespace gl {

class Shader {

private:
    // The OpenGL ID of this shader.
    unsigned program_id;
    // Create a single vertex or fragment shader.
    int create_subshader(FileContents source, GLenum type);
    // Finalize the shader.
    void link(int vert, int frag);

    // All uniforms.
    std::map<std::string, int> uniforms;

public:
    // Take in the file paths.
  Shader(FileContents vertex_source, FileContents fragment_source);
  ~Shader();

  void bind(); // set as active shader
  void unbind();
  void destroy();

  void register_uniform(std::string name);
  void set_uniform_value(std::string name, float value);

  friend void unload_all_shaders();

};

extern std::unique_ptr<Shader> GAME_SHADER; // the basic shader

/**
 * Initialize all shaders (for now just one)
 */
void load_all_shaders();
void unload_all_shaders();

}
