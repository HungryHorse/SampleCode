#version 450 core

out vec4 fColor;

void main()
{
	if(gl_FragCoord.x > 150 && gl_FragCoord.y > 150)
	{
		fColor = vec4(0.0, 1.0, 0.0, 1.0);
	}
	else{
    fColor = vec4(0.0, 0.0, 1.0, 1.0);
	}
}
