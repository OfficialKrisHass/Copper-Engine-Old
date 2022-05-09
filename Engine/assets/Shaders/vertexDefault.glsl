//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 uvs;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 a_color;
out vec2 a_uvs;

void main() {
	
	gl_Position = Projection * View * Model * vec4(position, 1.0);
	
	a_color = color;
	a_uvs = uvs;

}