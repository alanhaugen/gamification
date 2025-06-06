#version 330 core
//es

// ES requires setting precision qualifier
// Can be mediump or highp
precision highp float; // affects all floats (vec3, vec4 etc)

layout(location = 0) in vec3 vVertex;	//object space vertex position
layout(location = 1) in vec4 vColor;	//per-vertex colour
layout(location = 2) in vec4 vNormal;	//per-vertex normals
layout(location = 3) in vec2 vTexcoord;	//per-vertex texcoord

#ifdef VULKAN
layout(set = 0, binding = 0) uniform UniformBlock
{
  mat4 MVP;	// combined modelview projection matrix
  vec4 colour;
  vec4 time;
  vec4 index;
  vec4 pos;
  vec4 scaleX;
  vec4 scaleY;
  vec4 width;
  vec4 height;
  vec4 totalWidth;
  vec4 totalHeight;
  vec4 screenWidth;
  vec4 screenHeight;
  vec4 flip;
  vec4 flipVertical;
  vec4 colourTint;
  mat4 modelMat;
  mat4 normalMat;
  vec4 lightPosition;
  vec4 cameraPosition;
} uniformBuffer;

layout(location = 0) out vec4 vSmoothColor;		//smooth colour to fragment shader
layout(location = 1) out vec2 vSmoothTexcoord;
layout(location = 2) out float vTime;
#else
//output from the vertex shader
smooth out vec4 vSmoothColor;		//smooth colour to fragment shader
smooth out vec2 vSmoothTexcoord;

//uniform
uniform mat4 MVP;	// combined modelview projection matrix
uniform vec4 colour;

uniform float time;
out float vTime;
#endif

void main()
{
#ifdef VULKAN
    vec4 colour = uniformBuffer.colour;
    mat4 MVP = uniformBuffer.MVP;
    float time = uniformBuffer.time.x;
#endif
    // assign the per-vertex colour to vSmoothColor varying
    //vSmoothColor = vec4(vColor) * colour;
    vSmoothColor = colour;
    vSmoothTexcoord = vTexcoord;
    vTime = time;

    //get the clip space position by multiplying the combined MVP matrix with the object space
    //vertex position
    gl_Position = MVP * vec4(vVertex, 1.0);
}

