int validate_list(unsigned char* data, int offset, int value)
{
	//If the file is valid, the byte should be lower than the value and the list should be a given length
	if(data[value] <= length && data[offset + data[offset] + 1] == 0xFF)
	{
		return 1;
	}
	return 0;
}


int pokemon_file_type(unsigned char* data, int size)
{
	//Differentiate between save files and individual pokemon files
	//If individual pokemon file
	if(size < 0x4000)
	{
		return -size;
	}

	//Differentiate between different save files from different games and languages
	//Search the save file for byte values and ranges that are unique to a specific game and language
	//Return code is of the format: Generation, Game Set, Language
	
	//Gen 1
	if(validate_list(data, 0x2F2C, 20) && validate_list(data, 0x30C0, 20))
	{
		//If the starter Pokemon is Pikachu
		if(data[0x29C3] == 0x54)
		{
			return 110;//Yellow international file
		}
		return 100;//Red/Blue international file
	}
	else if(validate_list(data, 0x2ED5, 30) && validate_list(data, 0x302D, 30))
	{
		//If the starter Pokemon is Pikachu
		if(data[0x29B9] == 0x54)
		{
			return 111;//Yellow japaneese file
		}
		return 101;//Red/Blue japaneese file
	}

	//Gen 2
	else if(validate_list(data, 0x288A, 20) && validate_list(data, 0x2D6C, 20))
	{
		return 200;//Gold/Silver international file
	}
	else if(validate_list(data, 0x283E, 30))
	{
		return 201;//Gold/Silver japaneese file
	}
	else if(validate_list(data, 0x2DAE, 20) && validate_list(data, 0x28CC, 20))
	{
		return 202;//Gold/Silver korean file
	}
	else if(validate_list(data, 0x2865, 20) && validate_list(data, 0x2D10, 20))
	{
		return 210;//Crystal international file
	}
	else if(validate_list(data, 0x281A, 30))
	{
		return 211;//Crystal japaneese file
	}

	return -1;
}
