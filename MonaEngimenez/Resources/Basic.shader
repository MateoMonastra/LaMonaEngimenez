#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

void main()
{
	gl_Position = position;
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;         // Color uniforme (puedes usarlo si quieres un color base)
uniform sampler2D u_Texture;   // Textura
uniform float u_Alpha;         // Valor de alpha para el parpadeo

void main()
{
    vec4 texColor = texture(u_Texture, v_TexCoord);    // Obtiene el color de la textura
    texColor.a *= u_Alpha;                             // Multiplica el alpha de la textura por u_Alpha
    color = texColor;                                  // Asigna el color final con el alpha modificado
};