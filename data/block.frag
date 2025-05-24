#version 330 core
//es

// ES requires setting precision qualifier
// Can be mediump or highp
precision highp float; // affects all floats (vec3, vec4 etc)

layout(location=0) out vec4 vFragColor;	//fragment shader output

//input form the vertex shader
smooth in vec4 vSmoothColor;		//interpolated colour to fragment shader
smooth in vec2 vSmoothTexcoord;

in float o_index;
uniform sampler2D textureSampler;
uniform bool uEnableTexture;

void main()
{
    vec4 final = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    if (uEnableTexture)
    {
        vec2 coords = vSmoothTexcoord;

        float x, y;

        float o_totalwidth = 64.0f;
        float o_totalheight = 4608.0f;
        float o_width = 64.0f;
        float o_height = 64.0f;

        //float o_index = 0;

        x = coords.x * (o_width  / o_totalwidth);
        y = coords.y * (o_height / o_totalheight) + o_index * (o_height  / o_totalheight);

        coords.x = x;
        coords.y = y;

        final = texture(textureSampler, coords);
    } else {
        //set the interpolated colour as the shader output
        final = vSmoothColor;
    }
    vFragColor = final;

    if (final.r == 1.0f && final.g == 0.0f && final.b == 1.0f)
        discard;

    vFragColor.rgb -= vSmoothColor.rgb;



    if (vFragColor.rgb == vec3(0.0f,0.0f,0.0f))
    {
        vFragColor.rgb = vec3(1.0f,1.0f,1.0f);
    }

    vFragColor.rgb = vec3(1.0f,1.0f,1.0f);
}

