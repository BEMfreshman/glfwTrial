#include "Shader.h"

Shader::Shader(const char* vertexpath, const char* fragmentpath) {
	id = 0;
	this->vertexpath = vertexpath;
	this->fragmentpath = fragmentpath;
}

Shader::~Shader() {
	if (id != 0) {
		glDeleteProgram(id);
	}
}

bool Shader::compile()
{

	string vertexcode;
	string fragmentcode;

	ifstream vShaderfile;
	ifstream fShaderfile;

	vShaderfile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderfile.exceptions(ifstream::failbit | ifstream::badbit);

	try {
		vShaderfile.open(vertexpath);
		fShaderfile.open(fragmentpath);

		stringstream vshaderstream, fshaderstream;

		vshaderstream << vShaderfile.rdbuf();
		fshaderstream << fShaderfile.rdbuf();

		vShaderfile.close();
		fShaderfile.close();

		vertexcode   = vshaderstream.str();
		fragmentcode = fshaderstream.str();
	}
	catch (ifstream::failure e) {
		cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		return false;
	}

	const char* vShaderCode = vertexcode.c_str();
	const char* fShaderCode = fragmentcode.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoMsg[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, infoMsg);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoMsg << endl;
		return false;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, infoMsg);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoMsg << endl;
		return false;
	}

	id = glCreateProgram();
	glAttachShader(id, vertex);
	glAttachShader(id, fragment);
	glLinkProgram(id);

	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoMsg);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoMsg << endl;
		return false;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return true;
}

void Shader::use() {
	glUseProgram(id);
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
