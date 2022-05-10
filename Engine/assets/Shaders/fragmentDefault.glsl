//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#version 330 core

in vec3 a_color;
in vec2 a_uvs;

uniform sampler2D tex0;

out vec4 FragColor;

void main() {
	
	//FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	//FragColor = vec4(a_color, 1.0);

	//FragColor = texture(tex0, a_uvs);
	FragColor = texture(tex0, a_uvs) * vec4(a_color, 1.0f);

}