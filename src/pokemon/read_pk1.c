#include "read_pk1.h"
#include "tables.h"


void read_pk1(gen_1_pokemon* p, unsigned char* data)
{
	//0, 1, 2
	p->species = data[3];
	p->current_hp = (data[4] << 8) | data[5];
	//6
	p->status_condition = data[7];
	p->type_1 = data[8];
	p->type_2 = data[9];
	p->catch_rate = data[10];
	p->move_1.name = data[11];
	p->move_2.name = data[12];
	p->move_3.name = data[13];
	p->move_4.name = data[14];
	p->ot_id = (data[15] << 8) | data[16];
	p->exp_points = (data[17] << 16) | (data[18] << 8) | data[19];
	p->ev.hp = (data[20] << 8) | data[21];
	p->ev.attack = (data[22] << 8) | data[23];
	p->ev.defence = (data[24] << 8) | data[25];
	p->ev.speed = (data[26] << 8) | data[27];
	p->ev.special = (data[28] << 8) | data[29];
	p->iv.attack = data[30] >> 4;
	p->iv.defence = data[30] & 0b1111;
	p->iv.speed = data[31] >> 4;
	p->iv.special = data[31] & 0b1111;
	p->move_1.pp = data[32] & 0b111111;
	p->move_1.pp_ups = data[32] >> 6;
	p->move_2.pp = data[33] & 0b111111;
	p->move_2.pp_ups = data[33] >> 6;
	p->move_3.pp = data[34] & 0b111111;
	p->move_3.pp_ups = data[34] >> 6;
	p->move_4.pp = data[35] & 0b111111;
	p->move_4.pp_ups = data[35] >> 6;
	p->level = data[36];
	p->stat.hp = (data[37] << 8) | data[38];
	p->stat.attack = (data[39] << 8) | data[40];
	p->stat.defence = (data[41] << 8) | data[42];
	p->stat.speed = (data[43] << 8) | data[44];
	p->stat.special = (data[45] << 8) | data[46];

	for(int i = 0; i < 10; i++)
	{
		p->original_trainer[i] = data[47 + i];
		p->nickname[i] = data[58 + i];
	}

	p->iv.hp = ((p->iv.attack & 1) << 3) + ((p->iv.defence & 1) << 2) + ((p->iv.speed & 1) << 1) + (p->iv.special & 1);
	p->gender = gender_list(pk1_pk2_species(p->species), p->iv.attack);
	p->shiny = 0;
	if(p->iv.defence == 10 && p->iv.speed == 10 && p->iv.special == 10)
	{
		if((p->iv.attack & 0b11) == 0b10 || (p->iv.attack & 0b11) == 0b11)
		{
			p->shiny = 1;
		}

	}
}
