#ifndef PERSONA_H
#define PERSONA_H
class Persona
{
	protected:
		int _id;
		char _apellido[50];
		char _nombre[50];
		char _dni[20];

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