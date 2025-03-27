#include <stdio.h>

#include "pokemon_file_type.h"
#include "data/pokemon_structs.h"
#include "data/game_versions.h"

#include "saves/read_rb_international.h"
#include "pokemon/read_pk1.h"
#include "pokemon/print_pk1.h"

#include "pokemon/read_pk2.h"


int file_size(FILE *file)
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
	FILE *file = fopen(argv[1], "rb");
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
		case RB_U:
			read_rb_international(buffer);
			break;

		case RB_J:
			printf("Red/Green/Blue japaneese file\n");
			break;

		case Y_U:
			printf("Yellow international file\n");
			break;

		case Y_J:
			printf("Yellow japaneese file\n");
			break;

		case GS_U:
			printf("Gold/Silver international file\n");
			break;

		case GS_J:
			printf("Gold/Silver japaneese file\n");
			break;

		case GS_K:
			printf("Gold/Silver korean file\n");
			break;

		case C_U:
			printf("Crystal international file\n");
			break;

		case C_J:
			printf("Crystal japaneese file\n");
			break;


		case 69:	//.pk1
			pk1 p;
			read_pk1(&p, buffer);
			print_pk1(&p);
			break;

		case 73:	//.pk2
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
