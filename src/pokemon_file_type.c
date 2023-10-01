int validate_list(unsigned char* data, int offset, int length)
{
	if(data[offset] <= length && data[offset + data[offset] + 1] == 0xFF)
	{
		return 1;
	}
	return 0;
}


int pokemon_file_type(unsigned char* data, int size)
{
	if(size < 0x4000)
	{
		return -size;
	}
	
	//Gen, game set, language
	//Gen 1
	if(validate_list(data, 0x2F2C, 20) && validate_list(data, 0x30C0, 20))
	{
		if(data[0x29C3] == 0x54)
		{
			return 110;
		}
		return 100;
	}
	else if(validate_list(data, 0x2ED5, 30) && validate_list(data, 0x302D, 30))
	{
		if(data[0x29B9] == 0x54)
		{
			return 111;
		}
		return 101;
	}

	//Gen 2
	else if(validate_list(data, 0x288A, 20) && validate_list(data, 0x2D6C, 20))
	{
		return 200;
	}
	else if(validate_list(data, 0x283E, 30))
	{
		return 201;
	}
	else if(validate_list(data, 0x2DAE, 20) && validate_list(data, 0x28CC, 20))
	{
		return 202;
	}
	else if(validate_list(data, 0x2865, 20) && validate_list(data, 0x2D10, 20))
	{
		return 210;
	}
	else if(validate_list(data, 0x281A, 30))
	{
		return 211;
	}

	return -1;
}
