#ifndef PERSONA_H
#define PERSONA_H
class Persona
{
	protected:
		int _id;
		char _apellido[23];
		char _nombre[23];
		char _dni[10];

	public:
		Persona();

		void setId(int i);
		void setApellido(char* a);
		void setNombre(char* n);
		void setDni(char* d);

		int getId();
		char* getApellido();
		char* getNombre();
		char* getDni();
};
#endif