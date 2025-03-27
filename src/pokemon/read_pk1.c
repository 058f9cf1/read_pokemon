#include "data/pokemon_structs.h"
#include "data/tables.h"


void read_pk1(pk1 *p, unsigned char *data)
{
	int offset = 0x03;

	//Core bytes
	p->species = data[0x00 + offset];
	p->current_hp = (data[0x01 + offset] << 8) | data[0x02 + offset];
	p->level = data[0x03 + offset];
	p->status_condition = data[0x04 + offset];
	p->type_1 = data[0x05 + offset];
	p->type_2 = data[0x06 + offset];
	p->catch_rate = data[0x07 + offset];
	p->move_1.name = data[0x08 + offset];
	p->move_2.name = data[0x09 + offset];
	p->move_3.name = data[0x0A + offset];
	p->move_4.name = data[0x0B + offset];
	p->ot_id = (data[0x0C + offset] << 8) | data[0x0D + offset];
	p->exp_points = (data[0x0E + offset] << 16) | (data[0x0F + offset] << 8) | data[0x10 + offset];
	p->ev.hp = (data[0x11 + offset] << 8) | data[0x12 + offset];
	p->ev.attack = (data[0x13 + offset] << 8) | data[0x14 + offset];
	p->ev.defence = (data[0x15 + offset] << 8) | data[0x16 + offset];
	p->ev.speed = (data[0x17 + offset] << 8) | data[0x18 + offset];
	p->ev.special = (data[0x19 + offset] << 8) | data[0x1A + offset];
	p->iv.attack = data[0x1B + offset] >> 4;
	p->iv.defence = data[0x1B + offset] & 0b1111;
	p->iv.speed = data[0x1C + offset] >> 4;
	p->iv.special = data[0x1C + offset] & 0b1111;
	p->move_1.pp = data[0x1D + offset] & 0b111111;
	p->move_1.pp_ups = data[0x1D + offset] >> 6;
	p->move_2.pp = data[0x1E + offset] & 0b111111;
	p->move_2.pp_ups = data[0x1E + offset] >> 6;
	p->move_3.pp = data[0x1F + offset] & 0b111111;
	p->move_3.pp_ups = data[0x1F + offset] >> 6;
	p->move_4.pp = data[0x20 + offset] & 0b111111;
	p->move_4.pp_ups = data[0x20 + offset] >> 6;

	//Temp bytes
	//NOTE: Offset 0x21 is level when in the pc. It is always the same as the level stored in core bytes
	p->stat.hp = (data[0x22 + offset] << 8) | data[0x23 + offset];
	p->stat.attack = (data[0x24 + offset] << 8) | data[0x25 + offset];
	p->stat.defence = (data[0x26 + offset] << 8) | data[0x27 + offset];
	p->stat.speed = (data[0x28 + offset] << 8) | data[0x29 + offset];
	p->stat.special = (data[0x2A + offset] << 8) | data[0x2B + offset];

	//Trainer information
	for(int i = 0; i < 10; i++)
	{
		p->original_trainer[i] = gb_character_map(data[0x2F + i]);
		p->nickname[i] = gb_character_map(data[0x3A + i]);
	}

	//Calculated values
	p->iv.hp = ((p->iv.attack & 1) << 3) + ((p->iv.defence & 1) << 2) + ((p->iv.speed & 1) << 1) + (p->iv.special & 1);
	p->gender = gender(gb_species_index(p->species), p->iv.attack);
	p->shiny = 0;
	if(p->iv.defence == 10 && p->iv.speed == 10 && p->iv.special == 10)
	{
		if((p->iv.attack & 0b11) == 0b10 || (p->iv.attack & 0b11) == 0b11)
		{
			p->shiny = 1;
		}

	}
}
