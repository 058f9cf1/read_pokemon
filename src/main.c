#include <stdio.h>

#include "pokemon_file_type.h"
#include "pokemon/pokemon_structs.h"

#include "saves/read_rb_international.h"
#include "pokemon/read_pk1.h"
#include "pokemon/print_pk1.h"

#include "pokemon/read_pk2.h"


int file_size(FILE* file)
{
	//Test that the argument given is a file
	if(file == NULL)
	{
		return -1;
	}

	//Calculate the size of the file
	fseek(file, 0, SEEK_END); //Seek to the end of the file
	int size = ftell(file); //Get current file pointer
	fseek(file, 0, SEEK_SET); //Seek back to beginning of the file

	return size;
}


int main(int argc, char **argv)
{
	//Open file given as argument
	FILE* file = fopen(argv[1], "rb");
	//Determine the size of the file
	int size = file_size(file);
	if(size < 0)
	{
		printf("File doesn't exist\n");
		return -1;
	}
	//Read file to buffer
	unsigned char buffer[size];
	fread(buffer, size, 1, file);

	//Determine what type of file has been supplied
	int file_type = pokemon_file_type(buffer, size);

	switch(file_type)
	{
		case 100:	//Red/Blue international save file
			read_rb_international(buffer);
			break;

		case 101:	//Red/Green/Blue japaneese save file
			printf("Red/Green/Blue japaneese file\n");
			break;

		case 110:	//Yellow international save file
			printf("Yellow international file\n");
			break;

		case 111:	//Yellow japaneese save file
			printf("Yellow japaneese file\n");
			break;

		case 200:	//Gold/Silver international save file
			printf("Gold/Silver international file\n");
			break;

		case 201:	//Gold/Silver japaneese save file
			printf("Gold/Silver japaneese file\n");
			break;

		case 202:	//Gold/Silver korean save file
			printf("Gold/Silver korean file\n");
			break;

		case 210:	//Crystal international save file
			printf("Crystal international file\n");
			break;

		case 211:	//Crystal japaneese save file
			printf("Crystal japaneese file\n");
			break;


		case -69:	//.pk1
			gen_1_pokemon p;
			read_pk1(&p, buffer);
			print_pk1(&p);
			break;

		case -74:	//.pk2
			read_pk2(buffer);
			break;

		//Gen 3+ Pokemon and saves need to be decrypted


		//If file size does not match a known pokemon format
		default:
			printf("Not a Pokemon file\n");
			return -1;
	}

	fclose(file);

	return 0;
}
